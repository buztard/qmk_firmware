#include "buz.h"

extern userspace_config_t userspace_config;

#ifdef LEADER_ENABLE
extern bool leading;
#endif

#define COLOR_ADJUST 0xff, 0x0, 0x0
#define COLOR_CAPSLOCK 0xff, 0x0, 0x0
#define COLOR_VIM 0x0, 0xff, 0x0
#define COLOR_MOUSE 0xff, 0x0, 0x0
#define COLOR_NUM 95, 7, 53

__attribute__((weak)) bool rgb_layer_indicator_keymap(void) { return true; }

#if defined(RGB_MATRIX_ENABLE)
extern rgb_config_t rgb_matrix_config;

static void rgb_matrix_layer_helper_rgb(uint8_t red, uint8_t green, uint8_t blue, uint8_t flags) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], flags)) {
            rgb_matrix_set_color(i, red, green, blue);
        }
    }
}

void rgb_layer_indicator_user(void) {
    if (!rgb_matrix_config.enable || !userspace_config.rgb_layer_change) {
        return;
    }

    if (!rgb_layer_indicator_keymap()) {
        return;
    }

    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
        rgb_matrix_layer_helper_rgb(COLOR_CAPSLOCK, LED_FLAG_MODIFIER);
    }

    switch (biton32(layer_state)) {
        case _ADJUST:
            rgb_matrix_layer_helper_rgb(COLOR_ADJUST, LED_FLAG_UNDERGLOW);
            break;

        case _VIM:
            rgb_matrix_layer_helper_rgb(COLOR_VIM, LED_FLAG_UNDERGLOW);
            break;

        case _MOUSE:
            rgb_matrix_layer_helper_rgb(COLOR_MOUSE, LED_FLAG_UNDERGLOW);
            break;

        case _NUM:
            rgb_matrix_layer_helper_rgb(COLOR_NUM, LED_FLAG_UNDERGLOW);
            break;
    }

#    ifdef LEADER_ENABLE
    if (leading) {
        rgb_matrix_layer_helper_rgb(0x0, 0xff, 0x0, LED_FLAG_MODIFIER);
    }
#    endif
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
#ifdef RGBLIGHT_EFFECT_BREATHING
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+3);
#endif
    }
}
#endif
