RGB_MATRIX_EFFECT(DASHER)
RGB_MATRIX_EFFECT(GODSPEED)

#define RGB_MATRIX_EFFECT_CUSTOM_CRKBD
#define DASHER_ALPHA 160, 207, 0
#define DASHER_MODS 112, 255, 0
#define DASHER_UNDERGLOW 160, 207, 0

#define GODSPEED_ALPHA 40, 48, 0
#define GODSPEED_MODS 40, 48, 0
#define GODSPEED_UNDERGLOW 40, 48, 0
#define GODSPEED_RED 248, 255, 0
#define GODSPEED_YELLOW 32, 207, 0
#define GODSPEED_BLUE 128, 207, 0

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
extern uint8_t is_master;

static RGB get_color(uint8_t h, uint8_t s, uint8_t v) {
    HSV hsv = {h, s, v ? v : rgb_matrix_config.hsv.v};
    return hsv_to_rgb(hsv);
}

static bool DASHER(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB alpha     = get_color(DASHER_ALPHA);
    RGB mods      = get_color(DASHER_MODS);
    RGB underglow = get_color(DASHER_UNDERGLOW);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) {
            rgb_matrix_set_color(i, alpha.r, alpha.g, alpha.b);
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, mods.r, mods.g, mods.b);
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            rgb_matrix_set_color(i, underglow.r, underglow.g, underglow.b);
        }
    }
    return led_max < DRIVER_LED_TOTAL;
}

static bool GODSPEED(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB alpha     = get_color(GODSPEED_ALPHA);
    RGB mods      = get_color(GODSPEED_BLUE);
    RGB yellow    = get_color(GODSPEED_YELLOW);
    RGB red       = get_color(GODSPEED_RED);
    RGB underglow = get_color(GODSPEED_ALPHA);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) {
            rgb_matrix_set_color(i, alpha.r, alpha.g, alpha.b);
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            if (i == 24 || i == 06) {
                rgb_matrix_set_color(i, yellow.r, yellow.g, yellow.b);
            } else if (i == 25 && is_master) {
                rgb_matrix_set_color(i, red.r, red.g, red.b);
            } else {
                rgb_matrix_set_color(i, mods.r, mods.g, mods.b);
            }
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            rgb_matrix_set_color(i, underglow.r, underglow.g, underglow.b);
        }
    }
    return led_max < DRIVER_LED_TOTAL;
}
#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
