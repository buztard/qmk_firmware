#include "buz.h"

#ifdef LEADER_ENABLE
LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        // XXX: This is still shitty. Need to find a better place for this.
        leading = false;
        leader_end();

#    ifndef LEADER_ON_KEY_PROCESSING
        SEQ_ONE_KEY(KC_S) { SEND_STRING(SS_LCTRL("a") "s" SS_LCTRL("s")); }

        SEQ_THREE_KEYS(KC_G, KC_O, KC_S) { SEND_STRING(SS_LGUI("2") SS_LALT("1")); }

        SEQ_THREE_KEYS(KC_G, KC_O, KC_G) { SEND_STRING(SS_LGUI("2") SS_LALT("2")); }

        SEQ_THREE_KEYS(KC_G, KC_O, KC_J) { SEND_STRING(SS_LGUI("2") SS_LALT("3")); }
#    endif
    }
}

bool leader_on_key(void) {
    SEQ_ONE_KEY(KC_S) { SEND_STRING(SS_LCTRL("a") "s" SS_LCTRL("s")); return true; }

    SEQ_THREE_KEYS(KC_G, KC_O, KC_S) { SEND_STRING(SS_LGUI("2") SS_LALT("1")); return true; }

    SEQ_THREE_KEYS(KC_G, KC_O, KC_G) { SEND_STRING(SS_LGUI("2") SS_LALT("2")); return true; }

    return false;
}
#endif
