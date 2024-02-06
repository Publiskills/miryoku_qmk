// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define SPLIT_WPM_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define USB_MAX_POWER_CONSUMPTION 500

#define HRML(k1,k2,k3,k4) LGUI_T(k1),LALT_T(k2),LCTL_T(k3),LSFT_T(k4)
#define HRMR(k1,k2,k3,k4) LSFT_T(k1),LCTL_T(k2),LALT_T(k3),LGUI_T(k4)

#define U_FR_UND C(FR_Z)

#define MIRYOKU_MAPPING( \
      K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09, \
      K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19, \
      K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29, \
      N30,  N31,  K32,  K33,  K34,         K35,  K36,  K37,  N38,  N39 \
) \
LAYOUT_split_3x6_3( \
KC_TAB,   K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09,  KC_BSPC, \
KC_LSFT,  K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19,  LT(U_ACC,FR_QUOT), \
KC_LCTL,  K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29,  KC_ENT , \
                      K32,  K33,  K34,         K35,  K36,  K37 \
)

#define MIRYOKU_LAYER_BASE \
FR_Q,              FR_W,              FR_E,               FR_R,              FR_T,               FR_Y,              FR_U,              FR_I,                FR_O,              FR_P,                \
HRML(FR_A,         FR_S,              FR_D,               FR_F),             FR_G,               FR_H,              HRMR(FR_J,         FR_K,                FR_L,              FR_SCLN),            \
LT(U_BUTTON,FR_Z), LT(U_MOUSE,FR_X),  FR_C,               FR_V,              FR_B,               FR_N,              FR_M,              FR_COMM,             FR_DOT,            LT(U_BUTTON,FR_SLSH),\
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC), LT(U_NAV,KC_SPC),  LT(U_EXTRA,KC_TAB), LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),    U_NP,              U_NP

#define MIRYOKU_LAYER_MEDIA \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              RGB_TOG,           RGB_MOD,           KC_VOLU,           RGB_HUI,           RGB_SAI,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NU,              KC_MPRV,           KC_VOLD,           KC_MNXT,           RGB_VAI,           \
U_NA,              KC_ALGR,           TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  U_NA,              U_NU,              U_NU,              U_NU,              U_NU,              U_NU,              \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP

#define MIRYOKU_LAYER_NAV \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              KC_INS,            KC_HOME,           KC_UP,             KC_END,            KC_PGUP,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              KC_CAPS,           KC_LEFT,           KC_DOWN,           KC_RGHT,           KC_PGDN,           \
U_NA,              KC_ALGR,           TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_FR_UND,             \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

#define MIRYOKU_LAYER_EXTRA \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_NA,           U_NA,           U_NA,           RID_IMPL,       RID_RENAME,     \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NA,           U_NA,           U_NA,           U_NA,           U_NA,           \
U_NA,              KC_ALGR,           TD(U_TD_U_SYM),    TD(U_TD_U_EXTRA),  U_NA,              U_NA,           U_NA,           U_NA,           U_NA,           X_EXTRA,        \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              U_NA,           U_NA,           U_NA,           U_NP,           U_NP

#define MIRYOKU_LAYER_SYM \
FR_LCBR,           FR_AMPR,           FR_ASTR,           FR_LPRN,           FR_RCBR,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
FR_COLN,           FR_DLR,            FR_PERC,           FR_CIRC,           FR_PLUS,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
FR_TILD,           FR_EXLM,           FR_AT,             FR_HASH,           FR_PIPE,           U_NA,              TD(U_TD_U_SYM),    TD(U_TD_U_EXTRA),  KC_ALGR,           U_NA,              \
U_NP,              U_NP,              FR_LPRN,           FR_RPRN,           FR_UNDS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_NUM \
FR_LBRC,           FR_7,              FR_8,              FR_9,              FR_RBRC,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
FR_SCLN,           FR_4,              FR_5,              FR_6,              FR_EQL,            U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
FR_GRV,            FR_1,              FR_2,              FR_3,              FR_BSLS,           U_NA,              TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    KC_ALGR,           U_NA,              \
U_NP,              U_NP,              FR_DOT,            FR_0,              FR_MINS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_FUN \
KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           U_NA,              TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  KC_ALGR,           U_NA,              \
U_NP,              U_NP,              KC_APP,            KC_SPC,            KC_TAB,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_TAP \
FR_Q,              FR_W,              FR_E,              FR_R,              FR_T,              FR_Y,              FR_U,              FR_I,              FR_O,              FR_P,              \
FR_A,              FR_S,              FR_D,              FR_F,              FR_G,              FR_H,              FR_J,              FR_K,              FR_L,              FR_SCLN,           \
FR_Z,              FR_X,              FR_C,              FR_V,              FR_B,              FR_N,              FR_M,              FR_COMM,           FR_DOT,            FR_SLSH,           \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

#define MIRYOKU_LAYER_BUTTON \
U_FR_UND,          U_CUT,             U_CPY,             U_PST,          U_RDO,             U_RDO,             U_PST,          U_CPY,             U_CUT,             U_FR_UND,          \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,        U_NU,              U_NU,              KC_LSFT,        KC_LCTL,           KC_LALT,           KC_LGUI,           \
U_FR_UND,          U_CUT,             U_CPY,             U_PST,          U_RDO,             U_RDO,             U_PST,          U_CPY,             U_CUT,             U_FR_UND,          \
U_NP,              U_NP,              KC_BTN3,           KC_BTN1,        KC_BTN2,           KC_BTN2,           KC_BTN1,        KC_BTN3,           U_NP,              U_NP

#define MIRYOKU_LAYER_MOUSE \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_NU,              KC_WH_L,           KC_MS_U,           KC_WH_R,           KC_WH_U,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NU,              KC_MS_L,           KC_MS_D,           KC_MS_R,           KC_WH_D,           \
U_NA,              U_NA,              U_NA,              TD(U_TD_U_MOUSE),  U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_FR_UND,             \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP


#define MIRYOKU_LAYER_ACC \
U_NU,             U_NU,             TD(TD_ACC_E),     U_NU,             U_NU,                   U_NU,              FR_C_UGr,         TD(TD_ACC_I),     FR_C_OCirc,       U_NU,                \
TD(TD_ACC_A),     U_NU,             U_NU,             U_NU,             U_NU,                   U_NU,              U_NU,             U_NU,             U_NU,             U_NU,                \
U_NU,             U_NU,             FR_C_CCed,        U_NU,             U_NU,                   U_NU,              U_NU,             U_NU,             U_NU,             U_NU,                \
U_NP,             U_NP,             KC_ESC,           KC_SPC,           KC_TAB,                 KC_ENT,            KC_BSPC,          KC_DEL,           U_NP,             U_NP
