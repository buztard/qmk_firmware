#include QMK_KEYBOARD_H
#include "buz.h"
#include "lib/lib8tion/lib8tion.h"

extern userspace_config_t userspace_config;

// clang-format off
/**
 * Based on the default iris layout, but the default QWERTY layer is modified
 * to be more like a default querty layout to not hurt my muscle memory too
 * much.
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  ________________NUMBER_LEFT________________,                            ________________NUMBER_RIGHT_______________, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TABMS,_________________QWERTY_L1_________________,                            _________________QWERTY_R1_________________, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CESC, _________________QWERTY_L2_________________,                            _________________QWERTY_R2_________________, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSPO, _________________QWERTY_L3_________________, KC_LBRC,          KC_RBRC, _________________QWERTY_R3_________________, KC_RSPC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TD_LALT, LOWER, KC_GENT,                  KC_SPC,  RAISE,   KC_TD_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT_wrapper(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, _________________LOWER_L1__________________,                            _________________LOWER_R1__________________, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILD, _________________LOWER_L1__________________,                            _________________LOWER_R1__________________, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _________________LOWER_L2__________________,                            _________________LOWER_R2__________________, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, _________________LOWER_L3__________________, KC_HYPR,          KC_SINS, _________________LOWER_R3__________________, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT_wrapper(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  _________________FUNC_LEFT_________________,                            _________________FUNC_RIGHT________________, KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  _________________RAISE_L1__________________,                            _________________RAISE_R1__________________, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _________________RAISE_L2__________________,                            _________________RAISE_R2__________________, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, _________________RAISE_L3__________________, KC_LPRN,          _______, _________________RAISE_R3__________________, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_VIM] = LAYOUT_wrapper(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, KC_END,  _______,                            _______, _______, _______, _______, KC_HOME, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, __________________VIM_L1___________________,                            __________________VIM_R1___________________, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, __________________VIM_L2___________________,                            __________________VIM_R2___________________, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, __________________VIM_L3___________________, _______,          _______, __________________VIM_R3___________________, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_MOUSE] = LAYOUT_wrapper(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _________________MOUSE_L1__________________,                            _________________MOUSE_R1__________________, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _________________MOUSE_L2__________________,                            _________________MOUSE_R2__________________, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _________________MOUSE_L3__________________, _______,          _______, _________________MOUSE_R3__________________, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   KC_BTN1, KC_BTN3, KC_BTN2
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT_wrapper(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _________________NUMPAD_R1_________________, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _________________NUMPAD_R2_________________, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _________________NUMPAD_R3_________________, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______,    KC_0,   KC_DOT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT_wrapper(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RESET,   RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,                           RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, RESET,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, _________________ADJUST_L1_________________,                            _________________ADJUST_R1_________________, RESET,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, _________________ADJUST_L2_________________,                            _________________ADJUST_R2_________________, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _________________ADJUST_L3_________________, _______,          _______, _________________ADJUST_R3_________________, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};
// clang-format on

#ifdef XXxRGBLIGHT_ENABLE
bool layer_indicator_keymap(void) {

    switch (biton32(layer_state)) {
        case _LOWER ... _NUM:
            return true;

        case _QWERTY:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            return false;
    }
    return true;
}
#endif

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;

static void rgblight_set_color(uint8_t h, uint8_t s, uint8_t v) { rgblight_sethsv_noeeprom(h, s, scale8(rgblight_config.val, v)); }

layer_state_t layer_state_set_keymap(layer_state_t state) {
    if (!userspace_config.rgb_layer_change) {
        return state;
    }

    // default mode
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);

    switch (biton32(state)) {
        case _MOUSE:
            // rgblight_sethsv_noeeprom_red();
            rgblight_set_color(213, 255, 255);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT);
            break;

        case _VIM:
            // rgblight_sethsv_noeeprom_green();
            rgblight_set_color(85, 255, 255);
            break;

        case _NUM:
            rgblight_set_color(43, 255, 255);
            break;

        case _ADJUST:
            rgblight_set_color(0, 255, 255);
            break;

        default:
            rgblight_set_color(128, 207, 100);
            break;
    }

    if (get_oneshot_mods()) rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);

    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+2);
    }

    return state;
}
#endif  // RGBLIGHT_ENABLE
