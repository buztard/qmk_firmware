/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

//#define USE_MATRIX_I2C

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250

#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#ifdef OLED_FONT_H
#undef OLED_FONT_H
#endif
#define OLED_FONT_H "keyboards/crkbd/keymaps/buz/glcdfont.c"

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_ANIMATIONS
/* #undef RGBLIGHT_ANIMATIONS */
/* #define RGBLIGHT_EFFECT_BREATHING */
/* #define RGBLIGHT_EFFECT_RAINBOW_MOOD */
/* #define RGBLIGHT_EFFECT_RAINBOW_SWIRL */
/* #define RGBLIGHT_EFFECT_STATIC_GRADIENT */
#endif

#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_KEYPRESSES

/* #define DISABLE_RGB_MATRIX_ALPHAS_MODS */
/* #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN */
/* #define DISABLE_RGB_MATRIX_BREATHING */
#define DISABLE_RGB_MATRIX_CYCLE_ALL
/* #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT */
/* #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN */
#define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define DISABLE_RGB_MATRIX_DUAL_BEACON
/* #define DISABLE_RGB_MATRIX_RAINBOW_BEACON */
/* #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS */
#define DISABLE_RGB_MATRIX_RAINDROPS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
/* #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE */
/* #define DISABLE_RGB_MATRIX_SOLID_REACTIVE */
/* #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE */
/* #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE */
/* #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS */
/* #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS */
/* #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS */
/* #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS */
/* #define DISABLE_RGB_MATRIX_SPLASH */
/* #define DISABLE_RGB_MATRIX_MULTISPLASH */
/* #define DISABLE_RGB_MATRIX_SOLID_SPLASH */
/* #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH */

#endif
