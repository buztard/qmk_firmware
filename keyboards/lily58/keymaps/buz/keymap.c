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
    KC_CESC, _________________QWERTY_L2_________________,                            _________________QWERTY_R2_________________, KC_QUOT,
    KC_LSPO, _________________QWERTY_L3_________________, KC_LBRC,          KC_RBRC, _________________QWERTY_R3_________________, KC_RSPC,
                                 KC_LALT, KC_LGUI, LOWER, KC_GENT,          KC_SPC,  RAISE, KC_O_RALT, KC_RGUI
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

void matrix_init_keymap(void) {
#ifdef SSD1306OLED
    iota_gfx_init(!has_usb());  // turns on the display
#endif
}

// SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) { iota_gfx_task(); }

void matrix_render_user(struct CharacterMatrix *matrix) {
    if (is_master) {
        // If you want to change the display of OLED, you need to change here
        matrix_write_ln(matrix, read_layer_state());
        matrix_write_ln(matrix, read_keylog());
        matrix_write_ln(matrix, read_keylogs());
        // matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
        // matrix_write_ln(matrix, read_host_led_state());
        // matrix_write_ln(matrix, read_timelog());
    } else {
        matrix_write(matrix, read_logo());
    }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
    if (memcmp(dest->display, source->display, sizeof(dest->display))) {
        memcpy(dest->display, source->display, sizeof(dest->display));
        dest->dirty = true;
    }
}

void iota_gfx_task_user(void) {
    struct CharacterMatrix matrix;
    matrix_clear(&matrix);
    matrix_render_user(&matrix);
    matrix_update(&display, &matrix);
}
#endif  // SSD1306OLED

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef SSD1306OLED
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }

    return true;
}
