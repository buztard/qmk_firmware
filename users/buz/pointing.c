// Copyright 2021 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "pointing.h"

#ifdef PIMORONI_TRACKBALL_ENABLE
static bool     mouse_auto_layer          = false;
static bool     mouse_scrolling_mode      = false;
static uint16_t mouse_timer               = 0;
static bool     mouse_enable_acceleration = true;
static bool     mouse_lock                = false;
static bool     mouse_key_pressed         = false;

bool process_record_pointing(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MS_UP ... KC_MS_ACCEL2:
        case MOUSE_SCROLL:
        case MOUSE_LOCK:
        case MOUSE_ACCEL:
        case LT(_MOUSE, KC_Q):
            mouse_key_pressed = record->event.pressed;
            break;
    }

    switch (keycode) {
        case MOUSE_AUTO_LAYER:
            if (record->event.pressed) {
                mouse_auto_layer = !mouse_auto_layer;
            }
            return false;

        case MOUSE_ACCEL:
            if (record->event.pressed) {
                mouse_enable_acceleration = !mouse_enable_acceleration;
            }
            return false;

        case MOUSE_LOCK:
            if (record->event.pressed) {
                mouse_lock = !mouse_lock;
            }
            return false;

        case MOUSE_SCROLL:
            mouse_scrolling_mode = record->event.pressed;
            // if (record->event.pressed) {
            //     mouse_scrolling_mode = !mouse_scrolling_mode;
            // }
            return false;
    }

    return true;
}
#endif

layer_state_t layer_state_set_pointing(layer_state_t state) {
#if PIMORONI_TRACKBALL_ENABLE
    pointing_device_set_cpi(8000);
    switch (get_highest_layer(state)) {
        case _MOUSE:
            // pointing_device_set_cpi(8000);
            pimoroni_trackball_set_rgbw(0, 0, 255, 0);
            break;

        case _VIM:
            // pointing_device_set_cpi(8000);
            pimoroni_trackball_set_rgbw(0, 255, 0, 0);
            break;

        default:
            // pointing_device_set_cpi(30000);
            pimoroni_trackball_set_rgbw(0, 0, 0, 0);
            break;
    }
#endif
    return state;
}

#ifdef PIMORONI_TRACKBALL_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    static int8_t x, y = 0;
    // x = (x == 0 && mouse_report.x > 0 && mouse_report.x < 10) ? 1 : mouse_report.x;
    // y = (y == 0 && mouse_report.y > 0 && mouse_report.y < 10) ? 1 : mouse_report.y;

    x = mouse_report.x, y = mouse_report.y;
    mouse_report.x = 0;
    mouse_report.y = 0;

    if (x != 0 || y != 0 || mouse_key_pressed) {
        uprintf("x:%d y:%d\n", x, y);
        mouse_timer = timer_read();

        if (mouse_scrolling_mode) {
            mouse_report.h = x / 2;
            mouse_report.v = -y / 2;
            return mouse_report;
        }

        if (mouse_enable_acceleration && !mouse_scrolling_mode) {
            x = (x > 0 ? x * x / 2 + x : -x * x / 2 + x);
            y = (y > 0 ? y * y / 2 + y : -y * y / 2 + y);
        }
        mouse_report.x = x;
        mouse_report.y = y;
        if (mouse_auto_layer && !layer_state_is(_MOUSE)) {
            layer_on(_MOUSE);
        }
    } else if (mouse_auto_layer && timer_elapsed(mouse_timer) > 650 && layer_state_is(_MOUSE) && !mouse_key_pressed) {
        layer_off(_MOUSE);
    }

    return mouse_report;
}
#endif
