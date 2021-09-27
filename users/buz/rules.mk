# Default build options that work for most of my boards
BOOTMAGIC_ENABLE ?= no # Virtual DIP switch configuration
MOUSEKEY_ENABLE ?= yes # Mouse keys
EXTRAKEY_ENABLE ?= yes # Audio control and System control
CONSOLE_ENABLE ?= no   # Console for debug
COMMAND_ENABLE ?= no   # Commands for debug and configuration
BACKLIGHT_ENABLE ?= no # Enable keyboard backlight functionality
TAP_DANCE_ENABLE ?= no # Enable Tap Dance feature.
LEADER_ENABLE = ?no    # Enable leader key.
GRAVE_ESC_ENABLE ?= no

# we're using a custom hack instead
SPACE_CADET_ENABLE ?= no

ifneq ($(PLATFORM),CHIBIOS)
    ifneq ($(strip $(LTO_SUPPORTED)), no)
        LTO_ENABLE = yes
    endif
endif

SRC += buz.c tapping.c

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
ifeq ($(strip $(OLED_ENABLE)), yes)
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

ifeq ($(strip $(COMBO_ENABLE)), yes)
  SRC += combos.c
endif

ifeq ($(strip $(ENCODER_ENABLE)), yes)
  SRC += encoder_stuff.c
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
ifeq ($(strip $(FLAVOR)), leviathan)
	OPT_DEFS += -DFLAVOR_LEVIATHAN -DFLAVOR=\"leviathan\"
endif
ifeq ($(strip $(FLAVOR)), dev/tty)
	OPT_DEFS += -DFLAVOR_DEV_TTY -DFLAVOR=\"dev/tty\"
endif
ifeq ($(strip $(FLAVOR)), troubledminds)
	OPT_DEFS += -DFLAVOR_TROUBLED_MINDS -DFLAVOR=\"troubledminds\"
endif
ifeq ($(strip $(FLAVOR)), symbiosis)
	OPT_DEFS += -DFLAVOR_SYMBIOSIS -DFLAVOR=\"symbiosis\"
endif
ifeq ($(strip $(FLAVOR)), bigbang)
	OPT_DEFS += -DFLAVOR_BIG_BANG -DFLAVOR=\"bigbang\"
endif
ifeq ($(strip $(FLAVOR)), acab)
	OPT_DEFS += -DFLAVOR_ACAB -DFLAVOR=\"acab\"
endif
ifeq ($(strip $(FLAVOR)), serika)
	OPT_DEFS += -DFLAVOR_SERIKA -DFLAVOR=\"serika\"
endif
ifeq ($(strip $(FLAVOR)), canvas)
	OPT_DEFS += -DFLAVOR_CANVAS -DFLAVOR=\"canvas\"
endif
ifeq ($(strip $(FLAVOR)), milkshake)
	OPT_DEFS += -DFLAVOR_MILKSHAKE -DFLAVOR=\"milkshake\"
endif
ifeq ($(strip $(FLAVOR)), susuwatari)
	OPT_DEFS += -DFLAVOR_SUSUWATARI -DFLAVOR=\"susuwatari\"
endif
