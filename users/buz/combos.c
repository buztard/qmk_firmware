#include "buz.h"

#define COMBO_ONLY_FROM_LAYER _QWERTY

enum combos {
    WE_TAB,
    IO_BSPC,
    SD_ESC,
    KL_ENT,
    JK_SFT,
    DF_SFT,
    FJ_CAPS,
    THUMB_CAPS,
    COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {LALT_T(KC_S), LCTL_T(KC_D), COMBO_END};
const uint16_t PROGMEM kl_combo[] = {RCTL_T(KC_K), LALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM jk_combo[] = {RSFT_T(KC_J), RCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM df_combo[] = {LCTL_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM fj_combo[] = {LSFT_T(KC_F), RSFT_T(KC_J), COMBO_END};

// clang-format off
combo_t key_combos[] = {
    [WE_TAB]     = COMBO(we_combo, KC_TAB),
    [SD_ESC]     = COMBO(sd_combo, KC_ESC),
    [IO_BSPC]    = COMBO(io_combo, KC_BSPC),
    [KL_ENT]     = COMBO(kl_combo, KC_ENT),
    [JK_SFT]     = COMBO(jk_combo, OSM(MOD_LSFT)),
    [DF_SFT]     = COMBO(df_combo, OSM(MOD_LSFT)),
    [FJ_CAPS]    = COMBO(fj_combo, CAPS_WORD),
};
