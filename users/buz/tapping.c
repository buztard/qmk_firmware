#include "buz.h"
#include "config.h"

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // qwerty index
        case LSFT_T(KC_F):
        case RSFT_T(KC_J):
        // colemak index
        case LSFT_T(KC_T):
        case RSFT_T(KC_N):
            return 150;

        case LT(_LOWER, KC_ESC):
        case LT(_RAISE, KC_BSPC):
            return 100;

        case LT(_EXTRA, KC_SPC):
        case LT(_VIM, KC_SPC):
            return 250;

        // My pinkies are slow...
        // qwerty pinkies
        case LGUI_T(KC_A):
        case LGUI_T(KC_SCLN):
            // colemak pinkies
        case LGUI_T(KC_O):
            return 300;

        default:
            return TAPPING_TERM;
    }
}
#endif

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // qwerty
        case LSFT_T(KC_F):
        case RSFT_T(KC_J):
        // colemak
        case LSFT_T(KC_T):
        case RSFT_T(KC_N):
            return false;

        // qwerty pinkies
        case LGUI_T(KC_A):
        case LGUI_T(KC_SCLN):
        // colemak pinkies
        case LGUI_T(KC_O):
            return true;

        default:
            return true;
    }
}
#endif

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_LOWER, KC_ESC):
        case LT(_SYMBOL, KC_ESC):
        case LT(_SYMBOL, KC_ENT):
            return true;

        case LT(_RAISE, KC_BSPC):
        case LT(_NUM, KC_BSPC):
        case LT(_VIM, KC_BSPC):
            return true;

        case LT(_NUM, KC_SPACE):
            return false;

        default:
            return false;
    }
}
#endif

#ifdef IGNORE_MOD_TAP_INTERRUPT_PER_KEY
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):
        case LT(_LOWER, KC_ESC):
        case LT(_SYMBOL, KC_ESC):
        case LT(_RAISE, KC_BSPC):
        case LT(_NUM, KC_BSPC):
        case LSFT_T(KC_LPRN):
        case RSFT_T(KC_RPRN):
        case LT(_SYMBOL, KC_ENT):
            return false;

        default:
            return true;
    }
}
#endif

#ifdef TAPPING_FORCE_HOLD_PER_KEY
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_SPC):
        case LT(_NUM, KC_BSPC):
            return false;

        default:
            return true;
    }
}
#endif

#ifdef RETRO_TAPPING_PER_KEY
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_T(KC_S):
        case LCTL_T(KC_D):
        case LSFT_T(KC_F):
            return true;

        case RSFT_T(KC_J):
        case RCTL_T(KC_K):
        case LALT_T(KC_L):
            return true;

        default:
            return false;
    }
}
#endif
