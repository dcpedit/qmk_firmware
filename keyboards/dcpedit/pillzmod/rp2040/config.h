// Copyright 2025 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define AUDIO_PIN GP12
#define AUDIO_PWM_DRIVER PWMD6
#define AUDIO_INIT_DELAY
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_RANDOMNESS 1.5f

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(STARTUP_SOUND)
#endif

#define SOLENOID_PIN   GP10
#define NO_HAPTIC_MOD

// SPI configuration
#define SPI_MATRIX_DIVISOR 16
#define SPI_MODE 0
#define SPI_DRIVER SPID0

// GPIO config for main SPI config needs to match up with the SPI bus you are using
#define SPI_SCK_PIN  GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN NO_PIN

// GPIO config for CS/latch pins can be any GPIO
#define SPI_MATRIX_LATCH_PIN GP21

// custom matrix config
#define MATRIX_COLS_SHIFT_REGISTER_COUNT 1

// LED for layer indicator
#define LED_LAYER_PIN GP16