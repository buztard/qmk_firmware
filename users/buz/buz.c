#include "buz.h"

__attribute__ ((weak))
void layer_state_set_rgb(uint32_t state) {}

__attribute__ ((weak))
uint32_t layer_state_set_keymap (uint32_t state) {
  return state;
}

#if 0
__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      break;
  }
  return process_record_keymap(keycode, record);
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
  state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
  layer_state_set_rgb(state);
  return layer_state_set_keymap(state);
}

// TODO
#if defined(RAW_ENABLE) && defined(RAW_PROTO_FUN)
void raw_hid_receive(uint8_t *data, uint8_t length)
{
  raw_hid_send(data, length);
}
#endif
