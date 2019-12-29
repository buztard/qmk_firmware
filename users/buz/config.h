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

#ifdef RGB_MATRIX_ENABLE
// disable these modes as there are mult-keypress versions as well
#    ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#        define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    endif

#    ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#        define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    endif

#    ifndef DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#        define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    endif

#    ifdef DISABLE_RGB_MATRIX_SPLASH
#        define DISABLE_RGB_MATRIX_SPLASH
#    endif

#    ifdef DISABLE_RGB_MATRIX_SOLID_SPLASH
#        define DISABLE_RGB_MATRIX_SOLID_SPLASH
#    endif
#endif
