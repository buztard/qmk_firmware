MOUSEKEY_ENABLE  = yes # Mouse keys(+4700)
AUDIO_ENABLE     = yes # Audio output on port C6
TAP_DANCE_ENABLE = yes
LEADER_ENABLE    = yes

ifeq ($(strip $(KEYBOARD)), planck/rev6)
	RGBLIGHT_ENABLE  = yes # Enable WS2812 RGB underlight.
endif

SRC += muse.c
