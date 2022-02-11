#ifdef FLAVOR_DASHER
RGB_MATRIX_EFFECT(DASHER)
#endif

#ifdef FLAVOR_GODSPEED
RGB_MATRIX_EFFECT(GODSPEED)
#endif

#ifdef FLAVOR_LEVIATHAN
RGB_MATRIX_EFFECT(LEVIATHAN)
#endif

#ifdef FLAVOR_TROUBLED_MINDS
RGB_MATRIX_EFFECT(TROUBLED_MINDS)
#endif

#ifdef FLAVOR_MILKSHAKE
RGB_MATRIX_EFFECT(MILKSHAKE)
#endif

#ifdef FLAVOR_SERIKA
RGB_MATRIX_EFFECT(SERIKA)
#endif

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    include "flavors.h"
#    include "split_util.h"

RGB get_color(uint8_t h, uint8_t s, uint8_t v) {
    HSV hsv = {h, s, v ? v : rgb_matrix_config.hsv.v};
    return hsv_to_rgb(hsv);
}

#    ifdef FLAVOR_DASHER
static bool DASHER(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB alpha     = get_color(COLOR_ALPHA);
    RGB mods      = get_color(COLOR_MODS);
    RGB underglow = get_color(160, 207, rgb_matrix_config.hsv.v + 100 > 255 ? 255 : rgb_matrix_config.hsv.v + 100);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) {
            rgb_matrix_set_color(i, alpha.r, alpha.g, alpha.b);
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, mods.r, mods.g, mods.b);
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            rgb_matrix_set_color(i, underglow.r, underglow.g, underglow.b);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}
#    endif  // FLAVOR_DASHER

#    ifdef FLAVOR_GODSPEED
static bool GODSPEED(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB alpha     = get_color(COLOR_ALPHA);
    RGB mods      = get_color(COLOR_MODS);
    RGB yellow    = get_color(COLOR_YELLOW);
    RGB red       = get_color(COLOR_RED);
    RGB underglow = get_color(COLOR_UNDERGLOW);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) {
            rgb_matrix_set_color(i, alpha.r, alpha.g, alpha.b);
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            if (i == 24 || i == 6) {
                rgb_matrix_set_color(i, yellow.r, yellow.g, yellow.b);
            } else if (i == 25 && is_keyboard_left()) {
                rgb_matrix_set_color(i, red.r, red.g, red.b);
            } else {
                rgb_matrix_set_color(i, mods.r, mods.g, mods.b);
            }
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            rgb_matrix_set_color(i, underglow.r, underglow.g, underglow.b);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}
#    endif  // FLAVOR_GODSPEED

#    ifdef FLAVOR_LEVIATHAN
static bool LEVIATHAN(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB alpha     = get_color(COLOR_ALPHA);
    RGB mods      = get_color(COLOR_MODS);
    RGB underglow = get_color(COLOR_UNDERGLOW);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) {
            rgb_matrix_set_color(i, alpha.r, alpha.g, alpha.b);
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, mods.r, mods.g, mods.b);
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            rgb_matrix_set_color(i, underglow.r, underglow.g, underglow.b);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}
#    endif  // FLAVOR_LEVIATHAN

#    ifdef FLAVOR_TROUBLED_MINDS
static bool TROUBLED_MINDS(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB alpha     = get_color(COLOR_ALPHA);
    RGB mods      = get_color(COLOR_MODS);
    RGB underglow = get_color(COLOR_UNDERGLOW);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) {
            rgb_matrix_set_color(i, alpha.r, alpha.g, alpha.b);
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, mods.r, mods.g, mods.b);
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            rgb_matrix_set_color(i, underglow.r, underglow.g, underglow.b);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}
#    endif  // FLAVOR_TROUBLED_MINDS

#    ifdef FLAVOR_MILKSHAKE
static bool MILKSHAKE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB alpha     = get_color(COLOR_ALPHA);
    RGB yellow    = get_color(COLOR_YELLOW);
    RGB pink      = get_color(COLOR_PINK);
    RGB green     = get_color(COLOR_GREEN);
    RGB blue      = get_color(COLOR_BLUE);
    RGB purple    = get_color(COLOR_PURPLE);
    RGB underglow = get_color(COLOR_UNDERGLOW);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) {
            rgb_matrix_set_color(i, alpha.r, alpha.g, alpha.b);
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            if (is_keyboard_left()) {
                if (i == 24) {
                    rgb_matrix_set_color(i, yellow.r, yellow.g, yellow.b);
                } else if (i == 25) {
                    rgb_matrix_set_color(i, green.r, green.g, green.b);
                } else if (i == 26) {
                    rgb_matrix_set_color(i, blue.r, blue.g, blue.b);
                } else if (i == 13) {
                    rgb_matrix_set_color(i, pink.r, pink.g, pink.b);
                } else {
                    rgb_matrix_set_color(i, alpha.r, alpha.g, alpha.b);
                }
            } else {
                if (i == 24) {
                    rgb_matrix_set_color(i, pink.r, pink.g, pink.b);
                } else if (i == 25) {
                    rgb_matrix_set_color(i, purple.r, purple.g, purple.b);
                } else if (i == 26) {
                    rgb_matrix_set_color(i, green.r, green.g, green.b);
                } else if (i == 13) {
                    rgb_matrix_set_color(i, yellow.r, yellow.g, yellow.b);
                } else {
                    rgb_matrix_set_color(i, alpha.r, alpha.g, alpha.b);
                }
            }
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            rgb_matrix_set_color(i, underglow.r, underglow.g, underglow.b);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}
#    endif  // FLAVOR_MILKSHAKE

#    ifdef FLAVOR_SERIKA
static bool SERIKA(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB alpha     = get_color(COLOR_ALPHA);
    RGB mods      = get_color(COLOR_MODS);
    RGB underglow = get_color(COLOR_UNDERGLOW);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) {
            rgb_matrix_set_color(i, alpha.r, alpha.g, alpha.b);
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, mods.r, mods.g, mods.b);
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            rgb_matrix_set_color(i, underglow.r, underglow.g, underglow.b);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}
#    endif  // FLAVOR_SERIKA

#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
/* vim: set ft=c: */
