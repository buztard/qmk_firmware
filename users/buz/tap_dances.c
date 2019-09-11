#include "quantum.h"
#include "tap_dances.h"

int cur_dance (qk_tap_dance_state_t *state) {
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
    } else {
        return TAP_END;
    }
}

static tap_state tap_ralt = {
    .is_press_action = true,
    .state = 0
};

void td_ralt_finished (qk_tap_dance_state_t *state, void *user_data) {
    tap_ralt.state = cur_dance(state);
    switch (tap_ralt.state) {
        case SINGLE_TAP:
            register_code(KC_X);
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RALT));
            break;
        case DOUBLE_TAP:
            register_code(KC_ENT);
            break;
        case DOUBLE_HOLD:
            register_mods(MOD_BIT(KC_LALT));
            break;
        case DOUBLE_SINGLE_TAP:
            register_code(KC_X);
            unregister_code(KC_X);
            register_code(KC_X);
            break;
    }
}

void td_ralt_reset (qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_ralt.state) {
        case SINGLE_TAP:
            unregister_code(KC_X);
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RALT));
            break;
        case DOUBLE_TAP:
            unregister_code(KC_ENT);
            break;
        case DOUBLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code(KC_X);
            break;
    }
    tap_ralt.state = TAP_END;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RALT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_ralt_finished, td_ralt_reset, 100),
};

