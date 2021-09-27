#include "encoder_stuff.h"
#include "quantum.h"

static encoder_mode_t encoder_modes[2];

void encoder_init_user(void) {
    encoder_modes[0] = ENCODER_MODE_VOLUME;
    encoder_modes[1] = ENCODER_MODE_PAGING;
}

static void encoder_volume(bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}

static void encoder_paging(bool clockwise) {
    if (clockwise) {
        tap_code(KC_PGUP);
    } else {
        tap_code(KC_PGDN);
    }
}

static void encoder_nav(bool clockwise) {
    if (clockwise) {
        tap_code(KC_UP);
    } else {
        tap_code(KC_DOWN);
    }
}

static void encoder_tmux_win(bool clockwise) {
    if (clockwise) {
        SEND_STRING(SS_LCTL("an"));
    } else {
        SEND_STRING(SS_LCTL("ap"));
    }
}

static void encoder_tmux_pane(bool clockwise) {
    if (clockwise) {
        SEND_STRING(SS_LCTL("a") "O");
    } else {
        SEND_STRING(SS_LCTL("a") "o");
    }
}

static void encoder_tmux_session(bool clockwise) {
    if (clockwise) {
        SEND_STRING(SS_LCTL("a") ")");
    } else {
        SEND_STRING(SS_LCTL("a") "(");
    }
}

static void encoder_mouse(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code16(KC_MS_RIGHT);
        } else {
            tap_code16(KC_MS_LEFT);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code16(KC_MS_UP);
        } else {
            tap_code16(KC_MS_DOWN);
        }
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    // encoder_mode_t mode;

    // if (index == 0) {
    //     mode = encoder_mode_0;
    // } else if (index == 1) {
    //     mode = encoder_mode_1;
    // } else {
    //     return;
    // }

    switch (encoder_modes[index]) {
        case ENCODER_MODE_VOLUME:
            encoder_volume(clockwise);
            break;
        case ENCODER_MODE_PAGING:
            encoder_paging(clockwise);
            break;
        case ENCODER_MODE_NAV:
            encoder_nav(clockwise);
            break;
        case ENCODER_MODE_TMUX_WIN:
            encoder_tmux_win(clockwise);
            break;
        case ENCODER_MODE_TMUX_PANE:
            encoder_tmux_pane(clockwise);
            break;
        case ENCODER_MODE_TMUX_SESSION:
            encoder_tmux_session(clockwise);
            break;
        case ENCODER_MODE_MOUSE:
            encoder_mouse(index, clockwise);
            break;
        default:
            break;
    }
    return true;
}

void encoder_mode_next(uint8_t index) {
    // if (index == 0) {
    //     encoder_mode_0 = encoder_mode_0 >= ENCODER_MODE_LAST - 1 ? 0 : encoder_mode_0 + 1;
    // } else if (index == 1) {
    //     encoder_mode_1 = encoder_mode_1 >= ENCODER_MODE_LAST - 1 ? 0 : encoder_mode_1 + 1;
    // }
    encoder_modes[index] = encoder_modes[index] >= ENCODER_MODE_LAST - 1 ? 0 : encoder_modes[index] + 1;
}

const char* encoder_mode_name(uint8_t index) {
    // encoder_mode_t mode;

    // if (index == 0) {
    //     mode = encoder_mode_0;
    // } else if (index == 1) {
    //     mode = encoder_mode_1;
    // } else {
    //     return NULL;
    // }

    switch (encoder_modes[index]) {
        case ENCODER_MODE_VOLUME:
            return PSTR("Vol");
        case ENCODER_MODE_PAGING:
            return PSTR("Pag");
        case ENCODER_MODE_NAV:
            return PSTR("Nav");
        case ENCODER_MODE_TMUX_WIN:
            return PSTR("Tmux Win");
        case ENCODER_MODE_TMUX_PANE:
            return PSTR("Tmux Pane");
        case ENCODER_MODE_TMUX_SESSION:
            return PSTR("Tmux Sess");
        case ENCODER_MODE_MOUSE:
            return PSTR("Mouse");
        default:
            return NULL;
    }
}
