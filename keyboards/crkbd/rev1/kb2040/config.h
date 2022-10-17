/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

#undef PRODUCT
#define PRODUCT Corne KB2040

// I2C settings
#define I2C_DRIVER I2CD2
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3

// rp2040 bootloader settings
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

// changed pin names
#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS \
    { GP4, GP5, GP6, GP7 }
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS \
    { GP29, GP28, GP27, GP26, GP22, GP20 }

#ifdef SOFT_SERIAL_PIN
#    undef SOFT_SERIAL_PIN
#endif
#define SOFT_SERIAL_PIN GP1

// #ifdef SERIAL_USART_TX_PIN
// #    undef SERIAL_USART_TX_PIN
// #endif
// #define SERIAL_USART_TX_PIN GP1

// #ifdef SERIAL_USART_RX_PIN
// #    undef SERIAL_USART_RX_PIN
// #endif
// #define SERIAL_USART_RX_PIN GP1

#undef RGB_DI_PIN
#define RGB_DI_PIN GP0
#define SERIAL_PIO_USE_PIO1
// #define WS2812_PIO_USE_PIO1
