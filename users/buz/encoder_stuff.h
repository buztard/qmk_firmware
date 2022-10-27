#pragma once
#include "quantum.h"

typedef enum {
    ENCODER_MODE_VOLUME = 0,
    ENCODER_MODE_PAGING,
    ENCODER_MODE_NAV,
    ENCODER_MODE_TMUX_WIN,
    ENCODER_MODE_TMUX_PANE,
    ENCODER_MODE_TMUX_SESSION,
    ENCODER_MODE_MOUSE,
    ENCODER_MODE_LAST,
} encoder_mode_t;

encoder_mode_t encoder_mode_0;
encoder_mode_t encoder_mode_1;

void encoder_init_user(void);

void encoder_mode_next(uint8_t index);

const char* encoder_mode_name(uint8_t index);

bool encoder_update_keymap(uint8_t index, bool clockwise);
