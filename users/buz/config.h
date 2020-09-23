#pragma once

// tapping configuration
// more granular config in tapping.c
#ifndef TAPPING_TERM
#    define TAPPING_TERM 200
#endif
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
#define TAPPING_FORCE_HOLD_PER_KEY
// #define IGNORE_MOD_TAP_INTERRUPT
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
#define IGNORE_LAYER_TAP_INTERRUPT
#define CUSTOM_TAPPING_KEYS

// combo configuration
#define COMBO_COUNT 1
#define COMBO_TERM 50

// leader key
#define LEADER_PER_KEY_TIMING
// #ifdef LEADER_TIMEOUT
// #    undef LEADER_TIMEOUT
// #endif
// #define LEADER_TIMEOUT 500
// #ifndef LEADER_ENABLE
// #    define KC_LEAD KC_TRANSPARENT
// #endif

// RGB matrix config
#ifdef RGB_MATRIX_ENABLE
// disable these modes as there are multi-keypress versions as well
#    ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#        define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    endif

#    ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#        define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    endif

#    ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#        define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    endif

#    ifdef DISABLE_RGB_MATRIX_SPLASH
#        define DISABLE_RGB_MATRIX_SPLASH
#    endif

#    ifdef DISABLE_RGB_MATRIX_SOLID_SPLASH
#        define DISABLE_RGB_MATRIX_SOLID_SPLASH
#    endif
#endif
