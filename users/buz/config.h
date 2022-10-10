#pragma once

#define LAYER_STATE_16BIT

// tapping configuration
// more granular config in tapping.c
#ifndef TAPPING_TERM
#    define TAPPING_TERM 200
#endif
#define TAPPING_TERM_PER_KEY

// permissive hold
#define PERMISSIVE_HOLD_PER_KEY

// force hold
#define TAPPING_FORCE_HOLD_PER_KEY

// retro tapping
// #define RETRO_TAPPING_PER_KEY

// ignore mod tap interrupt
// #define IGNORE_MOD_TAP_INTERRUPT
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define BILATERAL_COMBINATIONS 500

// combo configuration
#define COMBO_TERM 30

#define UNICODE_TYPE_DELAY 70

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
#if defined(RGB_MATRIX_ENABLE)
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

#if defined(SPLIT_KEYBOARD)
#    define SPLIT_LAYER_STATE_ENABLE
// #    define SPLIT_LED_STATE_ENABLE
// #    define SPLIT_MODS_ENABLE
#    ifdef OLED_ENABLE
#        define SPLIT_OLED_ENABLE
#    endif
#    ifdef CUSTOM_SPLIT_TRANSPORT_SYNC
#        define SPLIT_TRANSACTION_IDS_USER RPC_ID_USER_CONFIG_SYNC
#    endif
#endif

// Unicode mode
#define UNICODE_SELECTED_MODES UC_LNX

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
