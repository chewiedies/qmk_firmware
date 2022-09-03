/* Copyright 2021 duckyb
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

enum custom_keycodes {
    BSPREV = SAFE_RANGE,
    BSNEXT,
    BSPLAY,
    BSTHMUP,
    BSTHMDN,
    YTMUSIC
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE = 0,
    _FN,
    _MEDIA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base Layer
   * ,-------------------------------------.
   * |     |  Esc  |  1|  2|  3|  4|  5|  6|
   * |	   |-------+---+---+---+---+---+---|
   * |     |  Tab  |  Q|  W|  E|  R|  T|  7|
   * |----||-------+---+---+---+---+---+---|
   * | F13|| Enter |  A|  S|  D|  F|  G|  8|
   * |----||-------+---+---+---+---+---+---|
   * | F14|| Shift |  Z|  X|  C|  V|  B|  9|
   * |----||-------------------------------|
   * | F15|| LCtrl | GUI |Alt|  Space  |  0|
   * `----'`-------------------------------'
   */
    [_BASE] = LAYOUT(
		          KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,
		          KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_7,
		KC_F13,   KC_ENT,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_8,
		KC_F14,   KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_9,
		KC_F15,   KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,                       LT(_FN, KC_0)
    ),

    [_FN] = LAYOUT(
                  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
		          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_HUD,  RGB_HUI,  KC_F7,
     DF(_MEDIA),  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_VAD,  RGB_VAI,  KC_F9,
		RGB_TOG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_SAD,  RGB_SAI,  KC_F10,
		RESET,    XXXXXXX,  XXXXXXX,  RGB_RMOD, RGB_MOD,                      _______
    ),
    [_MEDIA] = LAYOUT(
                  DF(_BASE),XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
		          XXXXXXX,  XXXXXXX,  KC_WH_U,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
		YTMUSIC,  XXXXXXX,  KC_WH_L,  KC_WH_D,  KC_WH_R,  XXXXXXX,  XXXXXXX,  XXXXXXX,
		KC_VOLU,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
		KC_VOLD,  BSTHMDN,  BSTHMUP,  BSPREV,             BSPLAY,             BSNEXT
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSPREV:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LGUI);
                register_code(KC_PGDN);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
                unregister_code(KC_PGDN);
            }
            break;
        case BSNEXT:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LGUI);
                register_code(KC_PGUP);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
                unregister_code(KC_PGUP);
            }
            break;
        case BSPLAY:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LGUI);
                register_code(KC_SPC);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
                unregister_code(KC_SPC);
            }
            break;
        case BSTHMDN:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LGUI);
                register_code(KC_D);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
                unregister_code(KC_D);
            }
            break;
        case BSTHMUP:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LGUI);
                register_code(KC_L);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
                unregister_code(KC_L);
            }
            break;
        case YTMUSIC:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_Y);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_Y);
            }
            break;
    }
    return true;
}
// Runs just one time when the keyboard initializes.
void matrix_scan_user(void) {
    static bool has_ran_yet = false;
    if (!has_ran_yet) {
        has_ran_yet = true;
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 3);
        // rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
        // rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        // rgblight_sethsv(HSV_YELLOW);
    }
};
