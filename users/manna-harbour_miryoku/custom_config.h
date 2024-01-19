// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define SPLIT_LAYER_STATE_ENABLE
#define USB_MAX_POWER_CONSUMPTION 500

#define U_FR_PST C(FR_V)
#define U_FR_UND C(FR_Z)

#define MIRYOKU_MAPPING( \
      K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09, \
      K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19, \
      K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29, \
      N30,  N31,  K32,  K33,  K34,         K35,  K36,  K37,  N38,  N39 \
) \
LAYOUT_split_3x6_3( \
KC_TAB,   K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09,  KC_DEL, \
KC_LSFT,  K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19,  FR_QUOT, \
KC_LCTL,  K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29,  KC_ENT , \
                      K32,  K33,  K34,         K35,  K36,  K37 \
)

#define MIRYOKU_LAYER_BASE \
FR_Q,              FR_W,              FR_E,              FR_R,              FR_T,              FR_Y,              FR_U,              FR_I,              FR_O,              FR_P,                \
LGUI_T(FR_A),      LALT_T(FR_S),      LCTL_T(FR_D),      LSFT_T(FR_F),      FR_G,              FR_H,              LSFT_T(FR_J),      LCTL_T(FR_K),      LALT_T(FR_L),      LGUI_T(FR_SCLN),     \
LT(U_BUTTON,FR_Z), ALGR_T(FR_X),      FR_C,              FR_V,              FR_B,              FR_N,              FR_M,              FR_COMM,           FR_DOT,            LT(U_BUTTON,FR_SLSH),\
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP

#define MIRYOKU_LAYER_TAP \
FR_Q,              FR_W,              FR_E,              FR_R,              FR_T,              FR_Y,              FR_U,              FR_I,              FR_O,              FR_P,              \
FR_A,              FR_S,              FR_D,              FR_F,              FR_G,              FR_H,              FR_J,              FR_K,              FR_L,              FR_SCLN,           \
FR_Z,              FR_X,              FR_C,              FR_V,              FR_B,              FR_N,              FR_M,              FR_COMM,           FR_DOT,            FR_SLSH,           \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

#define MIRYOKU_LAYER_EXTRA MIRYOKU_LAYER_BASE

#define MIRYOKU_LAYER_BUTTON \
U_FR_UND,          U_CUT,             U_CPY,             U_FR_PST,          U_RDO,             U_RDO,             U_FR_PST,          U_CPY,             U_CUT,             U_FR_UND,          \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NU,              U_NU,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
U_FR_UND,          U_CUT,             U_CPY,             U_FR_PST,          U_RDO,             U_RDO,             U_FR_PST,          U_CPY,             U_CUT,             U_FR_UND,          \
U_NP,              U_NP,              KC_BTN3,           KC_BTN1,           KC_BTN2,           KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP
