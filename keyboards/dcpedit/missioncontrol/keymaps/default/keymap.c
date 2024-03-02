// Copyright 2023 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
                                  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  AU_TOGG, HF_TOGG,
                                  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,

    MO(1),   KC_ESC,     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
    _______, _______,      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,           KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    _______, _______,       KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                            KC_UP,               KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    _______, _______,    KC_LSFT, KC_BSLS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS, KC_RSFT,             KC_LEFT, KC_DOWN, KC_RIGHT,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
    _______, KC_LGUI,    KC_LCTL,                          KC_LALT,     KC_BSPC,     KC_SPC,      MO(1),       KC_RALT,                                KC_RCTL,             KC_DOWN,             KC_P0,   KC_P0,   KC_PDOT, KC_PENT
  ),

  [1] = LAYOUT(
                                 QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

    _______, QK_RBT,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, AU_TOGG,    _______, _______, _______, _______,
    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, HF_TOGG,    _______, _______, _______, _______,
    _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                            _______,             _______, _______, _______, _______,
    _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______,    _______, _______, _______, _______,
    _______, _______,   _______,                          KC_LGUI,     _______,     _______,     _______,     KC_RGUI,                                _______,             _______,             _______, _______, _______, _______
  )
};