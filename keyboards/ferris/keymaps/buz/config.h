#pragma once

/* Select hand configuration */
#define EE_HANDS

#define USE_SERIAL_PD2

#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

#define OLED_TIMEOUT 60000
#define OLED_FADE_OUT 7
#define OLED_SCROLL_TIMEOUT 10000

#ifdef DEBOUNCE
#    undef DEBOUNCE
#endif
#define DEBOUNCE 10
