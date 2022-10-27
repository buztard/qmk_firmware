#include QMK_KEYBOARD_H
#ifdef PROTOCOL_LUFA
#    include "lufa.h"
#    include "split_util.h"
#endif
#include "buz.h"
#include "version.h"

#ifdef RGB_MATRIX_ENABLE
extern rgb_config_t rgb_matrix_config;
#endif

#ifdef OLED_DRIVER_ENABLE
static uint32_t oled_timer = 0;
#endif

extern uint8_t is_master;

extern userspace_config_t userspace_config;

enum custom_keycodes {
    RGBRST = USER_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    KC_TABMS,_________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC,
    KC_CESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT,
    KC_LSPO, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_RSPC,
                              KC_TD_LALT, LOWER, KC_GENT, KC_SPC, RAISE, KC_TD_RALT
  ),
  [_COLEMAK] = LAYOUT_wrapper(
    KC_TABMS,_________________COLEMAK_L1________________, _________________COLEMAK_R1________________, KC_BSPC,
    KC_CESC, _________________COLEMAK_L2________________, _________________COLEMAK_R2________________, KC_QUOT,
    KC_LSPO, _________________COLEMAK_L3________________, _________________COLEMAK_R3________________, KC_RSPC,
                              KC_TD_LALT, LOWER, KC_GENT, KC_SPC, RAISE, KC_TD_RALT
  ),
  [_LOWER] = LAYOUT_wrapper(
    KC_TILD, _________________LOWER_L1__________________, _________________LOWER_R1__________________, _______,
    _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_PIPE,
    KC_CAPS, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
                               _______, _______, _______, _______, _______, _______
  ),
  [_RAISE] = LAYOUT_wrapper(
    KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, KC_DEL,
    _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,
    _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
                               _______, _______, _______, _______, _______, _______
  ),
  [_ADJUST] = LAYOUT_wrapper(
    RESET,   _________________ADJUST_L1_________________, _________________ADJUST_R1_________________, RESET,
    _______, _________________ADJUST_L2_________________, _________________ADJUST_R2_________________, RGBRST,
    KC_CAPS, _________________ADJUST_L3_________________, _________________ADJUST_R3_________________, _______,
                               _______, _______, _______, _______, _______, _______
  ),
  [_VIM] = LAYOUT_wrapper(
    _______, __________________VIM_L1___________________, __________________VIM_R1___________________, _______,
    _______, __________________VIM_L2___________________, __________________VIM_R2___________________, _______,
    _______, __________________VIM_L3___________________, __________________VIM_R3___________________, _______,
                               _______, _______, _______, _______, _______, _______
  ),
  [_MOUSE] = LAYOUT_wrapper(
    _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, _______,
    _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______,
    _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________, _______,
                              _______, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2
  ),
  [_NUM] = LAYOUT_wrapper(
    _______, ___________________BLANK___________________, _________________NUMPAD_R1_________________, _______,
    _______, ___________________BLANK___________________, _________________NUMPAD_R2_________________, _______,
    _______, ___________________BLANK___________________, _________________NUMPAD_R3_________________, _______,
                               _______, _______, _______, _______, KC_0,    _______
  ),
};
// clang-format on

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        oled_timer = timer_read32();
#endif
#ifndef SPLIT_KEYBOARD
        if ((keycode == RESET || keycode == MAKE) && !is_master) {
            return false;
        }
#endif
    }

    switch (keycode) {
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

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_master) return OLED_ROTATION_180;
    return rotation;
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
    // Render to mode icon
    static const char PROGMEM mode_logo[4][4] = {{0x99, 0x9a, 0}, {0xb9, 0xba, 0}};

    oled_write_P(mode_logo[0], false);
    oled_set_cursor(3, 0);
    oled_render_layer();
    oled_write_P(mode_logo[1], false);
    oled_set_cursor(3, 1);
    oled_render_mods();

#    if defined(RGBLIGHT_ENABLE) && defined(OLED_EXTRAS)
    oled_render_rgblight_effect_name();
#    endif  // RGBLIGHT_ENABLE
#    if defined(RGB_MATRIX_ENABLE) && defined(OLED_EXTRAS)
    oled_render_rgb_matrix_effect_name();
#    endif  // RGB_MATRIX_ENABLE
}

void oled_task_user(void) {
    if (!userspace_config.oled_enabled) {
        oled_off();
        return;
    }
    if (timer_elapsed32(oled_timer) > 60000) {
        oled_off();
        return;
    } else if (timer_elapsed32(oled_timer) > 10000) {
        oled_scroll_left();
        return;
    } else {
        oled_scroll_off();
    }
#    ifndef SPLIT_KEYBOARD
    oled_on();
#    endif

    if (is_master) {
        render_status();
    } else {
        render_logo();
    }
}
#endif  // OLED_DRIVER_ENABLE

#ifdef RGB_MATRIX_ENABLE
static void rgb_matrix_layer_helper_rgb(uint8_t red, uint8_t green, uint8_t blue, uint8_t flags) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], flags)) {
            rgb_matrix_set_color(i, red, green, blue);
        }
    }
}

#    ifdef LEADER_ENABLE
extern bool leading;
#    endif

void rgb_matrix_indicators_user(void) {
    if (!rgb_matrix_config.enable || !userspace_config.rgb_layer_change) {
        return;
    }
    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(g_led_config.matrix_co[2][0], 0xFF, 0x0, 0x0);
    }

    switch (get_highest_layer(layer_state)) {
        case _ADJUST:
            rgb_matrix_layer_helper_rgb(0xFF, 0x0, 0x0, LED_FLAG_UNDERGLOW);
            break;

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
    }

#    ifdef LEADER_ENABLE
    if (leading) {
        rgb_matrix_layer_helper_rgb(0x0, 0xff, 0x0, LED_FLAG_MODIFIER);
    }
#    endif
}
#endif  // RGB_MATRIX_ENABLE
