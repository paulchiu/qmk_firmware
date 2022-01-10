/*
Copyright 2022 Paul Chiu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

enum crkbd_layers {
  _BASE,
  _NAVI, // Navigation
  _SYMB, // Symbols
  _NUMB  // Numbers
};

#define ESNV LT(_NAVI, KC_ESC) // Layer-taps
#define ESNU LT(_NUMB, KC_ESC)
#define ETSB LT(_SYMB, KC_ENT)
#define SPNU LT(_NUMB, KC_SPC)
#define MTCZ MT(MOD_LCTL, KC_Z) // Mod-taps
#define MTAX MT(MOD_LALT, KC_X)
#define MTGC MT(MOD_LGUI, KC_C)
#define MTGM MT(MOD_RGUI, KC_COMM)
#define MTAD MT(MOD_LALT, KC_DOT)
#define MTCS MT(MOD_RCTL, KC_SLSH)
#define CUT  LGUI(KC_X)       // Cut
#define COPY LGUI(KC_C)       // Copy
#define PSTE LGUI(KC_V)       // Paste
#define UNDO LGUI(KC_Z)       // Undo
#define MAC_DW  LALT(KC_BSPC) // MacOS Delete word (backwards)
#define MAC_SP  LGUI(KC_SPC)  // MacOS Spotlight
#define MAC_NW  LALT(KC_RGHT) // MacOS Next word
#define MAC_PW  LALT(KC_LEFT) // MacOS Prev word
#define MAC_XW  LGUI(KC_GRV)  // MacOS Next window
#define MAC_PD  LCTL(KC_LEFT) // MacOS Previous desktop
#define MAC_ND  LCTL(KC_RGHT) // MacOS Next desktop)      // Next desktop

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    MTCZ,    MTAX,    MTGC,    KC_V,    KC_B,                         KC_N,    KC_M,    MTGM,    MTAD,    MTCS, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_HYPR,    ESNV,    SPNU,     KC_SPC,    ETSB,   MAC_SP
                                      //`--------------------------'  `--------------------------'

  ),

  [_NAVI] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX,  MAC_XW, KC_PGUP, C(KC_R), KC_HOME,                      XXXXXXX, KC_CAPS,  KC_INS, XXXXXXX, XXXXXXX,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, G(KC_S), KC_PGDN,  MAC_PD,  MAC_ND,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_ENT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    UNDO,     CUT,    COPY,    PSTE, C(KC_B),                       MAC_PW,  MAC_NW, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,     MAC_DW, XXXXXXX,   RESET
                                      //`--------------------------'  `--------------------------'
  ),

  /* Symbols
   * ,-----------------------------------------.                ,-----------------------------------------.
   * |      |  !   |  @   |  #   |  $   |  %   |                |  ^   |  &   |  *   |      |      |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      |  `   |  ~   |  (   |  )   |      |                |  |   |  -   |  =   |  <   |  >   |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      |  [   |  ]   |  {   |  }   |      |                |  \   |  _   |  +   |      |      |      |
   * `------+------+------+------+------+------|------.  .------+------+------+---------------------------'
   *                             |      |      |      |  |      |      |      |
   *                             `--------------------'  `--------------------'
   */
  [_SYMB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_EXLM,  KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_GRV,KC_TILDE, KC_LPRN, KC_RPRN, XXXXXXX,                      KC_PIPE, KC_MINS,  KC_EQL,   KC_LT,   KC_GT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, XXXXXXX,                      KC_BSLS, KC_UNDS, KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  KC_SPC,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  /* Numbers
   * ,-----------------------------------------.                ,-----------------------------------------.
   * |      | F12  |  F7  |  F8  |  F9  |      |                |  -   |  7   |  8   |  9   |  /   |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      | F11  |  F4  |  F5  |  F6  |      |                |  +   |  4   |  5   |  6   |  *   |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      | F10  |  F1  |  F2  |  F3  |      |                |  _   |  1   |  2   |  3   | Enter|      |
   * `------+------+------+------+------+------|------.  .------+------+------+---------------------------'
   *                             |      |      |      |  |  ,   |  0   |  .   |
   *                             `--------------------'  `--------------------'
   */
  [_NUMB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  KC_F12,   KC_F7,   KC_F8,   KC_F9, XXXXXXX,                      KC_MINS,    KC_7,    KC_8,    KC_9, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F11,   KC_F4,   KC_F5,   KC_F6, XXXXXXX,                      KC_PLUS,    KC_4,    KC_5,    KC_6, KC_ASTR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,                      KC_UNDS,    KC_1,    KC_2,    KC_3,  KC_ENT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    KC_COMM,    KC_0,  KC_DOT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case _BASE:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case _NAVI:
            oled_write_ln_P(PSTR("NAV"), false);
            break;
        case _SYMB:
            oled_write_ln_P(PSTR("SYMB"), false);
            break;
        case _NUMB:
            oled_write_ln_P(PSTR("NUMB"), false);
            break;
        default:
            oled_write_ln_P(PSTR("???"), false);
            break;
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';

  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
     (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
     keycode = keycode & 0xFF;
  }

  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "Key: %c (%d,%d)\n",
           name, record->event.key.row, record->event.key.col);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

char caps_state_str[11] = {};

void oled_render_caps_state(void) {
    led_t led_state = host_keyboard_led_state();  // caps lock stuff, prints CAPS on new line if caps led is on
    snprintf(caps_state_str, sizeof(caps_state_str), "Caps: %s\n", led_state.caps_lock ? "ON " : "OFF");
    oled_write(caps_state_str, false);
}

static void oled_render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,192,192,192, 64, 32, 16,  8,  8,  4,  4,  2,  2,  2,  2,  2,  2,  2,  2,  2,  4,  4,  8,  8, 16,224,224,224,224,224, 64, 96, 96,112,240,224,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224,224,240,112, 96, 96, 64,224,224,224,224,224, 16,  8,  8,  4,  4,  2,  2,  2,  2,  2,  2,  2,  2,  2,  4,  4,  8,  8, 16, 32, 64,192,192,192,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 39,255,255,195,224,224,192,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,224,224,224,  0,  0,  0,  0,  7, 15, 15,  3,  1,  0,  0,128,128,192,192,193,129,130,  4, 24,240,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,240, 24,  4,130,129,193,192,192,128,128,  0,  0,  1,  3, 15, 15,  7,  0,  0,  0,  0,224,224,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,192,224,224,195,255,255, 39,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,124,255,255,255,255,255,255,255,255,254,240,240,240,224,224,192,  0,  0,255,255,255,255,252,240,224,192,128,128,128,128,128,128,158,191, 63, 63, 63, 31,  7,  7,  0,  0, 51,115, 52,204,248,240,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,224,240,248,204, 52,115, 51,  0,  0,  7,  7, 31, 63, 63, 63,191,158,128,128,128,128,128,128,192,224,240,252,255,255,255,255,  0,  0,192,224,224,240,240,240,254,255,255,255,255,255,255,255,255,124,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3, 15, 31, 63, 63,127,127, 67, 65, 64, 64, 32, 32, 56, 47, 32, 32, 32, 35, 39, 47, 63, 63, 63,127,127,127,127,127,127,127,127,127,127, 63, 62, 16, 16,  8,  8,  4,  4,  6,  7,  7,  3,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  3,  7,  7,  6,  4,  4,  8,  8, 16, 16, 62, 63,127,127,127,127,127,127,127,127,127,127, 63, 63, 63, 47, 39, 35, 32, 32, 32, 47, 56, 32, 32, 64, 64, 65, 67,127,127, 63, 63, 31, 15,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

// Used to draw on to the oled screen
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_caps_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif
