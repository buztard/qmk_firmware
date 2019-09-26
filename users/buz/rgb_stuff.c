#include "buz.h"

#if defined(RGBLIGHT_ENABLE)
extern rgblight_config_t rgblight_config;
#elif defined(RGB_MATRIX_ENABLE)
extern rgb_config_t rgb_matrix_config;
extern led_config_t g_led_config;
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
void rgb_matrix_layer_helper_rgb(uint8_t red, uint8_t green, uint8_t blue, bool default_layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, red, green, blue);
        }
    }
}
#endif  // RGB_MATRIX_ENABLE
