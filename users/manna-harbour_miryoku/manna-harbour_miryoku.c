// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "quantum/keymap_extras/keymap_french.h"
#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"

enum my_keycodes {
  FR_C_UGr = SAFE_RANGE,
  FR_C_OCirc,
  FR_C_CCed,
  RID_RENAME,
  RID_IMPL,
  X_EXTRA
};

// Additional Features double tap guard
enum {
    U_TD_BOOT,
#define MIRYOKU_X(LAYER, STRING) U_TD_U_##LAYER,
    MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
    TD_ACC_A,
    TD_ACC_E,
    TD_ACC_I
};

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        reset_keyboard();
    }
}

#define MIRYOKU_X(LAYER, STRING)                                        \
    void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
        if (state->count == 2) {                                        \
            default_layer_set((layer_state_t)1 << U_##LAYER);           \
        }                                                               \
    }
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X

#define WITHOUT_MODS(...) \
  do { \
    const uint8_t _real_mods = get_mods(); \
    const uint8_t _weak_mods = get_weak_mods(); \
    clear_mods(); \
    clear_weak_mods(); \
    { __VA_ARGS__ } \
    set_mods(_weak_mods); \
    set_weak_mods(_real_mods); \
  } while (0)

#define tapSpecial3Codes(k1, k2, k3) \
    register_code(KC_LALT); \
    tap_code(k1); \
    tap_code(k2); \
    tap_code(k3); \
    unregister_code(KC_LALT);
  
#define tapSpecial4Codes(k1, k2, k3, k4) \
    register_code(KC_LALT); \
    tap_code(k1); \
    tap_code(k2); \
    tap_code(k3); \
    tap_code(k4); \
    unregister_code(KC_LALT);

#define tapSpecialCodesWithShifted_4_4(l1, l2, l3, l4, u1, u2, u3, u4) \
    if(get_mods() & MOD_MASK_SHIFT) { \
        WITHOUT_MODS({ \
            tapSpecial4Codes(u1, u2, u3, u4); \
        }); \
    } else { \
        tapSpecial4Codes(l1, l2, l3, l4); \
    }

#define tapSpecialCodesWithShifted_3_4(l1, l2, l3, u1, u2, u3, u4) \
    if(get_mods() & MOD_MASK_SHIFT) { \
        WITHOUT_MODS({ \
            tapSpecial4Codes(u1, u2, u3, u4); \
        }); \
    } else { \
        tapSpecial3Codes(l1, l2, l3); \
    }

#define tapSpecialCodesWithShifted_3_3(l1, l2, l3, u1, u2, u3) \
    if(get_mods() & MOD_MASK_SHIFT) { \
        WITHOUT_MODS({ \
            tapSpecial3Codes(u1, u2, u3); \
        }); \
    } else { \
        tapSpecial3Codes(l1, l2, l3); \
    }

void td_acc_a(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tapSpecialCodesWithShifted_3_4(KC_KP_1, KC_KP_3, KC_KP_3, KC_KP_0, KC_KP_1, KC_KP_9, KC_KP_2);
    } else {
        tapSpecialCodesWithShifted_4_4(KC_KP_0, KC_KP_2, KC_KP_2, KC_KP_6, KC_KP_0, KC_KP_1, KC_KP_9, KC_KP_4);
        reset_tap_dance(state);
    }
}

void td_acc_e(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tapSpecialCodesWithShifted_3_4(KC_KP_1, KC_KP_3, KC_KP_0, KC_KP_0, KC_KP_2, KC_KP_0, KC_KP_1);
    } else if (state->count == 2) {
        tapSpecialCodesWithShifted_3_4(KC_KP_1, KC_KP_3, KC_KP_8, KC_KP_0, KC_KP_2, KC_KP_0, KC_KP_0);
    } else if (state->count == 3) {
        tapSpecialCodesWithShifted_4_4(KC_KP_0, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_0, KC_KP_2, KC_KP_0, KC_KP_2);
    } else if (state->count == 4) {
        tapSpecialCodesWithShifted_4_4(KC_KP_0, KC_KP_2, KC_KP_3, KC_KP_5, KC_KP_0, KC_KP_2, KC_KP_0, KC_KP_3);
    } else {
        WITHOUT_MODS({
            tap_code16(FR_EURO);
        });
        reset_tap_dance(state);
    }
}

void td_acc_i(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tapSpecialCodesWithShifted_4_4(KC_KP_0, KC_KP_2, KC_KP_3, KC_KP_8, KC_KP_0, KC_KP_2, KC_KP_0, KC_KP_6);
    } else {
        tapSpecialCodesWithShifted_4_4(KC_KP_0, KC_KP_2, KC_KP_3, KC_KP_9, KC_KP_0, KC_KP_2, KC_KP_0, KC_KP_7);
        reset_tap_dance(state);
    }
}

tap_dance_action_t tap_dance_actions[] = {[U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
#define MIRYOKU_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
                                          MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
[TD_ACC_A] = ACTION_TAP_DANCE_FN(td_acc_a),
[TD_ACC_E] = ACTION_TAP_DANCE_FN(td_acc_e),
[TD_ACC_I] = ACTION_TAP_DANCE_FN(td_acc_i),
};

// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define MIRYOKU_X(LAYER, STRING) [U_##LAYER] = U_MACRO_VA_ARGS(MIRYOKU_LAYERMAPPING_##LAYER, MIRYOKU_LAYER_##LAYER),
    MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

// shift functions

const key_override_t capsword_key_override =   ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);
const key_override_t shift_quot_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO);
const key_override_t shift_winscln_key_override = ko_make_basic(MOD_MASK_SHIFT, LGUI_T(FR_SCLN), FR_COLN);
const key_override_t shift_dot_key_override =  ko_make_basic(MOD_MASK_SHIFT, FR_DOT,  FR_RABK);
const key_override_t shift_comm_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_COMM, FR_LABK);
const key_override_t shift_lbrc_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_LBRC, FR_LCBR);
const key_override_t shift_rbrc_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_RBRC, FR_RCBR);
const key_override_t shift_scln_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_SCLN, FR_COLN);
const key_override_t shift_0_key_override    = ko_make_basic(MOD_MASK_SHIFT, FR_0, FR_RPRN);
const key_override_t shift_1_key_override    = ko_make_basic(MOD_MASK_SHIFT, FR_1, FR_EXLM);
const key_override_t shift_2_key_override    = ko_make_basic(MOD_MASK_SHIFT, FR_2, FR_AT);
const key_override_t shift_3_key_override    = ko_make_basic(MOD_MASK_SHIFT, FR_3, FR_HASH);
const key_override_t shift_4_key_override    = ko_make_basic(MOD_MASK_SHIFT, FR_4, FR_DLR);
const key_override_t shift_5_key_override    = ko_make_basic(MOD_MASK_SHIFT, FR_5, FR_PERC);
const key_override_t shift_6_key_override    = ko_make_basic(MOD_MASK_SHIFT, FR_6, FR_CIRC);
const key_override_t shift_7_key_override    = ko_make_basic(MOD_MASK_SHIFT, FR_7, FR_AMPR);
const key_override_t shift_8_key_override    = ko_make_basic(MOD_MASK_SHIFT, FR_8, FR_ASTR);
const key_override_t shift_9_key_override    = ko_make_basic(MOD_MASK_SHIFT, FR_9, FR_LPRN);
const key_override_t shift_grv_key_override  = ko_make_basic(MOD_MASK_SHIFT, FR_GRV, FR_TILD);
const key_override_t shift_mins_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_MINS, FR_UNDS);
const key_override_t shift_bsls_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_BSLS, FR_PIPE);

const key_override_t **key_overrides = (const key_override_t *[]){
    &capsword_key_override, 
    &shift_quot_key_override,
    &shift_winscln_key_override,
    &shift_dot_key_override,
    &shift_comm_key_override,
    &shift_lbrc_key_override,
    &shift_rbrc_key_override,
    &shift_scln_key_override,
    &shift_0_key_override,
    &shift_1_key_override,   
    &shift_2_key_override,  
    &shift_3_key_override,   
    &shift_4_key_override,   
    &shift_5_key_override,   
    &shift_6_key_override,   
    &shift_7_key_override,   
    &shift_8_key_override,   
    &shift_9_key_override,   
    &shift_grv_key_override, 
    &shift_mins_key_override,
    &shift_bsls_key_override,
    NULL};

// thumb combos

enum combos {
    EXIT_TAP
};

#if defined(MIRYOKU_KLUDGE_THUMBCOMBOS)
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(U_SYM, KC_ENT), LT(U_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[]  = {LT(U_NAV, KC_SPC), LT(U_MOUSE, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[]        = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[]      = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[]      = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[]        = {KC_0, KC_MINS, COMBO_END};
#    if defined(MIRYOKU_LAYERS_FLIP)
const uint16_t PROGMEM thumbcombos_sym[] = {KC_UNDS, KC_LPRN, COMBO_END};
#    else
const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
#    endif
const uint16_t PROGMEM thumbcombos_fun[]       = {KC_SPC, KC_TAB, COMBO_END};
combo_t                key_combos[COMBO_COUNT] = {COMBO(thumbcombos_base_right, LT(U_FUN, KC_DEL)),
                                                  COMBO(thumbcombos_base_left, LT(U_MEDIA, KC_ESC)),
                                                  COMBO(thumbcombos_nav, KC_DEL),
                                                  COMBO(thumbcombos_mouse, KC_BTN3),
                                                  COMBO(thumbcombos_media, KC_MUTE),
                                                  COMBO(thumbcombos_num, KC_DOT),
#    if defined(MIRYOKU_LAYERS_FLIP)
                                   COMBO(thumbcombos_sym, KC_RPRN),
#    else
                                   COMBO(thumbcombos_sym, KC_LPRN),e
#    endif
                                                  COMBO(thumbcombos_fun, KC_APP)};
#endif

// my combos

const uint16_t PROGMEM exittap_combo[] = {KC_ESC, KC_DEL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [EXIT_TAP] = COMBO(exittap_combo, DF(U_BASE))
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case EXIT_TAP:
            if (!layer_state_is(U_TAP)) {
                return false;
            }
    }
    return true;
}

void rgb_matrix_layer_helper(uint8_t hue, uint8_t sat, uint8_t val) {
    HSV hsv = {hue, sat, val};
    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case U_BASE:
            rgb_matrix_layer_helper(HSV_GREEN);
            break;
        case U_NAV:
            rgb_matrix_layer_helper(HSV_PURPLE);
            break;
        case U_TAP:
            rgb_matrix_layer_helper(HSV_RED);
            break;
        case U_BUTTON:
            rgb_matrix_layer_helper(HSV_BLUE);
            break;
        case U_MEDIA:
            rgb_matrix_layer_helper(HSV_YELLOW);
            break;
        case U_NUM:
            rgb_matrix_layer_helper(HSV_ORANGE);
            break;
        case U_SYM:
            rgb_matrix_layer_helper(HSV_TURQUOISE);
            break;
        case U_FUN:
            rgb_matrix_layer_helper(HSV_MAGENTA);
            break;
        case U_EXTRA:
            rgb_matrix_layer_helper(HSV_WHITE);
            break;
        case U_ACC:
            rgb_matrix_layer_helper(HSV_PINK);
            break;
        case U_MOUSE:
            rgb_matrix_layer_helper(HSV_CHARTREUSE);
            break;
        default:
            rgb_matrix_layer_helper(HSV_CHARTREUSE);
            break;
    }
    return false;
}

/* 32 * 32 logo */
static void render_logo(void) {
    static const char PROGMEM coffee_logo[] = {0x00, 0x00, 0x00, 0x00, 0x30, 0x78, 0xf8, 0xf0, 0xf8, 0x78, 0x30, 0x00, 0x00, 0x30, 0x78, 0xf8, 
	0xf0, 0xf8, 0x78, 0x30, 0x00, 0x00, 0x30, 0x78, 0xf8, 0xf0, 0x88, 0x48, 0x30, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0xc0, 
	0x01, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xd9, 0x46, 0xc0, 0xcc, 
	0xc3, 0xc0, 0xd9, 0xc6, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x38, 0x37, 0x3f, 
	0x3f, 0x3f, 0x3f, 0x1f, 0x0f, 0x0c, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    oled_write_raw_P(coffee_logo, sizeof(coffee_logo));
}

/* 32 * 32 logo */
static void render_dino(void) {
    static const char PROGMEM dino_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 
	0x40, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x9f, 0x9f, 0x17, 0x17, 0x17, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x1f, 0x3e, 0x7e, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 
	0x3f, 0x1f, 0x0f, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x05, 0x00, 0x00, 0x00, 0x07, 
	0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    oled_write_raw_P(dino_logo, sizeof(dino_logo));
}

/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       40

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }};

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[current_frame], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[current_frame], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[current_frame], ANIM_SIZE);
        }
    }

#    if OLED_TIMEOUT > 0
    /* the animation prevents the normal timeout from occuring */
    if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
        return;
    } else {
        oled_on();
    }
#    endif

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }
}

static void print_logo_narrow(void) {
    render_logo();

    /* wpm counter */
    uint8_t n = get_current_wpm();
    char    wpm_str[4];
    oled_set_cursor(0, 14);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0, 15);
    oled_write(" wpm", false);
}

/* KEYBOARD PET END */

static void print_status_narrow(void) {
    render_dino();

    oled_set_cursor(0, 5);

    /* Print current layer */
    oled_write("LAYER", false);

    oled_set_cursor(0, 6);

    switch (get_highest_layer(layer_state|default_layer_state)) {
        case U_BASE:
            oled_write("Base ", false);
            break;
        case U_NAV:
            oled_write("Navig", false);
            break;
        case U_TAP:
            oled_write("Tap  ", false);
            break;
        case U_BUTTON:
            oled_write("Btn  ", false);
            break;
        case U_MEDIA:
            oled_write("Media", false);
            break;
        case U_NUM:
            oled_write("Num  ", false);
            break;
        case U_SYM:
            oled_write("Symb ", false);
            break;
        case U_FUN:
            oled_write("Func ", false);
            break;
        case U_EXTRA:
            oled_write("Extra", false);
            break;
        case U_ACC:
            oled_write("Acc  ", false);
            break;
        case U_MOUSE:
            oled_write("Mouse", false);
            break;
        default:
            oled_write("Undef", false);
            break;
    }

    /* caps lock */
    oled_set_cursor(0, 8);
    oled_write("CPSLK", led_usb_state.caps_lock);

    /* KEYBOARD PET RENDER START */

    render_luna(0, 13);

    /* KEYBOARD PET RENDER END */
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(U_BUTTON, FR_SLSH):
            if (record->tap.count && record->event.pressed) {
                if(get_mods() & MOD_MASK_SHIFT) {
                    tap_code16(FR_QUES); // Send FR_QUES on tap when shifted
                }
                else {
                    tap_code16(FR_SLSH); // Send FR_SLSH on tap
                }
                return false;        // Return false to ignore further processing of key
            }
            break;
        case FR_C_UGr:
            if (record->event.pressed) {
                tapSpecialCodesWithShifted_3_4(KC_KP_1, KC_KP_5, KC_KP_1, KC_KP_0, KC_KP_2, KC_KP_1, KC_KP_7);
                return false; 
            }
            break;
        case FR_C_OCirc:
            if (record->event.pressed) {
                tapSpecialCodesWithShifted_4_4(KC_KP_0, KC_KP_2, KC_KP_4, KC_KP_4, KC_KP_0, KC_KP_2, KC_KP_1, KC_KP_2);
                return false; 
            }
            break;
        case FR_C_CCed:
            if (record->event.pressed) {
                tapSpecialCodesWithShifted_3_3(KC_KP_1, KC_KP_3, KC_KP_5, KC_KP_1, KC_KP_2, KC_KP_8);
                return false; 
            }
            break;
        case RID_RENAME:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("rr"));
                return false; 
            }
            break;
        case RID_IMPL:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_F12));
                return false; 
            }
            break;
        case X_EXTRA:
            if (record->event.pressed) {
                tap_code16(LSFT(FR_E));
                tap_code(FR_X);
                tap_code(FR_T);
                tap_code(FR_R);
                tap_code(FR_A);
                return false; 
            }
            break;

            /* KEYBOARD PET STATUS START */
        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
        case LT(U_NAV,KC_SPC):
            if (record->tap.count) {
                if (record->event.pressed) {
                    isJumping  = true;
                    showedJump = false;
                } else {
                    isJumping = false;
                }
            }
            break;

            /* KEYBOARD PET STATUS END */
    }
    return true;
}
