/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUM,
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
    KC_IMP,
    LGUIRSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base Layer: _QWERTY
 *                            ╭────────╮                                                            ╭────────╮
 *                   ╭────────╯        ╰────────╮                                          ╭────────╯        ╰────────╮
 *                   │        │   E    │        ╰────────╮                        ╭────────╯        │    I   │        │
 *          ╭────────╯   W    ╰────────╯   R    │        │                        │        │    U   ╰────────╯    O   ╰────────╮
 *          │        ╰────────╯        ╰────────╯   T    │                        │    Y   ╰────────╯        ╰────────╯        │
 * ╭────────╮   Q    │        │   D    │        ╰────────╯                        ╰────────╯        │    K   │        │    P   ╰────────╮
 * │ (ALT)  ╰────────╯   S    ╰────────╯   F    │        │                        │        │    J   ╰────────╯    L   ╰────────╯        │
 * │  Tab   │        ╰────────╯        ╰────────╯   G    │                        │    H   ╰────────╯    <   ╰────────╯    :   │ Bkspce │
 * ╰────────╯   A    │        │   C    │        ╰────────╯                        ╰────────╯        │    ,   │    >   │    ;   ╰────────╯
 * │ (CMD)  ╰────────╯   X    ╰────────╯   V    │        │                        │        │    M   ╰────────╯    .   ╰────────╯    "   │
 * │  Esc   │        ╰────────╯        ╰────────╯   B    │                        │    N   ╰────────╯        ╰────────╯    ?   │    '   │
 * ╰────────╯   Z    │                          ╰────────╯                        ╰────────╯                          │    /   ╰────────╯
 * │        ╰────────╯                  ╭────────╮                                        ╭────────╮                  ╰────────╯(Shift) │
 * │  CTRL  │                           │        ╰────────╮                      ╭────────╯        │                           │ Enter  │
 * ╰────────╯                           │  RSE   │ (Shift)╰────────╮    ╭────────╯        │  Mute  │                           ╰────────╯
 *                                      ╰────────╯ Space  │ (num)  │    │  (num) │  LWR   ╰────────╯
 *                                               ╰────────╯ Enter  │    │  - _   ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 */
    [_QWERTY] = LAYOUT_split_3x6_3(
        ALTTAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,              KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,     KC_BSPC,
        CMDESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,              KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
        KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,              KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  ALTENT,
                                      RAISE,    SFTSPC,   NUMENT,            NUMBSP,  KC_SPC,   LOWER
    ),

/* Layer: _RAISE
 *                            ╭────────╮                                                            ╭────────╮
 *                   ╭────────╯        ╰────────╮                                          ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                        ╭────────╯        │        │        │
 *          ╭────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╮
 *          │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │
 * ╭────────╮        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╮
 * │ Shift/ ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │ Tab    │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯  Redo  │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╯
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │  Undo  │        ╰────────╯        ╰────────╯ Bkspce │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │                          ╰────────╯                        ╰────────╯                          │        ╰────────╯
 * │        ╰────────╯                  ╭────────╮                                        ╭────────╮                  ╰────────╯        │
 * │        │                           │        ╰────────╮                      ╭────────╯        │                           │        │
 * ╰────────╯                           │  RSE   │        ╰────────╮    ╭────────╯(Shift) │   LWR  │                           ╰────────╯
 *                                      ╰────────╯        │        │    │        │ Space  ╰────────╯
 *                                               ╰────────╯        │    │        ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 */

[_RAISE] = LAYOUT_split_3x6_3(
    SFTTAB,   XXXXXXX,  KC_MUTE,  KC_VOLD,  KC_VOLU,  XXXXXXX,           PGTOP,    PRVWRD,   KC_UP,    NXTWRD,   XXXXXXX,  KC_DEL,
    KCUNDO,   KCREDO,   OSMALT,   OSMCTL,   OSMGUI,   OSMSFT,            XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_DEL,   KC_BSPC,           PGBOT,    LNBEG,    XXXXXXX,  LNEND,    XXXXXXX,  XXXXXXX,
                                  _______,  _______,  _______,           XXXXXXX,  SFTSPC,   _______
),


/* Layer: _LOWER
 *                            ╭────────╮                                                            ╭────────╮
 *                   ╭────────╯        ╰────────╮                                          ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                        ╭────────╯        │        │        │
 *          ╭────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╮
 *          │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │
 * ╭────────╮        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╮
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╯
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │                          ╰────────╯                        ╰────────╯                          │        ╰────────╯
 * │        ╰────────╯                  ╭────────╮                                        ╭────────╮                  ╰────────╯        │
 * │        │                           │        ╰────────╮                      ╭────────╯        │                           │        │
 * ╰────────╯                           │        │        ╰────────╮    ╭────────╯        │        │                           ╰────────╯
 *                                      ╰────────╯        │        │    │        │        ╰────────╯
 *                                               ╰────────╯        │    │        ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 */

[_LOWER] = LAYOUT_split_3x6_3(
    KC_IMP,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,           KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
    CMDESC,   XXXXXXX,  THECLAW,  KC_LPRN,  KC_RPRN,  KC_LCBR,           KC_RCBR,  KC_GRV,   XXXXXXX,  KC_DQUO,  KC_QUOT,  XXXXXXX,
    XXXXXXX,  KC_EQL,   KC_PLUS,  KC_MINS,  KC_UNDS,  KC_LBRC,           KC_RBRC,  KC_TILD,  XXXXXXX,  KC_PIPE,  KC_BSLS,  XXXXXXX,
                                  _______,  _______,  _______,           _______,  KC_LSFT,  _______
),


/* Layer: _ADJUST
 *                            ╭────────╮                                                            ╭────────╮
 *                   ╭────────╯        ╰────────╮                                          ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                        ╭────────╯        │        │        │
 *          ╭────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╮
 *          │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │
 * ╭────────╮        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╮
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╯
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │                          ╰────────╯                        ╰────────╯                          │        ╰────────╯
 * │        ╰────────╯                  ╭────────╮                                        ╭────────╮                  ╰────────╯        │
 * │        │                           │        ╰────────╮                      ╭────────╯        │                           │        │
 * ╰────────╯                           │        │        ╰────────╮    ╭────────╯        │        │                           ╰────────╯
 *                                      ╰────────╯        │        │    │        │        ╰────────╯
 *                                               ╰────────╯        │    │        ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 */

[_ADJUST] = LAYOUT_split_3x6_3(
    RGB_TOG,  XXXXXXX,  W_SHOW,   W_TTHRD,  XXXXXXX,  RGB_RMOD,          RGB_MOD,  XXXXXXX,  W_THALF,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  W_LTHRD,  W_MAX,    W_RTHRD,  RGB_HUD,           RGB_HUI,  W_LHALF,  W_CENT,   W_RHALF,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  W_BTHRD,  XXXXXXX,  RGB_VAD,           RGB_VAI,  XXXXXXX,  W_BHALF,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                  _______,  XXXXXXX,  RGB_SAD,           RGB_SAI,  XXXXXXX,  _______
),


/* Layer: _NUM
 *                            ╭────────╮                                                            ╭────────╮
 *                   ╭────────╯        ╰────────╮                                          ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                        ╭────────╯        │        │        │
 *          ╭────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╮
 *          │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │
 * ╭────────╮        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╮
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╯
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │                          ╰────────╯                        ╰────────╯                          │        ╰────────╯
 * │        ╰────────╯                  ╭────────╮                                        ╭────────╮                  ╰────────╯        │
 * │        │                           │        ╰────────╮                      ╭────────╯        │                           │        │
 * ╰────────╯                           │        │        ╰────────╮    ╭────────╯        │        │                           ╰────────╯
 *                                      ╰────────╯        │        │    │        │        ╰────────╯
 *                                               ╰────────╯        │    │        ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 */
[_NUM] =  LAYOUT_split_3x6_3(
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,              KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    _______,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_COLN,  _______,
    _______,  KC_EQL,   KC_PLUS,  KC_MINS,  KC_COMM,  KC_DOT,            XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,
                                  _______,  SFTSPC,   _______,           _______,  SFTSPC,   _______
)

/* Layer: SAMPLE
 *                            ╭────────╮                                                            ╭────────╮
 *                   ╭────────╯        ╰────────╮                                          ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                        ╭────────╯        │        │        │
 *          ╭────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╮
 *          │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │
 * ╭────────╮        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╮
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╯
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │                          ╰────────╯                        ╰────────╯                          │        ╰────────╯
 * │        ╰────────╯                  ╭────────╮                                        ╭────────╮                  ╰────────╯        │
 * │        │                           │        ╰────────╮                      ╭────────╯        │                           │        │
 * ╰────────╯                           │        │        ╰────────╮    ╭────────╯        │        │                           ╰────────╯
 *                                      ╰────────╯        │        │    │        │        ╰────────╯
 *                                               ╰────────╯        │    │        ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 *
 *[_SAMPLE] = LAYOUT_ffkb(
 *  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 *  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 *  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 *                                _______,  XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  _______
 *),
 */

};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return OLED_ROTATION_270;
}


// // Commenting out logo as it takes up a lot of space :(
void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0
    };
    oled_write_P(crkbd_logo, false);
}

static void render_status(void) {
    oled_write_P(PSTR("-----CRKBD-----\n\n\n\n"), false);

    oled_write_P(PSTR("Layer\n"), false);
    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base \n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjus\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Numbr\n"), false);
            break;

        default:
            oled_write_P(PSTR("Undef\n"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);

}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        oled_render_logo();
    }

return true;
}

#endif // end OLED_ENABLE


// Custom keycodes output
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
                SEND_STRING("!important");
            } else {

            }
            break;
    }

    return true;
}

