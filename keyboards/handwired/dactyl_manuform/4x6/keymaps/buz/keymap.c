#include QMK_KEYBOARD_H
#include "buz.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    KC_TABMS, _________________QWERTY_L1_________________,  _________________QWERTY_R1_________________, KC_BSPC,
     KC_CESC, _________________QWERTY_L2_________________,  _________________QWERTY_R2_________________, RCTL_T(KC_QUOT),
        LSPO, _________________QWERTY_L3_________________,  _________________QWERTY_R3_________________, RSPC,
                                KC_LCBR, KC_RCBR,              KC_LBRC, KC_RBRC,
                       LT(_LOWER, KC_ESC), LGUI_T(KC_ENT),     LT(_EXTRA, KC_SPC), LT(_RAISE, KC_BSPC),
                                KC_TD_LALT, LSPO,              RSPC, KC_TD_RALT,
                                TMUX_PP, TMUX_WP,              TMUX_WN, TMUX_PN
  ),

  [_COLEMAK] = LAYOUT_wrapper(
    KC_TABMS, _________________COLEMAK_L1________________,  _________________COLEMAK_R1________________, KC_BSPC,
     KC_CESC, _________________COLEMAK_L2________________,  _________________COLEMAK_R2________________, RCTL_T(KC_QUOT),
        LSPO, _________________COLEMAK_L3________________,  _________________COLEMAK_R3________________, RSPC,
                            KC_LCBR, KC_RCBR,                            KC_LBRC, KC_RBRC,
                                      LOWER,   KC_GENT,           KC_SPC,  RAISE,
                                  KC_TD_LALT, KC_LSPO,           KC_RSPC, KC_TD_RALT,
                                      KC_CESC, KC_DEL,            KC_PGUP, KC_PGDN
  ),

  [_LOWER] = LAYOUT_wrapper(
      KC_TILD, _________________LOWER_L1__________________,  _________________LOWER_R1__________________, _______,
      _______, _________________LOWER_L2__________________,  _________________LOWER_R2__________________, KC_PIPE,
      KC_CAPS, _________________LOWER_L3__________________,  _________________LOWER_R3__________________, _______,
                            _______, _______,                            _______, _______,
                                      _______, _______,           _______, _______,
                                      _______, _______,           _______, _______,
                                      _______, _______,           _______, _______
  ),

  [_RAISE] = LAYOUT_wrapper(
      KC_GRV,  _________________RAISE_L1__________________,  _________________RAISE_R1__________________, KC_DEL,
      _______, _________________RAISE_L2__________________,  _________________RAISE_R2__________________, KC_BSLS,
      _______, _________________RAISE_L3__________________,  _________________RAISE_R3__________________, _______,
                            _______, _______,                            KC_PGUP, KC_PGDN,
                                      _______, _______,           _______, _______,
                                      _______, _______,           _______, _______,
                                      _______, _______,           _______, _______
  ),

  [_VIM] = LAYOUT_wrapper(
      _______, __________________VIM_L1___________________,  __________________VIM_R1___________________, _______,
      _______, __________________VIM_L2___________________,  __________________VIM_R2___________________, _______,
      _______, __________________VIM_L3___________________,  __________________VIM_R3___________________, _______,
                            _______, _______,                            _______, _______,
                                      _______, _______,           _______, _______,
                                      _______, _______,           _______, _______,
                                      _______, _______,           _______, _______
  ),

  [_MOUSE] = LAYOUT_wrapper(
      _______, _________________MOUSE_L1__________________,  _________________MOUSE_R1__________________, _______,
      _______, _________________MOUSE_L2__________________,  _________________MOUSE_R2__________________, _______,
      _______, _________________MOUSE_L3__________________,  _________________MOUSE_R3__________________, _______,
                            KC_WH_U, KC_WH_D,                            _______, _______,
                                      _______, _______,           KC_BTN1, KC_BTN3,
                                      _______, _______,           KC_BTN2, _______,
                                      _______, _______,           KC_BTN4, KC_BTN5
  ),

  [_NUM] = LAYOUT_wrapper(
      _______, ___________________BLANK___________________,  _________________NUMPAD_R1_________________, _______,
      _______, ___________________BLANK___________________,  _________________NUMPAD_R2_________________, _______,
      _______, ___________________BLANK___________________,  _________________NUMPAD_R3_________________, _______,
                            _______, _______,                            _______, _______,
                                      _______, _______,           _______, _______,
                                      _______, _______,           _______, _______,
                                      _______, _______,           _______, _______
  ),

  [_ADJUST] = LAYOUT_wrapper(
      _______, _________________ADJUST_L1_________________,  _________________ADJUST_R1_________________, _______,
      _______, _________________ADJUST_L2_________________,  _________________ADJUST_R2_________________, _______,
      _______, _________________ADJUST_L3_________________,  _________________ADJUST_R3_________________, _______,
                            _______, _______,                            _______, _______,
                                      _______, _______,           _______, _______,
                                      _______, _______,           _______, _______,
                                      _______, _______,           _______, _______
  ),
  [_EXTRA] = LAYOUT_wrapper(
      _______, _________________EXTRA_L1__________________,  _________________EXTRA_R1__________________, _______,
      _______, _________________EXTRA_L2__________________,  _________________EXTRA_R2__________________, _______,
      _______, _________________EXTRA_L3__________________,  _________________EXTRA_R3__________________, _______,
                            _______, _______,                            _______, _______,
                                      _______, _______,           _______, _______,
                                      _______, _______,           _______, _______,
                                      _______, _______,           _______, _______
  ),
};
// clang-format on
