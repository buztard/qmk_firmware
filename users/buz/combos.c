#include "buz.h"

bool no_combo_layer;

enum combos {
    WE_ESC,
    SD_TAB,
    IO_ENT,
    KL_BSPC,
    COMBO_IE,
    COMBO_XC,
    COMBO_FJ,
    COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {LALT_T(KC_S), LCTL_T(KC_D), COMBO_END};
const uint16_t PROGMEM kl_combo[] = {RCTL_T(KC_K), LALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM ie_combo[] = {KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, LT(_TMUX, KC_C), COMBO_END};
const uint16_t PROGMEM fj_combo[] = {LSFT_T(KC_F), RSFT_T(KC_J), COMBO_END};

// clang-format off
combo_t key_combos[] = {
    [WE_ESC]      = COMBO(we_combo, KC_ESC),
    [IO_ENT]      = COMBO(io_combo, KC_ENT),
    [SD_TAB]      = COMBO(sd_combo, KC_TAB),
    [KL_BSPC]     = COMBO(kl_combo, KC_BSPC),
    [COMBO_IE]    = COMBO(ie_combo, IFERR),
    [COMBO_XC]    = COMBO(xc_combo, LCTL(KC_SPACE)),
    [COMBO_FJ]    = COMBO(fj_combo, CAPS_WORD),
};

// disable combos on some layers, especially symbol pairs like () are sometimes typed too fast.
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  return !no_combo_layer;
}
