#pragma once

// tap dance keycodes
enum {
    TD_LALT = 0,
    TD_RALT,
    TD_F,
    TD_RAISE,
    TD_SCLN,
    TD_O,
    TD_GUI,
    TD_SPC,
};

typedef enum {
    SINGLE_TAP,         // a single tap
    SINGLE_SHORT_TAP,   // single key press, interrupted by pressing another key
    SINGLE_HOLD,        // hold a single key until timeout
    DOUBLE_TAP,         // double tap
    DOUBLE_HOLD,        // tap once, then hold
    DOUBLE_SINGLE_TAP,  // two key presses, interrupted by pressing another key
    TRIPLE_TAP,         // triple tap
    TRIPLE_HOLD,        // two taps, then hold
    TRIPLE_SINGLE_TAP,  // three taps, interrupted by pressing another key
    TAP_END             // enough for now, close with a magic number...
} td_state_t;
