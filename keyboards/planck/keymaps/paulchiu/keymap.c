/* Copyright 2021 Paul Chiu
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

enum planck_layers {
  _BASE,
  _QWER,
  _NAVI, // Navigation
  _SYMB, // Symbols
  _NUMB, // Numbers and function keys
  _TOGG, // Toggle layers
  _ADJU  // Adjustments
};

#define ESNV LT(_NAVI, KC_ESC)
#define ESNU LT(_NUMB, KC_ESC)
#define ETSB LT(_SYMB, KC_ENT)
#define SPNU LT(_NUMB, KC_SPC)
#define NAVI MO(_NAVI)
#define NUMB MO(_NUMB)
#define QWET TG(_QWER)
#define NAVT TG(_NAVI)
#define SYMT TG(_SYMB)
#define NUMT TG(_NUMB)
#define ADJT TG(_ADJU)
#define TOGG MO(_TOGG)
#define ADJU MO(_ADJU)
#define MTCZ MT(MOD_LCTL, KC_Z)
#define MTAX MT(MOD_LALT, KC_X)
#define MTGC MT(MOD_LGUI, KC_C)
#define MTGM MT(MOD_RGUI, KC_COMM)
#define MTAD MT(MOD_LALT, KC_DOT)
#define MTCS MT(MOD_RCTL, KC_SLSH)
#define SPLT LGUI(KC_SPC)       // Spotlight
#define COPY LGUI(KC_C)         // Copy
#define PSTE LGUI(KC_V)         // Paste
#define UNDO LGUI(KC_Z)         // Undo
#define NXWN LGUI(KC_GRV)       // Next application window
#define PVWD LALT(KC_LEFT)      // Previous word
#define NXWD LALT(KC_RGHT)      // Next word
#define DPVW LALT(KC_BSPC)      // Delete previous word

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  ⌃Z  |  ⌥X  |  ⌘C  |   V  |   B  |   N  |   M  |  ⌘,  |  ⌥.  |  ⌃/  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps | Ctrl | HYPR | NUMB | ESNU |    Space    | ETSB | SPLT | HYPR | Ctrl | TOGG |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
    KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT,   MTCZ,    MTAX,    MTGC,    KC_V,    KC_B,    KC_N,    KC_M,    MTGM,    MTAD,    MTCS, KC_RSFT,
    KC_CAPS,KC_LCTL, KC_HYPR,    NUMB,    ESNV,  KC_SPC,  KC_SPC,    ETSB,    SPLT, KC_HYPR, KC_RCTL,    TOGG
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |      |
 * |- ----+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWER] = LAYOUT_planck_grid(
    _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,
    _______,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, _______,
    _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Navigation
 * ,-----------------------------------------------------------------------------------.
 * | NXWN | Home |  ↑   | End  | PgUp |      |      |      | Ins  |      |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Enter|  ←   |  ↓   |  →   | PgDn |      |  ←   |  ↓   |  ↑   |  →   | Enter|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | UNDO | Del  | COPY | PAST |      |      | PVWD | NXWD |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             | DPVW |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVI] = LAYOUT_planck_grid(
       NXWN, KC_HOME,   KC_UP,  KC_END, KC_PGUP, _______, _______, _______,  KC_INS, _______, _______,  KC_DEL,
     KC_ENT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_ENT, _______,
    _______,    UNDO,  KC_DEL,    COPY,    PSTE, _______, _______,    PVWD,    NXWD, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    DPVW, _______, _______, _______, _______
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |      |  !   |  @   |  #   |  $   |  %   |  ^   |  &   |  *   |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  `   |  ~   |  (   |  )   |      |  |   |  _   |  =   |  <   |  >   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  [   |  ]   |  {   |  }   |      |  \   |  -   |  +   |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMB] = LAYOUT_planck_grid(
    _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, _______,
    _______,  KC_GRV,KC_TILDE, KC_LPRN, KC_RPRN, _______, KC_PIPE, KC_UNDS,  KC_EQL,   KC_LT,   KC_GT, _______,
    _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, KC_BSLS, KC_MINS, KC_PLUS, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Numbers, Functions and Adjustments
 * ,-----------------------------------------------------------------------------------.
 * |      | F12  |  F7  |  F8  |  F9  |      |  -   |  7   |  8   |  9   |  /   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | F11  |  F4  |  F5  |  F6  |      |  +   |  4   |  5   |  6   |  *   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | F10  |  F1  |  F2  |  F3  |      |  _   |  1   |  2   |  3   | Enter|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |  0   |  .   |  ,   |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMB] = LAYOUT_planck_grid(
    _______,  KC_F12,   KC_F7,   KC_F8,   KC_F9, _______, KC_MINS,    KC_7,    KC_8,     KC_9, KC_SLSH, _______,
    _______,  KC_F11,   KC_F4,   KC_F5,   KC_F6, _______, KC_PLUS,    KC_4,    KC_5,     KC_6, KC_ASTR, _______,
    _______,  KC_F10,   KC_F1,   KC_F2,   KC_F3, _______, KC_UNDS,    KC_1,    KC_2,     KC_3,  KC_ENT, _______,
    _______, _______, _______, _______, _______, _______, _______,    KC_0,    KC_DOT,KC_COMM, _______, _______
),

/* Toggle layers
 * ,-----------------------------------------------------------------------------------.
 * |      | QWET |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | ADJT |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | NUMT | NAVT |             | SYMT |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_TOGG] = LAYOUT_planck_grid(
    _______,    QWET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,    ADJT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,    NUMT,    NAVT, _______, _______,    SYMT, _______, _______, _______, _______
),

/* Adjustments
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      | RgbT |      | RHu- | RHu+ |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | RMoF |      | RSa- | RSa+ |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | VoMu | VoDn | VoUp |      | RBr- | RBr+ |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJU] = LAYOUT_planck_grid(
    _______, _______, _______,    _______,  RGB_TOG, _______, RGB_HUD, RGB_HUI, _______, _______, _______, _______,
    _______, _______, _______,    _______,  RGB_MOD, _______, RGB_SAD, RGB_SAI, _______, _______, _______, _______,
    _______, _______,KC__MUTE,KC__VOLDOWN,KC__VOLUP, _______, RGB_VAD, RGB_VAI, _______, _______, _______, _______,
    _______, _______, _______,    _______,  _______, _______, _______, _______, _______, _______, _______, _______
)
};
