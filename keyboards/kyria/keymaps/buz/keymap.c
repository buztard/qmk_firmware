#include QMK_KEYBOARD_H
#include "buz.h"

extern userspace_config_t userspace_config;
extern rgblight_config_t  rgblight_config;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    KC_TABMS,_________________QWERTY_L1_________________,                                     _________________QWERTY_R1_________________, KC_BSPC,
    KC_CESC, _________________QWERTY_L2_________________,                                     _________________QWERTY_R2_________________, LCTL_T(KC_QUOT),
       LSPO, _________________QWERTY_L3_________________, TMUX_PP, TMUX_WP, TMUX_WN, TMUX_PN, _________________QWERTY_R3_________________, RSPC,
                              ENC_0, KC_TD_LALT, LOWER,   KC_GENT, LSPO,    RSPC,    KC_SPC,  RAISE,   KC_TD_RALT, ENC_1
  ),

  [_COLEMAK] = LAYOUT_wrapper(
    KC_TABMS,_________________COLEMAK_L1________________,                                     _________________COLEMAK_R1________________, KC_BSPC,
    KC_CESC, _________________COLEMAK_L2________________,                                     _________________COLEMAK_R2________________, KC_QUOT,
       LSPO, _________________COLEMAK_L3________________, KC_MINS, KC_PGUP, KC_PGDN, KC_EQL,  _________________COLEMAK_R3________________, RSPC,
                            KC_MUTE, KC_TD_LALT, LOWER,   KC_GENT, LSPO,    RSPC,    KC_SPC,  RAISE,   KC_TD_RALT, KC_MUTE
  ),

  [_LOWER] = LAYOUT_wrapper(
    KC_TILD, _________________LOWER_L1__________________,                                     _________________LOWER_R1__________________, _______,
    _______, _________________LOWER_L2__________________,                                     _________________LOWER_R2__________________, KC_PIPE,
    KC_CAPS, _________________LOWER_L3__________________, _______, _______, _______, _______, _________________LOWER_R3__________________, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT_wrapper(
    KC_GRV,  _________________RAISE_L1__________________,                                     _________________RAISE_R1__________________, KC_DEL,
    _______, _________________RAISE_L2__________________,                                     _________________RAISE_R2__________________, KC_BSLS,
    _______, _________________RAISE_L3__________________, _______, _______, _______, _______, _________________RAISE_R3__________________, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_wrapper(
    KC_GRV,  _________________ADJUST_L1_________________,                                     _________________ADJUST_R1_________________, KC_DEL,
    _______, _________________ADJUST_L2_________________,                                     _________________ADJUST_R2_________________, KC_BSLS,
    _______, _________________ADJUST_L3_________________, _______, _______, _______, _______, _________________ADJUST_R3_________________, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_VIM] = LAYOUT_wrapper(
    _______, __________________VIM_L1___________________,                                     __________________VIM_R1___________________, _______,
    _______, __________________VIM_L2___________________,                                     __________________VIM_R2___________________, _______,
    _______, __________________VIM_L3___________________, _______, _______, _______, _______, __________________VIM_R3___________________, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_MOUSE] = LAYOUT_wrapper(
    _______, _________________MOUSE_L1__________________,                                     _________________MOUSE_R1__________________, _______,
    _______, _________________MOUSE_L2__________________,                                     _________________MOUSE_R2__________________, _______,
    _______, _________________MOUSE_L3__________________, _______, _______, _______, _______, _________________MOUSE_R2__________________, _______,
                               _______, _______, _______, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______
  ),

  [_NUM] = LAYOUT_wrapper(
    _______, ___________________BLANK___________________,                                     _________________NUMPAD_R1_________________, _______,
    _______, ___________________BLANK___________________,                                     _________________NUMPAD_R2_________________, _______,
    _______, ___________________BLANK___________________, _______, _______, _______, _______, _________________NUMPAD_R3_________________, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_MEDIA] = LAYOUT_wrapper(
    _______, _________________MEDIA_L1__________________,                                     _________________MEDIA_R1__________________, _______,
    _______, _________________MEDIA_L2__________________,                                     _________________MEDIA_R2__________________, _______,
    _______, _________________MEDIA_L3__________________, _______, _______, _______, _______, _________________MEDIA_R3__________________, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}
// clang-format on

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    // oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    oled_render_layer();
    oled_render_mods();

#    if defined(RGBLIGHT_ENABLE)
    oled_write_P(PSTR("R: "), false);
    oled_render_rgblight_effect_name();
#    endif  // RGBLIGHT_ENABLE
#    if defined(ENCODER_ENABLE)
    oled_write_P(PSTR("L: "), false);
    oled_write_P(encoder_mode_name(0), false);
    oled_write_P(PSTR(" R: "), false);
    oled_write_P(encoder_mode_name(1), false);
    oled_advance_page(true);
#    endif
}

void oled_task_user(void) {
    if (!userspace_config.oled_enabled) {
        oled_off();
        return;
    }

    if (is_keyboard_master()) {
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

// #ifdef ENCODER_ENABLE
// void encoder_update_keymap(uint8_t index, bool clockwise) {
//     if (index == 0) {
//         switch (get_highest_layer(layer_state)) {
//             case _RAISE:
//                 if (!clockwise) {
//                     SEND_STRING(SS_LCTL("a") "o");
//                 } else {
//                     SEND_STRING(SS_LCTL("a") "O");
//                 }
//                 break;

//             case _MOUSE:
//                 if (!clockwise) {
//                     tap_code(KC_MS_DOWN);
//                 } else {
//                     tap_code(KC_MS_UP);
//                 }
//                 break;

//             default:
//                 if (!clockwise) {
//                     tap_code(KC_VOLU);
//                 } else {
//                     tap_code(KC_VOLD);
//                 }
//                 break;
//         }
//     } else if (index == 1) {
//         switch (get_highest_layer(layer_state)) {
//             case _LOWER:
//                 if (!clockwise) {
//                     SEND_STRING(SS_LCTL("an"));
//                 } else {
//                     SEND_STRING(SS_LCTL("ap"));
//                 }
//                 break;
//             case _MOUSE:
//                 if (!clockwise) {
//                     tap_code(KC_MS_RIGHT);
//                 } else {
//                     tap_code(KC_MS_LEFT);
//                 }
//                 break;
//             default:
//                 if (!clockwise) {
//                     tap_code(KC_PGDN);
//                 } else {
//                     tap_code(KC_PGUP);
//                 }
//                 break;
//         }
//     }
// }
// #endif

#ifdef RGBLIGHT_ENABLE
static void rgblight_set_color(uint8_t h, uint8_t s, uint8_t v) { rgblight_sethsv_noeeprom(h, s, rgblight_config.val); }

layer_state_t layer_state_set_keymap(layer_state_t state) {
    if (!rgblight_config.enable || !userspace_config.rgb_layer_change) {
        return state;
    }

    switch (get_highest_layer(state)) {
        case _ADJUST:
            rgblight_set_color(HSV_AZURE);
            break;

        case _VIM:
            rgblight_set_color(HSV_GREEN);
            break;

        case _MOUSE:
            rgblight_set_color(HSV_PURPLE);
            break;

        case _NUM:
            rgblight_set_color(HSV_ORANGE);
            break;

        default:
            rgblight_set_color(HSV_RED);
            break;
    }

    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
        rgblight_set_color(HSV_WHITE);
#    ifdef RGBLIGHT_EFFECT_BREATHING
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
#    endif
    }

    return state;
}
#endif
