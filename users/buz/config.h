#pragma once

#define TAPPING_FORCE_HOLD
#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#    define TAPPING_TERM 200
#endif

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250

#ifndef LEADER_ENABLE
#    define KC_LEAD KC_TRANSPARENT
#endif
