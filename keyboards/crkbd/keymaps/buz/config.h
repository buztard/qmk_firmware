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

#define USE_SERIAL_PD2

#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

#define OLED_TIMEOUT 60000
#define OLED_FADE_OUT 7
#define OLED_SCROLL_TIMEOUT 10000

#ifdef OLED_FONT_H
#    undef OLED_FONT_H
#endif
#if defined(FLAVOR_GODSPEED)
#    define OLED_FONT_H "keyboards/crkbd/keymaps/buz/glcdfont_godspeed.c"
#elif defined(FLAVOR_DASHER)
#    define OLED_FONT_H "keyboards/crkbd/keymaps/buz/glcdfont_dasher.c"
#elif defined(FLAVOR_LEVIATHAN)
#    define OLED_FONT_H "keyboards/crkbd/keymaps/buz/glcdfont_leviathan.c"
#elif defined(FLAVOR_TROUBLED_MINDS)
#    define OLED_FONT_H "keyboards/crkbd/keymaps/buz/glcdfont_troubledminds.c"
#elif defined(FLAVOR_SERIKA)
#    define OLED_FONT_H "keyboards/crkbd/keymaps/buz/glcdfont_serika.c"
#elif defined(FLAVOR_MILKSHAKE)
#    define OLED_FONT_H "keyboards/crkbd/keymaps/buz/glcdfont_milkshake.c"
#elif defined(FLAVOR_SUSUWATARI)
#    define OLED_FONT_H "keyboards/crkbd/keymaps/buz/glcdfont_susuwatari.c"
#else
#    define OLED_FONT_H "keyboards/crkbd/keymaps/buz/glcdfont.c"
#endif

// RGB matrix configuration
#ifdef RGB_MATRIX_ENABLE

#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
// #    define RGB_MATRIX_KEYPRESSES
// #    define RGB_MATRIX_FRAMEBUFFER_EFFECTS

#    ifndef FLAVOR_ACAB
// #        undef RGB_MATRIX_FRAMEBUFFER_EFFECTS

#        define DISABLE_RGB_MATRIX_ALPHAS_MODS
#        define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#        define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#        define DISABLE_RGB_MATRIX_BREATHING
#        define DISABLE_RGB_MATRIX_BAND_SAT
#        define DISABLE_RGB_MATRIX_BAND_VAL
#        define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#        define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#        define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#        define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#        define DISABLE_RGB_MATRIX_CYCLE_ALL
#        define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#        define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
#        define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
// #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#        define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#        define DISABLE_RGB_MATRIX_DUAL_BEACON
#        define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
#        define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
#        define DISABLE_RGB_MATRIX_RAINBOW_BEACON
#        define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#        define DISABLE_RGB_MATRIX_RAINDROPS
#        define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#        define DISABLE_RGB_MATRIX_TYPING_HEATMAP
#        define DISABLE_RGB_MATRIX_DIGITAL_RAIN
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#        define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#        define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#        define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#        define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#        define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#        define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#        define DISABLE_RGB_MATRIX_SPLASH
#        define DISABLE_RGB_MATRIX_MULTISPLASH
#        define DISABLE_RGB_MATRIX_SOLID_SPLASH
#        define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#        define DISABLE_RGB_MATRIX_HUE_BREATHING
#        define DISABLE_RGB_MATRIX_HUE_PENDULUM
#        define DISABLE_RGB_MATRIX_HUE_WAVE
#        define DISABLE_RGB_MATRIX_PIXEL_RAIN
#        define DISABLE_RGB_MATRIX_PIXEL_FLOW
#        define DISABLE_RGB_MATRIX_PIXEL_FRACTAL
#    endif

#    define LEADER_PER_KEY_TIMING
#    define LEADER_ON_KEY_PROCESSING
#    ifdef LEADER_TIMEOUT
#        undef LEADER_TIMEOUT
#        define LEADER_TIMEOUT 3000
#    endif

#endif

#ifdef PS2_MOUSE_ENABLE
// clock on pin 3 (d0, int0)
#    define PS2_CLOCK_PORT PORTD
#    define PS2_CLOCK_PIN PIND
#    define PS2_CLOCK_DDR DDRD
#    define PS2_CLOCK_BIT 0
#    define PS2_INT_INIT()                          \
        do {                                        \
            EICRA |= ((1 << ISC01) | (0 << ISC00)); \
        } while (0)
#    define PS2_INT_ON()          \
        do {                      \
            EIMSK |= (1 << INT0); \
        } while (0)
#    define PS2_INT_OFF()          \
        do {                       \
            EIMSK &= ~(1 << INT0); \
        } while (0)
#    define PS2_INT_VECT INT0_vect
// data on pin 2 (d1)
#    define PS2_DATA_PORT PORTD
#    define PS2_DATA_PIN PIND
#    define PS2_DATA_DDR DDRD
#    define PS2_DATA_BIT 1
#    define PS2_MOUSE_ROTATE 270  // compensate for east-facing device orientation
#    define PS2_MOUSE_SCROLL_BTN_MASK (1 << PS2_MOUSE_BTN_MIDDLE)
#    define PS2_MOUSE_SCROLL_BTN_SEND TAPPING_TERM
#    define PS2_MOUSE_SCROLL_DIVISOR_V 3
#    define PS2_MOUSE_SCROLL_DIVISOR_H PS2_MOUSE_SCROLL_DIVISOR_V
#endif

#ifdef AUDIO_ENABLE
#    define B5_AUDIO
#    define NO_MUSIC_MODE
#    define AUDIO_CLICKY
#endif

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE
// #define LAYER_STATE_8BIT
// #define LAYER_STATE_16BIT

#ifdef FLAVOR_ACAB
#    define ENABLE_RGB_MATRIX_ALPHAS_MODS             // Enables RGB_MATRIX_ALPHAS_MODS
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN        // Enables RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT     // Enables RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_BREATHING               // Enables RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BAND_SAT                // Enables RGB_MATRIX_BAND_SAT
#    define ENABLE_RGB_MATRIX_BAND_VAL                // Enables RGB_MATRIX_BAND_VAL
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT       // Enables RGB_MATRIX_BAND_PINWHEEL_SAT
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL       // Enables RGB_MATRIX_BAND_PINWHEEL_VAL
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT         // Enables RGB_MATRIX_BAND_SPIRAL_SAT
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL         // Enables RGB_MATRIX_BAND_SPIRAL_VAL
#    define ENABLE_RGB_MATRIX_CYCLE_ALL               // Enables RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT        // Enables RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN           // Enables RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON  // Enables RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN            // Enables RGB_MATRIX_CYCLE_OUT_IN
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL       // Enables RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL          // Enables RGB_MATRIX_CYCLE_PINWHEEL
#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL            // Enables RGB_MATRIX_CYCLE_SPIRAL
#    define ENABLE_RGB_MATRIX_DUAL_BEACON             // Enables RGB_MATRIX_DUAL_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON          // Enables RGB_MATRIX_RAINBOW_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS       // Enables RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_RAINDROPS               // Enables RGB_MATRIX_RAINDROPS
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS     // Enables RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING           // Enables RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_HUE_PENDULUM            // Enables RGB_MATRIX_HUE_PENDULUM
#    define ENABLE_RGB_MATRIX_HUE_WAVE                // Enables RGB_MATRIX_HUE_WAVE
#    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL           // Enables RGB_MATRIX_PIXEL_FRACTAL
#    define ENABLE_RGB_MATRIX_PIXEL_RAIN              // Enables RGB_MATRIX_PIXEL_RAIN

#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP  // Enables RGB_MATRIX_TYPING_HEATMAP
#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN    // Enables RGB_MATRIX_DIGITAL_RAIN

#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE  // Enables RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE         // Enables RGB_MATRIX_SOLID_REACTIVE
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE        // Enables RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Enables RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS       // Enables RGB_MATRIX_SOLID_REACTIVE_CROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS  // Enables RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS       // Enables RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS  // Enables RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #    define ENABLE_RGB_MATRIX_SPLASH                     // Enables RGB_MATRIX_SPLASH
#    define ENABLE_RGB_MATRIX_MULTISPLASH  // Enables RGB_MATRIX_MULTISPLASH
// #    define ENABLE_RGB_MATRIX_SOLID_SPLASH               // Enables RGB_MATRIX_SOLID_SPLASH
#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH  // Enables RGB_MATRIX_SOLID_MULTISPLASH
#else
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL  // Enables RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #    define ENABLE_RGB_MATRIX_TYPING_HEATMAP     // Enables RGB_MATRIX_TYPING_HEATMAP
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE     // Enables RGB_MATRIX_SOLID_REACTIVE
#endif
