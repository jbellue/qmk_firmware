# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE        = no  # Enable Bootmagic Lite
CONSOLE_ENABLE          = no  # Console for debug
COMMAND_ENABLE          = no  # Commands for debug and configuration
MAGIC_ENABLE            = no  # Save space by not PROCESS_MAGIC, which is bootmagic with out the boot (+634)
LTO_ENABLE              = yes
SPLIT_KEYBOARD          = yes
SWAP_HANDS_ENABLE       = no

RGBLIGHT_ENABLE         = no  # Enable keyboard RGB underglow
BACKLIGHT_ENABLE        = no  # Enable keyboard backlight functionality

RGB_MATRIX_DRIVER       = WS2812
OLED_DRIVER             = SSD1306