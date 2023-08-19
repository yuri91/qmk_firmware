// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "keymap_us_international.h"

enum Layers {
    Default,
    NumUtil,
    Symbols,
    Media
};

enum CustomKey {
    Y_A_GRA = SAFE_RANGE,
    Y_E_GRA,
    Y_E_ACU,
    Y_I_GRA,
    Y_O_GRA,
    Y_U_GRA,
    Y_GRA,
    Y_ACU,
    Y_TLD,
    Y_QUO,
    Y_CIR,
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
    case Y_A_GRA:
        if(record->event.pressed) {
            SEND_STRING("`a");
        }
        break;
    case Y_E_GRA:
        if(record->event.pressed) {
            SEND_STRING("`e");
        }
        break;
    case Y_E_ACU:
        if(record->event.pressed) {
            SEND_STRING("'e");
        }
        break;
    case Y_I_GRA:
        if(record->event.pressed) {
            SEND_STRING("`i");
        }
        break;
    case Y_O_GRA:
        if(record->event.pressed) {
            SEND_STRING("`o");
        }
        break;
    case Y_U_GRA:
        if(record->event.pressed) {
            SEND_STRING("`u");
        }
        break;
    case Y_GRA:
        if(record->event.pressed) {
            SEND_STRING("` ");
        }
        break;
    case Y_ACU:
        if(record->event.pressed) {
            SEND_STRING("' ");
        }
        break;
    case Y_TLD:
        if(record->event.pressed) {
            SEND_STRING("~ ");
        }
        break;
    case Y_QUO:
        if(record->event.pressed) {
            SEND_STRING("\" ");
        }
        break;
    case Y_CIR:
        if(record->event.pressed) {
            SEND_STRING("^ ");
        }
        break;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, NumUtil, Symbols, Media);
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │   │
      * │   │   │   │   │ALT│CTL│       │SFT│ALT│   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │ESC├───┐           ┌───┤DEL│
      *               │L1 │|_|│           │ ↲ │L2 │
      *               └───┤SFT├───┐   ┌───┤CTL├───┘
      *                   └───┤TAB│   │ ⌫ ├───┘
      *                       └───┘   └───┘
      */
    [Default] = LAYOUT_split_3x6_3(
        KC_NO, KC_Q, KC_W, KC_E, KC_R,         KC_T,                        KC_Y,         KC_U,         KC_I,    KC_O,   KC_P,    KC_NO,
        KC_NO, KC_A, KC_S, KC_D, KC_F,         KC_G,                        KC_H,         KC_J,         KC_K,    KC_L,   KC_SCLN, KC_NO,
        KC_NO, KC_Z, KC_X, KC_C, LALT_T(KC_V), LCTL_T(KC_B),                RSFT_T(KC_N), RALT_T(KC_M), KC_COMM, KC_DOT, KC_SLSH, KC_NO,
                            LT(1,KC_ESC), LSFT_T(KC_SPC), KC_TAB,      KC_BSPC, RCTL_T(KC_ENT), LT(2,KC_DEL)
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ 1 │ 2 │ 3 │ 4 │ 5 │       │ 6 │ 7 │ 8 │ 9 │ 0 │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ À │ È │ Ì │ Ò │ Ù │       │ ← │ ↓ │ ↑ │ → │PRT│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │CAP│ É │INS│DEL│ESC│       │HOM│PGD│PGU│END│   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │ 🛇 ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [NumUtil] = LAYOUT_split_3x6_3(
        KC_NO, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_NO,
        KC_NO, Y_A_GRA, Y_E_GRA, Y_I_GRA, Y_O_GRA, Y_U_GRA,                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_PSCR, KC_NO,
        KC_NO, KC_CAPS, Y_E_ACU, KC_INS,  KC_DEL,  KC_ESC,                  KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_TRNS, KC_NO,
                                    KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ ! │ @ │ # │ $ │ % │       │ ^ │ & │ * │ ` │ ~ │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ " │ [ │ { │ ( │ < │       │ / │ - │ = │ | │ ° │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ ' │ ] │ } │ ) │ > │       │ \ │ _ │ + │ µ │ € │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │ 🛇 ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [Symbols] = LAYOUT_split_3x6_3(
        KC_NO, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                 Y_CIR,   KC_AMPR, KC_ASTR, Y_GRA,   Y_TLD,   KC_NO,
        KC_NO, Y_QUO,   KC_LBRC, KC_LCBR, KC_LPRN, KC_LABK,                 KC_SLSH, KC_MINS, KC_EQL,  KC_PIPE, US_DEG,  KC_NO,
        KC_NO, Y_ACU,   KC_RBRC, KC_RCBR, KC_RPRN, KC_RABK,                 KC_BSLS, KC_UNDS, KC_PLUS, US_MICR, US_EURO, KC_NO,
                                    KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │MCL│M↑ │MCR│+🕨 │|⏴⏴│       │F1 │F2 │F3 │F4 │F5 │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │M← │M↓ │M→ │-🕨 │⏵⏵|│       │F6 │F7 │F8 │F9 │F10│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │MWD│MCM│MWU│x🕨 │ ⏵ │       │F11│F12│   │   │RST│   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │ 🛇 ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [Media] = LAYOUT_split_3x6_3(
        KC_NO, KC_BTN1, KC_MS_U, KC_BTN2, KC_KB_VOLUME_UP,   KC_MPRV,       KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_NO,
        KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_KB_VOLUME_DOWN, KC_MNXT,       KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_NO,
        KC_NO, KC_WH_L, KC_BTN3, KC_WH_D, KC_KB_MUTE,        KC_MPLY,       KC_F11, KC_F12, KC_TRNS, KC_TRNS, QK_BOOT, KC_NO,
                                             KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

