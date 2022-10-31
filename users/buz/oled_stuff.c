#include "buz.h"
// #include "caps_word.h"
#include "oled_stuff.h"

#ifdef LEADER_ENABLE
extern bool leading;
#endif

const char* get_layer_name(void) {
    switch (get_highest_layer(layer_state)) {
        case _ADJUST:
            return PSTR(OLED_TEXT_LAYER_ADJUST);
        case _VIM:
            return PSTR(OLED_TEXT_LAYER_VIM);
        case _MOUSE:
            return PSTR(OLED_TEXT_LAYER_MOUSE);
        case _NUM:
            return PSTR(OLED_TEXT_LAYER_NUM);
        case _SYMBOL:
            return PSTR(OLED_TEXT_LAYER_SYM);
        case _TMUX:
            return PSTR(OLED_TEXT_LAYER_TMUX);
        // case _FN:
        //     return PSTR(OLED_TEXT_LAYER_FN);
        case _MEDIA:
            return PSTR(OLED_TEXT_LAYER_MEDIA);
        case _FUNC:
            return PSTR(OLED_TEXT_LAYER_FN);
        default:
            switch (get_highest_layer(default_layer_state)) {
                case _QWERTY:
                    return PSTR(OLED_TEXT_LAYOUT_QUERTY);
                case _GAME:
                    return PSTR(OLED_TEXT_LAYOUT_GAME);
                case _COLEMAK:
                    return PSTR(OLED_TEXT_LAYOUT_COLEMAK);
                default:
                    return PSTR(OLED_TEXT_UNKNOWN);
            }
    }
}

void oled_render_layer(void) {
    oled_write_P(PSTR(OLED_TEXT_LAYOUT_NAME), false);
    oled_write_P(get_layer_name(), false);
    oled_write_P(PSTR("\n"), false);

#ifdef LEADER_ENABLE
    if (leading) {
        oled_write_P(PSTR("(lead) "), false);
    }
#endif
}

void oled_render_mods(void) {
    uint8_t modifiers     = get_mods();
    uint8_t one_shot      = get_oneshot_mods();
    uint8_t led_usb_state = host_keyboard_leds();
    bool    mod           = false;

#ifdef OLED_TEXT_MOD_NAME
    oled_write_P(PSTR(OLED_TEXT_MOD_NAME), false);
#endif
    if ((modifiers & MOD_MASK_CTRL) || (one_shot & MOD_MASK_CTRL)) {
        oled_write_P(PSTR(OLED_TEXT_MOD_CTRL " "), false);
        mod = true;
    }
    if ((modifiers & MOD_MASK_GUI) || (one_shot & MOD_MASK_GUI)) {
        oled_write_P(PSTR(OLED_TEXT_MOD_GUI " "), false);
        mod = true;
    }
    if ((modifiers & MOD_MASK_ALT) || (one_shot & MOD_MASK_ALT)) {
        oled_write_P(PSTR(OLED_TEXT_MOD_ALT " "), false);
        mod = true;
    }
    if ((modifiers & MOD_MASK_SHIFT) || (one_shot & MOD_MASK_SHIFT)) {
        oled_write_P(PSTR(OLED_TEXT_MOD_SHIFT " "), false);
        mod = true;
    }
    if (led_usb_state & (1 << USB_LED_CAPS_LOCK)) {
        oled_write_P(PSTR(OLED_TEXT_MOD_CAPS " "), false);
        mod = true;
    }
    if (!mod) {
        oled_write_P(PSTR(OLED_TEXT_NONE), false);
    }
    oled_write_P(PSTR("\n"), false);
}

void oled_render_mods_XXX(void) {
    uint8_t modifiers     = get_mods();
    uint8_t one_shot      = get_oneshot_mods();
    uint8_t led_usb_state = host_keyboard_leds();

    oled_write_P(PSTR(OLED_TEXT_MOD_NAME), false);
    oled_write_P(PSTR("C"), ((modifiers & MOD_MASK_CTRL) || (one_shot & MOD_MASK_CTRL)));
    // oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("G"), ((modifiers & MOD_MASK_GUI) || (one_shot & MOD_MASK_GUI)));
    // oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("A"), ((modifiers & MOD_MASK_ALT) || (one_shot & MOD_MASK_ALT)));
    // oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), ((modifiers & MOD_MASK_SHIFT) || (one_shot & MOD_MASK_SHIFT)));
    // oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("C"), (led_usb_state & (1 << USB_LED_CAPS_LOCK)));
    oled_write_P(PSTR("\n"), false);
}

#ifdef RGBLIGHT_ENABLE
void oled_render_rgblight_effect_name(void) {
    switch (rgblight_get_mode()) {
        case RGBLIGHT_MODE_STATIC_LIGHT:
            oled_write_P(PSTR(OLED_TEXT_RGBLIGHT_MODE_STATIC_LIGHT), false);
            break;
#    ifdef RGBLIGHT_EFFECT_BREATHING
        case RGBLIGHT_MODE_BREATHING:
            oled_write_P(PSTR(OLED_TEXT_RGBLIGHT_MODE_BREATHING), false);
            break;
#    endif
#    ifdef RGBLIGHT_EFFECT_RAINBOW_MOOD
        case RGBLIGHT_MODE_RAINBOW_MOOD:
            oled_write_P(PSTR(OLED_TEXT_RGBLIGHT_MODE_RAINBOW_MOOD), false);
            break;
#    endif
#    ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
        case RGBLIGHT_MODE_RAINBOW_SWIRL:
            oled_write_P(PSTR(OLED_TEXT_RGBLIGHT_MODE_RAINBOW_SWIRL), false);
            break;
#    endif
#    ifdef RGBLIGHT_EFFECT_SNAKE
        case RGBLIGHT_MODE_SNAKE:
            oled_write_P(PSTR(OLED_TEXT_RGBLIGHT_MODE_SNAKE), false);
            break;
#    endif
#    ifdef RGBLIGHT_EFFECT_KNIGHT
        case RGBLIGHT_MODE_KNIGHT:
            oled_write_P(PSTR(OLED_TEXT_RGBLIGHT_MODE_KNIGHT), false);
            break;
#    endif
#    ifdef RGBLIGHT_EFFECT_CHRISTMAS
        case RGBLIGHT_MODE_CHRISTMAS:
            oled_write_P(PSTR(OLED_TEXT_RGBLIGHT_MODE_CHRISTMAS), false);
            break;
#    endif
#    ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
        case RGBLIGHT_MODE_STATIC_GRADIENT:
            oled_write_P(PSTR(OLED_TEXT_RGBLIGHT_MODE_STATIC_GRADIENT), false);
            break;
#    endif
#    ifdef RGBLIGHT_EFFECT_RGB_TEST
        case RGBLIGHT_MODE_RGB_TEST:
            oled_write_P(PSTR(OLED_TEXT_RGBLIGHT_MODE_RGB_TEST), false);
            break;
#    endif
#    ifdef RGBLIGHT_EFFECT_ALTERNATING
        case RGBLIGHT_MODE_ALTERNATING:
            oled_write_P(PSTR(OLED_TEXT_RGBLIGHT_MODE_ALTERNATING), false);
            break;
#    endif
        default:
            break;
    }
    oled_advance_page(true);
}
#endif // RGBLIGHT_ENABLE

#ifdef RGB_MATRIX_ENABLE
extern rgb_config_t rgb_matrix_config;

const char* rgb_matrix_effect_name(uint8_t mode) {
    switch (mode) {
        case RGB_MATRIX_NONE:
            return PSTR(OLED_TEXT_RGB_MATRIX_NONE);
        case RGB_MATRIX_SOLID_COLOR:
            return PSTR(OLED_TEXT_RGB_MATRIX_SOLID_COLOR);
#    ifdef ENABLE_RGB_MATRIX_ALPHAS_MODS
        case RGB_MATRIX_ALPHAS_MODS:
            return PSTR(OLED_TEXT_RGB_MATRIX_ALPHAS_MODS);
#    endif // DISABLE_RGB_MATRIX_ALPHAS_MODS
#    ifdef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
        case RGB_MATRIX_GRADIENT_UP_DOWN:
            return PSTR(OLED_TEXT_RGB_MATRIX_GRADIENT_UP_DOWN);
#    endif // DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    ifdef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
        case RGB_MATRIX_GRADIENT_LEFT_RIGHT:
            return PSTR(OLED_TEXT_RGB_MATRIX_GRADIENT_LEFT_RIGHT);
#    endif // DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    ifdef ENABLE_RGB_MATRIX_BREATHING
        case RGB_MATRIX_BREATHING:
            return PSTR(OLED_TEXT_RGB_MATRIX_BREATHING);
#    endif // DISABLE_RGB_MATRIX_BREATHING
#    ifdef ENABLE_RGB_MATRIX_BAND_SAT
        case RGB_MATRIX_BAND_SAT:
            return PSTR(OLED_TEXT_RGB_MATRIX_BAND_SAT);
#    endif // DISABLE_RGB_MATRIX_BAND_SAT
#    ifdef ENABLE_RGB_MATRIX_BAND_VAL
        case RGB_MATRIX_BAND_VAL:
            return PSTR(OLED_TEXT_RGB_MATRIX_BAND_VAL);
#    endif // DISABLE_RGB_MATRIX_BAND_VAL
#    ifdef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
        case RGB_MATRIX_BAND_PINWHEEL_SAT:
            return PSTR(OLED_TEXT_RGB_MATRIX_BAND_PINWHEEL_SAT);
#    endif // DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    ifdef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
        case RGB_MATRIX_BAND_PINWHEEL_VAL:
            return PSTR(OLED_TEXT_RGB_MATRIX_BAND_PINWHEEL_VAL);
#    endif // DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    ifdef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
        case RGB_MATRIX_BAND_SPIRAL_SAT:
            return PSTR(OLED_TEXT_RGB_MATRIX_BAND_SPIRAL_SAT);
#    endif // DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    ifdef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
        case RGB_MATRIX_BAND_SPIRAL_VAL:
            return PSTR(OLED_TEXT_RGB_MATRIX_BAND_SPIRAL_VAL);
#    endif // DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    ifdef ENABLE_RGB_MATRIX_CYCLE_ALL
        case RGB_MATRIX_CYCLE_ALL:
            return PSTR(OLED_TEXT_RGB_MATRIX_CYCLE_ALL);
#    endif // DISABLE_RGB_MATRIX_CYCLE_ALL
#    ifdef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
        case RGB_MATRIX_CYCLE_LEFT_RIGHT:
            return PSTR(OLED_TEXT_RGB_MATRIX_CYCLE_LEFT_RIGHT);
#    endif // DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    ifdef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
        case RGB_MATRIX_CYCLE_UP_DOWN:
            return PSTR(OLED_TEXT_RGB_MATRIX_CYCLE_UP_DOWN);
#    endif // DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    ifdef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
        case RGB_MATRIX_CYCLE_OUT_IN:
            return PSTR(OLED_TEXT_RGB_MATRIX_CYCLE_OUT_IN);
#    endif // DISABLE_RGB_MATRIX_CYCLE_OUT_IN
#    ifdef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
        case RGB_MATRIX_CYCLE_OUT_IN_DUAL:
            return PSTR(OLED_TEXT_RGB_MATRIX_CYCLE_OUT_IN_DUAL);
#    endif // DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    ifdef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
        case RGB_MATRIX_RAINBOW_MOVING_CHEVRON:
            return PSTR(OLED_TEXT_RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
#    endif // DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    ifdef ENABLE_RGB_MATRIX_DUAL_BEACON
        case RGB_MATRIX_DUAL_BEACON:
            return PSTR(OLED_TEXT_RGB_MATRIX_DUAL_BEACON);
#    endif // DISABLE_RGB_MATRIX_DUAL_BEACON
#    ifdef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
        case RGB_MATRIX_CYCLE_PINWHEEL:
            return PSTR(OLED_TEXT_RGB_MATRIX_CYCLE_PINWHEEL);
#    endif // DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    ifdef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
        case RGB_MATRIX_CYCLE_SPIRAL:
            return PSTR(OLED_TEXT_RGB_MATRIX_CYCLE_SPIRAL);
#    endif // DISABLE_RGB_MATRIX_CYCLE_SPIRAL
#    ifdef ENABLE_RGB_MATRIX_RAINBOW_BEACON
        case RGB_MATRIX_RAINBOW_BEACON:
            return PSTR(OLED_TEXT_RGB_MATRIX_RAINBOW_BEACON);
#    endif // DISABLE_RGB_MATRIX_RAINBOW_BEACON
#    ifdef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
        case RGB_MATRIX_RAINBOW_PINWHEELS:
            return PSTR(OLED_TEXT_RGB_MATRIX_PINWHEELS);
#    endif // DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    ifdef ENABLE_RGB_MATRIX_RAINDROPS
        case RGB_MATRIX_RAINDROPS:
            return PSTR(OLED_TEXT_RGB_MATRIX_RAINDROPS);
#    endif // DISABLE_RGB_MATRIX_RAINDROPS
#    ifdef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
        case RGB_MATRIX_JELLYBEAN_RAINDROPS:
            return PSTR(OLED_TEXT_RGB_MATRIX_JELLYBEAN_RAINDROPS);
#    endif // DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    ifdef RGB_MATRIX_FRAMEBUFFER_EFFECTS
#        ifdef ENABLE_RGB_MATRIX_TYPING_HEATMAP
        case RGB_MATRIX_TYPING_HEATMAP:
            return PSTR(OLED_TEXT_RGB_MATRIX_TYPING_HEATMAP);
#        endif // DISABLE_RGB_MATRIX_TYPING_HEATMAP
#        ifdef ENABLE_RGB_MATRIX_DIGITAL_RAIN
        case RGB_MATRIX_DIGITAL_RAIN:
            return PSTR(OLED_TEXT_RGB_MATRIX_DIGITAL_RAIN);
#        endif // DISABLE_RGB_MATRIX_DIGITAL_RAIN
#    endif     // RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#        ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE
        case RGB_MATRIX_SOLID_REACTIVE:
            return PSTR(OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE);
#        endif // DISABLE_RGB_MATRIX_SOLID_REACTIVE
#        ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
        case RGB_MATRIX_SOLID_REACTIVE_SIMPLE:
            return PSTR(OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
#        endif
#        ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
        case RGB_MATRIX_SOLID_REACTIVE_WIDE:
            return PSTR(OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_WIDE);
#        endif // DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#        ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
        case RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE:
            return PSTR(OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE);
#        endif // DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#        ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
        case RGB_MATRIX_SOLID_REACTIVE_CROSS:
            return PSTR(OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_CROSS);
#        endif // DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#        ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
        case RGB_MATRIX_SOLID_REACTIVE_MULTICROSS:
            return PSTR(OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS);
#        endif // DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#        ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
        case RGB_MATRIX_SOLID_REACTIVE_NEXUS:
            return PSTR(OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_NEXUS);
#        endif // DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#        ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
        case RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS:
            return PSTR(OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
#        endif // DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#        ifdef ENABLE_RGB_MATRIX_SPLASH
        case RGB_MATRIX_SPLASH:
            return PSTR(OLED_TEXT_RGB_MATRIX_SPLASH);
#        endif // DISABLE_RGB_MATRIX_SPLASH
#        ifdef ENABLE_RGB_MATRIX_MULTISPLASH
        case RGB_MATRIX_MULTISPLASH:
            return PSTR(OLED_TEXT_RGB_MATRIX_MULTISPLASH);
#        endif // DISABLE_RGB_MATRIX_MULTISPLASH
#        ifdef ENABLE_RGB_MATRIX_SOLID_SPLASH
        case RGB_MATRIX_SOLID_SPLASH:
            return PSTR(OLED_TEXT_RGB_MATRIX_SOLID_SPLASH);
#        endif // DISABLE_RGB_MATRIX_SOLID_SPLASH
#        ifdef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
        case RGB_MATRIX_SOLID_MULTISPLASH:
            return PSTR(OLED_TEXT_RGB_MATRIX_SOLID_MULTISPLASH);
#        endif // DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#    endif     // RGB_MATRIX_KEYREACTIVE_ENABLED
#    if defined(RGB_MATRIX_CUSTOM_USER) && defined(FLAVOR_DASHER)
        case RGB_MATRIX_CUSTOM_DASHER:
            return PSTR(OLED_TEXT_FLAVOR_DASHER);
#    endif // FLAVOR_DASHER
#    if defined(RGB_MATRIX_CUSTOM_USER) && defined(FLAVOR_GODSPEED)
        case RGB_MATRIX_CUSTOM_GODSPEED:
            return PSTR(OLED_TEXT_FLAVOR_GODSPEED);
#    endif // FLAVOR_GODSPEED
#    if defined(RGB_MATRIX_CUSTOM_USER) && defined(FLAVOR_LEVIATHAN)
        case RGB_MATRIX_CUSTOM_LEVIATHAN:
            return PSTR(OLED_TEXT_FLAVOR_LEVIATHAN);
#    endif // FLAVOR_LEVIATHAN
#    if defined(RGB_MATRIX_CUSTOM_USER) && defined(FLAVOR_TROUBLED_MINDS)
        case RGB_MATRIX_CUSTOM_TROUBLED_MINDS:
            return PSTR(OLED_TEXT_FLAVOR_TROUBLED_MINDS);
#    endif // FLAVOR_TROUBLED_MINDS
#    if defined(RGB_MATRIX_CUSTOM_USER) && defined(FLAVOR_MILKSHAKE)
        case RGB_MATRIX_CUSTOM_MILKSHAKE:
            return PSTR(OLED_TEXT_FLAVOR_MILKSHAKE);
#    endif // FLAVOR_MILKSHAKE
#    if defined(RGB_MATRIX_CUSTOM_USER) && defined(FLAVOR_SERIKA)
        case RGB_MATRIX_CUSTOM_SERIKA:
            return PSTR(OLED_TEXT_FLAVOR_SERIKA);
#    endif // FLAVOR_SERIKA
        default:
            return PSTR(OLED_TEXT_UNKNOWN);
    }
}

void oled_render_rgb_matrix_effect_name(void) {
    if (!rgb_matrix_config.enable) {
        oled_write_P(PSTR("RGB Disabled\n"), false);
        return;
    }
    oled_write_P(PSTR("A: "), false);
    oled_write_P(rgb_matrix_effect_name(rgb_matrix_get_mode()), false);
    oled_write_P(PSTR("\n"), false);
}
#endif // RGB_MATRIX_ENABLE
