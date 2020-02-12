/* Copyright 2015-2017 Jack Humbert
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

#include "preonic.h"
#include "action_layer.h"


enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
  * ,-----------------------------------------------------------------------------------.
  * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Esc  | Ctrl | GUI  | Alt  |Lower |    Space    |Raise |  -   |  =   |  (   |   )  |
  * `-----------------------------------------------------------------------------------'
  */
  [_QWERTY] = LAYOUT_preonic_1x2uC(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, 
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL,
    KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, MEH_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT, 
    KC_ESC, HYPR(OSL(3)), KC_LGUI, KC_LALT, LOWER, KC_SPC, RAISE, KC_MINS, KC_EQL, KC_LPRN, KC_RPRN
  ),

  /* Colemak
  * ,-----------------------------------------------------------------------------------.
  * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Ctrl |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Esc  | Ctrl | GUI  | Alt  |Lower |    Space    |Raise |  -   |  =   |  (   |   )  |
  * `-----------------------------------------------------------------------------------'
  */
  [_COLEMAK] = LAYOUT_preonic_1x2uC(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, 
    KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_DEL,
    KC_LCTL, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
    KC_LSFT, MEH_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT, 
    KC_ESC, HYPR(OSL(3)), KC_LGUI, KC_LALT, LOWER, KC_SPC, RAISE, KC_MINS, KC_EQL, KC_LPRN, KC_RPRN
  ),

  /* Dvorak
  * ,-----------------------------------------------------------------------------------.
  * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Ctrl |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Esc  | Ctrl | GUI  | Alt  |Lower |    Space    |Raise |  -   |  =   |  (   |   )  |
  * `-----------------------------------------------------------------------------------'
  */
  [_DVORAK] = LAYOUT_preonic_1x2uC(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, 
    KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_DEL,
    KC_LCTL, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_SLSH,
    KC_LSFT, MEH_T(KC_SCLN), KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_SFTENT, 
    KC_ESC, HYPR(OSL(3)), KC_LGUI, KC_LALT, LOWER, KC_SPC, RAISE, KC_MINS, KC_EQL, KC_LPRN, KC_RPRN
  ),

  /* Lower
  * ,-----------------------------------------------------------------------------------.
  * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Tab  | Home |  Up  | End  |Pg up |      |      |      |      |      |      |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Ctrl | Left | Down |Right |Pg dn |      |      |      |      |      |      |Prntsc|
  * |------+------+------+------+------+------|------+------+------+------+------+------|+
  * | Shift| Bksp | Del  | Enter|      |      | Mute | Vol- | Vol+ | Next | Play |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Esc  |      | GUI  | Alt  |      |     GUI     |      |      |      |  [   |  ]   |
  * `-----------------------------------------------------------------------------------'
  */
  [_LOWER] = LAYOUT_preonic_1x2uC(KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    KC_TRNS, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR,
    KC_TRNS, KC_BSPC, KC_DEL, KC_ENT, KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_NO,
    KC_ESC, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_LGUI, KC_TRNS, KC_NO, KC_NO, KC_LBRC, KC_RBRC
  ),

  /* Raise
  * ,-----------------------------------------------------------------------------------.
  * |      |Prntsc| Pause| Ins  |      |      |Nmlock|   /  |   7  |   8  |   9  | Bksp |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |   *  |   4  |   5  |   6  | Del  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |   -  |   1  |   2  |   3  |  =   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |   +  |   0  |  ,   |   .  |Enter |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |    Space    |      |      |      |  {   |  }   |
  * `-----------------------------------------------------------------------------------'
  */
  [_RAISE] = LAYOUT_preonic_1x2uC(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NLCK, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_BSPC,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PAST, KC_P4, KC_P5, KC_P6, KC_DEL,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PMNS, KC_P1, KC_P2, KC_P3, KC_PEQL,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PPLS, KC_P0, KC_PDOT, KC_PCMM, KC_PENT,
    KC_NO, KC_NO, KC_NO, KC_LALT, KC_TRNS, KC_SPC, KC_TRNS, KC_RALT, KC_NO, KC_LCBR, KC_RCBR
  ),

  /* Adjust (Lower + Raise)
  * ,-----------------------------------------------------------------------------------.
  * |      |      |      |      |      |      |      |      |      |      |      /      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      | Reset|Debug |      |      |      |      |TRMON |TRMOFF|      |      |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_ADJUST] = LAYOUT_preonic_1x2uC(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, RESET, DEBUG, EEP_RST, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, MU_MOD, AU_ON, AU_OFF, AG_NORM, AG_SWAP, QWERTY, COLEMAK, DVORAK, KC_NO, KC_NO,
    KC_NO, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      }
    return true;
};
