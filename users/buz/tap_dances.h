#pragma once

// tap dance keycodes
enum {
    TD_RALT = 0
};

typedef struct {
    bool is_press_action;
    int state;
} tap_state;

typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    TAP_END
} td_state_t;

