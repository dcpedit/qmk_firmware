// Copyright 2023 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define AUDIO_INIT_DELAY
#define AUDIO_PIN B7
#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_RANDOMNESS 1.5f

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(STARTUP_SOUND)
#endif

// SPI configuration
#define SPI_MATRIX_DIVISOR 16
#define SPI_MODE 0
//#define SPI_DRIVER SPID1 // you might change this

// GPIO config for main SPI config needs to match up with the SPI bus you are using
//#define SPI_SCK_PIN  GPxx // e.g. SPI0 SCK
//#define SPI_MOSI_PIN GPxx // e.g. SPI0 TX (Master Out, Slave In)
//#define SPI_MISO_PIN GPxx // e.g. SPI0 RX (Master In, Slave Out)
#ifdef SPI_MISO_PIN
#undef SPI_MISO_PIN
#endif
#define SPI_MISO_PIN NO_PIN

// GPIO config for CS/latch pins can be any GPIO
#define SPI_MATRIX_LATCH_PIN B6
#define SPI_MATRIX_CHIP_SELECT_PIN_COLS B0

// custom matrix config
#define MATRIX_COLS_SHIFT_REGISTER_COUNT 1

// LED for layer indicator
#define LED_LAYER_PIN F0
//#define DEBUG_ENABLE 1