// Copyright 2024 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once
#include_next <mcuconf.h>

#undef STM32_PWM_USE_TIM1 //timer 1 channel 3
#define STM32_PWM_USE_TIM1 TRUE

#undef STM32_SPI_USE_SPI1
#define STM32_SPI_USE_SPI1 TRUE

#undef STM32_PWM_USE_PWM1
#define STM32_PWM_USE_PWM1 TRUE