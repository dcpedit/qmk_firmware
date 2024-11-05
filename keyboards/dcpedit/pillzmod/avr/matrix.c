// Copyright 2025 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "wait.h"
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
        /*
         * Since AVR has no internal pull-down resistors,
         * physical 10k resistors are required on each row pin
         */
        // setPinInputLow(row_pins[row]);
    }

    // Init latch pin
    setPinOutput(latch_pin);
    writePinLow(latch_pin);

    // Initialize shift register (for columns)
    spi_init();
}

#ifdef DEBUG_ENABLE
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
#endif

static inline void write_to_cols_dynamic(uint8_t col) {
    uint8_t message[MATRIX_COLS_SHIFT_REGISTER_COUNT] = {0x00}; // Initialize all bits to '0'

    // Calculate which register should get the '1' and shift it accordingly
    uint8_t register_index = col / 8;
    uint8_t bit_position = col % 8;

    // Set the correct bit in the appropriate shift register (set to '1')
    message[register_index] |= (1 << bit_position);

#ifdef DEBUG_ENABLE
    // Output the contents of the message array
    xprintf("Message contents for col %d: ", col);
    for (uint8_t i = 0; i < MATRIX_COLS_SHIFT_REGISTER_COUNT; i++) {
        xprintf("0x%02X ", message[i]); // Output in hex format
    }
    xprintf("\n");
#endif

    // Transmit the message to the SPI bus
    spi_start(NO_PIN, true, SPI_MODE, SPI_MATRIX_DIVISOR);
    spi_transmit(message, MATRIX_COLS_SHIFT_REGISTER_COUNT);
    spi_stop();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool matrix_has_changed = false;

#ifdef DEBUG_ENABLE
    xprintf("START scan ======================================\n");
#endif

    // Scan each column
    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        write_to_cols_dynamic(col);

        // Move data from latch to shift register
        write_and_wait_for_pin(latch_pin, 1);
        write_and_wait_for_pin(latch_pin, 0);

        // Read each row pin and update `current_matrix` directly
        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            bool row_value = readPin(row_pins[row]);

            // Check if the row pin is low (key pressed)
            uint16_t row_bit = (1 << col);  // Represents the current column's bit in the row

            // If the row is pressed (row_value == 1) and current_matrix is not updated
            if (row_value) {
                if (!(current_matrix[row] & row_bit)) {
                    current_matrix[row] |= row_bit; // Set the bit for the column
                    matrix_has_changed = true; // Mark matrix as changed
                }
            } else {
                // If row is not pressed, and current_matrix was previously set
                if (current_matrix[row] & row_bit) {
                    current_matrix[row] &= ~row_bit; // Clear the bit
                    matrix_has_changed = true; // Mark matrix as changed
                }
            }
        }
    }

#ifdef DEBUG_ENABLE
    // Print column scan debug info
    xprintf("Current Matrix:\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        print_binary(current_matrix[row], MATRIX_COLS);
    }

    // Optional wait time in debug mode
    wait_ms(3000);
#endif


    return matrix_has_changed;
}

