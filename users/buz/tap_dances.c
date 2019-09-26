#include "quantum.h"
#include "tap_dances.h"
#include "buz.h"

td_state_t tap_lalt = TAP_END;
td_state_t tap_ralt = TAP_END;

int cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return SINGLE_TAP;
        } else {
            return SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        if (state->interrupted) {
            return DOUBLE_SINGLE_TAP;
        } else if (state->pressed) {
            return DOUBLE_HOLD;
        } else {
            return DOUBLE_TAP;
        }
    } else if (state->count == 3) {
        if (state->interrupted || !state->pressed) {
            return TRIPLE_TAP;
        } else {
            return TRIPLE_HOLD;
        }
    } else {
        return TAP_END;
    }
}

void td_lalt_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_lalt = cur_dance(state);
    switch (tap_lalt) {
        case SINGLE_TAP:
            register_code(KC_DEL);
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LALT));
            break;
        case DOUBLE_TAP:
            if (biton32(layer_state) == _MOUSE) {
                layer_off(_MOUSE);
            } else {
                layer_on(_MOUSE);
            }
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_DEL);
            register_code(KC_DEL);
            break;
        default:
            break;
    }
}

void td_lalt_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_lalt) {
        case SINGLE_TAP:
            unregister_code(KC_DEL);
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code(KC_DEL);
            break;
        default:
            break;
    }
    tap_lalt = TAP_END;
}

void td_ralt_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_ralt = cur_dance(state);
    switch (tap_ralt) {
        case SINGLE_TAP:
            register_code(KC_BSPC);
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RALT));
            break;
        case DOUBLE_TAP:
            if (biton32(layer_state) == _VIM) {
                layer_off(_VIM);
            } else {
                layer_on(_VIM);
            }
            break;
        case DOUBLE_HOLD:
            register_mods(MOD_BIT(KC_LALT));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_BSPC);
            register_code(KC_BSPC);
            break;
        case TRIPLE_TAP:
            if (biton32(layer_state) == _MOUSE) {
                layer_off(_MOUSE);
            } else {
                layer_on(_MOUSE);
            }
            break;
        default:
            break;
    }
}

void td_ralt_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_ralt) {
        case SINGLE_TAP:
            unregister_code(KC_BSPC);
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RALT));
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code(KC_BSPC);
            break;
        default:
            break;
    }
    tap_ralt = TAP_END;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LALT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_lalt_finished, td_lalt_reset, 300),
    [TD_RALT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_ralt_finished, td_ralt_reset, 300),
};
