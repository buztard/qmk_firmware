#include QMK_KEYBOARD_H
#ifdef PROTOCOL_LUFA
#    include "lufa.h"
#    include "split_util.h"
#endif
#include "buz.h"
#include "version.h"
#ifdef RAW_ENABLE
#    include "raw_hid.h"
#endif

#ifdef RGB_MATRIX_ENABLE
extern rgb_config_t rgb_matrix_config;
#endif

#ifdef OLED_ENABLE
static uint32_t oled_timer = 0;
#endif

extern userspace_config_t userspace_config;

enum custom_keycodes {
    RGBRST = USER_SAFE_RANGE,
    ADJ,
};

#define KC_LOWER LT(_LOWER, KC_ESC)
#define KC_RAISE LT(_RAISE, KC_BSPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
           KC_TABMS, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC,
            KC_CESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_CQUOT,
               LSPO, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, RSPC,
                    KC_TD_LALT, LT(_LOWER, KC_ESC), KC_GENT,         LT(_SYMBOL, KC_SPC), LT(_RAISE, KC_BSPC), KC_TD_RALT
  ),

  [_COLEMAK] = LAYOUT_wrapper(
    XXXXXXX, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, XXXXXXX,
    XXXXXXX, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, XXXXXXX,
    XXXXXXX, _________________QWERTY_L3_________________, _________________XWERTY_R3_________________, XXXXXXX,
       KC_LEAD, LT(_SYMBOL, KC_ESC), LT(_SYMBOL, KC_ENT), LT(_VIM, KC_SPC), LT(_NUM, KC_BSPC), KC_TD_RALT
  ),

  [_GAME] = LAYOUT_wrapper(
    KC_TABMS,__________________GAME_L1__________________, __________________GAME_R1__________________, KC_BSPC,
    KC_CESC, __________________GAME_L2__________________, __________________GAME_R2__________________, KC_QUOT,
    KC_LSFT, __________________GAME_L3__________________, __________________GAME_R3__________________, KC_RSFT,
                                  LOWER, KC_LGUI, KC_ENT, KC_SPC, QWERTY, LOWER
  ),

  [_LOWER] = LAYOUT_wrapper(
    KC_TILD, _________________LOWER_L1__________________, _________________LOWER_R1__________________, _______,
    _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_PIPE,
    KC_CAPS, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
                               _______, _______, _______, _______, RAISE, _______
  ),

  [_RAISE] = LAYOUT_wrapper(
    KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, KC_DEL,
    _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,
    _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
                               KC_LALT, LOWER, _______, _______, _______, _______
  ),

  [_SYMBOL] = LAYOUT_wrapper(
    _______, _________________SYMBOL_L1_________________, _________________SYMBOL_R1_________________, KC_AT,
    _______, _________________SYMBOL_L2_________________, _________________SYMBOL_R2_________________, REPEAT,
    _______, _________________SYMBOL_L3_________________, _________________SYMBOL_R3_________________, _______,
                             _______, _______, CAPS_WORD, _______, _______, CAPS_WORD
  ),

  [_VIM] = LAYOUT_wrapper(
    _______, __________________VIM_L1___________________, __________________VIM_R1___________________, _______,
    _______, __________________VIM_L2___________________, __________________VIM_R2___________________, _______,
    _______, __________________VIM_L3___________________, __________________VIM_R3___________________, _______,
                             _______, _______, CAPS_WORD, _______, _______, _______
  ),

  [_MOUSE] = LAYOUT_wrapper(
    _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, _______,
    _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______,
    _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________, _______,
                              _______, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2
  ),

  [_NUM] = LAYOUT_wrapper(
    RGB_MOD, _________________NUMPAD_L1_________________, _________________NUMPAD_R1_________________, _______,
    ADJ,     _________________NUMPAD_L2_________________, _________________NUMPAD_R2_________________, _______,
    QWERTY,  _________________NUMPAD_L3_________________, _________________NUMPAD_R3_________________, _______,
                               ADJUST, MO(_ADJUST), _______, _______, KC_0,    KC_DOT
  ),

  [_MEDIA] = LAYOUT_wrapper(
    _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______,
    _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________, _______,
    _______, _________________MEDIA_L3__________________, _________________MEDIA_R3__________________, _______,
                              _______, _______, _______, _______, _______, _______
  ),

  [_TMUX] = LAYOUT_wrapper(
    _______, __________________TMUX_L1__________________, __________________TMUX_R1__________________, _______,
    _______, __________________TMUX_L2__________________, __________________TMUX_R2__________________, _______,
    _______, __________________TMUX_L3__________________, __________________TMUX_R3__________________, _______,
                             _______, _______, CAPS_WORD, _______, _______, _______
  ),

  [_FUNC] = LAYOUT_wrapper(
    _______, __________________FUNC_L1__________________, __________________FUNC_R1__________________, _______,
    _______, __________________FUNC_L2__________________, __________________FUNC_R2__________________, _______,
    _______, __________________FUNC_L3__________________, __________________FUNC_R3__________________, _______,
                               _______, _______, _______, _______, _______,  _______
  ),

  [_ADJUST] = LAYOUT_wrapper(
    RESET,   _________________ADJUST_L1_________________, _________________ADJUST_R1_________________, RESET,
    _______, _________________ADJUST_L2_________________, _________________ADJUST_R2_________________, RGBRST,
    KC_CAPS, _________________ADJUST_L3_________________, _________________ADJUST_R3_________________, _______,
                               _______, _______, _______, _______, _______, _______
  ),

};
// clang-format on

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef CONSOLE_ENABLE
        // RGB rgb = hsv_to_rgb(rgb_matrix_config.hsv);
        // uprintf("R:%u G:%u, B:%u - H:%u S:%u V:%u\n", rgb.r, rgb.g, rgb.b, rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v);
#endif
#ifdef OLED_ENABLE
        oled_timer = timer_read32();
#endif
#ifndef SPLIT_KEYBOARD
        if ((keycode == RESET || keycode == MAKE) && !is_keyboard_master()) {
            return false;
        }
#endif
    }

    switch (keycode) {
        case ADJ:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return true;

        case RGBRST:
#ifdef RGBLIGHT_ENABLE
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
            }
#endif  // RGBLIGHT_ENABLE
            return false;
    }
    return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (isLeftHand) {
        return OLED_ROTATION_0;
        // return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
    }
}

static void render_logo(void) {
    // clang-format off
    static const char PROGMEM logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
    // clang-format on
    oled_write_P(logo, false);
}

static void render_status(void) {
    oled_render_layer();
    oled_render_mods();

#    if defined(RGBLIGHT_ENABLE) && defined(OLED_EXTRAS)
    oled_render_rgblight_effect_name();
#    endif  // RGBLIGHT_ENABLE
#    if defined(RGB_MATRIX_ENABLE) && defined(OLED_EXTRAS)
    oled_render_rgb_matrix_effect_name();
#    endif  // RGB_MATRIX_ENABLE
}

bool oled_task_user(void) {
    if (!userspace_config.oled_enabled) {
        oled_off();
        return false;
    }
#    if 0
    if (timer_elapsed32(oled_timer) > 60000) {
        oled_off();
        return false;
    } else if (timer_elapsed32(oled_timer) > 10000) {
        render_logo();
        oled_scroll_left();
        return false;
    } else {
        oled_scroll_off();
    }
    oled_on();
#    endif

    if (is_keyboard_master()) {
        render_status();
    } else {
        render_logo();
    }
    return false;
}
#endif  // OLED_ENABLE

#ifdef RGB_MATRIX_ENABLE
void suspend_power_down_user(void) { rgb_matrix_set_suspend_state(true); }
void suspend_wakeup_init_user(void) { rgb_matrix_set_suspend_state(false); }

#    ifdef LEADER_ENABLE
extern bool leading;
#    endif

bool rgb_matrix_indicators_keymap(void) {
#    ifdef LEADER_ENABLE
    if (leading) {
        rgb_matrix_layer_helper_rgb(0x0, 0xff, 0x0, LED_FLAG_MODIFIER);
        return false;
    }
#    endif

    switch (get_highest_layer(layer_state)) {
        case _VIM:
            for (int i = 2; i < 6; i++) {
                rgb_matrix_set_color(g_led_config.matrix_co[5][i], RGB_GREEN);
            }
            break;

        case _MOUSE:
            for (int i = 2; i < 6; i++) {
                rgb_matrix_set_color(g_led_config.matrix_co[5][i], RGB_ORANGE);
            }
            break;

        case _NUM:
            for (int i = 2; i < 5; i++) {
                for (int j = 4; j < 7; j++) {
                    rgb_matrix_set_color(g_led_config.matrix_co[j][i], 95, 7, 53);
                }
            }
            break;

        default:
#    ifdef FLAVOR_SUSUWATARI
            rgb_matrix_layer_helper_rgb(0x0, 0x0, 0x0, LED_FLAG_UNDERGLOW);
#    endif
            return true;
    }

    return false;
}
#endif  // RGB_MATRIX_ENABLE

#ifdef RAW_ENABLE
enum hid_commands {
    cmd_get_version       = 0x01,
    cmd_get_default_layer = 0x02,
    cmd_set_default_layer = 0x03,
    cmd_get_layer         = 0x04,
    cmd_rgb_matrix_next   = 0x05,
    cmd_invalid           = 0xFF,
};

void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t *command      = &(data[0]);
    uint8_t *command_data = &(data[1]);

    switch (*command) {
        case cmd_get_version:
            command_data[0] = 0x01;
            break;

        case cmd_get_default_layer:
            switch (get_highest_layer(default_layer_state)) {
                case _QWERTY:
                    command_data[0] = _QWERTY;
                    break;
                case _COLEMAK:
                    command_data[1] = _COLEMAK;
                    break;
                default:
                    break;
            }
            break;

        case cmd_set_default_layer:
            switch (command_data[0]) {
                case _QWERTY:
                    default_layer_set(1U << _QWERTY);
                    break;

                case _COLEMAK:
                    default_layer_set(1U << _COLEMAK);
                    break;

                default:
                    *command = cmd_invalid;
                    break;
            }

        case cmd_rgb_matrix_next:
#    ifdef RGB_MATRIX_ENABLE
            rgb_matrix_step();
#    endif
            break;

        default:
            break;
    }

    raw_hid_send(data, length);
}
#endif
