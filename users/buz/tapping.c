#include "buz.h"
#include "config.h"

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
#    ifdef CONSOLE_ENABLE
    uprintf("get_tapping_term ");
#    endif

    switch (keycode) {
        case LSFT_T(KC_A):
#    ifdef CONSOLE_ENABLE
            uprintf("LSFT_T(KC_A)\n");
#    endif
            return 180;

        case RSFT_T(KC_SCLN):
#    ifdef CONSOLE_ENABLE
            uprintf("RSFT_T(KC_SCLN)\n");
#    endif
            return 180;

        case LT(_LOWER, KC_TAB):
#    ifdef CONSOLE_ENABLE
            uprintf("LT(_LOWER, KC_TAB)\n");
#    endif
            return 100;

        case LT(_LOWER, KC_ESC):
#    ifdef CONSOLE_ENABLE
            uprintf("LT(_LOWER, KC_TAB)\n");
#    endif
            return 100;

        case LT(_RAISE, KC_LPRN):
#    ifdef CONSOLE_ENABLE
            uprintf("LT(_RAISE, KC_LPRN)\n");
#    endif
            return 100;

        case LT(_RAISE, KC_BSPC):
#    ifdef CONSOLE_ENABLE
            uprintf("LT(_RAISE, KC_BSPC)\n");
#    endif
            return 100;

        default:
#    ifdef CONSOLE_ENABLE
            uprintf("%d\n", keycode);
#    endif
            return TAPPING_TERM;
    }
}
#endif

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
#    ifdef CONSOLE_ENABLE
    uprintf("get_permissive_hold ");
#    endif

    switch (keycode) {
        case LSFT_T(KC_A):
#    ifdef CONSOLE_ENABLE
            uprintf("LSFT_T(KC_A)\n");
#    endif
            return false;

        case RSFT_T(KC_SCLN):
#    ifdef CONSOLE_ENABLE
            uprintf("RSFT_T(KC_SCLN)\n");
#    endif
            return false;

        default:
#    ifdef CONSOLE_ENABLE
            uprintf("%d\n", keycode);
#    endif
            return true;
    }
}
#endif

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(_LOWER, KC_TAB):
      return true;

    case LT(_LOWER, KC_ESC):
      return true;

    case LT(_RAISE, KC_BSPC):
      return true;

    default:
      return false;
  }
}
#endif

#ifdef IGNORE_MOD_TAP_INTERRUPT_PER_KEY
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
#    ifdef CONSOLE_ENABLE
    uprintf("get_ignore_mod_tap_interrupt ");
#    endif

    switch (keycode) {
        case LCTL_T(KC_ESC):
#    ifdef CONSOLE_ENABLE
            uprintf("LCTL_T(KC_ESC)\n");
#    endif
            return false;

        case LT(_LOWER, KC_TAB):
#    ifdef CONSOLE_ENABLE
            uprintf("LT(_LOWER, KC_TAB)\n");
#    endif
            return false;

        case LT(_LOWER, KC_ESC):
#    ifdef CONSOLE_ENABLE
            uprintf("LT(_LOWER, KC_TAB)\n");
#    endif
            return false;

        case LT(_RAISE, KC_BSPC):
#    ifdef CONSOLE_ENABLE
            uprintf("LT(_RAISE, KC_BSPC)\n");
#    endif
            return false;

        case LT(_LOWER, KC_LPRN):
#    ifdef CONSOLE_ENABLE
            uprintf("LT(_LOWER, KC_LPRN)\n");
#    endif
            return false;

        case LT(_RAISE, KC_RPRN):
#    ifdef CONSOLE_ENABLE
            uprintf("LT(_RAISE, KC_RPRN)\n");
#    endif
            return false;

        case LSFT_T(KC_LPRN):
#    ifdef CONSOLE_ENABLE
            uprintf("LSFT_T(KC_LPRN)\n");
#    endif
            return false;

        case RSFT_T(KC_RPRN):
#    ifdef CONSOLE_ENABLE
            uprintf("RSFT_T(KC_RPRN)\n");
#    endif
            return false;

        default:
#    ifdef CONSOLE_ENABLE
            uprintf("%d\n", keycode);
#    endif
            return true;
    }
}
#endif

#ifdef TAPPING_FORCE_HOLD_PER_KEY
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
#    ifdef CONSOLE_ENABLE
    uprintf("get_tapping_force_hold ");
#    endif
    switch (keycode) {
        case LCTL_T(KC_ESC):
#    ifdef CONSOLE_ENABLE
            uprintf("LCTL_T(KC_ESC)\n");
#    endif
            return true;

        case RCTL_T(KC_QUOT):
#    ifdef CONSOLE_ENABLE
            uprintf("RCTL_T(KC_QUOT)\n");
#    endif
            return true;

        case SFT_T(KC_SPC):
#    ifdef CONSOLE_ENABLE
            uprintf("SFT_T(KC_SPC)\n");
#    endif
            return false;

        case LSFT_T(KC_LPRN):
#    ifdef CONSOLE_ENABLE
            uprintf("LSFT_T(KC_LPRN)\n");
#    endif
            return true;

        case RSFT_T(KC_RPRN):
#    ifdef CONSOLE_ENABLE
            uprintf("RSFT_T(KC_RPRN)\n");
#    endif
            return true;

        default:
            return false;
    }
}
#endif

#ifdef CUSTOM_TAPPING_KEYS
bool process_tap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_LPRN):
            if (record->event.pressed) {
                register_code16(KC_LPRN);
            } else {
                unregister_code16(KC_LPRN);
            }
            return false;

        case RSFT_T(KC_RPRN):
            if (record->event.pressed) {
                register_code16(KC_RPRN);
            } else {
                unregister_code16(KC_RPRN);
            }
            return false;

        case LT(_LOWER, KC_LPRN):
            if (record->event.pressed) {
                register_code16(KC_LPRN);
            } else {
                unregister_code16(KC_LPRN);
            }
            return false;

        case LT(_RAISE, KC_RPRN):
            if (record->event.pressed) {
                register_code16(KC_RPRN);
            } else {
                unregister_code16(KC_RPRN);
            }
            return false;

        default:
            return true;
    }
}
#endif
