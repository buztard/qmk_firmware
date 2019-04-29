#include "buz.h"

#ifdef OLED_DRIVER_ENABLE
void oled_render_layer(void) {
  oled_write_P(PSTR("Layer: "), false);

  switch (biton32(layer_state)) {
    case _QWERTY:
      oled_write_P(PSTR("Default\n"), false);
      break;
    case _LOWER:
      oled_write_P(PSTR("Lower  \n"), false);
      break;
    case _RAISE:
      oled_write_P(PSTR("Raise  \n"), false);
      break;
    case _ADJUST:
      oled_write_P(PSTR("Adjust \n"), false);
      break;
    case _VIM:
      oled_write_P(PSTR("Vim    \n"), false);
      break;
    case _MOUSE:
      oled_write_P(PSTR("Mouse  \n"), false);
      break;
    case _NUM:
      oled_write_P(PSTR("Numpad \n"), false);
      break;
    case _FN:
      oled_write_P(PSTR("FN     \n"), false);
      break;
    default:
      oled_write_P(PSTR("Unknown\n"), false);
      break;
  }
}

#ifdef RGBLIGHT_ENABLE
void render_rgblight_effect_name(void) {
  switch (rgblight_get_mode()) {
    case RGBLIGHT_MODE_STATIC_LIGHT:
      oled_write_P(PSTR("Static\n"), false);
      break;
    case RGBLIGHT_MODE_BREATHING:
      oled_write_P(PSTR("Breathing\n"), false);
      break;
    case RGBLIGHT_MODE_RAINBOW_MOOD:
      oled_write_P(PSTR("Rainbow mood\n"), false);
      break;
    case RGBLIGHT_MODE_RAINBOW_SWIRL:
      oled_write_P(PSTR("Rainbow swirl\n"), false);
      break;
    case RGBLIGHT_MODE_SNAKE:
      oled_write_P(PSTR("Snake\n"), false);
      break;
    case RGBLIGHT_MODE_KNIGHT:
      oled_write_P(PSTR("Knight\n"), false);
      break;
    case RGBLIGHT_MODE_CHRISTMAS:
      oled_write_P(PSTR("Christmas\n"), false);
      break;
    case RGBLIGHT_MODE_STATIC_GRADIENT:
      oled_write_P(PSTR("Gradient\n"), false);
      break;
    case RGBLIGHT_MODE_RGB_TEST:
      oled_write_P(PSTR("RGB test\n"), false);
      break;
    case RGBLIGHT_MODE_ALTERNATING:
      oled_write_P(PSTR("Alternating\n"), false);
      break;
  }
}
#endif // RGBLIGHT_ENABLE

#ifdef RGB_MATRIX_ENABLE
void render_rgb_matrix_effect_name(void) {
  switch (rgb_matrix_get_mode()) {
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
#endif // DISABLE_RGB_MATRIX_ALPHAS_MODS
#ifndef DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    case RGB_MATRIX_GRADIENT_UP_DOWN:
      oled_write_P(PSTR("Gradient up/down\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#ifndef DISABLE_RGB_MATRIX_BREATHING
    case RGB_MATRIX_BREATHING:
      oled_write_P(PSTR("Breathing\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_BREATHING
#ifndef DISABLE_RGB_MATRIX_CYCLE_ALL
    case RGB_MATRIX_CYCLE_ALL:
      oled_write_P(PSTR("Cycle all\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_CYCLE_ALL
#ifndef DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    case RGB_MATRIX_CYCLE_LEFT_RIGHT:
      oled_write_P(PSTR("Cycle left/right\n"), false);
      break;
#endif // DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
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
#endif // RGB_MATRIX_ENABLE

#endif // OLED_DRIVER_ENABLE