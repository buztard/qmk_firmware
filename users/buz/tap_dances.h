#pragma once

// tap dance keycodes
enum {
    TD_LALT = 0,
    TD_RALT
};

typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    TRIPLE_TAP,
    TRIPLE_HOLD,
    TAP_END
} td_state_t;

