#include "buz.h"

__attribute__((weak)) void layer_state_set_rgb(uint32_t state) {}

__attribute__((weak)) uint32_t layer_state_set_keymap(uint32_t state) { return state; }

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keymap(keycode, record)) {
        return false;
    }

    // special case for vim layer...
    if (biton(layer_state) == _VIM) {
        static uint16_t last_code = KC_NO;

        bool left_shift  = (keyboard_report->mods & MOD_BIT(KC_LSHIFT));
        bool right_shift = (keyboard_report->mods & MOD_BIT(KC_RSHIFT));

        switch (keycode) {
            case KC_G:
                if (record->event.pressed) {
                    if (left_shift || right_shift) {
                        if (left_shift) unregister_code(KC_LSHIFT);
                        if (right_shift) unregister_code(KC_RSHIFT);
                        register_code(KC_END);
                        unregister_code(KC_END);
                        last_code = KC_NO;
                    } else if (last_code == KC_G) {
                        register_code(KC_HOME);
                        unregister_code(KC_HOME);
                        last_code = KC_NO;
                    } else {
                        last_code = keycode;
                    }
                }
                return false;

            default:
                last_code = KC_NO;
                break;
        }
    }

    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;

        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;

        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;

        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;

        case MOUSE:
            if (record->event.pressed) {
                layer_on(_MOUSE);
            } else {
                layer_off(_MOUSE);
            }
            return false;

        case VIM:
            if (record->event.pressed) {
                layer_on(_VIM);
            } else {
                layer_off(_VIM);
            }
            return false;

        case NUM:
            if (record->event.pressed) {
                layer_on(_NUM);
            } else {
                layer_off(_NUM);
            }
            return false;
    }

    return true;
}

uint32_t layer_state_set_user(uint32_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    layer_state_set_rgb(state);
    return layer_state_set_keymap(state);
}

#ifdef LEADER_ENABLE
LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_S) { SEND_STRING(SS_LCTRL("a") "s" SS_LCTRL("s")); }
    }
}
#endif
