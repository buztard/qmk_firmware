
# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE = WS2812  # Enable RGB matrix.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
VELOCIKEY_ENABLE = no       # Enable Velocikey feature.
OLED_DRIVER_ENABLE = yes    # OLED_ENABLE (+5000)

TAP_DANCE_ENABLE = yes
LEADER_ENABLE = no
RGB_MATRIX_CUSTOM_USER ?= yes

LINK_TIME_OPTIMIZATION_ENABLE = yes


# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend
RAW_ENABLE = no

BOOTLOADER = atmel-dfu

UNICODEMAP_ENABLE = no

# ifeq ($(strip $(FLAVOR)), $(filter $(strip $(FLAVOR)), godspeed dasher))
# 	TAP_DANCE_ENABLE = yes
# 	LEADER_ENABLE = yes
# endif

# This board is about RGB, no unnecessary stuff!
# All Colors Are Beautiful :)
ifeq ($(strip $(FLAVOR)), acab)
	EXTRAKEY_ENABLE = no
	MOUSEKEY_ENABLE = no
	TAP_DANCE_ENABLE = no
	LEADER_ENABLE = no
	RGB_MATRIX_CUSTOM_USER = no
	OLED_DRIVER_ENABLE = no
endif

ifeq ($(strip $(TRACKPOINT)), yes)
	PS2_MOUSE_ENABLE = yes
	PS2_USE_INT = yes
endif
