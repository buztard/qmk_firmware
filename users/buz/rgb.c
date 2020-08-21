#include "buz.h"

extern userspace_config_t userspace_config;

#define COLOR_ADJUST 0xff, 0x0, 0x0
#define COLOR_CAPSLOCK 0xff, 0x0, 0x0
#define COLOR_VIM 0x0, 0xff, 0x0
#define COLOR_MOUSE 0xff, 0x0, 0x0
#define COLOR_NUM 95, 7, 53

__attribute__((weak)) bool rgb_layer_indicator_keymap(void) { return true; }

#if defined(RGB_MATRIX_ENABLE)
extern rgb_config_t rgb_matrix_config;

__attribute__((weak)) bool rgb_matrix_indicators_keymap(void) { return true; }

void rgb_matrix_layer_helper_rgb(uint8_t red, uint8_t green, uint8_t blue, uint8_t flags) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], flags)) {
            rgb_matrix_set_color(i, red, green, blue);
        }
    }
}

void rgb_matrix_layer_helper_hsv(uint8_t h, uint8_t s, uint8_t v, uint8_t flags) {
    HSV hsv = {h, s, v ? v : rgb_matrix_config.hsv.v};
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_layer_helper_rgb(rgb.r, rgb.g, rgb.b, flags);
}

void rgb_matrix_indicators_user(void) {
    if (!rgb_matrix_config.enable || !userspace_config.rgb_layer_change) {
        return;
    }
    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(g_led_config.matrix_co[2][0], 0xFF, 0x0, 0x0);
    }

    if (!rgb_matrix_indicators_keymap()) {
        return;
    }

    switch (get_highest_layer(layer_state)) {
#    ifdef COLOR_LAYER_LOWER
        case _LOWER:
            rgb_matrix_layer_helper_hsv(COLOR_LAYER_LOWER, LED_FLAG_UNDERGLOW);
            break;
#    endif

#    ifdef COLOR_LAYER_RAISE
        case _RAISE:
            rgb_matrix_layer_helper_hsv(COLOR_LAYER_RAISE, LED_FLAG_UNDERGLOW);
            break;
#    endif

#    ifdef COLOR_LAYER_ADJUST
        case _ADJUST:
            rgb_matrix_layer_helper_hsv(COLOR_LAYER_ADJUST, LED_FLAG_UNDERGLOW);
            break;
#    endif

        default:
#    ifdef LAYER_UNDERGLOW_DEFAULT
            rgb_matrix_layer_helper_rgb(LAYER_UNDERGLOW_DEFAULT, LED_FLAG_UNDERGLOW);
#    endif
            break;
    }
}
#endif  // RGB_MATRIX_ENABLE

#if defined(RGBLIGHT_ENABLE)
extern rgblight_config_t rgblight_config;

static void rgblight_set_color(uint8_t h, uint8_t s, uint8_t v) { rgblight_sethsv_noeeprom(h, s, rgblight_config.val); }

void rgb_layer_indicator_user(void) {
    if (!rgblight_config.enable || !userspace_config.rgb_layer_change) {
        return;
    }

    if (!rgb_layer_indicator_keymap()) {
        return;
    }

    switch (biton32(layer_state)) {
        case _ADJUST:
            rgblight_set_color(COLOR_ADJUST);
            break;

        case _VIM:
            rgblight_set_color(COLOR_VIM);
            break;

        case _MOUSE:
            rgblight_set_color(COLOR_MOUSE);
            break;

        case _NUM:
            rgblight_set_color(COLOR_NUM);
            break;
    }

    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
        rgblight_set_color(COLOR_CAPSLOCK);
#    ifdef RGBLIGHT_EFFECT_BREATHING
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
#    endif
    }
}
#endif
