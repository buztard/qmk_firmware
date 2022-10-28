#include "cocot46plus/cocot46plus.h"
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"
#include "buz.h"


// Defines names for use in layer keycodes and the keymap
// enum layer_number {
//     _BASE = 0,
//     _LOWER = 1,
//     _RAISE = 2,
//     _TRACKBALL = 3
// };


#define TH_LI LT(_NUM, KC_ESC)
#define TH_LH LT(_SYMBOL, KC_ENT)
#define TH_RH LT(_SYMBOL, KC_SPC)
#define TH_RI LT(_NUM, KC_BSPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
       KC_TABMS, _________________QWERTY_L1_________________,                                    _________________QWERTY_R1_________________,  KC_BSPC,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
 LCTL_T(KC_ESC), _________________QWERTY_L2_________________,                                    _________________QWERTY_R2_________________, RCTL_T(KC_QUOT),
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
  OSM(MOD_LSFT), _________________QWERTY_L3_________________,                                    _________________QWERTY_R3_________________, OSM(MOD_RSFT),
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        SCRL_SW, SCRL_MO, TH_LI,  TH_LH, KC_MS_BTN1,                     KC_MS_BTN2,  TH_RH, TH_RI, KC_TAB, XXXXXXX,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDOWN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),

  [_COLEMAK] = LAYOUT_wrapper(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
       KC_TABMS, _________________COLEMAK_DHM_L1____________,                                    _________________COLEMAK_DHM_R1____________, KC_BSPC,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
 LCTL_T(KC_ESC), _________________COLEMAK_DHM_L2____________,                                    _________________COLEMAK_DHM_R2____________, RCTL_T(KC_QUOT),
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
  OSM(MOD_LSFT), _________________COLEMAK_DHM_L3____________,                                    _________________COLEMAK_DHM_R3____________, OSM(MOD_RSFT),
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        XXXXXXX, XXXXXXX, TH_LI,  TH_LH, KC_MS_BTN1,                     KC_MS_BTN2,  TH_RH, TH_RI, KC_TAB,  XXXXXXX,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDOWN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),

  [_SYMBOL] = LAYOUT_wrapper(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, _________________SYMBOL_L1_________________,                                    _________________SYMBOL_R1_________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, _________________SYMBOL_L2_________________,                                    _________________SYMBOL_R2_________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, _________________SYMBOL_L3_________________,                                    _________________SYMBOL_R3_________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______, _______,  KC_TAB,  _______,              _______, KC_SPC,  _______, _______,  _______,
                                                                 _______, _______,  _______, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),

  [_NUM] = LAYOUT_wrapper(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, _________________NUMPAD_L1_________________,                                    _________________NUMPAD_R1_________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, _________________NUMPAD_L2_________________,                                    _________________NUMPAD_R2_________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, _________________NUMPAD_L3_________________,                                    _________________NUMPAD_R3_________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______, ADJUST,   _______,  _______,             _______,  _______, _______, _______,  _______,
                                                                 _______, _______,  _______, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),

  [_VIM] = LAYOUT_wrapper(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, __________________VIM_L1___________________,                                    __________________VIM_R1___________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, __________________VIM_L2___________________,                                    __________________VIM_R2___________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, __________________VIM_L3___________________,                                    __________________VIM_R3___________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______, _______,  _______,   _______,             _______,  _______, _______, _______,  _______,
                                                                 KC_UP, _______,  KC_DOWN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),

  [_MEDIA] = LAYOUT_wrapper(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, _________________MEDIA_L1__________________,                                    _________________MEDIA_R1__________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, _________________MEDIA_L2__________________,                                    _________________MEDIA_R2__________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, _________________MEDIA_L3__________________,                                    _________________MEDIA_R3__________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______, _______,  _______,   _______,             _______,  _______, _______, _______,  _______,
                                                                 KC_VOLD, _______,  KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),

  [_TMUX] = LAYOUT_wrapper(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, __________________TMUX_L1__________________,                                    __________________TMUX_R1__________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, __________________TMUX_L2__________________,                                    __________________TMUX_R2__________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, __________________TMUX_L3__________________,                                    __________________TMUX_R3__________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______, _______,  _______,   _______,             _______,  _______, _______, _______,  _______,
                                                                 TMUX_WP, _______,  TMUX_WN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),

  [_FUNC] = LAYOUT_wrapper(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, __________________FUNC_L1__________________,                                    __________________FUNC_R1__________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, __________________FUNC_L2__________________,                                    __________________FUNC_R2__________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, __________________FUNC_L3__________________,                                    __________________FUNC_R3__________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______, _______,  _______,   _______,             _______,  _______, _______, _______,  _______,
                                                                 _______, _______,  _______, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),

  [_MOUSE] = LAYOUT_wrapper(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, _________________MOUSE_L1__________________,                                    _________________MOUSE_R1__________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, _________________MOUSE_L2__________________,                                    _________________MOUSE_R2__________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, _________________MOUSE_L3__________________,                                    _________________MOUSE_R3__________________, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______, _______,  _______,   _______,             KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, _______,  _______,
                                                                 _______, _______,  _______, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),

  [_ADJUST] = LAYOUT_wrapper(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, _________________ADJUST_L1_________________,                                    SCRL_TO, QWERTY,  CPI_SW,  SCRL_SW, ROT_L15, ROT_R15,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, _________________ADJUST_L2_________________,                                    SCRL_MO, COLEMAK, _______, _______, _______, CMB_TOG,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        _______, _________________ADJUST_L3_________________,                                    SCRL_IN, MAKE,    _______, _______, _______, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______, _______,  _______,   _______,             _______,  _______, _______, _______,  _______,
                                                                 _______, _______,  _______, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    )

  //[_TRACKBALL] = LAYOUT(
  ////|-------------------------------------------------------|                                   |-------------------------------------------------------|
  //    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                                       SCRL_TO,  CPI_SW, SCRL_SW, ROT_L15, ROT_R15, XXXXXXX,
  ////|-------------------------------------------------------|                                   |-------------------------------------------------------|
  //    XXXXXXX, XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,                                       SCRL_MO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  ////|-------------------------------------------------------|                                   |-------------------------------------------------------|
  //    XXXXXXX, XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD,RGB_RMOD,                                       SCRL_IN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  ////|-------------------------------------------------------|                                   |-------------------------------------------------------|
  //                      KC_LGUI, DEL_ALT, KC_TRNS,  KC_SPC,   KC_MS_BTN1,             KC_MS_BTN2,  KC_ENT, RS_HENK, KC_BSPC,  KC_ESC,
  //                                                               KC_PGUP, KC_MS_BTN3,  KC_PGDOWN, XXXXXXX, XXXXXXX, XXXXXXX
  //                                                          //`--------------'  `--------------'
  //  )
};

keyevent_t encoder1_ccw = {
    .key = (keypos_t){.row = 4, .col = 2},
    .pressed = false
};

keyevent_t encoder1_cw = {
    .key = (keypos_t){.row = 4, .col = 5},
    .pressed = false
};

bool encoder_update_keymap(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            encoder1_cw.pressed = true;
            encoder1_cw.time = (timer_read() | 1);
            action_exec(encoder1_cw);
        } else {
            encoder1_ccw.pressed = true;
            encoder1_ccw.time = (timer_read() | 1);
            action_exec(encoder1_ccw);
        }
    }

    return false;
}


void matrix_scan_user(void) {

    if (IS_PRESSED(encoder1_ccw)) {
        encoder1_ccw.pressed = false;
        encoder1_ccw.time = (timer_read() | 1);
        action_exec(encoder1_ccw);
    }

    if (IS_PRESSED(encoder1_cw)) {
        encoder1_cw.pressed = false;
        encoder1_cw.time = (timer_read() | 1);
        action_exec(encoder1_cw);
    }

}


/*
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    int8_t degree = 45;
    int8_t x_rev, y_rev;
    x_rev =  + mouse_report.x * cos(degree) + mouse_report.y * sin(degree);
    y_rev =  - mouse_report.x * sin(degree) + mouse_report.y * cos(degree);
    if (isScrollMode) {
        mouse_report.h = x_rev;
        #ifdef COCOT_DRAGSCROLL_INVERT
                // Invert vertical scroll direction
                mouse_report.v = -y_rev;
        #else
                mouse_report.v = y_rev;
        #endif
        // mouse_report.v = y_rev;
        mouse_report.x = 0;
        mouse_report.y = 0;
    } else {
        mouse_report.x = x_rev;
        mouse_report.y = y_rev;
    }
    return mouse_report;
}
*/

// int hue_fst = -1;
// int sat_fst = -1;
// int val_fst = -1;


// layer_state_t layer_state_set_user(layer_state_t state) {
//     hue_fst = rgblight_get_hue();
//     sat_fst = rgblight_get_sat();
//     val_fst = rgblight_get_val();

//     switch (get_highest_layer(state)) {
//     case _LOWER:
//         rgblight_sethsv_range(HSV_BLUE, 0, 2);
//         cocot_set_scroll_mode(true);
//         break;
//     case _RAISE:
//         rgblight_sethsv_range(HSV_RED, 0, 2);
//         cocot_set_scroll_mode(true);
//         break;
//     case _TRACKBALL:
//         rgblight_sethsv_range(HSV_GREEN, 0, 2);
//         cocot_set_scroll_mode(false);
//         break;
//     default:
//         // rgblight_sethsv_range( 0, 0, 0, 0, 2);
//         rgblight_sethsv_range(hue_fst, sat_fst, val_fst, 0, 2);
//         cocot_set_scroll_mode(false);
//         break;
//     }
//     rgblight_set_effect_range( 2, 10);
//   return state;
// };

layer_state_t layer_state_set_keymap(layer_state_t state) {
#if 0
  switch (get_highest_layer(state)) {
    case _QWERTY:
    case _COLEMAK:
      set_auto_mouse_enable(true);
      break;
    default:
      state = remove_auto_mouse_layer(state, false);
      set_auto_mouse_enable(false);
      break;
  }
#endif
  if (IS_LAYER_ON_STATE(state, _SYMBOL)) {
    cocot_set_scroll_mode(true);
  } else {
    cocot_set_scroll_mode(false);
  }
  return state;
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_logo();
    oled_write_layer_state();
    return false;
}
#endif

