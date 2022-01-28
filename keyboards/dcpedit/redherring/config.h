/* Copyright 2021 Kyle McCreery 
 * 
 * This program is free software: you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 2 of the License, or 
 * (at your option) any later version. 
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * GNU General Public License for more details. 
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 */


#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xDC9E
#define PRODUCT_ID      0x12ED
#define DEVICE_VER      0x0001
#define MANUFACTURER    dcpedit
#define PRODUCT         redherring

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 15

/* key matrix pins */
#define MATRIX_ROW_PINS { C6, A6, A7, A4, C7, A5 }
#define MATRIX_COL_PINS { A1, A2, A3, B0, B1, B2, B3, B4, D0, D1, D5, D6, C5, C4, C3 }
#define UNUSED_PINS

/* Indicator LEDs */
#define LED_CAPS_LOCK_PIN   A0

/* encoder pins */
#define ENCODERS_PAD_A { C2 }
#define ENCODERS_PAD_B { D7 }
#define ENCODER_DIRECTION_FLIP

/* encoder resolution */
#define ENCODER_RESOLUTION 4
#define TAP_CODE_DELAY 10

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

/* OLED DRIVER CONFIG */
/* Merged from: https://github.com/qmk/qmk_firmware/compare/master...sigprof:oled-driver-new-hardware-support-v2 */
#define OLED_DISPLAY_CUSTOM
#define OLED_DISPLAY_WIDTH 64
#define OLED_DISPLAY_HEIGHT 128
#define OLED_COM_PIN_OFFSET 32
#define OLED_MATRIX_SIZE (OLED_DISPLAY_HEIGHT / 8 * OLED_DISPLAY_WIDTH)
#define OLED_BLOCK_TYPE uint16_t
#define OLED_SOURCE_MAP { 0, 8, 16, 24, 32, 40, 48, 56 }
#define OLED_TARGET_MAP { 56, 48, 40, 32, 24, 16, 8, 0 }
#define OLED_BLOCK_COUNT (sizeof(OLED_BLOCK_TYPE) * 8)
#define OLED_BLOCK_SIZE (OLED_MATRIX_SIZE / OLED_BLOCK_COUNT)
#define OLED_COM_PINS COM_PINS_ALT
#define OLED_IC OLED_IC_SH1107
#define OLED_BRIGHTNESS 30
/*
#define OLED_TIMEOUT 15000
#define OLED_UPDATE_INTERVAL 200
*/
