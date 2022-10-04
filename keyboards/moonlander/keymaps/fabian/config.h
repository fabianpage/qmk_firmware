/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#pragma once
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 151

#define TAPPING_FORCE_HOLD

#undef IGNORE_MOD_TAP_INTERRUPT

#define USB_SUSPEND_WAKEUP_DELAY 0
#define CAPS_LOCK_STATUS
#define RGB_MATRIX_STARTUP_SPD 60

// #define AUTO_SHIFT_TIMEOUT 200
// #define NO_AUTO_SHIFT_SPECIAL
// #define NO_AUTO_SHIFT_NUMERIC
