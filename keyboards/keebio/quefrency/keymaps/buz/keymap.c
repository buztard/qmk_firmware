#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN 1
#define _ADJUST 2
#define _MOUSE 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define KC_CESC LCTL_T(KC_ESC)
#define KC_CTAB LCTL_T(KC_TAB)
#define KC_CENT LGUI_T(KC_ENT)
#define KC_SINS LSFT(KC_INSERT)

#define KC_OGUI OSM(MOD_LGUI)
#define KC_OALT OSM(MOD_RALT)

#define L_FN MO(_FN)
#define L_ADJ MO(_ADJUST)
#define L_MS MO(_MOUSE)

/**
 * QWERTY ansi
 * ,-----------------------------------------------------------------------------------------.
 * | `   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 0   | -   | =   | Backspace |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    | Q   | W   | E   | R   | T   | Y   | U   | I   | O   | P   | [   | ]   |  \     |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl/Esc | A   | S   | D   | F   | G   | H   | J   | K   | L   | ;   | '   | Enter      |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     | Z   | X   | C   | V   | B   | N   | M   | ,   | .   | /   |   Shift   | Fn3 |
 * |-----------------------------------------------------------------------------------------+
 * | Fn2  | Alt  | Gui  |  Ctrl/Enter  |  Fn  |      Space      | RAlt | Gui  | Fn3  | Ctrl  |
 * `-----------------------------------------------------------------------------------------'
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC,
    KC_CTAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, L_ADJ,
    L_MS,    KC_OGUI, KC_LALT, KC_CENT, LT(_FN, KC_ENT),  KC_SPC,  KC_NO,   KC_OALT, KC_RGUI, KC_NO,   KC_APP,  OSM(MOD_RCTL)
  ),

  [_FN] = LAYOUT(
    KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_INS,  _______, _______, _______, _______, RESET,
    KC_CAPS, _______, _______, KC_PGDN, KC_PGUP, KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SINS, _______, _______,
    _______, _______, KC_DEL,  _______, KC_END,  KC_PGUP, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT(
    _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, _______, _______, _______, _______,
    _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
    _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_MOUSE] = LAYOUT(
    _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_WH_U, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_WH_D, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______, _______, _______, _______, _______
  ),
};
