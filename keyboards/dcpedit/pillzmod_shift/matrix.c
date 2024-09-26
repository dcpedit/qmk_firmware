#include "wait.h"  // Include QMK wait functions
#include "print.h"
#include "quantum.h"
#include "spi_master.h"
#include <util/delay.h>  // AVR-specific delay library

#if (MATRIX_ROWS <= 8)
typedef uint8_t matrix_col_t;
#elif (MATRIX_ROWS <= 16)
typedef uint16_t matrix_col_t;
#elif (MATRIX_ROWS <= 32)
typedef uint32_t matrix_col_t;
#else
#    error "MATRIX_ROWS: invalid value"
#endif

// Define row pins directly
static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const pin_t latch_pin = SPI_MATRIX_LATCH_PIN;

/*
static void write_and_wait_for_pin(pin_t pin, uint8_t target_state) {
    writePin(pin, target_state);  // Write the target state to the pin
    while (readPin(pin) != target_state) {
        wait_us(1);  // Wait 1 microsecond until the pin state matches the target state
    }
}
*/

static void write_and_wait_for_pin(pin_t pin, uint8_t target_state) {
    //writePin(pin, target_state);  // Write the target state to the pin
    if (target_state) {
        writePinHigh(pin);
    } else {
        writePinLow(pin);
    }

    // Simple polling loop to wait until the pin reaches the target state
    uint16_t timeout = 20000; // 20 ms timeout in microseconds
    while (timeout--) {
        if (readPin(pin) == target_state) {
            return;  // Pin has reached the target state, exit the function
        }
        _delay_us(1);  // Wait for 1 microsecond between checks
    }
}

void matrix_init_custom(void) {
    // Initialize row pins as inputs
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        setPinInput(row_pins[row]);
        // Enable internal pull-up resistors
        setPinInputHigh(row_pins[row]);
    }

    // Init latch pin
    setPinOutput(latch_pin);
    writePinLow(latch_pin);

    // Initialize shift register (for columns)
    spi_init();
    //spi_start(SPI_MATRIX_CHIP_SELECT_PIN_COLS, true, SPI_MODE, SPI_MATRIX_DIVISOR);
    //writePinLow(latch_pin);
}

void print_binary(uint16_t value, uint8_t bits) {
    for (int8_t i = bits - 1; i >= 0; i--) {
        if (value & (1 << i)) {
            xprintf("1");
        } else {
            xprintf("0");
        }
    }
    xprintf("\n");
}

static inline void write_to_cols_dynamic(uint8_t col) {
    uint8_t message[MATRIX_COLS_SHIFT_REGISTER_COUNT] = {0xFF}; // Initialize all bits to '1'

    // Calculate which register should get the '0' and shift it accordingly
    uint8_t register_index = col / 8;
    uint8_t bit_position = col % 8;

    // Clear the correct bit in the appropriate shift register (set to '0')
    message[register_index] &= ~(1 << bit_position);

    // Output the contents of the message array
    xprintf("Message contents for col %d: ", col);
    for (uint8_t i = 0; i < MATRIX_COLS_SHIFT_REGISTER_COUNT; i++) {
        xprintf("0x%02X ", message[i]); // Output in hex format
    }
    xprintf("\n");

    // Transmit the message to the SPI bus
    //spi_start(SPI_MATRIX_CHIP_SELECT_PIN_COLS, true, SPI_MODE, SPI_MATRIX_DIVISOR);
    spi_transmit(message, MATRIX_COLS_SHIFT_REGISTER_COUNT);
    //spi_stop();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    static matrix_row_t temp_matrix[MATRIX_ROWS] = {0};
    static matrix_col_t temp_matrix_inverted[MATRIX_COLS] = {0};

    xprintf("START scan ======================================\n");

    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        write_to_cols_dynamic(col);
        // Move data from latch to shift register
        write_and_wait_for_pin(latch_pin, 1);
        write_and_wait_for_pin(latch_pin, 0);

        // Read each row pin
        uint16_t temp_row_state = 0;
        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            bool row_value = readPin(row_pins[row]); 
            // Check if the row pin is low (key pressed)
            if (!row_value) {
                temp_row_state |= (1 << row);  // Set the bit for this row in the row state
            }
        }

        temp_matrix_inverted[col] = temp_row_state;

        //xprintf("Col %u - Row state: ", col);
        //print_binary(temp_row_state, MATRIX_COLS); // Print 7 bits for 7 columns
    }

    // Transpose the inverted matrix to the normal matrix
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        temp_matrix[row] = 0;  // Clear the row first

        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            // Check if the bit for this row is set in the column
            if (temp_matrix_inverted[col] & (1 << row)) {
                temp_matrix[row] |= (1 << col);  // Set the bit in the normal matrix
            }
        }
        xprintf("Row %u - col state: ", row);
        print_binary(temp_matrix[row], MATRIX_ROWS);
        //print_binary(current_matrix[row], MATRIX_ROWS);
    }

    bool matrix_has_changed = memcmp(current_matrix, temp_matrix, sizeof(temp_matrix)) != 0;

    if (matrix_has_changed) {
        xprintf("Matrix has changed!\n");
        memcpy(current_matrix, temp_matrix, sizeof(temp_matrix));
    }

#ifdef DEBUG_ENABLE
    wait_ms(3000);
#endif

    return matrix_has_changed;
}

