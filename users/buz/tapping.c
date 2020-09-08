#include "buz.h"
#include "config.h"

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
#    ifdef CONSOLE_ENABLE
    // uprintf("get_tapping_term %d %d\n", timer_read32(), keycode);
#    endif

    switch (keycode) {
        case LSFT_T(KC_A):
            return 180;

        case RSFT_T(KC_SCLN):
            return 180;

        case LCTL_T(KC_S):
            return 200;

        case RCTL_T(KC_L):
            return 200;

        case LT(_LOWER, KC_TAB):
            return 150;

        case LT(_RAISE, KC_BSPC):
            return 150;

        case SFT_T(KC_SPC):
            return 200;

        case LT(_EXTRA, KC_SPC):
            return TAPPING_TERM;

        default:
            return TAPPING_TERM;
    }
}
#endif

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
#    ifdef CONSOLE_ENABLE
    uprintf("get_permissive_hold %d\n", keycode);
#    endif
    switch (keycode) {
        case LSFT_T(KC_A):
#    ifdef CONSOLE_ENABLE
            uprintf("hold shift\n");
#    endif
            return false;

        case RSFT_T(KC_SCLN):
#    ifdef CONSOLE_ENABLE
            uprintf("dont hold\n");
#    endif
            return false;

        default:
            return true;
    }
}
#endif

#ifdef IGNORE_MOD_TAP_INTERRUPT_PER_KEY
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
#    ifdef CONSOLE_ENABLE
    uprintf("get_ignore_mod_tap_interrupt %d\n", keycode);
#    endif

    switch (keycode) {
        case LSFT_T(KC_A):
            return true;

        case RSFT_T(KC_SCLN):
            return true;

        case LCTL_T(KC_S):
            return true;

        case RCTL_T(KC_L):
            return true;

        case LCTL_T(KC_ESC):
            return false;

        case RCTL_T(KC_QUOT):
            return true;

        case SFT_T(KC_SPC):
            return true;

        case LCTL_T(KC_Z):
            return true;

        case RCTL_T(KC_SLASH):
            return true;

        // are layer taps affected as well?
        case LT(_VIM, KC_Z):
            return false;

        case LT(_NUM, KC_X):
            return true;

        case LT(_RAISE, KC_BSPC):
#    ifdef CONSOLE_ENABLE
            uprintf("raise/bspc\n");
#    endif
            return false;

        default:
            return false;
    }
}
#endif

#ifdef TAPPING_FORCE_HOLD_PER_KEY
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):
            return true;

        case RCTL_T(KC_QUOT):
            return true;

        case SFT_T(KC_SPC):
            return false;

        default:
            return false;
    }
}
#endif
