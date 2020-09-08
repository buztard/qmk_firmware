#include "action.h"
#include "keycode.h"
#include "process_tap_dance.h"
#include "quantum.h"
#include "tap_dances.h"
#include "buz.h"

static td_state_t tap_lalt = TAP_END;
static td_state_t tap_ralt = TAP_END;
// static td_state_t tap_f     = TAP_END;
static td_state_t tap_raise = TAP_END;

// clang-format off
#ifdef CONSOLE_ENABLE
static void debug_td(const char *prefix, qk_tap_dance_state_t *state) {
    // state debugging
    uprintf("%s C:%d M:%d:%d IKC:%d I:%d P:%d F:%d\n",
        prefix,
        state->count,
        state->oneshot_mods,
        state->weak_mods,
        state->interrupting_keycode,
        state->interrupted,
        state->pressed,
        state->finished
    );
}
#endif
// clang-format on

static int cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted) {
            return SINGLE_SHORT_TAP;
        } else if (state->pressed) {
            return SINGLE_HOLD;
        } else {
            return SINGLE_TAP;
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
        if (state->interrupted) {
            return TRIPLE_SINGLE_TAP;
        } else if (state->pressed) {
            return TRIPLE_HOLD;
        } else {
            return TRIPLE_TAP;
        }
    } else {
#ifdef CONSOLE_ENABLE
        uprintf("reset");
#endif
        return TAP_END;
    }
}

static void td_lalt_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_lalt = cur_dance(state);
    switch (tap_lalt) {
        case SINGLE_TAP:
#ifdef LEADER_ENABLE
            qk_leader_start();
#else
            register_mods(MOD_BIT(KC_LALT));
#endif
            break;
        case SINGLE_SHORT_TAP:
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LALT));
            break;
        case DOUBLE_TAP:
            if (IS_LAYER_ON(_MOUSE)) {
                layer_off(_MOUSE);
            } else {
                layer_on(_MOUSE);
            }
            break;
        case DOUBLE_HOLD:
            layer_on(_MOUSE);
        default:
            break;
    }
}

static void td_lalt_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_lalt) {
        case SINGLE_TAP:
#ifndef LEADER_ENABLE
            unregister_mods(MOD_BIT(KC_LALT));
#endif
            break;
        case SINGLE_SHORT_TAP:
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT));
            break;
        case DOUBLE_HOLD:
            layer_off(_MOUSE);
            break;
        default:
            break;
    }
    tap_lalt = TAP_END;
}

static void td_ralt_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_ralt = cur_dance(state);
    switch (tap_ralt) {
        case SINGLE_SHORT_TAP:
        case SINGLE_TAP:
            set_oneshot_mods(MOD_BIT(KC_RALT));
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RALT));
            break;
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP:
            if (IS_LAYER_ON(_VIM)) {
                layer_off(_VIM);
            } else {
                layer_on(_VIM);
            }
            break;
        case DOUBLE_HOLD:
            layer_on(_VIM);
            break;
        default:
            break;
    }
}

static void td_ralt_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_ralt) {
        case SINGLE_TAP:
        case SINGLE_SHORT_TAP:
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RALT));
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_SINGLE_TAP:
        case DOUBLE_HOLD:
            layer_off(_VIM);
            break;
        default:
            break;
    }
    tap_ralt = TAP_END;
}

#if 0
static void td_f_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_f = cur_dance(state);

    switch (tap_f) {
        case SINGLE_SHORT_TAP:
        case SINGLE_TAP:
            register_code(KC_F);
            break;
        case SINGLE_HOLD:
            layer_on(_VIM);
            break;
        case DOUBLE_SINGLE_TAP:
        case DOUBLE_TAP:
            register_code(KC_F);
            unregister_code(KC_F);
            register_code(KC_F);
            break;
        case DOUBLE_HOLD:
            layer_on(_MOUSE);
            break;
        default:
            break;
    }
}

static void td_f_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_f) {
        case SINGLE_SHORT_TAP:
        case SINGLE_TAP:
        case DOUBLE_SINGLE_TAP:
        case DOUBLE_TAP:
            unregister_code(KC_F);
            break;
        case SINGLE_HOLD:
            layer_off(_VIM);
            break;
        case DOUBLE_HOLD:
            layer_off(_MOUSE);
            break;
        default:
            break;
    }
}
#endif

static void td_raise_each(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
#ifdef CONSOLE_ENABLE
        uprintf("manual reset\n");
#endif
        reset_tap_dance(state);
    }
}

static void td_raise_finished(qk_tap_dance_state_t *state, void *user_data) {
#ifdef CONSOLE_ENABLE
    debug_td("raise finished", state);
#endif
    tap_raise = cur_dance(state);
    switch (tap_raise) {
        case SINGLE_SHORT_TAP:
        case SINGLE_HOLD:
            layer_on(_RAISE);
            break;

        case SINGLE_TAP:
            register_code(KC_BSPC);
            break;

        case DOUBLE_TAP:
            if (IS_LAYER_ON(_VIM)) {
                layer_off(_VIM);
            } else {
                layer_on(_VIM);
            }
        case DOUBLE_SINGLE_TAP:
        case DOUBLE_HOLD:
            layer_on(_VIM);
            break;
        default:
            break;
    }
}

static void td_raise_reset(qk_tap_dance_state_t *state, void *user_data) {
#ifdef CONSOLE_ENABLE
    debug_td("raise reset   ", state);
#endif

    switch (tap_raise) {
        case SINGLE_TAP:
            unregister_code(KC_BSPC);
            break;

        case SINGLE_SHORT_TAP:
        case SINGLE_HOLD:
            if (IS_LAYER_ON(_RAISE)) {
                layer_off(_RAISE);
            }
            break;

        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP:
        case DOUBLE_HOLD:
            if (IS_LAYER_ON(_VIM)) {
                layer_off(_VIM);
            }
            break;

        default:
            break;
    }
    tap_raise = TAP_END;
}

#if 0
static void td_semicolon_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_f = cur_dance(state);

    switch (tap_f) {
        case SINGLE_SHORT_TAP:
        case SINGLE_TAP:
            register_code(KC_SCLN);
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RCTL));
            break;
        default:
            break;
    }
}

static void td_semicolon_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_f) {
        case SINGLE_SHORT_TAP:
        case SINGLE_TAP:
            unregister_code(KC_SCLN);
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RCTL));
            break;
        default:
            break;
    }
}

static void td_o_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_f = cur_dance(state);

    switch (tap_f) {
        case SINGLE_SHORT_TAP:
        case SINGLE_TAP:
            register_code(KC_O);
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RCTL));
            break;
        default:
            break;
    }
}

static void td_o_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_f) {
        case SINGLE_SHORT_TAP:
        case SINGLE_TAP:
            unregister_code(KC_O);
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RCTL));
            break;
        default:
            break;
    }
}

static void td_gui_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_f = cur_dance(state);

    switch (tap_f) {
        case SINGLE_SHORT_TAP:
        case SINGLE_TAP:
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LGUI));
            break;
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP:
        case DOUBLE_HOLD:
            register_mods(MOD_BIT(KC_LALT));
            break;
        default:
            break;
    }
}

static void td_gui_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_f) {
        case SINGLE_TAP:
        case SINGLE_SHORT_TAP:
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LGUI));
            break;
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP:
        case DOUBLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT));
            break;
        default:
            break;
    }
}

static void td_space_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_f = cur_dance(state);

    switch (tap_f) {
        case SINGLE_SHORT_TAP:
        case SINGLE_TAP:
            register_code(KC_SPC);
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LGUI));
            break;
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP:
        case DOUBLE_HOLD:
            tap_code(KC_SPC);
            register_code(KC_SPC);
            break;
        default:
            break;
    }
}

static void td_space_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_f) {
        case SINGLE_TAP:
        case SINGLE_SHORT_TAP:
            unregister_code(KC_SPC);
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LGUI));
            break;
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP:
        case DOUBLE_HOLD:
            unregister_code(KC_SPC);
            break;
        default:
            break;
    }
}
#endif

// clang-format off
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LALT]  = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_lalt_finished, td_lalt_reset, 300),
    [TD_RALT]  = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_ralt_finished, td_ralt_reset, 300),
    [TD_RAISE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(td_raise_each, td_raise_finished, td_raise_reset, 200),
    // [TD_F]     = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_f_finished, td_f_reset, 175),
    // [TD_SCLN]  = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_semicolon_finished, td_semicolon_reset, 100),
    // [TD_O]     = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_o_finished, td_o_reset, 100),
    // [TD_GUI]   = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_gui_finished, td_gui_reset, 200),
    // [TD_SPC]   = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_space_finished, td_space_reset, 200),
};
// clang-format on
