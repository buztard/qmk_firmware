#include "buz.h"

#ifdef OLED_DRIVER_ENABLE
#    ifdef LEADER_ENABLE
extern bool leading;
#    endif

const char* get_layer_name(void) {
    switch (get_highest_layer(layer_state)) {
        case _LOWER:
            return PSTR("Lower");
        case _RAISE:
            return PSTR("Raise");
        case _ADJUST:
            return PSTR("Adjust");
        case _VIM:
            return PSTR("Vim");
        case _MOUSE:
            return PSTR("Mouse");
        case _NUM:
            return PSTR("Numpad");
        case _FN:
            return PSTR("FN");
        default:
            switch (get_highest_layer(default_layer_state)) {
                case _QWERTY:
                    return PSTR("QUERTY");
                case _COLEMAK:
                    return PSTR("COLEMAK");
                default:
                    return PSTR("Unknown");
            }
    }
}

void oled_render_layer(void) {
    oled_write_P(PSTR("L: "), false);
    oled_write_P(get_layer_name(), false);
    oled_write_P(PSTR("\n"), false);

#    ifdef LEADER_ENABLE
    if (leading) {
        oled_write_P(PSTR("(lead) "), false);
    }
#    endif
}

void oled_render_mods(void) {
    uint8_t modifiers     = get_mods();
    uint8_t one_shot      = get_oneshot_mods();
    uint8_t led_usb_state = host_keyboard_leds();
    bool    mod           = false;

    oled_write_P(PSTR("M: "), false);
    if ((modifiers & MOD_MASK_CTRL) || (one_shot & MOD_MASK_CTRL)) {
        oled_write_P(PSTR("CTRL "), false);
        mod = true;
    }
    if ((modifiers & MOD_MASK_GUI) || (one_shot & MOD_MASK_GUI)) {
        oled_write_P(PSTR("GUI "), false);
        mod = true;
    }
    if ((modifiers & MOD_MASK_ALT) || (one_shot & MOD_MASK_ALT)) {
        oled_write_P(PSTR("ALT "), false);
        mod = true;
    }
    if ((modifiers & MOD_MASK_SHIFT) || (one_shot & MOD_MASK_SHIFT)) {
        oled_write_P(PSTR("SFT "), false);
        mod = true;
    }
    if (led_usb_state & (1 << USB_LED_CAPS_LOCK)) {
        oled_write_P(PSTR("CAP "), false);
        mod = true;
    }
    if (!mod) {
        oled_write_P(PSTR("None"), false);
    }
    oled_write_P(PSTR("\n"), false);
}

#    ifdef RGBLIGHT_ENABLE
void oled_render_rgblight_effect_name(void) {
    switch (rgblight_get_mode()) {
        case RGBLIGHT_MODE_STATIC_LIGHT:
            oled_write_P(PSTR("Static\n"), false);
            break;
#        ifdef RGBLIGHT_EFFECT_BREATHING
        case RGBLIGHT_MODE_BREATHING:
            oled_write_P(PSTR("Breathing\n"), false);
            break;
#        endif
#        ifdef RGBLIGHT_EFFECT_RAINBOW_MOOD
        case RGBLIGHT_MODE_RAINBOW_MOOD:
            oled_write_P(PSTR("Rainbow mood\n"), false);
            break;
#        endif
#        ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
        case RGBLIGHT_MODE_RAINBOW_SWIRL:
            oled_write_P(PSTR("Rainbow swirl\n"), false);
            break;
#        endif
#        ifdef RGBLIGHT_EFFECT_SNAKE
        case RGBLIGHT_MODE_SNAKE:
            oled_write_P(PSTR("Snake\n"), false);
            break;
#        endif
#        ifdef RGBLIGHT_EFFECT_KNIGHT
        case RGBLIGHT_MODE_KNIGHT:
            oled_write_P(PSTR("Knight\n"), false);
            break;
#        endif
#        ifdef RGBLIGHT_EFFECT_CHRISTMAS
        case RGBLIGHT_MODE_CHRISTMAS:
            oled_write_P(PSTR("Christmas\n"), false);
            break;
#        endif
#        ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
        case RGBLIGHT_MODE_STATIC_GRADIENT:
            oled_write_P(PSTR("Gradient\n"), false);
            break;
#        endif
#        ifdef RGBLIGHT_EFFECT_RGB_TEST
        case RGBLIGHT_MODE_RGB_TEST:
            oled_write_P(PSTR("RGB test\n"), false);
            break;
#        endif
#        ifdef RGBLIGHT_EFFECT_ALTERNATING
        case RGBLIGHT_MODE_ALTERNATING:
            oled_write_P(PSTR("Alternating\n"), false);
            break;
#        endif
        default:
            break;
    }
}
#    endif  // RGBLIGHT_ENABLE

#    ifdef RGB_MATRIX_ENABLE
extern rgb_config_t rgb_matrix_config;

const char* rgb_matrix_effect_name(uint8_t mode) {
    switch (mode) {
        case RGB_MATRIX_NONE:
            return PSTR("None");
        case RGB_MATRIX_SOLID_COLOR:
            return PSTR("Solid color");
#        ifndef DISABLE_RGB_MATRIX_ALPHAS_MODS
        case RGB_MATRIX_ALPHAS_MODS:
            return PSTR("Alpha mods");
#        endif  // DISABLE_RGB_MATRIX_ALPHAS_MODS
#        ifndef DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
        case RGB_MATRIX_GRADIENT_UP_DOWN:
            return PSTR("Gradient up/down");
#        endif  // DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#        ifndef DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
        case RGB_MATRIX_GRADIENT_LEFT_RIGHT:
            return PSTR("Gradient l/r");
#        endif  // DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#        ifndef DISABLE_RGB_MATRIX_BREATHING
        case RGB_MATRIX_BREATHING:
            return PSTR("Breathing");
#        endif  // DISABLE_RGB_MATRIX_BREATHING
#        ifndef DISABLE_RGB_MATRIX_BAND_SAT
        case RGB_MATRIX_BAND_SAT:
            return PSTR("Band Sat");
#        endif  // DISABLE_RGB_MATRIX_BAND_SAT
#        ifndef DISABLE_RGB_MATRIX_BAND_VAL
        case RGB_MATRIX_BAND_VAL:
            return PSTR("Band Val");
#        endif  // DISABLE_RGB_MATRIX_BAND_VAL
#        ifndef DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
        case RGB_MATRIX_BAND_PINWHEEL_SAT:
            return PSTR("Band PW Sat");
#        endif  // DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#        ifndef DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
        case RGB_MATRIX_BAND_PINWHEEL_VAL:
            return PSTR("Band PW Val");
#        endif  // DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#        ifndef DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
        case RGB_MATRIX_BAND_SPIRAL_SAT:
            return PSTR("Band Spiral Sat");
#        endif  // DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#        ifndef DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
        case RGB_MATRIX_BAND_SPIRAL_VAL:
            return PSTR("Band Spiral Val");
#        endif  // DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#        ifndef DISABLE_RGB_MATRIX_CYCLE_ALL
        case RGB_MATRIX_CYCLE_ALL:
            return PSTR("Cycle all");
#        endif  // DISABLE_RGB_MATRIX_CYCLE_ALL
#        ifndef DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
        case RGB_MATRIX_CYCLE_LEFT_RIGHT:
            return PSTR("Cycle left/right");
#        endif  // DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#        ifndef DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
        case RGB_MATRIX_CYCLE_UP_DOWN:
            return PSTR("Cycle up/down");
#        endif  // DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
#        ifndef DISABLE_RGB_MATRIX_CYCLE_OUT_IN
        case RGB_MATRIX_CYCLE_OUT_IN:
            return PSTR("Cycle Out/In");
#        endif  // DISABLE_RGB_MATRIX_CYCLE_OUT_IN
#        ifndef DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
        case RGB_MATRIX_CYCLE_OUT_IN_DUAL:
            return PSTR("Cycle Out/In Dual");
#        endif  // DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#        ifndef DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
        case RGB_MATRIX_RAINBOW_MOVING_CHEVRON:
            return PSTR("Moving chevron");
#        endif  // DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#        ifndef DISABLE_RGB_MATRIX_DUAL_BEACON
        case RGB_MATRIX_DUAL_BEACON:
            return PSTR("Dual beacon");
#        endif  // DISABLE_RGB_MATRIX_DUAL_BEACON
#        ifndef DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
        case RGB_MATRIX_CYCLE_PINWHEEL:
            return PSTR("Cycle Pinwheel");
#        endif  // DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
#        ifndef DISABLE_RGB_MATRIX_CYCLE_SPIRAL
        case RGB_MATRIX_CYCLE_SPIRAL:
            return PSTR("Cycle spiral");
#        endif  // DISABLE_RGB_MATRIX_CYCLE_SPIRAL
#        ifndef DISABLE_RGB_MATRIX_RAINBOW_BEACON
        case RGB_MATRIX_RAINBOW_BEACON:
            return PSTR("Rainbow beacon");
#        endif  // DISABLE_RGB_MATRIX_RAINBOW_BEACON
#        ifndef DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
        case RGB_MATRIX_PINWHEELS:
            return PSTR("Pinwheels");
#        endif  // DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#        ifndef DISABLE_RGB_MATRIX_RAINDROPS
        case RGB_MATRIX_RAINDROPS:
            return PSTR("Raindrops");
#        endif  // DISABLE_RGB_MATRIX_RAINDROPS
#        ifndef DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
        case RGB_MATRIX_JELLYBEAN_RAINDROPS:
            return PSTR("Jellybean rain");
#        endif  // DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#        ifdef RGB_MATRIX_FRAMEBUFFER_EFFECTS
#            ifndef DISABLE_RGB_MATRIX_TYPING_HEATMAP
        case RGB_MATRIX_TYPING_HEATMAP:
            return PSTR("Typing heatmap");
#            endif  // DISABLE_RGB_MATRIX_TYPING_HEATMAP
#            ifndef DISABLE_RGB_MATRIX_DIGITAL_RAIN
        case RGB_MATRIX_DIGITAL_RAIN:
            return PSTR("Digital rain");
#            endif  // DISABLE_RGB_MATRIX_DIGITAL_RAIN
#        endif      // RGB_MATRIX_FRAMEBUFFER_EFFECTS
#        ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#            ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE
        case RGB_MATRIX_SOLID_REACTIVE:
            return PSTR("Solid reactive");
#            endif  // DISABLE_RGB_MATRIX_SOLID_REACTIVE
#            ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
        case RGB_MATRIX_SOLID_REACTIVE_SIMPLE:
            return PSTR("Reactive simple");
#            endif
#            ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
        case RGB_MATRIX_SOLID_REACTIVE_WIDE:
            return PSTR("Reactive wide");
#            endif  // DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#            ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
        case RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE:
            return PSTR("Reactive wide");
#            endif  // DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#            ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
        case RGB_MATRIX_SOLID_REACTIVE_CROSS:
            return PSTR("Reactive cross");
#            endif  // DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#            ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
        case RGB_MATRIX_SOLID_REACTIVE_MULTICROSS:
            return PSTR("Reactive cross");
#            endif  // DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#            ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
        case RGB_MATRIX_SOLID_REACTIVE_NEXUS:
            return PSTR("Reactive nexus");
#            endif  // DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#            ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
        case RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS:
            return PSTR("Reactive nexus");
#            endif  // DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#            ifndef DISABLE_RGB_MATRIX_SPLASH
        case RGB_MATRIX_SPLASH:
            return PSTR("Splash");
#            endif  // DISABLE_RGB_MATRIX_SPLASH
#            ifndef DISABLE_RGB_MATRIX_MULTISPLASH
        case RGB_MATRIX_MULTISPLASH:
            return PSTR("Splash");
#            endif  // DISABLE_RGB_MATRIX_MULTISPLASH
#            ifndef DISABLE_RGB_MATRIX_SOLID_SPLASH
        case RGB_MATRIX_SOLID_SPLASH:
            return PSTR("Solid splash");
#            endif  // DISABLE_RGB_MATRIX_SOLID_SPLASH
#            ifndef DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
        case RGB_MATRIX_SOLID_MULTISPLASH:
            return PSTR("Solid splash");
#            endif  // DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#        endif      // RGB_MATRIX_KEYREACTIVE_ENABLED
#        if defined(RGB_MATRIX_CUSTOM_USER) && defined(FLAVOR_DASHER)
        case RGB_MATRIX_CUSTOM_DASHER:
            return PSTR("Dasher & Dancer");
#        endif  // FLAVOR_DASHER
#        if defined(RGB_MATRIX_CUSTOM_USER) && defined(FLAVOR_GODSPEED)
        case RGB_MATRIX_CUSTOM_GODSPEED:
            return PSTR("Godspeed");
#        endif  // FLAVOR_GODSPEED
#        if defined(RGB_MATRIX_CUSTOM_USER) && defined(FLAVOR_LEVIATHAN)
        case RGB_MATRIX_CUSTOM_LEVIATHAN:
            return PSTR("Leviathan");
#        endif  // FLAVOR_LEVIATHAN
#        if defined(RGB_MATRIX_CUSTOM_USER) && defined(FLAVOR_TROUBLED_MINDS)
        case RGB_MATRIX_CUSTOM_TROUBLED_MINDS:
            return PSTR("Troubled minds");
#        endif  // FLAVOR_TROUBLED_MINDS
#        if defined(RGB_MATRIX_CUSTOM_USER) && defined(FLAVOR_MILKSHAKE)
        case RGB_MATRIX_CUSTOM_MILKSHAKE:
            return PSTR("Milkshake");
#        endif  // FLAVOR_MILKSHAKE
#        if defined(RGB_MATRIX_CUSTOM_USER) && defined(FLAVOR_SERIKA)
        case RGB_MATRIX_CUSTOM_SERIKA:
            return PSTR("Serika");
#        endif  // FLAVOR_SERIKA
        default:
            return PSTR("unknown");
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
#    endif  // RGB_MATRIX_ENABLE

#endif  // OLED_DRIVER_ENABLE
