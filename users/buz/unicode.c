#include "quantum.h"

#ifdef UNICODEMAP_ENABLE
enum unicode_names {
    UC_SKULL,
    UC_SKULL_CROSS,
    UC_ROFL,
    UC_KISS,
    UC_ZZZ,
    UC_BOMB,
    UC_HEART,
    UC_BROKEN_HEART,
    UC_BEER,
    UC_BEERS,
    UC_GHOST,
    UC_OK,
    UC_POOP,
    UC_MUSCLE,
    UC_ROCKET,
};

const uint32_t PROGMEM unicode_map[] = {
    [UC_SKULL]        = 0x1F480, // 💀
    [UC_SKULL_CROSS]  = 0x2620,  // ☠
    [UC_ROFL]         = 0x1F923, // 🤣
    [UC_KISS]         = 0x1F619, // 😙
    [UC_ZZZ]          = 0x1F4A4, // 💤
    [UC_BOMB]         = 0x1F4A3, // 💣
    [UC_HEART]        = 0xFE0F,  // ♥️
    [UC_BROKEN_HEART] = 0x1F494, // 💔
    [UC_BEER]         = 0x1F37A, // 🍺
    [UC_BEERS]        = 0x1F37B, // 🍻
    [UC_GHOST]        = 0x1F47B, // 👻
    [UC_OK]           = 0x1F44C, // 👌
    [UC_POOP]         = 0x1F4A9, // 💩
    [UC_MUSCLE]       = 0x1F4AA, // 💪
    [UC_ROCKET]       = 0x1F680, // 🚀
};
#endif

#ifdef UCIS_ENABLE
// clang-format off
const qk_ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE(
  UCIS_SYM("skull", 0x1F480), // 💀
  UCIS_SYM("skullc", 0x2620),  // ☠
  UCIS_SYM("rofl", 0x1F923), // 🤣
  UCIS_SYM("kiss", 0x1F619), // 😙
  UCIS_SYM("zzz", 0x1F4A4), // 💤
  UCIS_SYM("bomb", 0x1F4A3), // 💣
  UCIS_SYM("heart", 0xFE0F),  // ♥️
  UCIS_SYM("bheart", 0x1F494), // 💔
  UCIS_SYM("beer", 0x1F37A), // 🍺
  UCIS_SYM("beers", 0x1F37B), // 🍻
  UCIS_SYM("ghost", 0x1F47B), // 👻
  UCIS_SYM("ok", 0x1F44C), // 👌
  UCIS_SYM("poop", 0x1F4A9), // 💩
  UCIS_SYM("muscle", 0x1F4AA), // 💪
  UCIS_SYM("rocket", 0x1F680) // 🚀
);
// clang-format on
#endif
