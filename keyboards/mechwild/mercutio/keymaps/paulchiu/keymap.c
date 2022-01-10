/* Copyright 2021 Kyle McCreery
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define NV_ESC  LT(1, KC_ESC)
#define SB_ENT  LT(2, KC_ENT)
#define OS_SFT  OSM(MOD_LSFT)
#define RSFT_SL RSFT_T(KC_SLSH)
#define MAC_DW  LALT(KC_BSPC) // MacOS Delete word (backwards)
#define MAC_NW  LALT(KC_RGHT) // MacOS Next word
#define MAC_PW  LALT(KC_LEFT) // MacOS Prev word
#define MAC_XW  LGUI(KC_GRV)  // MacOS Next window
#define MAC_ND  C(KC_RGHT)    // MacOS Next desktop
#define MAC_PD  C(KC_LEFT)    // MacOS Prev desktop

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all( /* Qwerty */
                                                                                                                  KC_MUTE,
      KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
      NV_ESC,           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    XXXXXXX, SB_ENT,
      KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,           RSFT_SL,
      KC_LCTL, KC_LALT, KC_LGUI,          KC_SPC,  KC_SPC,           KC_SPC,           TG(3),   OSL(2),           KC_HYPR ),

  [1] = LAYOUT_all( /* Nav and numbers */
                                                                                                                  _______,
  	  MAC_XW,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  	  _______,          MAC_PD,  MAC_ND,  KC_PGDN, KC_PGUP, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_DEL,
  	  _______, XXXXXXX, _______, _______, _______, _______, _______, _______, MAC_PW,  MAC_NW,  _______,          _______,
  	  _______, _______, _______,          _______, MAC_DW,           _______,          _______, RESET,            _______ ),

  [2] = LAYOUT_all( /* Symbols */
                                                                                                                  _______,
  	  _______,          KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LT,   KC_GT,   _______,
  	  KC_CAPS,          KC_GRV,  KC_TILD, KC_LPRN, KC_RPRN, KC_QUOT, KC_PIPE, KC_MINS, KC_EQL,  KC_COLN, XXXXXXX, _______,
  	  _______, _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_DQUO, KC_BSLS, KC_UNDS, KC_PLUS, KC_SCLN,          _______,
  	  _______, _______, _______,          _______, _______,          _______,          _______, _______,          _______ ),

  [3] = LAYOUT_all( /* Numbers */
                                                                                                                  _______,
  	  KC_ESC,           _______, KC_F7,   KC_F8,   KC_F9,   KC_F12,  KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS, _______,
  	  _______,          _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_ASTR, KC_4,    KC_5,    KC_6,    XXXXXXX, KC_PLUS,
  	  _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F10,  KC_0,    KC_1,    KC_2,    KC_3,             KC_DOT,
  	  _______, _______, _______,          _______, _______,          _______,          _______, _______,          _______ )
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        break;
    }
    return true;
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}

static void render_name(void) {
    static const char PROGMEM mercutio_name[] = {
        0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0x95, 0xB5, 0x96, 0xD5, 0xB6, 0xB6,
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(mercutio_name, false);
}

bool oled_task_user(void) {
    render_name();
    return false;
}
#endif
