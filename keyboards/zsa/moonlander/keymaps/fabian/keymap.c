#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#include "features/layer_lock.h"

enum custom_keycodes {
  // RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0 = SAFE_RANGE,
  LLCK,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 QK_DYNAMIC_TAPPING_TERM_UP,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,
    KC_TRANSPARENT, MT(MOD_LCTL, KC_P),KC_O,           KC_I,           KC_U,           KC_T,           KC_TRANSPARENT,                                 QK_DYNAMIC_TAPPING_TERM_PRINT,MT(MOD_LALT, KC_T),MT(MOD_LCTL, KC_U),KC_I,           MT(MOD_LGUI, KC_O),KC_P,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_S,           MT(MOD_LSFT, KC_A),KC_E,           KC_R,           LT(4,KC_N),     KC_TRANSPARENT,                                                                 QK_DYNAMIC_TAPPING_TERM_DOWN,LT(4,KC_N),     MT(MOD_LSFT, KC_R),KC_E,           MT(MOD_LSFT, KC_A),MT(MOD_LALT, KC_S),KC_TRANSPARENT,
    KC_TRANSPARENT, MT(MOD_LGUI, KC_D),KC_L,           KC_C,           KC_V,           KC_H,                                           KC_H,           MT(MOD_LGUI, KC_V),KC_C,           MT(MOD_LCTL, KC_L),KC_D,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    LT(3,KC_SPACE), LT(TL_LOWR,KC_ENTER), LT(TL_UPPR,KC_TAB),                   LT(2,KC_TAB),   LT(1,KC_ENTER), OSL(3)
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_BSPC,        KC_HOME,        KC_PAGE_UP,     KC_PGDN,        KC_END,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         CH_QST,         KC_TRANSPARENT,
    KC_TRANSPARENT, CH_DLR,         KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       CH_EXLM,        KC_TRANSPARENT,
    KC_TRANSPARENT, LLCK,        OSM(MOD_LGUI),  OSM(MOD_LALT),  OSM(MOD_LCTL),  CH_PERC,                                        CH_PERC,        OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LGUI),  LLCK,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, CH_BSLS,        KC_COMMA,       KC_DOT,         CH_SLSH,        KC_TRANSPARENT,                                 KC_TRANSPARENT, CH_SLSH,        KC_DOT,         KC_COMMA,       CH_BSLS,        CH_AT,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, CH_LCBR,        CH_LBRC,        CH_LPRN,        CH_LESS,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, CH_LESS,        CH_LPRN,        CH_LBRC,        CH_LCBR,        CH_PAST,        KC_TRANSPARENT,
    KC_TRANSPARENT, LLCK,        CH_RCBR,        CH_RBRC,        CH_RPRN,        CH_MORE,                                        CH_MORE,        CH_RPRN,        CH_RBRC,        CH_RCBR,        LLCK,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_X,           KC_Q,           KC_W,           KC_M,           CH_Z,           KC_TRANSPARENT,                                 KC_TRANSPARENT, CH_Z,           KC_M,           KC_W,           KC_Q,           KC_X,           KC_TRANSPARENT,
    KC_TRANSPARENT, CH_DLR,         CH_AE,          CH_OE,          KC_F,           LT(5,KC_G),     KC_TRANSPARENT,                                                                 KC_TRANSPARENT, LT(5,KC_G),     MT(MOD_LSFT, KC_F),CH_OE,          MT(MOD_LSFT, CH_AE),CH_DLR,         KC_TRANSPARENT,
    KC_TRANSPARENT, CH_UE,          CH_Y,           KC_K,           KC_J,           KC_B,                                           KC_B,           KC_J,           KC_K,           CH_Y,           CH_UE,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_9,           KC_8,           KC_7,           KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           CH_PLUS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_0,           KC_3,           KC_2,           KC_1,           KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, LLCK,        KC_6,           KC_5,           KC_4,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           LLCK,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_F9,          KC_F8,          KC_F7,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F10,         KC_F3,          KC_F2,          KC_F1,          KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F10,         KC_TRANSPARENT,
    KC_TRANSPARENT, LLCK,        KC_F6,          KC_F5,          KC_F4,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F4,          KC_F5,          KC_F6,          LLCK,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};
const uint16_t PROGMEM combo0[] = { MT(MOD_LGUI, KC_O), KC_P, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_END, CH_QST, COMBO_END};
const uint16_t PROGMEM combo2[] = { CH_AT, CH_BSLS, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_Q, KC_X, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_9, CH_PLUS, COMBO_END};
const uint16_t PROGMEM combo5[] = { MT(MOD_LCTL, KC_U), MT(MOD_LALT, KC_T), COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_DOWN, KC_UP, COMBO_END};
const uint16_t PROGMEM combo7[] = { CH_OE, MT(MOD_LSFT, KC_F), COMBO_END};
const uint16_t PROGMEM combo8[] = { MT(MOD_LSFT, KC_R), KC_E, COMBO_END};
const uint16_t PROGMEM combo9[] = { MT(MOD_LSFT, KC_A), MT(MOD_LALT, KC_S), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_BSPC),
    COMBO(combo1, KC_BSPC),
    COMBO(combo2, KC_BSPC),
    COMBO(combo3, KC_BSPC),
    COMBO(combo4, KC_BSPC),
    COMBO(combo5, KC_ESCAPE),
    COMBO(combo6, KC_SPACE),
    COMBO(combo7, KC_SPACE),
    COMBO(combo8, KC_SPACE),
    COMBO(combo9, ST_MACRO_0),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {152,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255} },

    [1] = { {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255} },

    [2] = { {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

// bool rgb_matrix_indicators_user(void) {
//   if (rawhid_state.rgb_control) {
//       return false;
//   }
//   if (keyboard_config.disable_layer_led) { return false; }
//   switch (biton32(layer_state)) {
//     case 0:
//       set_layer_color(0);
//       break;
//     case 1:
//       set_layer_color(1);
//       break;
//     case 2:
//       set_layer_color(2);
//       break;
//    default:
//     if (rgb_matrix_get_flags() == LED_FLAG_NONE)
//       rgb_matrix_set_color_all(0, 0, 0);
//     break;
//   }
//   return true;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_layer_lock(keycode, record, LLCK)) { return false; }
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_S) SS_DELAY(10) SS_TAP(X_C) SS_DELAY(10) SS_TAP(X_H));
    }
    break;

    // case RGB_SLD:
    //     if (rawhid_state.rgb_control) {
    //         return false;
    //     }
    //     if (record->event.pressed) {
    //         rgblight_mode(1);
    //     }
    //     return false;
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, 1, 2, 4);
  state = update_tri_layer_state(state, 2, 3, 5);
  return state;
}

