#pragma once

#if defined(OLED_FONT_H)
#    undef OLED_FONT_H
#endif

#if defined(FLAVOR_GODSPEED)
#    define OLED_FONT_H "users/buz/fonts/glcdfont_godspeed.c"
#    define COLOR_ALPHA 32, 191, 0
#    define COLOR_MODS 128, 207, 0
#    define COLOR_UNDERGLOW 128, 207, 0
#    define COLOR_RED 248, 255, 0
#    define COLOR_YELLOW 32, 207, 0
#    define COLOR_LAYER_ADJUST 1, 255, 255
#elif defined(FLAVOR_DASHER)
#    define OLED_FONT_H "users/buz/fonts/glcdfont_dasher.c"
#    define COLOR_ALPHA 160, 207, 0
#    define COLOR_MODS 112, 255, 0
#    define COLOR_UNDERGLOW 160, 207, 255
#elif defined(FLAVOR_LEVIATHAN)
#    define OLED_FONT_H "users/buz/fonts/glcdfont_leviathan.c"
#    define COLOR_ALPHA 85, 255, 0
#    define COLOR_MODS 85, 255, 0
#    define COLOR_UNDERGLOW 85, 255, 0
// #    define COLOR_LAYER_ADJUST 1, 255, 255
#elif defined(FLAVOR_TROUBLED_MINDS)
#    define OLED_FONT_H "users/buz/fonts/glcdfont_troubledminds.c"
#    define COLOR_ALPHA 200, 255, 0
#    define COLOR_MODS 85, 255, 0
#    define COLOR_UNDERGLOW 85, 255, 0
#    define COLOR_LAYER_ADJUST 0, 255, 255
#elif defined(FLAVOR_SERIKA)
#    define OLED_FONT_H "users/buz/fonts/glcdfont_serika.c"
#    define COLOR_ALPHA 24, 239, 0
#    define COLOR_MODS 24, 239, 0
#    define COLOR_UNDERGLOW 24, 239, 0
#    define COLOR_LAYER_ADJUST 0, 255, 255
#elif defined(FLAVOR_MILKSHAKE)
#    define OLED_FONT_H "users/buz/fonts/glcdfont_milkshake.c"
#    define COLOR_PINK 240, 176, 0
#    define COLOR_YELLOW 40, 239, 0
#    define COLOR_GREEN 80, 207, 0
#    define COLOR_BLUE 144, 255, 0
#    define COLOR_PURPLE 184, 255, 0
#    define COLOR_ALPHA 1, 0, 0
// #    define COLOR_UNDERGLOW 1, 0, 200
#    define COLOR_UNDERGLOW 144, 255, 200
#    define COLOR_LAYER_LOWER 240, 176, 255
#    define COLOR_LAYER_RAISE 40, 239, 255
#    define COLOR_LAYER_ADJUST 184, 255, 255
#elif defined(FLAVOR_SUSUWATARI)
#    define OLED_FONT_H "users/buz/fonts/glcdfont_susuwatari.c"
#    define COLOR_LAYER_ADJUST 0, 255, 255
// TODO
#else
#    define OLED_FONT_H "users/buz/fonts/glcdfont.c"
#    define COLOR_LAYER_DEFAULT 1, 255, 255
#    define COLOR_LAYER_RAISE 1, 255, 255
#    define COLOR_LAYER_LOWER 1, 255, 255
#    define COLOR_LAYER_ADJUST 1, 255, 255
#    define COLOR_LAYER_VIM 1, 255, 255
#    define COLOR_LAYER_MOUSE 1, 255, 255
#    define COLOR_LAYER_NUM 1, 255, 255
#endif
