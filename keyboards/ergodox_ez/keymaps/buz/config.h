#pragma once

#define TAPPING_FORCE_HOLD
#undef IGNORE_MOD_TAP_INTERRUPT

// fix my space cadet rollover
/* #undef DISABLE_SPACE_CADET_ROLLOVER */
#undef IS_COMMAND
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT) | MOD_BIT(KC_RGUI)) \
)
