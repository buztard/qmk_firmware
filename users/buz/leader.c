#include "buz.h"

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        // XXX: This is still shitty. Need to find a better place for this.
        leading = false;
        leader_end();

        SEQ_TWO_KEYS(KC_T, KC_F) {
            SEND_STRING("hello world");
        }

        SEQ_ONE_KEY(KC_S) {
            SEND_STRING(SS_LCTRL("a") "s" SS_LCTRL("s"));
        }

        SEQ_THREE_KEYS(KC_G, KC_O, KC_S) {
            SEND_STRING(SS_LGUI("2") SS_LALT("1"));
        }

        SEQ_THREE_KEYS(KC_G, KC_O, KC_G) {
            SEND_STRING(SS_LGUI("2") SS_LALT("2"));
        }

        SEQ_THREE_KEYS(KC_G, KC_O, KC_J) {
            SEND_STRING(SS_LGUI("2") SS_LALT("3"));
        }
    }
}
