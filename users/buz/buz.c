#include "buz.h"
#include "encoder_stuff.h"
#include "caps_word.h"
#include "keycode.h"
#include "quantum.h"

#ifdef CUSTOM_SPLIT_TRANSPORT_SYNC
#    include "transactions.h"
#    include <string.h>
#endif

#ifdef LAYER_LOCK_ENABLE
#    include "layer_lock.h"
#endif

#ifdef REPEAT_ENABLE
#    include "repeat.h"
#endif

userspace_config_t userspace_config;

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
#ifdef ACHORDION_ENABLE
    if (!process_achordion(keycode, record)) {
        return false;
    }
#endif

    uint8_t temp_mod = get_mods();
    uint8_t temp_osm = get_oneshot_mods();

#ifdef REPEAT_ENABLE
    if (!process_repeat(keycode, record)) {
        return false;
    }
    process_repeat_post();
#endif

    if (!process_caps_word(keycode, record)) {
        return false;
    }

#ifdef LAYER_LOCK_ENABLE
    if (!process_layer_lock(keycode, record, LAYER_LOCK)) {
        return false;
    }
#endif

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
        case LT(_NUM, KC_BSPC): {
            static bool delkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (temp_mod & MOD_LSFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_LSFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(temp_mod);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
        }

#if 0
        case LSPO:
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
#endif

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

#if 0
        case UNSLSH:
            if (!record->event.pressed) {
                return false;
            }
            if (userspace_config.unslsh) {
                clear_mods();
                clear_oneshot_mods();
                if ((temp_mod | temp_osm) & MOD_MASK_SHIFT) {
                    tap_code16(KC_SLASH);
                } else {
                    tap_code16(KC_UNDERSCORE);
                }
                set_mods(temp_mod);
            } else {
                tap_code16(KC_SLASH);
            }
            return false;

        case UNSLSTOG:
            if (record->event.pressed) {
                userspace_config.unslsh ^= 1;
                eeconfig_update_user(userspace_config.raw);
            }
            return false;
#endif

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

        case TMUX_PL:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("al"));
            }
            return false;

        case TMUX_PR:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("al"));
            }
            return false;

        case TMUX_PU:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("ak"));
            }
            return false;

        case TMUX_PD:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("aj"));
            }
            return false;

            //         case SELF:
            //             if (record->event.pressed) {
            //                 SEND_STRING("self");
            //             }
            //             return false;

        case IFERR:
            if (record->event.pressed) {
                SEND_STRING("if err != nil {" SS_TAP(X_ENTER));
                // SEND_STRING("if err != nil {" SS_TAP(X_ENTER) "return nil, err" SS_TAP(X_ENTER) "}" SS_TAP(X_ENTER));
            }
            return false;

        case IFERE:
            if (record->event.pressed) {
                SEND_STRING("if err != nil {" SS_TAP(X_ENTER) "return err" SS_TAP(X_ENTER) "}" SS_TAP(X_ENTER));
            }
            return false;

        case IFERNE:
            if (record->event.pressed) {
                SEND_STRING("if err != nil {" SS_TAP(X_ENTER) "return nil, err" SS_TAP(X_ENTER) "}" SS_TAP(X_ENTER));
            }
            return false;

#ifdef OLED_ENABLE
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

#ifdef UNICODE_ENABLE
        case TABLEFLIP:
            if (record->event.pressed) {
                send_unicode_string("(╯°□°)╯︵┻━┻");
            }
            return false;

        case FINGER:
            if (record->event.pressed) {
                send_unicode_string("╭∩╮(O_O)╭∩╮");
            }
            return false;

        case SHRUG:
            if (record->event.pressed) {
                send_unicode_string("¯\\(ツ)/¯");
            }
            return false;

        case MUSCLE_ROCKET:
            if (record->event.pressed) {
                send_unicode_string("💪🚀");
            }
            return false;
#endif

        case MAKE:
            if (record->event.pressed) {
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

layer_state_t layer_state_set_user(layer_state_t state) {
    // state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
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

#if defined(SPLIT_KEYBOARD) && defined(SPLIT_TRANSACTION_IDS_USER)
uint32_t transport_userspace_config = 0;

void user_config_sync(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer, uint8_t target2initiator_buffer_size, void* target2initiator_buffer) {
    if (initiator2target_buffer_size == sizeof(transport_userspace_config)) {
        memcpy(&transport_userspace_config, initiator2target_buffer, initiator2target_buffer_size);
    }
}

void user_transport_update(void) {
    if (is_keyboard_master()) {
        transport_userspace_config = userspace_config.raw;
    } else {
        userspace_config.raw = transport_userspace_config;
    }
}

void user_transport_sync(void) {
    if (is_keyboard_master()) {
        static uint32_t last_config = 0;
        bool            needs_sync  = false;

        if (memcmp(&transport_userspace_config, &last_config, sizeof(transport_userspace_config))) {
            needs_sync = true;
            memcpy(&last_config, &transport_userspace_config, sizeof(transport_userspace_config));
        }
        if (needs_sync) {
            if (transaction_rpc_send(RPC_ID_USER_CONFIG_SYNC, sizeof(transport_userspace_config), &transport_userspace_config)) {
                needs_sync = false;
            }
        }
    }
}

void housekeeping_task_user(void) {
    user_transport_update();
    user_transport_sync();
}
#endif

__attribute__((weak)) void keyboard_post_init_keymap(void) {}
void                       keyboard_post_init_user(void) {
#if defined(SPLIT_KEYBOARD) && defined(SPLIT_TRANSACTION_IDS_USER)
    transaction_register_rpc(RPC_ID_USER_CONFIG_SYNC, user_config_sync);
#endif
    keyboard_post_init_keymap();
}

#ifdef CAPS_WORD_ENABLE
// this is similar to the default one, but doesn't shift minus because it's not
// necessary on my keyboard layout.
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}
#endif

#ifdef ACHORDION_ENABLE
void matrix_scan_user(void) {
    achordion_task();

    bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t * tap_hold_record, uint16_t other_keycode, keyrecord_t * other_record) {
        // switch (tap_hold_keycode) {
        //     case LT(_SYMBOL, KC_ENT):
        //     case LT(_SYMBOL, KC_SPC):
        //     case LT(_NUM, KC_BSPC):
        //     case LT(_NUM, KC_ESC):
        //         return true;
        // }
        if (tap_hold_record->event.key.row % (MATRIX_ROWS / 2) >= 3) {
            return true;
        }
        if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 3) {
            return true;
        }
        return achordion_opposite_hands(tap_hold_record, other_record);
    }
#endif

#ifdef KEY_OVERRIDE_ENABLE
    const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(_NUM, KC_BSPC), KC_DEL);
    const key_override_t scln_key_override   = ko_make_basic(MOD_MASK_SHIFT, LGUI_T(KC_SCLN), KC_QUOT);
    const key_override_t slash_key_override  = ko_make_basic(MOD_MASK_SHIFT, LT(_VIM, KC_SLASH), KC_DQT);

    // This globally defines all key overrides to be used
    const key_override_t** key_overrides = (const key_override_t*[]){
        &delete_key_override, &scln_key_override, &slash_key_override,
        NULL // Null terminate the array of overrides!
    };
#endif
