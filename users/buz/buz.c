#include "buz.h"
#include "encoder_stuff.h"
#include "keycode.h"

userspace_config_t userspace_config;

__attribute__((weak)) layer_state_t layer_state_set_keymap(uint32_t state) { return state; }

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keymap(keycode, record)) {
        return false;
    }

#if 0
    // special case for vim layer...
    if (IS_LAYER_ON(_VIM)) {
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
#endif

    switch (keycode) {
        case LSPO:
#ifdef CONSOLE_ENABLE
            uprintf("P:%d I:%d T:%d\n", record->event.pressed, record->tap.interrupted, record->tap.count);
#endif
            if (!record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) {
                record->tap.count = 0;
                unregister_mods(MOD_LSFT);
                tap_code16(KC_LPRN);
                return false;
            }
            break;

        case RSPC:
            if (!record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) {
                record->tap.count = 0;
                unregister_mods(MOD_RSFT);
                tap_code16(KC_RPRN);
                return false;
            }
            break;

        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;

        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;

        case GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
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

        case XRAISE:
#ifdef CONSOLE_ENABLE
            uprintf("P:%d I:%d T:%d\n", record->event.pressed, record->tap.interrupted, record->tap.count);
#endif
            return true;

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

        case TMUX_PREFIX:
            if (record->event.pressed) {
                register_mods(MOD_LCTL);
                tap_code(KC_A);
            } else {
                unregister_mods(MOD_LCTL);
            }
            return false;

        case TMUX_WP:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("ap"));
            }
            return false;

        case TMUX_WN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("an"));
            }
            return false;

        case TMUX_PP:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") "O");
            }
            return false;

        case TMUX_PN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") "o");
            }
            return false;

#ifdef OLED_DRIVER_ENABLE
        case OLED:
            if (record->event.pressed) {
                userspace_config.oled_enabled ^= 1;
                eeconfig_update_user(userspace_config.raw);
            }
            return false;
#endif

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
        case RGB_LYR:
            if (record->event.pressed) {
                userspace_config.rgb_layer_change ^= 1;
                eeconfig_update_user(userspace_config.raw);
            }
            return false;
#endif

#ifdef ENCODER_ENABLE
        case ENC_0:
            if (record->event.pressed) {
                encoder_mode_next(0);
            }
            return false;

        case ENC_1:
            if (record->event.pressed) {
                encoder_mode_next(1);
            }
            return false;
#endif

        case MAKE:
            if (record->event.pressed) {
                uint8_t temp_mod = get_mods();
                uint8_t temp_osm = get_oneshot_mods();
                clear_mods();
                clear_oneshot_mods();

                // open new terminal if in neovim, but should not harm my zsh
                // otherwise
                SEND_STRING(SS_LALT(SS_TAP(X_ENTER)));

                SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP);
                if ((temp_mod | temp_osm) & MOD_MASK_SHIFT) {
                    SEND_STRING(":flash");
                }
#ifdef RGB_MATRIX_SPLIT_RIGHT
                SEND_STRING(" RGB_MATRIX_SPLIT_RIGHT=yes");
#endif
#ifdef FLAVOR
                SEND_STRING(" FLAVOR=" FLAVOR);
#endif
                SEND_STRING(SS_TAP(X_ENTER));

                if ((temp_mod | temp_osm) & MOD_MASK_SHIFT) {
                    if (is_keyboard_master()) {
                        reset_keyboard();
                    }
                }
            }
            return false;
    }

    return true;
}

uint32_t layer_state_set_user(uint32_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    // #if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    //     rgb_layer_indicator_user();
    // #endif
    return layer_state_set_keymap(state);
}

void eeconfig_init_user(void) {
    // TODO: init LED state per flavor
    userspace_config.raw              = 0;
    userspace_config.rgb_layer_change = true;
    userspace_config.oled_enabled     = true;
    eeconfig_update_user(userspace_config.raw);
}

void matrix_init_user(void) {
    userspace_config.raw = eeconfig_read_user();
#ifdef ENCODER_ENABLE
    encoder_init_user();
#endif
}
