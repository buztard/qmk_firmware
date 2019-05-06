#include "quantum.h"

#ifdef UNICODEMAP_ENABLE
enum unicode_names {
  UC_SKULL,
};

const uint32_t PROGMEM unicode_map[] = {
  [UC_SKULL] = 0x2620, // ☠
};
#endif

#ifdef UCIS_ENABLE
const qk_ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE(
  UCIS_SYM("poop", 0x1F4A9), // 💩
  UCIS_SYM("rofl", 0x1F923), // 🤣
  UCIS_SYM("kiss", 0x1F619)  // 😙
);
#endif

void eeconfig_init_user(void) {
  set_unicode_input_mode(UC_LNX);
}
