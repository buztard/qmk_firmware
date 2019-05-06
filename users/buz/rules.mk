SRC += buz.c

ifeq ($(PLATFORM), AVR)
  EXTRAFLAGS += -flto
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
  SRC += tap_dances.c
endif

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
  SRC += rgb_stuff.c
endif

ifneq ($(strip $(RGB_MATRIX_ENABLE)), no)
  SRC += rgb_stuff.c
endif

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
  SRC += oled_stuff.c
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
