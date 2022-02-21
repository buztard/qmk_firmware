#include "buz.h"
#include "caps_word.h"

static bool caps_word_active = false;

bool process_caps_word(uint16_t keycode, keyrecord_t *record) {
    static bool is_shifted = false;

    // we don't care about release events
    if (!record->event.pressed) {
        return true;
    }

    // activate caps_word mode mode
    if (keycode == CAPS_WORD) {
        caps_word_active = true;
        return false;
    }

    if (!caps_word_active) {
        return true;
    }

    // get the original keycode for mod/layer taps
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            // Earlier return if this has not been considered tapped yet
            if (record->tap.count == 0) return true;
            keycode = keycode & 0xFF;
            break;
        default:
            break;
    }

    switch (keycode) {
        case UNSLSH:
            if (userspace_config.unslsh) {
                if (!is_shifted) {
                    register_code(KC_LSFT);
                    is_shifted = true;
                }
                if (record->event.pressed) {
                    tap_code16(KC_MINUS);
                }
            } else {
                if (is_shifted) {
                    unregister_code(KC_LSFT);
                    is_shifted = false;
                }
                tap_code16(KC_SLASH);
                caps_word_active = false;
            }
            return false;

        case KC_A ... KC_Z:
            if (!is_shifted) {
                register_code(KC_LSFT);
                is_shifted = true;
            }
            return true;

        case KC_1 ... KC_9:
        case KC_BSPC:
        case KC_UNDS:
            // those don't need to be shifted
            if (is_shifted) {
                unregister_code(KC_LSFT);
                is_shifted = false;
            }
            return true;

        default:
            // deactivate caps_word mode
            if (is_shifted) {
                unregister_code(KC_LSFT);
                is_shifted = false;
            }
            caps_word_active = false;
            return true;
    }
}

bool caps_word(void) { return caps_word_active; }
