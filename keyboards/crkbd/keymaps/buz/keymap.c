#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  /* #include "split_util.h" */
#endif
#include "buz.h"
#include "raw_hid.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

#ifdef RGB_MATRIX_ENABLE
extern rgb_config_t rgb_matrix_config;
#endif

extern uint8_t is_master;

enum custom_keycodes {
  RGBRST = USER_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    KC_TABMS,_________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC,
    KC_CESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT,
    KC_LSPO, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_RSPC,
                               KC_O_LALT, LOWER, KC_GENT, KC_SPC, RAISE, KC_O_RALT \
  ),
  [_LOWER] = LAYOUT_wrapper(
    KC_TILD, _________________LOWER_L1__________________, _________________LOWER_R1__________________, _______,
    _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_PIPE,
    KC_CAPS, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
                               _______, _______, _______, _______, _______, _______ \
  ),
  [_RAISE] = LAYOUT_wrapper(
    KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, KC_DEL,
    _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,
    _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
                               _______, _______, _______, _______, _______, _______ \
  ),
  [_ADJUST] = LAYOUT_wrapper(
    RESET,   _________________ADJUST_L1_________________, _________________ADJUST_R1_________________, RESET,
    RGB_TOG, _________________ADJUST_L2_________________, _________________ADJUST_R2_________________, RGBRST,
    RGB_MOD, _________________ADJUST_L3_________________, _________________ADJUST_R3_________________, _______,
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
                               _______, _______, _______, _______, _______, _______ \
  ),
};

int RGB_current_mode;


void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    #ifdef RGB_MATRIX_ENABLE
      RGB_current_mode = rgb_matrix_config.mode;
    #endif
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGBRST:
#ifdef RGBLIGHT_ENABLE
      if (record->event.pressed) {
        eeconfig_update_rgblight_default();
        rgblight_enable();
        RGB_current_mode = rgblight_config.mode;
      }
#endif
#ifdef RGB_MATRIX_ENABLE
      // eeconfig_update_rgb_matrix_default();
      // rgb_matrix_enable();
      // eeconfig_update_rgb_matrix(rgb_matrix_config.raw);
      rgb_matrix_config.enable = 1;
      rgb_matrix_config.mode = RGB_MATRIX_SOLID_COLOR;
      rgb_matrix_config.hue = 0;
      rgb_matrix_config.sat = 100;
      rgb_matrix_config.val = 50;
      rgb_matrix_mode(rgb_matrix_config.mode);
#endif
      return false;
  }
  return true;
}

// OLED Driver Logic
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flip 180 for offhand
  return rotation;
}

static void render_logo(void) {
  static const char PROGMEM logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
      0};

  /* static const char PROGMEM logo[] = { */
  /*   0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94, */
  /*   0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4, */
  /*   0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0}; */

  oled_write_P(logo, false);
}

static void render_status(void) {
  // Render to mode icon
  static const char PROGMEM mode_logo[4][4] = {
      {0x99,0x9a,0},
      {0xb9,0xba,0} };

  oled_write_P(mode_logo[0], false);
  oled_set_cursor(4, 0);
  oled_render_layer();
  oled_write_P(mode_logo[1], false);
  oled_set_cursor(4, 1);
  oled_render_mods();

#ifdef RGBLIGHT_ENABLE
  render_rgblight_effect_name();
#endif // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
  render_rgb_matrix_effect_name();
#endif // RGB_MATRIX_ENABLE
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
    oled_scroll_left();  // Turns on scrolling
  }
}

#endif
