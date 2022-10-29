#pragma once
#include "quantum.h"
#include "flavors.h"

#ifdef OLED_ENABLE
#    include "oled_stuff.h"
#endif

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#    include "rgb.h"
#endif

#ifdef TAP_DANCE_ENABLE
#    include "tap_dances.h"
#    define KC_TD_LALT TD(TD_LALT)
#    define KC_TD_RALT TD(TD_RALT)
#else
#    define KC_TD_LALT OSM(MOD_LALT)
#    define KC_TD_RALT OSM(MOD_RALT)
#endif

#ifdef ENCODER_ENABLE
#    include "encoder_stuff.h"
#endif

#ifdef POINTING_DEVICE_ENABLE
#    include "pointing.h"
#endif

#ifdef ACHORDION_ENABLE
#    include "achordion.h"
#endif

#define LEADER_NO_TIMEOUT
#define LEADER_TIMEOUT 500
#define LEADER_PER_KEY_TIMING

layer_state_t layer_state_set_keymap(layer_state_t state);

typedef union {
    uint32_t raw;
    struct {
        bool rgb_layer_change : 1;
        bool oled_enabled : 1;
        bool unslsh : 1;
    };
} userspace_config_t;

extern userspace_config_t userspace_config;

enum userspace_layers {
    _QWERTY = 0,
    _COLEMAK,
    _GAME,
    _SYMBOL,
    _LOWER,
    _RAISE,
    _VIM,
    _NUM,
    _ADJUST,
    _MOUSE,
    _MEDIA,
    _EXTRA,
    _TMUX,
    _FUNC,
    _USER_LAYER_LAST,
};

enum userspace_custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    LOWER,
    RAISE,
    TMUX_PREFIX, // tmux prefix key
    TMUX_WN,     // next tmux window
    TMUX_WP,     // prev tmux window
    TMUX_PN,     // next tmux pane
    TMUX_PP,     // prev tmux pane
    TMUX_PL,     // left tmux pane
    TMUX_PR,     // right tmux pane
    TMUX_PU,     // upper tmux pane
    TMUX_PD,     // lower tmux pane
    MAKE,        // compile/flash qmk
    RGB_LYR,     // toggle rgb layer indication
    OLED,        // toggle oled display
    // CAPS_WORD,     // caps word
    ENC_0,         // first rotary encoder press
    ENC_1,         // second rotary encoder press
    MUSCLE_ROCKET, // work stuff
    LAYER_LOCK,    // toggle layer lock
    REPEAT,        // repeat the last keycode
    UNSLSH,        // underscore slash
    UNSLSTOG,
    SELF,
    EMOJI,
    MOUSE_AUTO_LAYER,
    MOUSE_ACCEL,
    MOUSE_LOCK,
    MOUSE_SCROLL,
    IFERR,
    IFERE,
    IFERNE,
    TABLEFLIP,
    FINGER,
    SHRUG,
    USER_SAFE_RANGE,
};

#define ADJUST MO(_ADJUST)
#define MOUSE MO(_MOUSE)
#define VIM MO(_VIM)
#define NUM MO(_NUM)
#define GAME DF(_GAME)

// Ugly workaround for shifted mod taps. It's used for space cadet keys shift
// keys, but works better for shifting other mod-tapped keys.
#define LSPO LSFT_T(KC_NO)
#define RSPC RSFT_T(KC_NO)

#define KC_CESC LCTL_T(KC_ESC)
#define KC_CSPC LCTL_T(KC_SPC)
#define KC_CQUOT RCTL_T(KC_QUOT)
#define KC_GENT LGUI_T(KC_ENT)
#define CTL_ESC CTL_T(KC_ESC)
#define GUI_ENT LGUI_T(KC_ENT)

#define KC_TABMS LT(_MOUSE, KC_TAB)
#define KC_Z_VIM LT(_VIM, KC_Z)
#define KC_X_NUM LT(_NUM, KC_X)
#define KC_O_LALT OSM(MOD_LALT)
#define KC_O_RALT OSM(MOD_RALT)
#define KC_SINS LSFT(KC_INSERT)
#define KC_EURO ALGR(KC_5)

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

// clang-format off
#define ___________________BLANK___________________        _______, _______, _______, _______, _______

#define _________________QWERTY_L1_________________        LT(_MOUSE, KC_Q), KC_W,           KC_E,             KC_R,           KC_T
#define _________________QWERTY_L2_________________        LGUI_T(KC_A),     LALT_T(KC_S),   LCTL_T(KC_D),     LSFT_T(KC_F),   LT(_FUNC, KC_G)
#define _________________QWERTY_L3_________________        RALT_T(KC_Z),     KC_X,   LT(_TMUX, KC_C),  LT(_VIM, KC_V), LT(_MEDIA, KC_B)

#define _________________QWERTY_R1_________________        KC_Y,            KC_U,           KC_I,            KC_O,           KC_P
#define _________________QWERTY_R2_________________        LT(_FUNC, KC_H), RSFT_T(KC_J),   RCTL_T(KC_K),    LALT_T(KC_L),   LGUI_T(KC_SCLN)
#define _________________QWERTY_R3_________________        KC_N,            LT(_VIM, KC_M), KC_COMM,         KC_DOT,         RALT_T(KC_SLASH)

#define _________________XWERTY_L1_________________        LT(_MOUSE, KC_Q), KC_W,           KC_E,             KC_R,           KC_T
#define _________________XWERTY_L2_________________        KC_A,             LALT_T(KC_S),   LCTL_T(KC_D),     LSFT_T(KC_F),   LT(_FUNC, KC_G)
#define _________________XWERTY_L3_________________        LGUI_T(KC_Z),     RALT_T(KC_X),   LT(_TMUX, KC_C),  LT(_VIM, KC_V), LT(_MEDIA, KC_B)

#define _________________XWERTY_R1_________________        KC_Y,            KC_U,           KC_I,               KC_O,           KC_P
#define _________________XWERTY_R2_________________        LT(_FUNC, KC_H), RSFT_T(KC_J),   RCTL_T(KC_K),       LALT_T(KC_L),   KC_SCLN
#define _________________XWERTY_R3_________________        KC_N,            LT(_VIM, KC_M), LT(_TMUX, KC_COMM), RALT_T(KC_DOT), RGUI_T(KC_SLASH)

// game layer is a query layer without mod taps
#define __________________GAME_L1__________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define __________________GAME_L2__________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define __________________GAME_L3__________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define __________________GAME_R1__________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define __________________GAME_R2__________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define __________________GAME_R3__________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________COLEMAK_L1________________        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________        LSFT_T(KC_A),    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________        KC_Z_VIM,KC_X_NUM,KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________        KC_H,    KC_N,    KC_E,    KC_I,    RSFT_T(KC_O)
#define _________________COLEMAK_R3________________        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________COLEMAK_DHM_L1____________        LT(_MOUSE, KC_Q),    KC_W,    KC_F,    KC_P,    KC_B
#define _________________COLEMAK_DHM_L2____________        LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), LT(_FUNC, KC_G)
#define _________________COLEMAK_DHM_L3____________        RALT_T(KC_Z), KC_X, LT(_TMUX, KC_C), LT(_VIM, KC_D),    LT(_MEDIA, KC_V)

#define _________________COLEMAK_DHM_R1____________        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_DHM_R2____________        LT(_FUNC, KC_M), RSFT_T(KC_N), RCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O)
#define _________________COLEMAK_DHM_R3____________        KC_K,    KC_H,    KC_COMM, KC_DOT,  RALT_T(KC_SLASH)

#define ________________NUMBER_LEFT________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define _________________FUNC_LEFT_________________        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define _________________LOWER_L1__________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L2__________________        _________________FUNC_LEFT_________________
#define _________________LOWER_L3__________________        _________________FUNC_RIGHT________________

#define _________________LOWER_R1__________________        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define _________________LOWER_R2__________________        KC_F11,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR
#define _________________LOWER_R3__________________        KC_F12,  KC_INS,  KC_DQT,  KC_LBRC, KC_RBRC

#define _________________RAISE_L1__________________        ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________        KC_ESC,  KC_MINS, KC_PLUS, KC_PGUP, KC_HOME
#define _________________RAISE_L3__________________        KC_TAB,  KC_EXLM, KC_VOLD, KC_PGDN, KC_END

#define _________________RAISE_R1__________________        ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________        KC_DQT,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define _________________RAISE_R3__________________        KC_QUOT, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR
// #define _________________RAISE_R3__________________        TMUX_WP, TMUX_WN, KC_DQT,  KC_LCBR, KC_RCBR

#define _________________ADJUST_L1_________________        RGB_TOG,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI
#define _________________ADJUST_L2_________________        RGB_MOD,  RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD
#define _________________ADJUST_L3_________________        UNSLSTOG, QK_BOOT, EEP_RST, KC_SLEP, KC_WAKE

#define _________________ADJUST_R1_________________        AU_TOG,  QWERTY,  KC_BRIU, OLED,    CMB_TOG
#define _________________ADJUST_R2_________________        MU_TOG,  COLEMAK, KC_BRID, RGB_LYR, KC_SINS
#define _________________ADJUST_R3_________________        CK_TOGG, MAKE,    DEBUG,   GAME,    QK_RBT

#define __________________VIM_L1___________________         KC_TAB, _______, _______, _______, _______
#define __________________VIM_L2___________________         KC_ESC, KC_TAB,  KC_PGDN, KC_PGUP, KC_HOME
#define __________________VIM_L3___________________        _______, _______, _______, KC_PGDN, KC_END

#define __________________VIM_R1___________________        _______, KC_PGUP, _______, _______, KC_DEL
#define __________________VIM_R2___________________        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC
#define __________________VIM_R3___________________        _______, _______, _______, _______, _______

#define _________________MOUSE_L1__________________        _______, MOUSE_SCROLL, MOUSE_ACCEL,  MOUSE_LOCK,   MOUSE_AUTO_LAYER
#define _________________MOUSE_L2__________________        _______, _______,      KC_WH_D,      _______,      _______
#define _________________MOUSE_L3__________________        _______, _______,      KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2

#define _________________MOUSE_R1__________________        KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______
#define _________________MOUSE_R2__________________        KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______
#define _________________MOUSE_R3__________________        _______, KC_BTN1, KC_BTN3, KC_BTN2, _______

#define _________________NUMPAD_L1_________________           KC_1,    KC_2,    KC_3,    KC_4, KC_5
#define _________________NUMPAD_L2_________________         KC_ESC,  KC_TAB, _______, KC_PGUP, KC_HOME 
#define _________________NUMPAD_L3_________________         KC_TAB, _______, _______, KC_PGDN, KC_END  

#define _________________NUMPAD_R1_________________           KC_6,    KC_7,    KC_8,    KC_9, KC_0
#define _________________NUMPAD_R2_________________        KC_BSPC,    KC_1,    KC_2,    KC_3, KC_0
#define _________________NUMPAD_R3_________________           KC_X,    KC_4,    KC_5,    KC_6, KC_DOT

#define _________________MEDIA_L1__________________        _______, _______, _______, _______, _______
#define _________________MEDIA_L2__________________        _______, _______, _______, KC_BRIU, _______
#define _________________MEDIA_L3__________________        _______, _______, _______, KC_BRID, _______

#define _________________MEDIA_R1__________________        KC_MSEL, XXXXXXX, KC_MSTP, XXXXXXX, KC_MPLY
#define _________________MEDIA_R2__________________        KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______
#define _________________MEDIA_R3__________________        KC_EJCT, KC_MUTE, KC_MRWD, KC_MFFD, _______

#define __________________PROG_L1__________________        _______, _______, _______, KC_LCBR, _______
#define __________________PROG_L2__________________        _______, _______, _______, KC_LPRN, _______
#define __________________PROG_L3__________________        _______, _______, _______, KC_LBRC, _______

#define __________________PROG_R1__________________        _______, KC_RCBR, _______, _______, _______
#define __________________PROG_R2__________________        _______, KC_RPRN, _______, _______, _______
#define __________________PROG_R3__________________        _______, KC_RBRC, _______, _______, _______

#define _________________EXTRA_L1__________________        KC_TAB,  KC_TILD, _______, _______, _______
#define _________________EXTRA_L2__________________        KC_ESC,  KC_GRV,  _______, _______, _______
#define _________________EXTRA_L3__________________        _______, _______, _______, _______, _______

#define _________________EXTRA_R1__________________        KC_LT,   KC_LCBR, KC_RCBR, _______, _______
#define _________________EXTRA_R2__________________        KC_BSPC, KC_LPRN, KC_RPRN, KC_DQT,  KC_QUOT
#define _________________EXTRA_R3__________________        KC_GT,   KC_LBRC, KC_RBRC, KC_PIPE, KC_BSLS

#define _________________SYMBOL_L1_________________        KC_GRV,  KC_LT,   KC_GT,   KC_DQT,   KC_DOT
#define _________________SYMBOL_L2_________________        KC_EXLM, KC_MINS, KC_PLUS, KC_EQL,  KC_HASH
#define _________________SYMBOL_L3_________________        KC_TILD, KC_AT,   KC_ASTR, KC_BSLS, KC_COMM

#define _________________SYMBOL_R1_________________        KC_AMPR, KC_QUOT, KC_LBRC, KC_RBRC, KC_PERC
#define _________________SYMBOL_R2_________________        KC_PIPE, KC_UNDS, KC_LPRN, KC_RPRN, KC_COLN
#define _________________SYMBOL_R3_________________        KC_CIRC, KC_DLR,  KC_LCBR, KC_RCBR, KC_ENT

#define __________________FUNC_L1__________________        KC_TAB,  TABLEFLIP, IFERR,   _______, _______
#define __________________FUNC_L2__________________        KC_ESC,  SHRUG, IFERE,   _______, CAPS_WORD
#define __________________FUNC_L3__________________        MUSCLE_ROCKET, FINGER, IFERNE,  _______, _______

#define __________________FUNC_R1__________________        C(KC_INS),   KC_F7,   KC_F8,   KC_F9, KC_F12
#define __________________FUNC_R2__________________        S(KC_INS),   KC_F4,   KC_F5,   KC_F6, KC_F11
#define __________________FUNC_R3__________________        S(KC_DEL),   KC_F1,   KC_F2,   KC_F3, KC_F10

#define __________________TMUX_L1__________________        ___________________BLANK___________________
#define __________________TMUX_L2__________________        ___________________BLANK___________________
#define __________________TMUX_L3__________________        ___________________BLANK___________________

#define __________________TMUX_R1__________________        _______, _______, _______, _______, _______
#define __________________TMUX_R2__________________        TMUX_PL, TMUX_PD, TMUX_PU, TMUX_PL, _______
#define __________________TMUX_R3__________________        _______, _______, TMUX_WP, TMUX_WN, _______

// clang-format on
