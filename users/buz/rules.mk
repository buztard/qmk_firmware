MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes

SRC += buz.c

ifeq ($(PLATFORM), AVR)
  EXTRAFLAGS += -flto
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
  SRC += tap_dances.c
endif

ifeq ($(strip $(LEADER_ENABLE)), yes)
  SRC += leader.c
endif

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
  SRC += rgb.c
endif

ifneq ($(strip $(RGB_MATRIX_ENABLE)), no)
  SRC += rgb.c
endif

OLED_EXTRAS ?= yes
ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
  SRC += oled_stuff.c
  ifeq ($(strip $(OLED_EXTRAS)), yes)
	OPT_DEFS += -DOLED_EXTRAS
  endif
endif

ifeq ($(strip $(UCIS_ENABLE)), yes)
  SRC += unicode.c
endif

ifeq ($(strip $(UNICODEMAP_ENABLE)), yes)
  SRC += unicode.c
endif

ifeq ($(strip $(UNICODE_ENABLE)), yes)
  SRC += unicode.c
endif

# settings for different flavors
ifeq ($(strip $(FLAVOR)), godspeed)
	OPT_DEFS += -DFLAVOR_GODSPEED -DFLAVOR=\"godspeed\"
endif
ifeq ($(strip $(FLAVOR)), dasher)
	OPT_DEFS += -DFLAVOR_DASHER -DFLAVOR=\"dasher\"
endif
ifeq ($(strip $(FLAVOR)), vilebloom)
	OPT_DEFS += -DFLAVOR_VILEBLOOM -DFLAVOR=\"vilebloom\"
endif
ifeq ($(strip $(FLAVOR)), leviatan)
	OPT_DEFS += -DFLAVOR_LEVIATAN -DFLAVOR=\"leviatan\"
endif
ifeq ($(strip $(FLAVOR)), tty)
	OPT_DEFS += -DFLAVOR_TTY -DFLAVOR=\"tty\"
endif
ifeq ($(strip $(FLAVOR)), acab)
	OPT_DEFS += -DFLAVOR_ACAB -DFLAVOR=\"acab\"
endif
