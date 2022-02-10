#include "buz.h"
#include "repeat.h"

static uint16_t last_keycode  = KC_NO;
static uint8_t  last_modifier = 0;

static uint8_t mod_state;
static uint8_t oneshot_mod_state;

bool process_repeat(uint16_t keycode, keyrecord_t *record) {
    // fun
    if (keycode == REPEAT) {
        if (record->event.pressed) {
            register_code16(last_keycode);
        } else {
            unregister_code16(last_keycode);
        }
        return false;
    } else {
        // we're not interested in these
        switch (keycode) {
            case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
            case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
            case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
            case QK_TO ... QK_TO_MAX:
            case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
                return true;
        }

        last_modifier = oneshot_mod_state > mod_state ? oneshot_mod_state : mod_state;
        switch (keycode) {
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                if (record->event.pressed) {
                    last_keycode = keycode & 0xFF;
                }
                break;
            default:
                if (record->event.pressed) {
                    last_keycode = keycode;
                }
                break;
        }
        return true;
    }
}

void process_repeat_post(void) {
    mod_state         = get_mods();
    oneshot_mod_state = get_oneshot_mods();
}
