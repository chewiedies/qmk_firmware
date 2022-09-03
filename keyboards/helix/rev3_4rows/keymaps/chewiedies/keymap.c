/* Copyright 2020 yushakobo
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

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUM
};

// #define LOWER MO(_LOWER)
// #define RAISE MO(_RAISE)
#define ALTTAB  MT(MOD_LALT, KC_TAB)
#define ALTENT  MT(MOD_LALT, KC_ENT)
#define CMDESC  MT(MOD_LGUI, KC_ESC)
#define SFTSPC  MT(MOD_LSFT, KC_SPC)
#define SFTENT  MT(MOD_LSFT, KC_ENT)
#define NUMENT  LT(_NUM, KC_ENT)
#define NUMMIN  LT(_NUM, KC_MINS)
#define MOUSBSP LT(_MOUSE, KC_BSPC)
#define MOUSLYR TT(_MOUSE)
#define NUMBSP  LT(_NUM, KC_BSPC)
#define OSMALT  OSM(MOD_LALT)
#define OSMCTL  OSM(MOD_LCTL)
#define OSMGUI  OSM(MOD_LGUI)
#define OSMSFT  OSM(MOD_LSFT)
#define KCUNDO  LGUI(KC_Z)
#define KCREDO  LGUI(LSFT(KC_Z))
#define SFTTAB  LSFT(KC_TAB)
#define PRVWRD  LALT(KC_LEFT)
#define NXTWRD  LALT(KC_RGHT)
#define LNBEG   LGUI(KC_LEFT)
#define LNEND   LGUI(KC_RGHT)
#define PGTOP   LGUI(KC_UP)
#define PGBOT   LGUI(KC_DOWN)
#define PSTBRD  LGUI(LALT(KC_V))
#define SCRNCAP LCTL(LGUI(LSFT(KC_4)))
#define THECLAW LCMD(LSFT(LALT(KC_S)))
#define W_LHALF LCTL(LGUI(KC_LEFT))
#define W_RHALF LCTL(LGUI(KC_RGHT))
#define W_THALF LCTL(LGUI(KC_UP))
#define W_BHALF LCTL(LGUI(KC_DOWN))
#define W_LTHRD LCTL(LALT(KC_LEFT))
#define W_RTHRD LCTL(LALT(KC_RGHT))
#define W_TTHRD LCTL(LALT(KC_UP))
#define W_BTHRD LCTL(LALT(KC_DOWN))
#define W_MAX   LCTL(LALT(LGUI(KC_F)))
#define W_CENT  LALT(LGUI(KC_C))
#define W_SHOW  LCTL(KC_DOWN)

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    KC_IMP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* _QWERTY
*╭────────╭────────╭────────╭────────╭────────╭────────╮                        ╭────────╮────────╮────────╮────────╮────────╮────────╮
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯                        ╰────────╰────────╰────────╰────────╰────────╰────────╯
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯                        ╰────────╰────────╰────────╰────────╰────────╰────────╯
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯────────╮      ╭────────╰────────╰────────╰────────╰────────╰────────╰────────╯
*│        │        │        │        │        │        │        │      │        │        │        │        │        │        │        │
*│        │        │        │        │        │        │        │      │        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯────────╯      ╰────────╰────────╰────────╰────────╰────────╰────────╰────────╯
*/
[_QWERTY] = LAYOUT(
  ALTTAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  CMDESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, RAISE,   SFTSPC,  NUMENT,         KC_BSPC, KC_SPC,  LOWER,   XXXXXXX, KC_RALT, KC_RCTL, KC_RGUI
),

/* _RAISE
*╭────────╭────────╭────────╭────────╭────────╭────────╮                        ╭────────╮────────╮────────╮────────╮────────╮────────╮
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯                        ╰────────╰────────╰────────╰────────╰────────╰────────╯
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯                        ╰────────╰────────╰────────╰────────╰────────╰────────╯
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯────────╮      ╭────────╰────────╰────────╰────────╰────────╰────────╰────────╯
*│        │        │        │        │        │        │        │      │        │        │        │        │        │        │        │
*│        │        │        │        │        │        │        │      │        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯────────╯      ╰────────╰────────╰────────╰────────╰────────╰────────╰────────╯
*/
[_RAISE] = LAYOUT(
  SFTTAB,  XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,                          PGTOP,   PRVWRD,  KC_UP,   NXTWRD,  XXXXXXX, KC_DEL,
  KCUNDO,  KCREDO,  XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3,                          XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  KC_CAPS, KC_EQL,  KC_PLUS, KC_MINS, KC_UNDS, KC_DOT,                           PGBOT,   LNBEG,   XXXXXXX, LNEND,   KC_BSLS, XXXXXXX,
  SCRNCAP, THECLAW, _______, _______, _______, _______, _______,        KC_DEL,  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* _LOWER
*╭────────╭────────╭────────╭────────╭────────╭────────╮                        ╭────────╮────────╮────────╮────────╮────────╮────────╮
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯                        ╰────────╰────────╰────────╰────────╰────────╰────────╯
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯                        ╰────────╰────────╰────────╰────────╰────────╰────────╯
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯────────╮      ╭────────╰────────╰────────╰────────╰────────╰────────╰────────╯
*│        │        │        │        │        │        │        │      │        │        │        │        │        │        │        │
*│        │        │        │        │        │        │        │      │        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯────────╯      ╰────────╰────────╰────────╰────────╰────────╰────────╰────────╯
*/
[_LOWER] = LAYOUT(
  KC_IMP,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  CMDESC,  KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_LBRC,                          KC_RBRC, KC_GRV,  XXXXXXX, KC_DQUO, KC_QUOT, XXXXXXX,
  KC_CAPS, KC_EQL,  KC_PLUS, KC_MINS, KC_UNDS, KC_DOT,                           XXXXXXX, KC_TILD, XXXXXXX, KC_PIPE, KC_BSLS, XXXXXXX,
  SCRNCAP, THECLAW, _______, _______, _______, _______, _______,        _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* _ADJUST
*╭────────╭────────╭────────╭────────╭────────╭────────╮                        ╭────────╮────────╮────────╮────────╮────────╮────────╮
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯                        ╰────────╰────────╰────────╰────────╰────────╰────────╯
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯                        ╰────────╰────────╰────────╰────────╰────────╰────────╯
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯────────╮      ╭────────╰────────╰────────╰────────╰────────╰────────╰────────╯
*│        │        │        │        │        │        │        │      │        │        │        │        │        │        │        │
*│        │        │        │        │        │        │        │      │        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯────────╯      ╰────────╰────────╰────────╰────────╰────────╰────────╰────────╯
*/
[_ADJUST] =  LAYOUT(
  RGB_TOG, XXXXXXX, W_SHOW,  W_TTHRD, XXXXXXX, RGB_RMOD,                         RGB_MOD, XXXXXXX, W_THALF, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, W_LTHRD, W_MAX,   W_RTHRD, RGB_HUD,                          RGB_HUI, W_LHALF, W_CENT,  W_RHALF, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, W_BTHRD, XXXXXXX, RGB_VAD,                          RGB_VAI, XXXXXXX, W_BHALF, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SPD, RESET,          RESET,   RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* _NUM
*╭────────╭────────╭────────╭────────╭────────╭────────╮                        ╭────────╮────────╮────────╮────────╮────────╮────────╮
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯                        ╰────────╰────────╰────────╰────────╰────────╰────────╯
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯                        ╰────────╰────────╰────────╰────────╰────────╰────────╯
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*│        │        │        │        │        │        │                        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯────────╮      ╭────────╰────────╰────────╰────────╰────────╰────────╰────────╯
*│        │        │        │        │        │        │        │      │        │        │        │        │        │        │        │
*│        │        │        │        │        │        │        │      │        │        │        │        │        │        │        │
*╰────────╰────────╰────────╰────────╰────────╰────────╯────────╯      ╰────────╰────────╰────────╰────────╰────────╰────────╰────────╯
*/

[_NUM] = LAYOUT(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COLN, _______,
  _______, KC_EQL,  KC_PLUS, KC_MINS, KC_COMM, KC_DOT,                           XXXXXXX, XXXXXXX, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______
)

  /* _SAMPLE
   *
   *  ╭────────╭────────╭────────╭────────╭────────╭────────╮                        ╭────────╮────────╮────────╮────────╮────────╮────────╮
   *  │        │        │        │        │        │        │                        │        │        │        │        │        │        │
   *  │        │        │        │        │        │        │                        │        │        │        │        │        │        │
   *  ╰────────╰────────╰────────╰────────╰────────╰────────╯                        ╰────────╰────────╰────────╰────────╰────────╰────────╯
   *  │        │        │        │        │        │        │                        │        │        │        │        │        │        │
   *  │        │        │        │        │        │        │                        │        │        │        │        │        │        │
   *  ╰────────╰────────╰────────╰────────╰────────╰────────╯                        ╰────────╰────────╰────────╰────────╰────────╰────────╯
   *  │        │        │        │        │        │        │                        │        │        │        │        │        │        │
   *  │        │        │        │        │        │        │                        │        │        │        │        │        │        │
   *  ╰────────╰────────╰────────╰────────╰────────╰────────╯────────╮      ╭────────╰────────╰────────╰────────╰────────╰────────╰────────╯
   *  │        │        │        │        │        │        │        │      │        │        │        │        │        │        │        │
   *  │        │        │        │        │        │        │        │      │        │        │        │        │        │        │        │
   *  ╰────────╰────────╰────────╰────────╰────────╰────────╯────────╯      ╰────────╰────────╰────────╰────────╰────────╰────────╰────────╯
   *
   *
   * [_SAMPLE] = LAYOUT(
   * _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
   * _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
   * _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
   * _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
   * )
   */
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Left side encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) { /* Right side encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Custom Keycode Stuff
// uint16_t key_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
        case KC_IMP:
            if (record->event.pressed) {
                SEND_STRING(" !important;");
            } else {

            }
            break;
        // case LGUIRSE:
        //      if (record->event.pressed) {
        //         key_timer = timer_read();
        //         layer_on(_RAISE);
        //         update_tri_layer(_LOWER, _RAISE, _ADJUST);
        //     } else {
        //         layer_off(_RAISE);
        //         update_tri_layer(_LOWER, _RAISE, _ADJUST);
        //         if (timer_elapsed(key_timer) < TAPPING_TERM) {
        //             add_oneshot_mods(MOD_BIT(KC_LGUI));
        //         }
        //     }
        //     break;
    }

    return true;
}
