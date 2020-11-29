#pragma once
#include "quantum.h"

/*
 * TODO: I need a way to distinguish different types of display layouts.
 *
 * - 128x64
 * - 128x32
 * - 32x128
 */

#if defined(OLED_DISPLAY_128X64)  // Kyria
#    define OLED_TEXT_UNKNOWN "Unknown"
#    define OLED_TEXT_NONE "None"

// Default layouts
#    define OLED_TEXT_LAYOUT_NAME "Layer: "
#    define OLED_TEXT_LAYOUT_QUERTY "QUERTY"
#    define OLED_TEXT_LAYOUT_COLEMAK "Colemak"
#    define OLED_TEXT_LAYOUT_GAME "Game"

// Layer names
#    define OLED_TEXT_LAYER_LOWER "Lower"
#    define OLED_TEXT_LAYER_RAISE "Raise"
#    define OLED_TEXT_LAYER_ADJUST "Adjust"
#    define OLED_TEXT_LAYER_VIM "Vim"
#    define OLED_TEXT_LAYER_NUM "Numpad"
#    define OLED_TEXT_LAYER_MOUSE "Mouse"
#    define OLED_TEXT_LAYER_FN "FN"
#    define OLED_TEXT_LAYER_MEDIA "Media"

// Mod names
#    define OLED_TEXT_MOD_NAME "Mods: "
#    define OLED_TEXT_MOD_CTRL "CTRL"
#    define OLED_TEXT_MOD_GUI "GUI"
#    define OLED_TEXT_MOD_ALT "ALT"
#    define OLED_TEXT_MOD_SHIFT "SFT"
#    define OLED_TEXT_MOD_CAPS "CAP"

// Leader mode
#    define OLED_TEXT_LEADING "(lead)"

// RGB underglow effects
#    define OLED_TEXT_RGBLIGHT_MODE_STATIC_LIGHT "Static"
#    define OLED_TEXT_RGBLIGHT_MODE_BREATHING "Breathing"
#    define OLED_TEXT_RGBLIGHT_MODE_RAINBOW_MOOD "Rainbow mood"
#    define OLED_TEXT_RGBLIGHT_MODE_RAINBOW_SWIRL "Rainbow swirl"
#    define OLED_TEXT_RGBLIGHT_MODE_SNAKE "Snake"
#    define OLED_TEXT_RGBLIGHT_MODE_KNIGHT "Knight"
#    define OLED_TEXT_RGBLIGHT_MODE_CHRISTMAS "Christmas"
#    define OLED_TEXT_RGBLIGHT_MODE_STATIC_GRADIENT "Gradient"
#    define OLED_TEXT_RGBLIGHT_MODE_RGB_TEST "RGB Test"
#    define OLED_TEXT_RGBLIGHT_MODE_ALTERNATING "Alternating"

// RGB matrix effects
#    define OLED_TEXT_RGB_MATRIX_NONE "None"
#    define OLED_TEXT_RGB_MATRIX_SOLID_COLOR "Solid Color"
#    define OLED_TEXT_RGB_MATRIX_ALPHAS_MODS "Alpha Mods"
#    define OLED_TEXT_RGB_MATRIX_GRADIENT_UP_DOWN "Gradient u/d"
#    define OLED_TEXT_RGB_MATRIX_GRADIENT_LEFT_RIGHT "Gradient l/r"
#    define OLED_TEXT_RGB_MATRIX_BREATHING "Breating"
#    define OLED_TEXT_RGB_MATRIX_BAND_SAT "Band Sat"
#    define OLED_TEXT_RGB_MATRIX_BAND_VAL "Band Val"
#    define OLED_TEXT_RGB_MATRIX_BAND_PINWHEEL_SAT "PW Sat"
#    define OLED_TEXT_RGB_MATRIX_BAND_PINWHEEL_VAL "PW Val"
#    define OLED_TEXT_RGB_MATRIX_BAND_SPIRAL_SAT "Spiral Sat"
#    define OLED_TEXT_RGB_MATRIX_BAND_SPIRAL_VAL "Spiral Val"
#    define OLED_TEXT_RGB_MATRIX_CYCLE_ALL "Cycle All"
#    define OLED_TEXT_RGB_MATRIX_CYCLE_LEFT_RIGHT "Cycle l/r"
#    define OLED_TEXT_RGB_MATRIX_CYCLE_UP_DOWN "Cycle u/d"
#    define OLED_TEXT_RGB_MATRIX_CYCLE_OUT_IN "Cycle i/o"
#    define OLED_TEXT_RGB_MATRIX_CYCLE_OUT_IN_DUAL "Cycle dual"
#    define OLED_TEXT_RGB_MATRIX_RAINBOW_MOVING_CHEVRON "Moving Chevron"
#    define OLED_TEXT_RGB_MATRIX_DUAL_BEACON "Dual Beacon"
#    define OLED_TEXT_RGB_MATRIX_CYCLE_PINWHEEL "Cycle Pinwheel"
#    define OLED_TEXT_RGB_MATRIX_CYCLE_SPIRAL "Cycle Spiral"
#    define OLED_TEXT_RGB_MATRIX_RAINBOW_BEACON "Rainbow Beacon"
#    define OLED_TEXT_RGB_MATRIX_PINWHEELS "Pinwheels"
#    define OLED_TEXT_RGB_MATRIX_RAINDROPS "Raindrops"
#    define OLED_TEXT_RGB_MATRIX_JELLYBEAN_RAINDROPS "Jellybean"
#    define OLED_TEXT_RGB_MATRIX_TYPING_HEATMAP "Heatmap"
#    define OLED_TEXT_RGB_MATRIX_DIGITAL_RAIN "Rain"
#    define OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE "Solic reactive"
#    define OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_SIMPLE "Reactive simple"
#    define OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_WIDE "Reactive wide"
#    define OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE "Reactive wide"
#    define OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_CROSS "Reactive Cross"
#    define OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS "Reactive Cross"
#    define OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_NEXUS "Reactive Nexus"
#    define OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS "Reactive Nexus"
#    define OLED_TEXT_RGB_MATRIX_SPLASH "Splash"
#    define OLED_TEXT_RGB_MATRIX_MULTISPLASH "Splash"
#    define OLED_TEXT_RGB_MATRIX_SOLID_SPLASH "Solid Splash"
#    define OLED_TEXT_RGB_MATRIX_SOLID_MULTISPLASH "Solid Splash"

// Custom flavor names
#    define OLED_TEXT_FLAVOR_DASHER "Dasher & Dancer"
#    define OLED_TEXT_FLAVOR_GODSPEED "Godspeed"
#    define OLED_TEXT_FLAVOR_LEVIATHAN "Leviathan"
#    define OLED_TEXT_FLAVOR_TROUBLED_MINDS "Troubled Minds"
#    define OLED_TEXT_FLAVOR_MILKSHAKE "Milkshake"
#    define OLED_TEXT_FLAVOR_SERIKA "Serika"

#elif defined(OLED_DISPLAY_VERTICAL)  // Experimental vertical mode (Crkbd)
#    define OLED_TEXT_UNKNOWN "?"
#    define OLED_TEXT_NONE "X"

#else  // crkbd, lily58, helix
#    define OLED_TEXT_UNKNOWN "Unknown"
#    define OLED_TEXT_NONE "None"

// Default layouts
#    define OLED_TEXT_LAYOUT_NAME "L: "
#    define OLED_TEXT_LAYOUT_QUERTY "QUERTY"
#    define OLED_TEXT_LAYOUT_COLEMAK "Colemak"
#    define OLED_TEXT_LAYOUT_GAME "Game"

// Layer names
#    define OLED_TEXT_LAYER_LOWER "Lower"
#    define OLED_TEXT_LAYER_RAISE "Raise"
#    define OLED_TEXT_LAYER_ADJUST "Adjust"
#    define OLED_TEXT_LAYER_VIM "Vim"
#    define OLED_TEXT_LAYER_NUM "Num"
#    define OLED_TEXT_LAYER_MOUSE "Mouse"
#    define OLED_TEXT_LAYER_FN "FN"
#    define OLED_TEXT_LAYER_MEDIA "Media"

// Mod names
#    define OLED_TEXT_MOD_NAME "M: "
#    define OLED_TEXT_MOD_CTRL "CTRL"
#    define OLED_TEXT_MOD_GUI "GUI"
#    define OLED_TEXT_MOD_ALT "ALT"
#    define OLED_TEXT_MOD_SHIFT "SFT"
#    define OLED_TEXT_MOD_CAPS "CAP"

// Leader mode
#    define OLED_TEXT_LEADING "(lead)"

// RGB underglow effects
#    define OLED_TEXT_RGBLIGHT_MODE_STATIC_LIGHT "Static"
#    define OLED_TEXT_RGBLIGHT_MODE_BREATHING "Breathing"
#    define OLED_TEXT_RGBLIGHT_MODE_RAINBOW_MOOD "Rainbow mood"
#    define OLED_TEXT_RGBLIGHT_MODE_RAINBOW_SWIRL "Rainbow swirl"
#    define OLED_TEXT_RGBLIGHT_MODE_SNAKE "Snake"
#    define OLED_TEXT_RGBLIGHT_MODE_KNIGHT "Knight"
#    define OLED_TEXT_RGBLIGHT_MODE_CHRISTMAS "Christmas"
#    define OLED_TEXT_RGBLIGHT_MODE_STATIC_GRADIENT "Gradient"
#    define OLED_TEXT_RGBLIGHT_MODE_RGB_TEST "RGB Test"
#    define OLED_TEXT_RGBLIGHT_MODE_ALTERNATING "Alternating"

// RGB matrix effects
#    define OLED_TEXT_RGB_MATRIX_NONE "None"
#    define OLED_TEXT_RGB_MATRIX_SOLID_COLOR "Solid Color"
#    define OLED_TEXT_RGB_MATRIX_ALPHAS_MODS "Alpha Mods"
#    define OLED_TEXT_RGB_MATRIX_GRADIENT_UP_DOWN "Gradient u/d"
#    define OLED_TEXT_RGB_MATRIX_GRADIENT_LEFT_RIGHT "Gradient l/r"
#    define OLED_TEXT_RGB_MATRIX_BREATHING "Breating"
#    define OLED_TEXT_RGB_MATRIX_BAND_SAT "Band Sat"
#    define OLED_TEXT_RGB_MATRIX_BAND_VAL "Band Val"
#    define OLED_TEXT_RGB_MATRIX_BAND_PINWHEEL_SAT "PW Sat"
#    define OLED_TEXT_RGB_MATRIX_BAND_PINWHEEL_VAL "PW Val"
#    define OLED_TEXT_RGB_MATRIX_BAND_SPIRAL_SAT "Spiral Sat"
#    define OLED_TEXT_RGB_MATRIX_BAND_SPIRAL_VAL "Spiral Val"
#    define OLED_TEXT_RGB_MATRIX_CYCLE_ALL "Cycle All"
#    define OLED_TEXT_RGB_MATRIX_CYCLE_LEFT_RIGHT "Cycle l/r"
#    define OLED_TEXT_RGB_MATRIX_CYCLE_UP_DOWN "Cycle u/d"
#    define OLED_TEXT_RGB_MATRIX_CYCLE_OUT_IN "Cycle i/o"
#    define OLED_TEXT_RGB_MATRIX_CYCLE_OUT_IN_DUAL "Cycle dual"
#    define OLED_TEXT_RGB_MATRIX_RAINBOW_MOVING_CHEVRON "Moving Chevron"
#    define OLED_TEXT_RGB_MATRIX_DUAL_BEACON "Dual Beacon"
#    define OLED_TEXT_RGB_MATRIX_CYCLE_PINWHEEL "Cycle Pinwheel"
#    define OLED_TEXT_RGB_MATRIX_CYCLE_SPIRAL "Cycle Spiral"
#    define OLED_TEXT_RGB_MATRIX_RAINBOW_BEACON "Rainbow Beacon"
#    define OLED_TEXT_RGB_MATRIX_PINWHEELS "Pinwheels"
#    define OLED_TEXT_RGB_MATRIX_RAINDROPS "Raindrops"
#    define OLED_TEXT_RGB_MATRIX_JELLYBEAN_RAINDROPS "Jellybean"
#    define OLED_TEXT_RGB_MATRIX_TYPING_HEATMAP "Heatmap"
#    define OLED_TEXT_RGB_MATRIX_DIGITAL_RAIN "Rain"
#    define OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE "Solic reactive"
#    define OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_SIMPLE "Reactive simple"
#    define OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_WIDE "Reactive wide"
#    define OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE "Reactive wide"
#    define OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_CROSS "Reactive Cross"
#    define OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS "Reactive Cross"
#    define OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_NEXUS "Reactive Nexus"
#    define OLED_TEXT_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS "Reactive Nexus"
#    define OLED_TEXT_RGB_MATRIX_SPLASH "Splash"
#    define OLED_TEXT_RGB_MATRIX_MULTISPLASH "Splash"
#    define OLED_TEXT_RGB_MATRIX_SOLID_SPLASH "Solid Splash"
#    define OLED_TEXT_RGB_MATRIX_SOLID_MULTISPLASH "Solid Splash"

// Custom flavor names
#    define OLED_TEXT_FLAVOR_DASHER "Dasher & Dancer"
#    define OLED_TEXT_FLAVOR_GODSPEED "Godspeed"
#    define OLED_TEXT_FLAVOR_LEVIATHAN "Leviathan"
#    define OLED_TEXT_FLAVOR_TROUBLED_MINDS "Troubled Minds"
#    define OLED_TEXT_FLAVOR_MILKSHAKE "Milkshake"
#    define OLED_TEXT_FLAVOR_SERIKA "Serika"
#endif

void oled_render_layer(void);
void oled_render_mods(void);
void oled_render_rgb_matrix_effect_name(void);
void oled_render_rgblight_effect_name(void);
