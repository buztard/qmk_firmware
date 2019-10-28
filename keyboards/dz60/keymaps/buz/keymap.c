#include QMK_KEYBOARD_H
#include "buz.h"

#define _QWERTY 0
#define _FN 1
#define _ADJUST 2
#define _MOUSE 3

#define L_FN MO(_FN)
#define L_ADJ MO(_ADJUST)
#define L_MS MO(_MOUSE)

/**
 * Notes:
 * This layer doesn't abuse the grave key as escape. Escape is combined with
 * ctrl on the CapsLock key.
 *
 * The fn layer contains some keys for Vim style navigation:
 * - HJKL arrow keys
 * - <C-d> <C-u> as well as <C-f> <C-b> for PGDOWN and PGUP
 * - TODO: gg and G
 *
 * I'm not yet sure whether to an ANSI or ISO layout. I'll try both and decide later on.
 */


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
    [_QWERTY] = LAYOUT_all(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC,
      KC_TABMS,KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
      KC_CESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSPO, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, KC_RSPC, L_ADJ,
      L_MS,    KC_LGUI, KC_LALT,          KC_GENT,          L_FN,             KC_SPC,         KC_O_RALT, KC_RGUI, XXXXXXX, KC_APP,  KC_RCTL
    ),

    [_FN] = LAYOUT_all(
      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
      _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_INS,  _______, _______, _______, _______, _______,
      KC_CAPS, _______, _______, KC_PGDN, KC_PGUP, KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SINS, _______, _______,
      _______, _______, _______, KC_DEL,  _______, KC_END,  KC_PGUP, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_all(
      _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, _______, _______, _______, _______,
      _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
      _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_MOUSE] = LAYOUT_all(
      _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, KC_WH_U, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, KC_WH_D, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______, _______, _______, _______
    ),
};

#ifdef RAW_ENABLE
void raw_hid_receive(uint8_t *data, uint8_t length)
{
	uint8_t *command_id = &(data[0]);
  uint8_t r, g, b, led;

  switch (*command_id) {
    case 0x01:
      rgblight_disable_noeeprom();
      break;

    case 0x02:
      rgblight_enable_noeeprom();
      break;

    case 0x11:
      rgblight_mode_noeeprom(data[1]);
      break;

    case 0x12:
      r = data[1];
      g = data[2];
      b = data[3];
      rgblight_enable_noeeprom();
      /* rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); */
      rgblight_setrgb(r, g, b);
      break;

    case 0x13:
      r = data[1];
      g = data[2];
      b = data[3];
      led = data[4];
      /* rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); */
      rgblight_setrgb_at(r, g, b, led);
      break;

    case 0x14:
    default:
      break;
  }

  // Return the same data again.
  /* raw_hid_send(data, length); */
}
#endif
