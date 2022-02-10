#include "buz.h"

enum combos {
    WE_TAB,
    IO_BSPC,
    JK_ESC,
    COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM jk_combo[] = {LSFT_T(KC_J), LCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};

combo_t key_combos[] = {
    [JK_ESC]  = COMBO(jk_combo, KC_ESC),
    [WE_TAB]  = COMBO(we_combo, KC_TAB),
    [IO_BSPC] = COMBO(io_combo, KC_BSPC),
};
