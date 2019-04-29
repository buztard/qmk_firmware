#include "buz.h"

#if defined(RGBLIGHT_ENABLE)
extern rgblight_config_t rgblight_config;
bool has_initialized;
#elif defined(RGB_MATRIX_ENABLE)
extern rgb_config_t rgb_matrix_config;
#endif

void layer_state_set_rgb(uint32_t state) {
  switch (biton32(state)) {
    case _LOWER:
      break;
    case _RAISE:
      break;
    case _ADJUST:
      break;
  }
}

#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_layer_helper_rgb (uint8_t red, uint8_t green, uint8_t blue, bool default_layer) {
  rgb_led led;
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    led = g_rgb_leds[i];
    if (led.matrix_co.raw < 0xFF) {
      if (led.modifier) {
          rgb_matrix_set_color(i, red, green, blue);
      }
    }
  }
}

void rgb_matrix_layer_helper_hsv (uint16_t hue, uint8_t sat, uint8_t val, bool default_layer) {
}

void rgb_matrix_indicators_user(void) {
  if (!rgb_matrix_config.enable) {
      return;
  }
  switch (biton32(layer_state)) {
    case _RAISE:
      rgb_matrix_layer_helper_rgb(0xFF, 0xFF, 0x00, false);
      break;
    case _LOWER:
      rgb_matrix_layer_helper_rgb(0x00, 0xFF, 0x00, false);
      break;
    case _ADJUST:
      rgb_matrix_layer_helper_rgb(0xFF, 0x00, 0x00, false);
      break;
    case _VIM:
      rgb_matrix_layer_helper_rgb(0x00, 0x00, 0xFF, false);
      break;
  }
}
#endif // RGB_MATRIX_ENABLE