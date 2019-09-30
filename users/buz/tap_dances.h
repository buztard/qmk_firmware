#pragma once

// tap dance keycodes
enum {
    TD_LALT = 0,
    TD_RALT,
    TD_F
};

typedef enum {
    SINGLE_TAP,
    SINGLE_SHORT_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    TRIPLE_TAP,
    TRIPLE_HOLD,
    TRIPLE_SINGLE_TAP,
    TAP_END
} td_state_t;

