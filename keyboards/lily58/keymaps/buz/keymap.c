#include QMK_KEYBOARD_H
#include "buz.h"

#ifdef PROTOCOL_LUFA
#    include "lufa.h"
#    include "split_util.h"
#endif
#ifdef SSD1306OLED
#    include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
// Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    KC_GRV,  ________________NUMBER_LEFT________________,                            ________________NUMBER_RIGHT_______________, KC_BSPC,
    KC_TABMS,_________________QWERTY_L1_________________,                            _________________QWERTY_R1_________________, KC_BSPC,
    KC_CESC, _________________QWERTY_L2_________________,                            _________________QWERTY_R2_________________, RCTL_T(KC_QUOT),
       LSPO, _________________QWERTY_L3_________________, KC_LBRC,          KC_RBRC, _________________QWERTY_R3_________________, RSPC,
                                 KC_LGUI, KC_LALT, LOWER, KC_GENT,          KC_SPC,  RAISE, KC_O_RALT, KC_RGUI
  ),

  [_COLEMAK] = LAYOUT_wrapper(
    KC_GRV,  ________________NUMBER_LEFT________________,                            ________________NUMBER_RIGHT_______________, KC_BSPC,
    KC_TABMS,_________________COLEMAK_L1________________,                            _________________COLEMAK_R1________________, KC_BSPC,
    KC_CESC, _________________COLEMAK_L2________________,                            _________________COLEMAK_R2________________, KC_QUOT,
    KC_LSPO, _________________COLEMAK_L3________________, KC_LBRC,          KC_RBRC, _________________COLEMAK_R2________________, KC_RSPC,
                                 KC_LALT, KC_LGUI, LOWER, KC_GENT,          KC_SPC,  RAISE, KC_O_RALT, KC_RGUI
  ),

  [_LOWER] = LAYOUT_wrapper(
    KC_TILD, _________________LOWER_L1__________________,                            _________________LOWER_R1__________________, KC_DEL,
    KC_TILD, _________________LOWER_L1__________________,                            _________________LOWER_R1__________________, KC_DEL,
    _______, _________________LOWER_L2__________________,                            _________________LOWER_R2__________________, KC_PIPE,
    KC_CAPS, _________________LOWER_L3__________________, _______,          _______, _________________LOWER_R3__________________, _______,
                               _______, _______, _______, _______,          _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT_wrapper(
    KC_F12,  _________________FUNC_LEFT_________________,                            _________________FUNC_RIGHT________________, KC_F11,
    KC_GRV,  _________________RAISE_L1__________________,                            _________________RAISE_R1__________________, KC_DEL,
    _______, _________________RAISE_L2__________________,                            _________________RAISE_R2__________________, KC_BSLS,
    KC_CAPS, _________________RAISE_L3__________________, _______,          _______, _________________RAISE_R3__________________, _______,
                              _______, _______, _______,  _______,          _______, _______, _______, _______
  ),

  [_VIM] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    _______, __________________VIM_L1___________________,                            __________________VIM_R1___________________, _______,
    _______, __________________VIM_L2___________________,                            __________________VIM_R2___________________, _______,
    _______, __________________VIM_L3___________________, _______,          _______, __________________VIM_R3___________________, _______,
                              _______, _______, _______,  _______,          _______, _______, _______, _______
  ),


  [_MOUSE] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    _______, _________________MOUSE_L1__________________,                            _________________MOUSE_R1__________________, _______,
    _______, _________________MOUSE_L2__________________,                            _________________MOUSE_R2__________________, _______,
    _______, _________________MOUSE_L3__________________, _______,          _______, _________________MOUSE_R3__________________, _______,
                              _______,  _______, _______, _______,          KC_BTN1, KC_BTN3, KC_BTN2, _______
  ),

  [_NUM] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                            _________________NUMPAD_R1_________________, _______,
    _______, _______, _______, _______, _______, _______,                            _________________NUMPAD_R2_________________, _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, _________________NUMPAD_R3_________________, _______,
                               _______, _______, _______, _______,          _______,    KC_0,   KC_DOT, _______
  ),

  [_ADJUST] = LAYOUT_wrapper(
    RESET,   RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,                           RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, RESET,
    RGB_TOG, _________________ADJUST_L1_________________,                            _________________ADJUST_R1_________________, _______,
    RGB_MOD, _________________ADJUST_L2_________________,                            _________________ADJUST_R2_________________, _______,
    _______, _________________ADJUST_L3_________________, _______,          _______, _________________ADJUST_R3_________________, _______,
                               _______, _______, _______, _______,          _______,  _______, _______, _______
  )
};
// clang-format on

int RGB_current_mode;

void matrix_init_keymap(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}

#ifdef OLED_DRIVER_ENABLE
static uint32_t oled_timer = 0;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
        return OLED_ROTATION_0;
        // return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
    }

    // if (!is_master) return OLED_ROTATION_180;
    // return rotation;
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
    // static const char PROGMEM mode_logo[4][4] = {{0x99, 0x9a, 0}, {0xb9, 0xba, 0}};

    // oled_write_P(mode_logo[0], false);
    // oled_set_cursor(3, 0);
    oled_render_layer();
    // oled_write_P(mode_logo[1], false);
    // oled_set_cursor(3, 1);
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

  if (is_keyboard_master()) {
        render_status();
        // render_logo();
    } else {
        render_logo();
        // render_status();
    }
}

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
#endif  // OLED_DRIVER_ENABLE
    return true;
}
