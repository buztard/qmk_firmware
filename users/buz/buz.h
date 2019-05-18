#pragma once
#include "quantum.h"

#ifdef OLED_DRIVER_ENABLE
#include "oled_stuff.h"
#endif

enum userspace_layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _VIM,
  _MOUSE,
  _NUM,
  _FN,
};

enum userspace_custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MOUSE,
  VIM,
  NUM,
  USER_SAFE_RANGE,
};


#define KC_CESC CTL_T(KC_ESC)
#define KC_GENT LGUI_T(KC_ENT)

#define KC_TABMS LT(_MOUSE, KC_TAB)
#define KC_Z_VIM LT(_VIM, KC_Z)
#define KC_X_NUM LT(_NUM, KC_X)
#define KC_O_LALT OSM(MOD_LALT)
#define KC_O_RALT OSM(MOD_RALT)
#define KC_SINS LSFT(KC_INSERT)

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define ___________________BLANK___________________        _______, _______, _______, _______, _______

#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z_VIM,KC_X_NUM,KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define ________________NUMBER_LEFT________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define _________________FUNC_LEFT_________________        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define _________________LOWER_L1__________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L2__________________        _________________FUNC_LEFT_________________
#define _________________LOWER_L3__________________        _________________FUNC_RIGHT________________

#define _________________LOWER_R1__________________        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define _________________LOWER_R2__________________        _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR
#define _________________LOWER_R3__________________        _______, KC_LCBR, KC_RCBR, _______, _______

#define _________________RAISE_L1__________________        ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________        KC_MNXT, KC_MPLY, KC_VOLU, KC_PGUP, KC_HOME
#define _________________RAISE_L3__________________        KC_MPRV, KC_MSTP, KC_VOLD, KC_PGDN, KC_END

#define _________________RAISE_R1__________________        ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define _________________RAISE_R3__________________        _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR

#define _________________ADJUST_L1_________________        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI
#define _________________ADJUST_L2_________________        RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD
#define _________________ADJUST_L3_________________        _______, _______, _______, _______, _______

#define _________________ADJUST_R1_________________        AU_TOG,  _______, _______, _______, _______
#define _________________ADJUST_R2_________________        MU_TOG,  _______, _______, _______, KC_SINS
#define _________________ADJUST_R3_________________        CK_TOGG, _______, _______, _______, _______

#define __________________VIM_L1___________________        _______, _______, _______, _______, _______
#define __________________VIM_L2___________________        _______, _______, KC_PGDN, _______, _______
#define __________________VIM_L3___________________        _______, _______, _______, _______, _______

#define __________________VIM_R1___________________        _______, KC_PGUP, _______, _______, _______
#define __________________VIM_R2___________________        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______
#define __________________VIM_R3___________________        _______, _______, _______, _______, _______

#define _________________MOUSE_L1__________________        _______, _______, _______, _______, _______
#define _________________MOUSE_L2__________________        _______, _______, KC_WH_D, _______, _______
#define _________________MOUSE_L3__________________        _______, _______, _______, _______, _______

#define _________________MOUSE_R1__________________        _______, KC_WH_U, _______, _______, _______
#define _________________MOUSE_R2__________________        KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______
#define _________________MOUSE_R3__________________        _______, KC_BTN1, KC_BTN3, KC_BTN2, _______

#define _________________NUMPAD_R1_________________        _______,    KC_7,    KC_8,    KC_9, _______
#define _________________NUMPAD_R2_________________        _______,    KC_4,    KC_5,    KC_6, _______
#define _________________NUMPAD_R3_________________           KC_0,    KC_1,    KC_2,    KC_3, KC_DOT
