#include "quantum.h"

#ifdef UNICODEMAP_ENABLE
enum unicode_names {
  UC_SKULL,
  UC_SKULL_CROSS,
  UC_ROFL,
  UC_KISS,
  UC_ZZZ,
  UC_BOMB,
  UC_BROKEN_HEART,
  UC_BEER,
  UC_BEERS,
  UC_GHOST,
  UC_OK,
};

const uint32_t PROGMEM unicode_map[] = {
  [UC_SKULL] = 0x1F480, // 💀
  [UC_SKULL_CROSS] = 0x2620, // ☠
  [UC_ROFL] = 0x1F923, // 🤣
  [UC_KISS] = 0x1F619,  // 😙
  [UC_ZZZ] = 0x1F4A4,  // 💤
  [UC_BOMB] = 0x1F4A3,  // 💣
  [UC_BROKEN_HEART] = 0x1F494, // 💔
  [UC_BEER] = 0x1F37A, // 🍺
  [UC_BEERS] = 0x1F37B, // 🍻
  [UC_GHOST] = 0x1F47B, // 👻
  [UC_OK] = 0x1F44C, // 👌
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
