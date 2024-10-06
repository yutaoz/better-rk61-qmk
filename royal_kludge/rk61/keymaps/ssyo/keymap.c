// Copyright 2024 ssyo
// SPDX-License-Identifier: GPL-2.0-or-later


#include QMK_KEYBOARD_H

enum {
    _BL,
    _FL,
    _AL,
    _CL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BL] = LAYOUT_all(
    QK_GESC,     KC_1,     KC_2,     KC_3,      KC_4,     KC_5,     KC_6,     KC_7,       KC_8,      KC_9,        KC_0,    KC_MINUS,    KC_EQUAL,    KC_BSPC,
        KC_NO, KC_TAB,     KC_Q,     KC_W,     KC_E,      KC_R,     KC_T,     KC_Y,     KC_U,       KC_I,      KC_O,        KC_P,     KC_LBRC,     KC_RBRC,    KC_BSLS,
       KC_CAPS,     KC_A,     KC_S,     KC_D,      KC_F,     KC_G,     KC_H,     KC_J,       KC_K,      KC_L,     KC_SCLN,     KC_QUOT,                  KC_ENT,
       KC_LSFT,     KC_Z,     KC_X,     KC_C,      KC_V,     KC_B,     KC_N,     KC_M,   KC_COMM ,    KC_DOT,    KC_SLASH,                  KC_RSFT,
       KC_NO, KC_NO, KC_LCTL,  KC_LWIN,  KC_LALT,              KC_SPC,   	              KC_RALT,      KC_APP,     KC_RCTL,                   MO(_FL)),

[_FL] = LAYOUT_all(
    KC_GRV,     KC_F1,    KC_F2,     KC_F3,    KC_F4,    KC_F5,    KC_F6,     KC_F7,    KC_F8,      KC_F9,       KC_F10,    KC_F11,     KC_F12,     KC_DEL,
      _______, _______,  KC_Q,  _______,  _______,  _______,   _______,  KC_PRINT_SCREEN,  KC_SCROLL_LOCK,   KC_PAUSE,   _______,   _______,   _______,  _______,  _______,
      _______,    _______,   _______,   _______,    _______,   _______,   KC_INSERT,   KC_HOME,   KC_PGUP,   _______,   _______,    _______,                 _______,
      _______,  _______,   _______,  _______,   _______,   _______,  _______,  KC_MUTE, KC_VOLD,  KC_VOLU,   KC_UP,                  _______,
      _______, _______, _______, _______, _______,             _______,   	            KC_LEFT,   KC_DOWN,   KC_RIGHT,                  _______),

[_AL] = LAYOUT_all(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,
    _______, _______, _______,       _______,                               _______, _______, _______, _______),

[_CL] = LAYOUT_all(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,
    _______, _______, _______,       _______,                               _______, _______, _______, _______)

 };

bool socd_held[2] = {false, false};
int a_idx = 0;
int d_idx = 1;
bool socd_enabled = true;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // toggle socd on fn + q
        case KC_Q:
            if (IS_LAYER_ON(_FL) && record->event.pressed) {
                socd_enabled = !socd_enabled;
                return false;
            }
            break;
        case KC_A:
            if (socd_enabled) {
                if (record->event.pressed) {
                    if (!socd_held[a_idx]) {
                        socd_held[a_idx] = true;
                        if (socd_held[d_idx]) {
                            unregister_code(KC_D);
                        }
                    }
                } else {
                    socd_held[a_idx] = false;
                    if (socd_held[d_idx]) {
                        register_code(KC_D);
                    }
                }
            }
            break;
        case KC_D:
            if (socd_enabled) {
                if (record->event.pressed) {
                    if (!socd_held[d_idx]) {
                        socd_held[d_idx] = true;
                        if (socd_held[a_idx]) {
                            unregister_code(KC_A);
                        }
                    }
                } else {
                    socd_held[d_idx] = false;
                    if (socd_held[a_idx]) {
                        register_code(KC_A);
                    }
                }
            }
            break;
    }
    return true;
}

