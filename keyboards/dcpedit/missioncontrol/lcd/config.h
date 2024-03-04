// Copyright 2023 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* LCD config */
#define LCD_INVERT_COLOUR true
#define LCD_DC_PIN A13    // data/command
#define LCD_CS_PIN A4     // chip select
#define LCD_RST_PIN A14   // reset
#define BACKLIGHT_PWM_DRIVER PWMD1
#define BACKLIGHT_PWM_CHANNEL 3
#define BACKLIGHT_PAL_MODE 1

/* SPI pins */
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN A5
#define SPI_MOSI_PIN A7
#define SPI_MISO_PIN NO_PIN

#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0 // milliseconds
#define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE