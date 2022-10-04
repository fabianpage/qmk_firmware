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

enum custom_keycodes { CH_TILDE_A = ML_SAFE_RANGE, CH_GRV_A, CH_ACUT_A, CH_DIAE_A, CH_CIRC_A, CH_ODIA_C, CH_ADIA_C, CH_UDIA_C };

// Tap Dance Declarations
enum { TD_ESC_CAPS = 0, TD_CTRL_ECKIG_OPEN, TD_CTRL_ECKIG_CLOSE, TD_SHIFT_RUND_OPEN, TD_SHIFT_RUND_CLOSE, TD_ALT_KLEINER, TD_ALT_GROESSER, TD_ESC_COMMAND };

void ctrl_open_eckig_finished(qk_tap_dance_state_t *state, void *user_data);
void ctrl_open_eckig_reset(qk_tap_dance_state_t *state, void *user_data);
void ctrl_close_eckig_finished(qk_tap_dance_state_t *state, void *user_data);
void ctrl_close_eckig_reset(qk_tap_dance_state_t *state, void *user_data);
void shift_open_rund_finished(qk_tap_dance_state_t *state, void *user_data);
void shift_open_rund_reset(qk_tap_dance_state_t *state, void *user_data);
void shift_close_rund_finished(qk_tap_dance_state_t *state, void *user_data);
void shift_close_rund_reset(qk_tap_dance_state_t *state, void *user_data);
void alt_kleiner_finished(qk_tap_dance_state_t *state, void *user_data);
void alt_kleiner_reset(qk_tap_dance_state_t *state, void *user_data);
void alt_groesser_finished(qk_tap_dance_state_t *state, void *user_data);
void alt_groesser_reset(qk_tap_dance_state_t *state, void *user_data);
void esc_command_finished(qk_tap_dance_state_t *state, void *user_data);
void esc_command_reset(qk_tap_dance_state_t *state, void *user_data);

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS), [TD_CTRL_ECKIG_OPEN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_open_eckig_finished, ctrl_open_eckig_reset), [TD_CTRL_ECKIG_CLOSE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_close_eckig_finished, ctrl_close_eckig_reset), [TD_SHIFT_RUND_OPEN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shift_open_rund_finished, shift_open_rund_reset), [TD_SHIFT_RUND_CLOSE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shift_close_rund_finished, shift_close_rund_reset), [TD_ALT_KLEINER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_kleiner_finished, alt_kleiner_reset), [TD_ALT_GROESSER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_groesser_finished, alt_groesser_reset), [TD_ESC_COMMAND] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_command_finished, esc_command_reset),
    //   [TD_CTRL_A_H] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_a_H_finished, ctrl_a_H_reset),
    //   [TD_CTRL_A_J] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_a_j_finished, ctrl_a_j_reset),
    //   [TD_CTRL_A_K] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_a_K_finished, ctrl_a_K_reset),
    //   [TD_CTRL_A_L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_a_L_finished, ctrl_a_L_reset),
    //   [TD_CTRL_A_CB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_a_CB_finished, ctrl_a_CB_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_moonlander(CH_BSLS, CH_1, CH_2, CH_3, CH_4, CH_5, KC_MSTP, KC_MPLY, CH_6, CH_7, CH_8, CH_9, CH_0, CH_SLSH, KC_TAB, CH_Q, CH_W, CH_E, CH_R, CH_T, KC_MPRV, KC_MNXT, CH_Z, CH_U, CH_I, CH_O, CH_P, CH_UDIA, TD(TD_CTRL_ECKIG_OPEN), CH_A, CH_S, CH_D, CH_F, CH_G, KC_VOLD, KC_VOLU, CH_H, CH_J, CH_K, CH_L, CH_ODIA, TD(TD_CTRL_ECKIG_CLOSE), TD(TD_SHIFT_RUND_OPEN), CH_Y, CH_X, CH_C, CH_V, CH_B, CH_N, CH_M, CH_COMM, CH_DOT, CH_MINS, TD(TD_SHIFT_RUND_CLOSE), TD(TD_ALT_KLEINER), CH_LCBR, KC_CAPS, KC_ENTER, KC_SPACE, LCTL(CH_BSLS), KC_MUTE, KC_SPACE, KC_ENTER, KC_CAPS, CH_RCBR, TD(TD_ALT_GROESSER), OSL(1), TD(TD_ESC_COMMAND), KC_BACKSPACE, KC_BACKSPACE, TD(TD_ESC_COMMAND), OSL(2)),
    [1] = LAYOUT_moonlander(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS, KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_TRNS, CH_ACUT_A, CH_7, CH_8, CH_9, CH_AMPR, KC_TRNS, KC_TRNS, CH_HASH, CH_ASTR, CH_PLUS, CH_EXLM, CH_QUES, CH_UDIA_C, KC_TRNS, CH_GRV_A, CH_4, CH_5, CH_6, CH_AT, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, CH_ODIA_C, CH_ADIA, KC_TRNS, CH_PERC, CH_1, CH_2, CH_3, CH_TILDE_A, CH_PIPE, CH_QUOT, CH_DQUO, CH_DIAE, CH_DLR, CH_EQL, KC_TRNS, KC_TRNS, CH_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, CH_CIRC, KC_TRNS, KC_TRNS, KC_DEL, KC_DEL, KC_TRNS, KC_TRNS),
    [2] = LAYOUT_moonlander(KC_TRNS, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_TRNS, KC_TRNS, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_TRNS, KC_TRNS, CH_ACUT, CH_7, CH_8, CH_9, CH_AMPR, KC_TRNS, KC_TRNS, CH_HASH, CH_ASTR, CH_PLUS, CH_EXLM, CH_QUES, CH_UDIA_C, KC_TRNS, CH_GRV, CH_4, CH_5, CH_6, CH_EURO, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, CH_ODIA_C, CH_ADIA_C, KC_TRNS, CH_DEG, CH_1, CH_2, CH_3, CH_TILD, CH_PIPE, CH_QUOT, CH_DQUO, CH_DIAE_A, CH_DLR, CH_EQL, KC_TRNS, KC_TRNS, CH_0, KC_TRNS, KC_TRNS, CH_TILD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, CH_CIRC_A, KC_TRNS, KC_TRNS, KC_DEL, KC_DEL, KC_TRNS, KC_TRNS),
};

// bool g_suspend_state = false;
rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = {{146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254},
           {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}, {146, 72, 254}},
    [1] = {{0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230},
           {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}, {0, 137, 230}},
    [2] = {{111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237},
           {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}, {111, 102, 237}},
};

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    //   if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
    switch (biton32(layer_state)) {
        case 0:
            set_layer_color(0);
            break;
        case 1:
            set_layer_color(1);
            break;
        case 2:
            set_layer_color(2);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
}

// DELETE?
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CH_TILDE_A:
            if (record->event.pressed) {
                register_code(KC_RALT);
                register_code(CH_N);
                unregister_code(KC_RALT);
                unregister_code(CH_N);
                register_code(KC_SPACE);
                unregister_code(KC_SPACE);
            }
            return false;
        case CH_GRV_A:
            if (record->event.pressed) {
                register_code(KC_LSHIFT);
                register_code(CH_CIRC);
                unregister_code(KC_LSHIFT);
                unregister_code(CH_CIRC);
                register_code(KC_SPACE);
                unregister_code(KC_SPACE);
            }
            return false;
        case CH_ACUT_A:
            if (record->event.pressed) {
                register_code(KC_RALT);
                register_code(CH_CIRC);
                unregister_code(KC_RALT);
                unregister_code(CH_CIRC);
                register_code(KC_SPACE);
                unregister_code(KC_SPACE);
            }
            return false;
        case CH_DIAE_A:
            if (record->event.pressed) {
                register_code(CH_DIAE);
                unregister_code(CH_DIAE);
                register_code(KC_SPACE);
                unregister_code(KC_SPACE);
            }
            return false;
        case CH_CIRC_A:
            if (record->event.pressed) {
                register_code(CH_CIRC);
                unregister_code(CH_CIRC);
                register_code(KC_SPACE);
                unregister_code(KC_SPACE);
            }
            return false;
        case CH_ODIA_C:
            if (record->event.pressed) {
                register_code(CH_DIAE);
                unregister_code(CH_DIAE);
                register_code(KC_LSFT);
                register_code(CH_O);
                unregister_code(CH_O);
                unregister_code(KC_LSFT);
            }
            return false;
        case CH_ADIA_C:
            if (record->event.pressed) {
                register_code(CH_DIAE);
                unregister_code(CH_DIAE);
                register_code(KC_LSFT);
                register_code(CH_A);
                unregister_code(CH_A);
                unregister_code(KC_LSFT);
            }
            return false;
        case CH_UDIA_C:
            if (record->event.pressed) {
                register_code(CH_DIAE);
                unregister_code(CH_DIAE);
                register_code(KC_LSFT);
                register_code(CH_U);
                unregister_code(CH_U);
                unregister_code(KC_LSFT);
            }
            return false;
    }
    return true;
}

typedef struct {
    bool is_press_action;
    // step needed?
    uint8_t step;
    int     state;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, MORE_TAPS };

// static tap dance_state[2];

// uint8_t dance_step(qk_tap_dance_state_t *state);

// uint8_t dance_step(qk_tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed) return SINGLE_TAP;
//         else return SINGLE_HOLD;
//     } else if (state->count == 2) {
//         if (state->interrupted) return DOUBLE_SINGLE_TAP;
//         else if (state->pressed) return DOUBLE_HOLD;
//         else return DOUBLE_TAP;
//     }
//     return MORE_TAPS;
// }

// void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
// void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
// void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

// void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
//     if(state->count == 3) {
//         tap_code16(LSFT(KC_8));
//         tap_code16(LSFT(KC_8));
//         tap_code16(LSFT(KC_8));
//     }
//     if(state->count > 3) {
//         tap_code16(LSFT(KC_8));
//     }
// }

// void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
//     dance_state[0].step = dance_step(state);
//     switch (dance_state[0].step) {
//         case SINGLE_TAP: register_code16(LSFT(KC_8)); break;
//         case SINGLE_HOLD: register_code16(KC_LSHIFT); break;
//         case DOUBLE_TAP: register_code16(KC_CAPSLOCK); break;
//         case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_8)); register_code16(LSFT(KC_8));
//     }
// }

// void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
//     wait_ms(10);
//     switch (dance_state[0].step) {
//         case SINGLE_TAP: unregister_code16(LSFT(KC_8)); break;
//         case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
//         case DOUBLE_TAP: unregister_code16(KC_CAPSLOCK); break;
//         case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_8)); break;
//     }
//     dance_state[0].step = 0;
// }
// void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
// void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
// void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

// void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
//     if(state->count == 3) {
//         tap_code16(RSFT(KC_9));
//         tap_code16(RSFT(KC_9));
//         tap_code16(RSFT(KC_9));
//     }
//     if(state->count > 3) {
//         tap_code16(RSFT(KC_9));
//     }
// }

// void dance_1_finished(qk_tap_dance_state_t *state, void *user_data)
//     dance_state[1].step = dance_step(state);
//     switch (dance_state[1].step) {
//         case SINGLE_TAP: register_code16(RSFT(KC_9)); break;
//         case SINGLE_HOLD: register_code16(KC_RSHIFT); break;
//         case DOUBLE_TAP: register_code16(KC_CAPSLOCK); break;
//         case DOUBLE_SINGLE_TAP: tap_code16(RSFT(KC_9)); register_code16(RSFT(KC_9));
//     }
// }

// void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
//     wait_ms(10);
//     switch (dance_state[1].step) {
//         case SINGLE_TAP: unregister_code16(RSFT(KC_9)); break;
//         case SINGLE_HOLD: unregister_code16(KC_RSHIFT); break;
//         case DOUBLE_TAP: unregister_code16(KC_CAPSLOCK); break;
//         case DOUBLE_SINGLE_TAP: unregister_code16(RSFT(KC_9)); break;
//     }
//     dance_state[1].step = 0;
// }

// qk_tap_dance_action_t tap_dance_actions[] = {
//         [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
//         [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
// };

// typedef struct {
//     bool is_press_action;
//     uint8_t step;
// } tap;

// static tap dance_state[2];

static tap ctrl_open_eckig_tap_state = {.is_press_action = true, .state = 0};

int cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        // If count = 1, and it has been interrupted - it doesn't matter if it is pressed or not: Send SINGLE_TAP
        if (/*state->interrupted ||*/ state->pressed == 0)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    }
    // If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
    // with single tap. In example below, that means to send `xx` instead of `Escape`.
    else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    } else
        return 6; // magic number. At some point this method will expand to work for more presses
}

void ctrl_open_eckig_finished(qk_tap_dance_state_t *state, void *user_data) {
    ctrl_open_eckig_tap_state.state = cur_dance(state);
    switch (ctrl_open_eckig_tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_RALT);
            register_code(CH_5);
            break;
        case SINGLE_HOLD:
            register_code(KC_LCTRL);
            break;
        case DOUBLE_HOLD:
            register_code(KC_LCTRL);
            break;
    }
}

void ctrl_open_eckig_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ctrl_open_eckig_tap_state.state) {
        case SINGLE_TAP:
            // unregister_code(CH_LBRC);
            unregister_code(KC_RALT);
            unregister_code(CH_5);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LCTRL);
            break;
        case DOUBLE_HOLD:
            unregister_code(KC_LCTRL);
            break;
    }
    ctrl_open_eckig_tap_state.state = 0;
}

static tap ctrl_close_eckig_tap_state = {.is_press_action = true, .state = 0};

void ctrl_close_eckig_finished(qk_tap_dance_state_t *state, void *user_data) {
    ctrl_close_eckig_tap_state.state = cur_dance(state);
    switch (ctrl_close_eckig_tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_RALT);
            register_code(KC_6);
            break;
        case SINGLE_HOLD:
            register_code(KC_LCTRL);
            break;
    }
}

void ctrl_close_eckig_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ctrl_close_eckig_tap_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_RALT);
            unregister_code(KC_6);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LCTRL);
            break;
    }
    ctrl_close_eckig_tap_state.state = 0;
}

static tap shift_open_rund_tap_state = {.is_press_action = true, .state = 0};

void shift_open_rund_finished(qk_tap_dance_state_t *state, void *user_data) {
    shift_open_rund_tap_state.state = cur_dance(state);
    switch (shift_open_rund_tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_LSHIFT);
            register_code(KC_8);
            break;
        case SINGLE_HOLD:
            register_code(KC_LSHIFT);
            break;
        case DOUBLE_HOLD:
            register_code(KC_LSHIFT);
            break;
    }
}

void shift_open_rund_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (shift_open_rund_tap_state.state) {
        case SINGLE_TAP:
            // unregister_code(CH_LBRC);
            unregister_code(KC_LSHIFT);
            unregister_code(KC_8);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LSHIFT);
            break;
        case DOUBLE_HOLD:
            unregister_code(KC_LSHIFT);
            break;
    }
    shift_open_rund_tap_state.state = 0;
}

static tap shift_close_rund_tap_state = {.is_press_action = true, .state = 0};

void shift_close_rund_finished(qk_tap_dance_state_t *state, void *user_data) {
    shift_close_rund_tap_state.state = cur_dance(state);
    switch (shift_close_rund_tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_LSHIFT);
            register_code(KC_9);
            break;
        case SINGLE_HOLD:
            register_code(KC_LSHIFT);
            break;
    }
}

void shift_close_rund_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (shift_close_rund_tap_state.state) {
        case SINGLE_TAP:
            // unregister_code(CH_LBRC);
            unregister_code(KC_LSHIFT);
            unregister_code(KC_9);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LSHIFT);
            break;
    }
    shift_close_rund_tap_state.state = 0;
}

static tap alt_kleiner_tap_state = {.is_press_action = true, .state = 0};

void alt_kleiner_finished(qk_tap_dance_state_t *state, void *user_data) {
    alt_kleiner_tap_state.state = cur_dance(state);
    switch (alt_kleiner_tap_state.state) {
        case SINGLE_TAP:
            register_code(CH_LABK);
            break;
        case SINGLE_HOLD:
            register_code(KC_LALT);
            break;
    }
}

void alt_kleiner_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (alt_kleiner_tap_state.state) {
        case SINGLE_TAP:
            unregister_code(CH_LABK);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LALT);
            break;
    }
    alt_kleiner_tap_state.state = 0;
}

static tap alt_groesser_tap_state = {.is_press_action = true, .state = 0};

void alt_groesser_finished(qk_tap_dance_state_t *state, void *user_data) {
    alt_groesser_tap_state.state = cur_dance(state);
    switch (alt_groesser_tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_LSHIFT);
            register_code(CH_LABK);
            break;
        case SINGLE_HOLD:
            register_code(KC_RALT);
            break;
    }
}

void alt_groesser_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (alt_groesser_tap_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_LSHIFT);
            unregister_code(CH_LABK);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_RALT);
            break;
    }
    alt_groesser_tap_state.state = 0;
}

static tap tilde_tap_state = {.is_press_action = true, .state = 0};

void tilde_start(qk_tap_dance_state_t *state, void *user_data) {
    register_code(KC_RALT);
    register_code(CH_N);
    unregister_code(KC_RALT);
    unregister_code(CH_N);
    register_code(KC_SPACE);
    unregister_code(KC_SPACE);
}

void tilde_finished(qk_tap_dance_state_t *state, void *user_data) {
    tilde_tap_state.state = cur_dance(state);
    switch (tilde_tap_state.state) {
        case SINGLE_TAP:
            //   register_code(KC_RALT);
            //   register_code(CH_N);
            //   unregister_code(KC_RALT);
            //   unregister_code(CH_N);
            //   register_code(KC_SPACE);
            //   unregister_code(KC_SPACE);
            //   SEND_STRING("   ");
            break;
    }
}

void tilde_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tilde_tap_state.state) {
        case SINGLE_TAP:
            break;
    }
    tilde_tap_state.state = 0;
}

static tap esc_command_tap_state = {.is_press_action = true, .state = 0};

void esc_command_finished(qk_tap_dance_state_t *state, void *user_data) {
    esc_command_tap_state.state = cur_dance(state);
    switch (esc_command_tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_ESC);
            break;
        case SINGLE_HOLD:
            register_code(KC_LGUI);
            break;
    }
}

void esc_command_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (esc_command_tap_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_ESC);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LGUI);
            break;
    }
    esc_command_tap_state.state = 0;
}

// void ctrl_a(void);
// void ctrl_a(void) {
//       register_code(KC_LCTRL);
//       register_code(KC_A);
//       unregister_code(KC_LCTRL);
//       unregister_code(KC_A);
// }

// void pressLetter(int letter);
// void pressLetter(int letter) {
//       register_code(letter);
//       unregister_code(letter);
// }

// void press2Letter(int letter1, int letter2);
// void press2Letter(int letter1, int letter2) {
//       register_code(letter1);
//       register_code(letter2);
//       unregister_code(letter1);
//       unregister_code(letter2);
// }

// void cltr_a_plus(int letter);
// void cltr_a_plus(int letter) {
//   ctrl_a();
//   pressLetter(letter);
// }

// void cltr_a_plus2(int letter1, int letter2);
// void cltr_a_plus2(int letter1, int letter2) {
//   ctrl_a();
//   press2Letter(letter1, letter2);
// }

// static tap ctrl_a_H_tap_state = {
//   .is_press_action = true,
//   .state = 0
// };

// void ctrl_a_H_finished (qk_tap_dance_state_t *state, void *user_data) {
//   ctrl_a_H_tap_state.state = cur_dance(state);
//   switch (ctrl_a_H_tap_state.state) {
//     case SINGLE_TAP:
//       cltr_a_plus(KC_H);
//       break;
//     // case SINGLE_HOLD: register_code(KC_RALT); break;
//   }
// }

// void ctrl_a_H_reset (qk_tap_dance_state_t *state, void *user_data) {
//   switch (ctrl_a_H_tap_state.state) {
//     case SINGLE_TAP:
//       break;
//     // case SINGLE_HOLD: unregister_code(KC_RALT); break;
//   }
//   ctrl_a_H_tap_state.state = 0;
// }

// static tap ctrl_a_j_tap_state = {
//   .is_press_action = true,
//   .state = 0
// };

// void ctrl_a_j_finished (qk_tap_dance_state_t *state, void *user_data) {
//   ctrl_a_j_tap_state.state = cur_dance(state);
//   switch (ctrl_a_j_tap_state.state) {
//     case SINGLE_TAP:
//       cltr_a_plus(KC_J);
//       break;
//     // case SINGLE_HOLD: register_code(KC_RALT); break;
//   }
// }

// void ctrl_a_j_reset (qk_tap_dance_state_t *state, void *user_data) {
//   switch (ctrl_a_j_tap_state.state) {
//     case SINGLE_TAP:
//       break;
//     // case SINGLE_HOLD: unregister_code(KC_RALT); break;
//   }
//   ctrl_a_j_tap_state.state = 0;
// }

// static tap ctrl_a_K_tap_state = {
//   .is_press_action = true,
//   .state = 0
// };

// void ctrl_a_K_finished (qk_tap_dance_state_t *state, void *user_data) {
//   ctrl_a_K_tap_state.state = cur_dance(state);
//   switch (ctrl_a_K_tap_state.state) {
//     case SINGLE_TAP:
//       cltr_a_plus(KC_K);
//       break;
//     // case SINGLE_HOLD: register_code(KC_RALT); break;
//   }
// }

// void ctrl_a_K_reset (qk_tap_dance_state_t *state, void *user_data) {
//   switch (ctrl_a_K_tap_state.state) {
//     case SINGLE_TAP:
//       break;
//     // case SINGLE_HOLD: unregister_code(KC_RALT); break;
//   }
//   ctrl_a_K_tap_state.state = 0;
// }

// static tap ctrl_a_L_tap_state = {
//   .is_press_action = true,
//   .state = 0
// };

// void ctrl_a_L_finished (qk_tap_dance_state_t *state, void *user_data) {
//   ctrl_a_K_tap_state.state = cur_dance(state);
//   switch (ctrl_a_L_tap_state.state) {
//     case SINGLE_TAP:
//       cltr_a_plus(KC_L);
//       break;
//     // case SINGLE_HOLD: register_code(KC_RALT); break;
//   }
// }

// void ctrl_a_L_reset (qk_tap_dance_state_t *state, void *user_data) {
//   switch (ctrl_a_L_tap_state.state) {
//     case SINGLE_TAP:
//       break;
//     // case SINGLE_HOLD: unregister_code(KC_RALT); break;
//   }
//   ctrl_a_L_tap_state.state = 0;
// }

// static tap ctrl_a_CB_tap_state = {
//   .is_press_action = true,
//   .state = 0
// };

// void ctrl_a_CB_finished (qk_tap_dance_state_t *state, void *user_data) {
//   ctrl_a_K_tap_state.state = cur_dance(state);
//   switch (ctrl_a_CB_tap_state.state) {
//     case SINGLE_TAP:
//       cltr_a_plus2(KC_LSHIFT, KC_9);
//       break;
//     // case SINGLE_HOLD: register_code(KC_RALT); break;
//   }
// }

// void ctrl_a_CB_reset (qk_tap_dance_state_t *state, void *user_data) {
//   switch (ctrl_a_CB_tap_state.state) {
//     case SINGLE_TAP:
//       break;
//     // case SINGLE_HOLD: unregister_code(KC_RALT); break;
//   }
//   ctrl_a_CB_tap_state.state = 0;
// }
