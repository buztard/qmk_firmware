#include QMK_KEYBOARD_H
#include "buz.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
     KC_TABMS, _________________QWERTY_L1_________________,  _________________QWERTY_R1_________________, KC_BSPC,
      KC_CESC, _________________QWERTY_L2_________________,  _________________QWERTY_R2_________________, RCTL_T(KC_QUOT),
OSM(MOD_LSFT), _________________QWERTY_L3_________________,  _________________QWERTY_R3_________________, OSM(MOD_RSFT),
                                KC_LCBR, KC_RCBR,              KC_LBRC, KC_RBRC,
                    LT(_NUM, KC_ESC), LT(_SYMBOL, KC_ENT),     LT(_SYMBOL, KC_SPC), LT(_NUM, KC_BSPC),
                                KC_TD_LALT, OSM(MOD_LSFT),     OSM(MOD_LSFT), KC_TD_RALT,
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
      _______, _________________NUMPAD_L1_________________,  _________________NUMPAD_R1_________________, _______,
      _______, _________________NUMPAD_L2_________________,  _________________NUMPAD_R2_________________, _______,
      _______, _________________NUMPAD_L3_________________,  _________________NUMPAD_R3_________________, _______,
                            _______, _______,                            _______, _______,
                                MO(_ADJUST), CAPS_WORD,           _______, _______,
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
  [_SYMBOL] = LAYOUT_wrapper(
      _______, _________________SYMBOL_L1_________________, _________________SYMBOL_R1_________________, KC_AT,
      _______, _________________SYMBOL_L2_________________, _________________SYMBOL_R2_________________, REPEAT,
      _______, _________________SYMBOL_L3_________________, _________________SYMBOL_R3_________________, _______,
                            _______, _______,                            _______, _______,
                                      _______, KC_TAB,            _______, _______,
                                      _______, _______,           _______, _______,
                                      _______, _______,           _______, _______
  ),
  [_TMUX] = LAYOUT_wrapper(
    _______, __________________TMUX_L1__________________, __________________TMUX_R1__________________, _______,
    _______, __________________TMUX_L2__________________, __________________TMUX_R2__________________, _______,
    _______, __________________TMUX_L3__________________, __________________TMUX_R3__________________, _______,
                            _______, _______,                            _______, _______,
                                      _______, _______,           _______, _______,
                                      _______, _______,           _______, _______,
                                      _______, _______,           _______, _______
  ),
};
// clang-format on
