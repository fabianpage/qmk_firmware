# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
ORYX_ENABLE = yes
# RGB_MATRIX_CUSTOM_KB = yes
SPACE_CADET_ENABLE = no
COMBO_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes
LAYER_LOCK_ENABLE = yes
KEY_LOCK_ENABLE = yes

SRC += features/layer_lock.c
TRI_LAYER_ENABLE = yes
