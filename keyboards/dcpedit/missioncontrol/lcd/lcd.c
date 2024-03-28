// Copyright 2023 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "qp_comms.h"
#include "qp_ili9xxx_opcodes.h"
#include "image/background.qgf.h"

static painter_device_t lcd;
static painter_image_handle_t background;

void keyboard_post_init_kb(void) {
    background = qp_load_image_mem(gfx_background);
    backlight_set(get_backlight_level());

    // Give the LCD some time to get some power
    wait_ms(150);

    // Initialise the LCD
    lcd = qp_ili9341_make_spi_device(240, 320, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 4, 0);
    qp_init(lcd, QP_ROTATION_180);

    #ifdef LCD_INVERT_COLOR
    qp_comms_start(lcd);
    qp_comms_command(lcd, ILI9XXX_CMD_INVERT_ON);
    qp_comms_stop(lcd);
    #endif

    // Turn on the LCD
    qp_power(lcd, true);

    // Draw image
    qp_drawimage(lcd, 0, 0, background);

    keyboard_post_init_user();
}