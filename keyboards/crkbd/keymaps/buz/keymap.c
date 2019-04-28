#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#include "buz.h"
#include "raw_hid.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

#ifdef RGB_MATRIX_ENABLE
extern rgb_config_t rgb_matrix_config;
#endif

extern uint8_t is_master;

enum custom_keycodes {
  RGBRST = USER_SAFE_RANGE,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_RST   RESET

#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LSPI  RGB_SPI
#define KC_LSPD  RGB_SPD
#define KC_LMOD  RGB_MOD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      TABMS,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       CESC,     A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCLN,  QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSPO, Z_VIM,     X,     C,     V,     B,                      N,     M,  COMM,   DOT,  SLSH,  RSPC,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                 O_LALT, LOWER,  GENT,      SPC, RAISE, O_RALT \
                              //`--------------------'  `--------------------'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
       TILD,  EXLM,    AT,  HASH,   DLR,  PERC,                   CIRC,  AMPR,  ASTR,  LPRN,  RPRN,   DEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____,                  _____,  UNDS,  PLUS,  LCBR,  RCBR,  PIPE,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       CAPS, _____, _____, _____, _____, _____,                  _____,  LCBR,  RBRC, _____, _____, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_RAISE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        GRV,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,   DEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____,  MSTP,  MNXT,  VOLU, _____,                  _____,  MINS,   EQL,  LBRC,  RBRC,  BSLS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       CAPS, _____,  MPLY,  MPRV,  VOLD, _____,                  _____,  LBRC,  RBRC,  LCBR,  RCBR, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        RST,  LRST, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX,     7,     8,     9, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI,  LSPI, XXXXX,                  XXXXX,     4,     5,     6,  SINS, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LMOD,  LHUD,  LSAD,  LVAD,  LSPD, XXXXX,                      0,     1,     2,     3,   DOT, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_VIM] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____, _____, _____, _____, _____, _____,                  _____,  PGUP, _____, _____, _____, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____,  PGDN, _____, _____,                   LEFT,  DOWN,    UP, RIGHT, _____, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____,                  _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_MOUSE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____, _____, _____, _____, _____, _____,                  _____,  WH_U, _____, _____, _____, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____,  WH_D, _____, _____,                   MS_L,  MS_D,  MS_U,  MS_R, _____, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____,                  _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,     BTN1,  BTN3,  BTN2 \
                              //`--------------------'  `--------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGBRST:
#ifdef RGBLIGHT_ENABLE
      if (record->event.pressed) {
        eeconfig_update_rgblight_default();
        rgblight_enable();
        RGB_current_mode = rgblight_config.mode;
      }
#endif
#ifdef RGB_MATRIX_ENABLE
      rgb_matrix_enable();
      rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
#endif
      return false;
  }
  return true;
}

#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_layer_helper (uint8_t red, uint8_t green, uint8_t blue, bool default_layer) {
  if (!rgb_matrix_config.enable) {
      return;
  }
  rgb_led led;
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    led = g_rgb_leds[i];
    if (led.matrix_co.raw < 0xFF) {
      if (led.modifier) {
          rgb_matrix_set_color( i, red, green, blue );
          /* rgblight_sethsv_at (i, h, s, v); */
      }
    }
  }
}

static int last = 0;

void rgb_matrix_indicators_user(void) {
  switch (biton32(layer_state)) {
    case _RAISE:
      rgb_matrix_layer_helper(0xFF, 0xFF, 0x00, false);
      break;
    case _LOWER:
      rgb_matrix_layer_helper(0x00, 0xFF, 0x00, false);
      break;
    case _ADJUST:
      rgb_matrix_layer_helper(0xFF, 0x00, 0x00, false);
      break;
    case _VIM:
      rgb_matrix_layer_helper(0x00, 0x00, 0xFF, false);
      break;
  }
  /* if (is_master && last < DRIVER_LED_TOTAL / 2) { */
  /*     rgb_matrix_set_color(last, 0, 255, 0); */
  /* } else if (!is_master && last >= DRIVER_LED_TOTAL / 2){ */
  /*     rgb_matrix_set_color(last - 27, 0, 255, 0); */
  /* } */
  /* rgb_matrix_set_color(last, 0, 255, 0); */
}
#endif

// OLED Driver Logic
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!has_usb())
    return OLED_ROTATION_180;  // flip 180 for offhand
  return rotation;
}

static void render_logo(void) {
  static const char PROGMEM logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
      0};

  /* static const char PROGMEM logo[] = { */
  /*   0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94, */
  /*   0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4, */
  /*   0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0}; */

  oled_write_P(logo, false);
}

#ifdef RGB_MATRIX_ENABLE
/* static char* itoa(int i, char b[]){ */
/*     char const digit[] = "0123456789"; */
/*     char* p = b; */
/*     if(i<0){ */
/*         *p++ = '-'; */
/*         i *= -1; */
/*     } */
/*     int shifter = i; */
/*     do{ //Move to where representation ends */
/*         ++p; */
/*         shifter = shifter/10; */
/*     }while(shifter); */
/*     *p = '\0'; */
/*     do{ //Move back, inserting digits as u go */
/*         *--p = digit[i%10]; */
/*         i = i/10; */
/*     }while(i); */
/*     return b; */
/* } */
static void render_effect(bool head) {
  oled_write_P(PSTR("\n"), false);
  if (head) {
    oled_write_P(PSTR("Effect: "), false);
  }
  if (!rgb_matrix_config.enable) {
    oled_write_P(PSTR("Disabled\n"), false);
    return;
  }

  switch (rgb_matrix_config.mode) {
    case RGB_MATRIX_NONE:
      oled_write_P(PSTR("None\n"), false);
      break;
    case RGB_MATRIX_SOLID_COLOR:
      oled_write_P(PSTR("Solid color\n"), false);
      break;
#ifndef DISABLE_RGB_MATRIX_ALPHAS_MODS
    case RGB_MATRIX_ALPHAS_MODS:
      oled_write_P(PSTR("Alpha mods\n"), false);
      break;
#endif
#ifndef DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    case RGB_MATRIX_GRADIENT_UP_DOWN:
      oled_write_P(PSTR("Gradient up/down\n"), false);
      break;
#endif
#ifndef DISABLE_RGB_MATRIX_BREATHING
    case RGB_MATRIX_BREATHING:
      oled_write_P(PSTR("Breathing\n"), false);
      break;
#endif
#ifndef DISABLE_RGB_MATRIX_CYCLE_ALL
    case RGB_MATRIX_CYCLE_ALL:
      oled_write_P(PSTR("Cycle all\n"), false);
      break;
#endif
#ifndef DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    case RGB_MATRIX_CYCLE_LEFT_RIGHT:
      oled_write_P(PSTR("Cycle left/right\n"), false);
      break;
#endif
#ifndef DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
    case RGB_MATRIX_CYCLE_UP_DOWN:
      oled_write_P(PSTR("Cycle up/down\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
#ifndef DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    case RGB_MATRIX_RAINBOW_MOVING_CHEVRON:
      oled_write_P(PSTR("Rb moving chevron\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#ifndef DISABLE_RGB_MATRIX_DUAL_BEACON
    case RGB_MATRIX_DUAL_BEACON:
      oled_write_P(PSTR("Dual beacon\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_DUAL_BEACON
#ifndef DISABLE_RGB_MATRIX_RAINBOW_BEACON
    case RGB_MATRIX_RAINBOW_BEACON:
      oled_write_P(PSTR("Rainbow beacon\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_RAINBOW_BEACON
#ifndef DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    case RGB_MATRIX_RAINBOW_PINWHEELS:
      oled_write_P(PSTR("Rainbow pinwheels\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#ifndef DISABLE_RGB_MATRIX_RAINDROPS
    case RGB_MATRIX_RAINDROPS:
      oled_write_P(PSTR("Raindrops\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_RAINDROPS
#ifndef DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    case RGB_MATRIX_JELLYBEAN_RAINDROPS:
      oled_write_P(PSTR("Jellybean rain\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#ifndef DISABLE_RGB_MATRIX_DIGITAL_RAIN
    case RGB_MATRIX_DIGITAL_RAIN:
      oled_write_P(PSTR("Digital rain\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_DIGITAL_RAIN
#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    case RGB_MATRIX_SOLID_REACTIVE_SIMPLE:
      oled_write_P(PSTR("Reactive simple\n"), false);
      break;
#endif
#ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE
    case RGB_MATRIX_SOLID_REACTIVE:
      oled_write_P(PSTR("Solid reactive\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_SOLID_REACTIVE
#ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    case RGB_MATRIX_SOLID_REACTIVE_WIDE:
      oled_write_P(PSTR("Reactive wide\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    case RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE:
      oled_write_P(PSTR("Reactive multiwide\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    case RGB_MATRIX_SOLID_REACTIVE_CROSS:
      oled_write_P(PSTR("Reactive cross\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    case RGB_MATRIX_SOLID_REACTIVE_MULTICROSS:
      oled_write_P(PSTR("Reactive multicross\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    case RGB_MATRIX_SOLID_REACTIVE_NEXUS:
      oled_write_P(PSTR("Reactive nexus\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    case RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS:
      oled_write_P(PSTR("Reactive multinexus\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#ifndef DISABLE_RGB_MATRIX_SPLASH
    case RGB_MATRIX_SPLASH:
      oled_write_P(PSTR("Splash\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_SPLASH
#ifndef DISABLE_RGB_MATRIX_MULTISPLASH
    case RGB_MATRIX_MULTISPLASH:
      oled_write_P(PSTR("Multisplash\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_MULTISPLASH
#ifndef DISABLE_RGB_MATRIX_SOLID_SPLASH
    case RGB_MATRIX_SOLID_SPLASH:
      oled_write_P(PSTR("Solid splash\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_SOLID_SPLASH
#ifndef DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
    case RGB_MATRIX_SOLID_MULTISPLASH:
      oled_write_P(PSTR("Solid multisplash\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif // RGB_MATRIX_KEYREACTIVE_ENABLED
    default:
      oled_write_P(PSTR("Unknown\n"), false);
      break;
  }
}
#endif

static void render_status(void) {
  // Render to mode icon
  /* static const char PROGMEM mode_logo[4][4] = { */
  /*   {0x95,0x96,0x0a,0}, */
  /*   {0xb5,0xb6,0x0a,0}, */
  /*   {0x97,0x98,0x0a,0}, */
  /*   {0xb7,0xb8,0x0a,0} }; */

  /* if (keymap_config.swap_lalt_lgui != false) { */
  /*   oled_write_P(mode_logo[0], false); */
  /*   oled_write_P(mode_logo[1], false); */
  /* } else { */
  /*   oled_write_P(mode_logo[2], false); */
  /*   oled_write_P(mode_logo[3], false); */
  /* } */

  oled_render_layer();
#ifdef RGBLIGHT_ENABLE
  render_rgblight_effect_name();
#endif // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
  render_rgb_matrix_effect_name();
#endif // RGB_MATRIX_ENABLE
}

void oled_task_user(void) {
  if (is_master)
    render_status();
  else
    render_logo();
}

#endif

#ifdef RAW_ENABLE
enum crkbd_command_id {
  id_get_protocol_version = 0x01,  // always 0x01
  id_matrix_get_mode,
  id_matrix_set_mode,
  id_oled_set_text,

  id_unhandled = 0xFF,
};

void raw_hid_receive(uint8_t *data, uint8_t length) {
  uint8_t *command_id = &(data[0]);

  switch (*command_id) {
    case id_get_protocol_version:
      break;

    case id_matrix_get_mode:
      break;

    case id_matrix_set_mode:
      break;

    case id_oled_set_text:
      break;

    default:
      break;
    case _VIM:
      oled_write_P(PSTR("Vim    \n"), false);
      break;
    case _MOUSE:
      oled_write_P(PSTR("Mouse  \n"), false);
      break;
    default:
      oled_write_P(PSTR("Unknown\n"), false);
      break;
  }
  // Return same buffer with values changed
  raw_hid_send(data, length);
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _LOWER:
      last++;
      if (last >= DRIVER_LED_TOTAL) {
        last = 0;
      }
      break;
  }
  return state;
}
