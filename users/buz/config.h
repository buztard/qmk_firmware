#pragma once

#define TAPPING_FORCE_HOLD
#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif
#define TAPPING_TERM 200

#define LEADER_PER_KEY_TIMING
#ifdef LEADER_TIMEOUT
#    undef LEADER_TIMEOUT
#endif
#define LEADER_TIMEOUT 500

#ifndef LEADER_ENABLE
#    define KC_LEAD KC_TRANSPARENT
#endif
