#pragma once

#include QMK_KEYBOARD_H

bool process_repeat(uint16_t keycode, keyrecord_t *record);

void process_repeat_post(void);
