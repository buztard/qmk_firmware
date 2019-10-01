#include QMK_KEYBOARD_H
#ifdef PROTOCOL_LUFA
#    include "lufa.h"
#    include "split_util.h"
#endif
#include "buz.h"
#include "raw_hid.h"

#ifdef RGB_MATRIX_ENABLE
extern rgb_config_t rgb_matrix_config;
#endif

static uint32_t oled_timer = 0;

extern uint8_t is_master;

enum custom_keycodes {
    RGBRST = USER_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    KC_TABMS,_________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC,
    KC_CESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT,
    KC_LSPO, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_RSPC,
                              KC_TD_LALT, LOWER, KC_GENT, KC_SPC, RAISE, KC_TD_RALT \
  ),
  [_LOWER] = LAYOUT_wrapper(
    KC_TILD, _________________LOWER_L1__________________, _________________LOWER_R1__________________, _______,
    _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_PIPE,
    KC_CAPS, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
                               _______, _______, _______, KC_LEAD, _______, _______ \
  ),
  [_RAISE] = LAYOUT_wrapper(
    KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, KC_DEL,
    _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,
    _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
                               _______, _______, _______, _______, _______, _______ \
  ),
  [_ADJUST] = LAYOUT_wrapper(
    RESET,   _________________ADJUST_L1_________________, _________________ADJUST_R1_________________, RESET,
    _______, _________________ADJUST_L2_________________, _______,TG(_JIRA), DEBUG,   _______, KC_SINS, RGBRST,
    KC_CAPS, _________________ADJUST_L3_________________, _________________ADJUST_R3_________________, _______,
                               _______, _______, _______, _______, _______, _______ \
  ),
  [_VIM] = LAYOUT_wrapper(
    _______, __________________VIM_L1___________________, __________________VIM_R1___________________, _______,
    _______, __________________VIM_L2___________________, __________________VIM_R2___________________, _______,
    _______, __________________VIM_L3___________________, __________________VIM_R3___________________, _______,
                               _______, _______, _______, _______, _______, _______ \
  ),
  [_MOUSE] = LAYOUT_wrapper(
    _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, _______,
    _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______,
    _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________, _______,
                              _______, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2 \
  ),
  [_NUM] = LAYOUT_wrapper(
    _______, ___________________BLANK___________________, _________________NUMPAD_R1_________________, _______,
    _______, ___________________BLANK___________________, _________________NUMPAD_R2_________________, _______,
    _______, ___________________BLANK___________________, _________________NUMPAD_R3_________________, _______,
                               _______, _______, _______, _______, KC_0,    _______ \
  ),
  [_JIRA] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_P,    _______, _______, KC_N,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______ \
  ),
};
// clang-format on

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        oled_timer = timer_read32();
#endif
#ifndef SPLIT_KEYBOARD
        if (keycode == RESET && !is_master) {
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
                // Godspeed: H:40 S:48 V:54 SPEED:111
                // Dasher:
            }
#endif  // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
            if (record->event.pressed) {
#    ifdef CONSOLE_ENABLE
                uprintf("H:%d S:%d V:%d SPEED:%d\n", rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v, rgb_matrix_config.speed);
#    endif  // CONSOLE_ENABLE
            }
#endif  // RGB_MATRIX_ENABLE
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
    oled_set_cursor(4, 0);
    oled_render_layer();
    oled_write_P(mode_logo[1], false);
    oled_set_cursor(4, 1);
    oled_render_mods();

#    ifdef RGBLIGHT_ENABLE
    render_rgblight_effect_name();
#    endif  // RGBLIGHT_ENABLE
#    ifdef RGB_MATRIX_ENABLE
    render_rgb_matrix_effect_name();
#    endif  // RGB_MATRIX_ENABLE
}

void oled_task_user(void) {
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

#ifdef RAW_ENABLE
enum crkbd_command_id {
    id_get_protocol_version = 0x01,  // always 0x01
    id_matrix_get_mode,
    id_matrix_set_mode,
    id_matrix_get_hsv,
    id_matrix_set_hsv,
    id_oled_set_text,

    id_unhandled = 0xFF,
};

void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t *command_id = &(data[0]);

    switch (*command_id) {
        case id_get_protocol_version:
            break;

        case id_matrix_get_mode:
            break;

        case id_matrix_set_mode:
            break;

        case id_matrix_get_hsv:
            data[1] = rgb_matrix_config.hsv.h;
            data[2] = rgb_matrix_config.hsv.s;
            data[3] = rgb_matrix_config.hsv.v;
            break;

        case id_matrix_set_hsv:
            rgb_matrix_config.hsv.h = data[1];
            rgb_matrix_config.hsv.s = data[2];
            rgb_matrix_config.hsv.v = data[3];
            break;

        case id_oled_set_text:
            break;

        default:
            break;
    }
    // Return same buffer with values changed
    raw_hid_send(data, length);
}
#endif  // RAW_ENABLE

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
    if (!rgb_matrix_config.enable) {
        return;
    }
    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(g_led_config.matrix_co[2][0], 0xFF, 0x0, 0x0);
    }

    switch (biton32(layer_state)) {
        case _LOWER:
            rgb_matrix_layer_helper_rgb(95, 7, 53, LED_FLAG_UNDERGLOW);
            break;

        case _RAISE:
            rgb_matrix_layer_helper_rgb(0x0, 0x0, 0x9F, LED_FLAG_UNDERGLOW);
            break;

        case _ADJUST:
            rgb_matrix_layer_helper_rgb(0xFF, 0x0, 0x0, LED_FLAG_UNDERGLOW);
            break;

        case _VIM:
            rgb_matrix_set_color(g_led_config.matrix_co[5][5], 0x0, 0xFF, 0x0);
            rgb_matrix_set_color(g_led_config.matrix_co[5][4], 0x0, 0xFF, 0x0);
            rgb_matrix_set_color(g_led_config.matrix_co[5][3], 0x0, 0xFF, 0x0);
            rgb_matrix_set_color(g_led_config.matrix_co[5][2], 0x0, 0xFF, 0x0);
            break;

        case _MOUSE:
            rgb_matrix_set_color(g_led_config.matrix_co[5][5], 0xff, 0x0, 0x0);
            rgb_matrix_set_color(g_led_config.matrix_co[5][4], 0xff, 0x0, 0x0);
            rgb_matrix_set_color(g_led_config.matrix_co[5][3], 0xff, 0x0, 0x0);
            rgb_matrix_set_color(g_led_config.matrix_co[5][2], 0xff, 0x0, 0x0);
            break;

        case _NUM:
            rgb_matrix_set_color(g_led_config.matrix_co[4][2], 95, 7, 53);
            rgb_matrix_set_color(g_led_config.matrix_co[4][3], 95, 7, 53);
            rgb_matrix_set_color(g_led_config.matrix_co[4][4], 95, 7, 53);
            rgb_matrix_set_color(g_led_config.matrix_co[5][2], 95, 7, 53);
            rgb_matrix_set_color(g_led_config.matrix_co[5][3], 95, 7, 53);
            rgb_matrix_set_color(g_led_config.matrix_co[5][4], 95, 7, 53);
            rgb_matrix_set_color(g_led_config.matrix_co[6][2], 95, 7, 53);
            rgb_matrix_set_color(g_led_config.matrix_co[6][3], 95, 7, 53);
            rgb_matrix_set_color(g_led_config.matrix_co[6][4], 95, 7, 53);
            break;

        case _JIRA:
            rgb_matrix_layer_helper_rgb(0x0, 0x9F, 0x0, LED_FLAG_UNDERGLOW);
            break;
    }

#    ifdef LEADER_ENABLE
    if (leading) {
        rgb_matrix_layer_helper_rgb(0xff, 0x0, 0x0, LED_FLAG_MODIFIER);
    }
#    endif
}
#endif  // RGB_MATRIX_ENABLE
