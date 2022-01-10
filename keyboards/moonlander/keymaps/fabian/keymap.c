#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german_osx_ch.h"
// #include "keymap_nordic.h"
// #include "keymap_french.h"
// #include "keymap_spanish.h"
// #include "keymap_hungarian.h"
// #include "keymap_swedish.h"
// #include "keymap_br_abnt2.h"
// #include "keymap_canadian_multilingual.h"
// #include "keymap_german_ch.h"
// #include "keymap_german_osx.h"
// #include "keymap_jp.h"
// #include "keymap_korean.h"
// #include "keymap_bepo.h"
// #include "keymap_italian.h"
// #include "keymap_slovenian.h"
// #include "keymap_lithuanian_azerty.h"
// #include "keymap_danish.h"
// #include "keymap_norwegian.h"
// #include "keymap_portuguese.h"
// #include "keymap_contributions.h"
// #include "keymap_czech.h"
// #include "keymap_romanian.h"
// #include "keymap_russian.h"
// #include "keymap_uk.h"
// #include "keymap_estonian.h"
// #include "keymap_belgian.h"
// #include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  DE_LSPO,
  DE_RSPC,
  CH_LSPO,
  CH_RSPC,
};

//Tap Dance Declarations
enum {
  TD_ESC_CAPS = 0,
  TD_CTRL_ECKIG_OPEN,
  TD_CTRL_ECKIG_CLOSE,
  TD_SHIFT_RUND_OPEN,
  TD_SHIFT_RUND_CLOSE,
  TD_ALT_KLEINER,
  TD_ALT_GROESSER,
  TD_TILD,
  TD_CTRL_A_H,
  TD_CTRL_A_J,
  TD_CTRL_A_K,
  TD_CTRL_A_L,
  TD_CTRL_A_CB,
};

void ctrl_open_eckig_finished (qk_tap_dance_state_t *state, void *user_data);
void ctrl_open_eckig_reset (qk_tap_dance_state_t *state, void *user_data);
void ctrl_close_eckig_finished (qk_tap_dance_state_t *state, void *user_data);
void ctrl_close_eckig_reset (qk_tap_dance_state_t *state, void *user_data);
void shift_open_rund_finished (qk_tap_dance_state_t *state, void *user_data);
void shift_open_rund_reset (qk_tap_dance_state_t *state, void *user_data);
void shift_close_rund_finished (qk_tap_dance_state_t *state, void *user_data);
void shift_close_rund_reset (qk_tap_dance_state_t *state, void *user_data);
void alt_kleiner_finished (qk_tap_dance_state_t *state, void *user_data);
void alt_kleiner_reset (qk_tap_dance_state_t *state, void *user_data);
void alt_groesser_finished (qk_tap_dance_state_t *state, void *user_data);
void alt_groesser_reset (qk_tap_dance_state_t *state, void *user_data);
void tilde_finished (qk_tap_dance_state_t *state, void *user_data);
void tilde_reset (qk_tap_dance_state_t *state, void *user_data);
void ctrl_a_H_finished (qk_tap_dance_state_t *state, void *user_data);
void ctrl_a_H_reset (qk_tap_dance_state_t *state, void *user_data);
void ctrl_a_j_finished (qk_tap_dance_state_t *state, void *user_data);
void ctrl_a_j_reset (qk_tap_dance_state_t *state, void *user_data);
void ctrl_a_K_finished (qk_tap_dance_state_t *state, void *user_data);
void ctrl_a_K_reset (qk_tap_dance_state_t *state, void *user_data);
void ctrl_a_L_finished (qk_tap_dance_state_t *state, void *user_data);
void ctrl_a_L_reset (qk_tap_dance_state_t *state, void *user_data);
void ctrl_a_CB_finished (qk_tap_dance_state_t *state, void *user_data);
void ctrl_a_CB_reset (qk_tap_dance_state_t *state, void *user_data);
void ctrl_a(void);

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
  [TD_CTRL_ECKIG_OPEN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_open_eckig_finished, ctrl_open_eckig_reset),
  [TD_CTRL_ECKIG_CLOSE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_close_eckig_finished, ctrl_close_eckig_reset),
  [TD_SHIFT_RUND_OPEN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shift_open_rund_finished, shift_open_rund_reset),
  [TD_SHIFT_RUND_CLOSE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shift_close_rund_finished, shift_close_rund_reset),
  [TD_ALT_KLEINER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_kleiner_finished, alt_kleiner_reset),
  [TD_ALT_GROESSER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_groesser_finished, alt_groesser_reset),
  [TD_TILD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tilde_finished, tilde_reset),
  [TD_CTRL_A_H] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_a_H_finished, ctrl_a_H_reset),
  [TD_CTRL_A_J] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_a_j_finished, ctrl_a_j_reset),
  [TD_CTRL_A_K] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_a_K_finished, ctrl_a_K_reset),
  [TD_CTRL_A_L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_a_L_finished, ctrl_a_L_reset),
  [TD_CTRL_A_CB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_a_CB_finished, ctrl_a_CB_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_EQUAL,              KC_1,     KC_2,         KC_3,    KC_4,       KC_5,     KC_LEFT,                     KC_RIGHT,           KC_6,     KC_7,     KC_8,     KC_9,        KC_0,    KC_MINUS,
    KC_TAB,                KC_Q,     KC_W,         KC_E,    KC_R,       KC_T,     TG(1),                       TG(1),              CH_Z,     KC_U,     KC_I,     KC_O,        KC_P,    KC_TAB,
    TD(TD_CTRL_ECKIG_OPEN),KC_A,     KC_S,         KC_D,    KC_F,       KC_G,     KC_HYPR,                     KC_MEH,             KC_H,     KC_J,     KC_K,     KC_L,        CH_ODIA,   TD(TD_CTRL_ECKIG_CLOSE),
    TD(TD_SHIFT_RUND_OPEN),CH_Y,     KC_X,         KC_C,    KC_V,       KC_B,                                                      KC_N,     KC_M,     KC_COMMA, KC_DOT,      CH_MINS, TD(TD_SHIFT_RUND_CLOSE),
    TD(TD_ALT_KLEINER),    CH_LCBR,  KC_CAPSLOCK,  OSL(1),  KC_ESCAPE,            LALT_T(KC_APPLICATION),      LCTL_T(KC_ESCAPE),            KC_SPACE, OSL(2),   KC_CAPSLOCK, CH_RCBR, TD(TD_ALT_GROESSER),
                                                  KC_BSPACE, KC_LGUI, KC_DELETE,                                                OSL(3),     KC_RGUI,  KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, CH_ASTR,        CH_HASH,        CH_PLUS,        CH_MINS,        CH_AMPR,        KC_TRANSPARENT,                                 KC_TRANSPARENT, CH_DQUO,        CH_QUOT,        CH_BSLS,        CH_SLSH,        CH_QUES,         CH_UDIA,
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       CH_ODIA,          CH_ADIA,
    KC_TRANSPARENT, CH_DEG,        KC_CIRC,        KC_LBRACKET,    CH_CIRC,        CH_TILD,                                        CH_PIPE,        KC_GRAVE,         CH_ACUT,        CH_EQL,         KC_BSLASH,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_MOD,                                                                                                        RGB_TOG,        KC_TRANSPARENT, KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, CH_ASTR,        CH_HASH,        CH_PLUS,        CH_MINS,        CH_AMPR,        KC_TRANSPARENT,                                 KC_TRANSPARENT, CH_SLSH,        CH_QUOT,        CH_BSLS,        CH_SLSH,        CH_QUES,         CH_EXLM,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       CH_AT,          CH_DLR,
    KC_TRANSPARENT, CH_PERC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, CH_TILD,                                     CH_PIPE,        CH_GRV,         CH_ACUT,        CH_EQL,         KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    AU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,
    MU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    MU_MOD,         KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, TD(TD_CTRL_A_H), TD(TD_CTRL_A_J), TD(TD_CTRL_A_K), TD(TD_CTRL_A_L), KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(TD_TILD),                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, TD(TD_CTRL_A_CB),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_BACK
  ),
};


bool g_suspend_state = false;
rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151}, {169,185,151} },

    [1] = { {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184}, {76,192,184} },

    [3] = { {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154}, {0,177,154} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
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

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

// DELETE?
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_NONUS_HASH) SS_DELAY(100) SS_TAP(X_SPACE));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_SPACE));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_QUOTE));

    }
    break;
    case DE_LSPO:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_8);
      return false;
    case DE_RSPC:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_9);
      return false;
    case CH_LSPO:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_8);
      return false;
    case CH_RSPC:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_9);
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

typedef struct {
    bool is_press_action;
    // step needed?
    uint8_t step;
    int state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[2];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_8));
        tap_code16(LSFT(KC_8));
        tap_code16(LSFT(KC_8));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_8));
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_8)); break;
        case SINGLE_HOLD: register_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: register_code16(KC_CAPSLOCK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_8)); register_code16(LSFT(KC_8));
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_8)); break;
        case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: unregister_code16(KC_CAPSLOCK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_8)); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RSFT(KC_9));
        tap_code16(RSFT(KC_9));
        tap_code16(RSFT(KC_9));
    }
    if(state->count > 3) {
        tap_code16(RSFT(KC_9));
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(RSFT(KC_9)); break;
        case SINGLE_HOLD: register_code16(KC_RSHIFT); break;
        case DOUBLE_TAP: register_code16(KC_CAPSLOCK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RSFT(KC_9)); register_code16(RSFT(KC_9));
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(RSFT(KC_9)); break;
        case SINGLE_HOLD: unregister_code16(KC_RSHIFT); break;
        case DOUBLE_TAP: unregister_code16(KC_CAPSLOCK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RSFT(KC_9)); break;
    }
    dance_state[1].step = 0;
}

// qk_tap_dance_action_t tap_dance_actions[] = {
//         [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
//         [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
// };

// typedef struct {
//     bool is_press_action;
//     uint8_t step;
// } tap;


// static tap dance_state[2];

static tap ctrl_open_eckig_tap_state = {
  .is_press_action = true,
  .state = 0
};

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    //If count = 1, and it has been interrupted - it doesn't matter if it is pressed or not: Send SINGLE_TAP
    if (/*state->interrupted ||*/ state->pressed==0) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  //If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
  //with single tap. In example below, that means to send `xx` instead of `Escape`.
  else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else return 6; //magic number. At some point this method will expand to work for more presses
}


void ctrl_open_eckig_finished (qk_tap_dance_state_t *state, void *user_data) {
  ctrl_open_eckig_tap_state.state = cur_dance(state);
  switch (ctrl_open_eckig_tap_state.state) {
    case SINGLE_TAP:
      register_code(KC_RALT);
      register_code(CH_UDIA);
      break;
    case SINGLE_HOLD: register_code(KC_LCTRL); break;
    case DOUBLE_HOLD: register_code(KC_LCTRL); break;
  }
}

void ctrl_open_eckig_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (ctrl_open_eckig_tap_state.state) {
    case SINGLE_TAP:
      //unregister_code(CH_LBRC);
      unregister_code(KC_RALT);
      unregister_code(CH_UDIA);
      break;
    case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
    case DOUBLE_HOLD: unregister_code(KC_LCTRL); break;
  }
  ctrl_open_eckig_tap_state.state = 0;
}

static tap ctrl_close_eckig_tap_state = {
  .is_press_action = true,
  .state = 0
};

void ctrl_close_eckig_finished (qk_tap_dance_state_t *state, void *user_data) {
  ctrl_close_eckig_tap_state.state = cur_dance(state);
  switch (ctrl_close_eckig_tap_state.state) {
    case SINGLE_TAP:
      register_code(KC_RALT);
      register_code(KC_9);
      break;
    case SINGLE_HOLD: register_code(KC_LCTRL); break;
  }
}

void ctrl_close_eckig_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (ctrl_close_eckig_tap_state.state) {
    case SINGLE_TAP:
      unregister_code(KC_RALT);
      unregister_code(KC_9);
      break;
    case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
  }
  ctrl_close_eckig_tap_state.state = 0;
}




static tap shift_open_rund_tap_state = {
  .is_press_action = true,
  .state = 0
};

void shift_open_rund_finished (qk_tap_dance_state_t *state, void *user_data) {
  shift_open_rund_tap_state.state = cur_dance(state);
  switch (shift_open_rund_tap_state.state) {
    case SINGLE_TAP:
      register_code(KC_LSHIFT);
      register_code(KC_8);
      break;
    case SINGLE_HOLD: register_code(KC_LSHIFT); break;
    case DOUBLE_HOLD: register_code(KC_LSHIFT); break;
  }
}

void shift_open_rund_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (shift_open_rund_tap_state.state) {
    case SINGLE_TAP:
      //unregister_code(CH_LBRC);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_8);
      break;
    case SINGLE_HOLD: unregister_code(KC_LSHIFT); break;
    case DOUBLE_HOLD: unregister_code(KC_LSHIFT); break;
  }
  shift_open_rund_tap_state.state = 0;
}

static tap shift_close_rund_tap_state = {
  .is_press_action = true,
  .state = 0
};

void shift_close_rund_finished (qk_tap_dance_state_t *state, void *user_data) {
  shift_close_rund_tap_state.state = cur_dance(state);
  switch (shift_close_rund_tap_state.state) {
    case SINGLE_TAP:
      register_code(KC_LSHIFT);
      register_code(KC_9);
      break;
    case SINGLE_HOLD: register_code(KC_LSHIFT); break;
  }
}

void shift_close_rund_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (shift_close_rund_tap_state.state) {
    case SINGLE_TAP:
      //unregister_code(CH_LBRC);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_9);
      break;
    case SINGLE_HOLD: unregister_code(KC_LSHIFT); break;
  }
  shift_close_rund_tap_state.state = 0;
}





static tap alt_kleiner_tap_state = {
  .is_press_action = true,
  .state = 0
};

void alt_kleiner_finished (qk_tap_dance_state_t *state, void *user_data) {
  alt_kleiner_tap_state.state = cur_dance(state);
  switch (alt_kleiner_tap_state.state) {
    case SINGLE_TAP:
      register_code(CH_LABK);
      break;
    case SINGLE_HOLD: register_code(KC_LALT); break;
  }
}


void alt_kleiner_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (alt_kleiner_tap_state.state) {
    case SINGLE_TAP:
      unregister_code(CH_LABK);
      break;
    case SINGLE_HOLD: unregister_code(KC_LALT); break;
  }
  alt_kleiner_tap_state.state = 0;
}

static tap alt_groesser_tap_state = {
  .is_press_action = true,
  .state = 0
};

void alt_groesser_finished (qk_tap_dance_state_t *state, void *user_data) {
  alt_groesser_tap_state.state = cur_dance(state);
  switch (alt_groesser_tap_state.state) {
    case SINGLE_TAP:
      register_code(KC_LSHIFT);
      register_code(CH_LABK);
      break;
    case SINGLE_HOLD: register_code(KC_RALT); break;
  }
}

void alt_groesser_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (alt_groesser_tap_state.state) {
    case SINGLE_TAP:
      unregister_code(KC_LSHIFT);
      unregister_code(CH_LABK);
      break;
    case SINGLE_HOLD: unregister_code(KC_RALT); break;
  }
  alt_groesser_tap_state.state = 0;
}

static tap tilde_tap_state = {
  .is_press_action = true,
  .state = 0
};

void tilde_finished (qk_tap_dance_state_t *state, void *user_data) {
  tilde_tap_state.state = cur_dance(state);
  switch (tilde_tap_state.state) {
    case SINGLE_TAP:
      register_code(KC_RALT);
      register_code(CH_CIRC);
      //register_code(KC_SPACE);
      unregister_code(KC_RALT);
      unregister_code(CH_CIRC);
      register_code(KC_SPACE);
      unregister_code(KC_SPACE);
      break;
    // case SINGLE_HOLD: register_code(KC_RALT); break;
  }
}

void tilde_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (tilde_tap_state.state) {
    case SINGLE_TAP:
      break;
    // case SINGLE_HOLD: unregister_code(KC_RALT); break;
  }
  tilde_tap_state.state = 0;
}

void ctrl_a(void);
void ctrl_a(void) {
      register_code(KC_LCTRL);
      register_code(KC_A);
      unregister_code(KC_LCTRL);
      unregister_code(KC_A);
}

void pressLetter(int letter);
void pressLetter(int letter) {
      register_code(letter);
      unregister_code(letter);
}

void press2Letter(int letter1, int letter2);
void press2Letter(int letter1, int letter2) {
      register_code(letter1);
      register_code(letter2);
      unregister_code(letter1);
      unregister_code(letter2);
}

void cltr_a_plus(int letter);
void cltr_a_plus(int letter) {
  ctrl_a();
  pressLetter(letter);
}

void cltr_a_plus2(int letter1, int letter2);
void cltr_a_plus2(int letter1, int letter2) {
  ctrl_a();
  press2Letter(letter1, letter2);
}

static tap ctrl_a_H_tap_state = {
  .is_press_action = true,
  .state = 0
};

void ctrl_a_H_finished (qk_tap_dance_state_t *state, void *user_data) {
  ctrl_a_H_tap_state.state = cur_dance(state);
  switch (ctrl_a_H_tap_state.state) {
    case SINGLE_TAP:
      cltr_a_plus(KC_H);
      break;
    // case SINGLE_HOLD: register_code(KC_RALT); break;
  }
}

void ctrl_a_H_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (ctrl_a_H_tap_state.state) {
    case SINGLE_TAP:
      break;
    // case SINGLE_HOLD: unregister_code(KC_RALT); break;
  }
  ctrl_a_H_tap_state.state = 0;
}

static tap ctrl_a_j_tap_state = {
  .is_press_action = true,
  .state = 0
};

void ctrl_a_j_finished (qk_tap_dance_state_t *state, void *user_data) {
  ctrl_a_j_tap_state.state = cur_dance(state);
  switch (ctrl_a_j_tap_state.state) {
    case SINGLE_TAP:
      cltr_a_plus(KC_J);
      break;
    // case SINGLE_HOLD: register_code(KC_RALT); break;
  }
}

void ctrl_a_j_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (ctrl_a_j_tap_state.state) {
    case SINGLE_TAP:
      break;
    // case SINGLE_HOLD: unregister_code(KC_RALT); break;
  }
  ctrl_a_j_tap_state.state = 0;
}

static tap ctrl_a_K_tap_state = {
  .is_press_action = true,
  .state = 0
};

void ctrl_a_K_finished (qk_tap_dance_state_t *state, void *user_data) {
  ctrl_a_K_tap_state.state = cur_dance(state);
  switch (ctrl_a_K_tap_state.state) {
    case SINGLE_TAP:
      cltr_a_plus(KC_K);
      break;
    // case SINGLE_HOLD: register_code(KC_RALT); break;
  }
}

void ctrl_a_K_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (ctrl_a_K_tap_state.state) {
    case SINGLE_TAP:
      break;
    // case SINGLE_HOLD: unregister_code(KC_RALT); break;
  }
  ctrl_a_K_tap_state.state = 0;
}

static tap ctrl_a_L_tap_state = {
  .is_press_action = true,
  .state = 0
};

void ctrl_a_L_finished (qk_tap_dance_state_t *state, void *user_data) {
  ctrl_a_K_tap_state.state = cur_dance(state);
  switch (ctrl_a_L_tap_state.state) {
    case SINGLE_TAP:
      cltr_a_plus(KC_L);
      break;
    // case SINGLE_HOLD: register_code(KC_RALT); break;
  }
}

void ctrl_a_L_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (ctrl_a_L_tap_state.state) {
    case SINGLE_TAP:
      break;
    // case SINGLE_HOLD: unregister_code(KC_RALT); break;
  }
  ctrl_a_L_tap_state.state = 0;
}


static tap ctrl_a_CB_tap_state = {
  .is_press_action = true,
  .state = 0
};

void ctrl_a_CB_finished (qk_tap_dance_state_t *state, void *user_data) {
  ctrl_a_K_tap_state.state = cur_dance(state);
  switch (ctrl_a_CB_tap_state.state) {
    case SINGLE_TAP:
      cltr_a_plus2(KC_LSHIFT, KC_9);
      break;
    // case SINGLE_HOLD: register_code(KC_RALT); break;
  }
}

void ctrl_a_CB_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (ctrl_a_CB_tap_state.state) {
    case SINGLE_TAP:
      break;
    // case SINGLE_HOLD: unregister_code(KC_RALT); break;
  }
  ctrl_a_CB_tap_state.state = 0;
}

