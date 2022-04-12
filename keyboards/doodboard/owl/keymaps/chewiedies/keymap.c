/*
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


enum layers{
    _BASE,
    _RSE,
    _LWR,
    _ADJ,
    _NUM,
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum custom_keycodes {
    KC_BASE = SAFE_RANGE,
    KC_LWR,
    KC_RSE,
    KC_ADJ,
    KC_NUMROW,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_REDO,
    PSTBRD,
    KC_SFTB,
    SCRNCAP,
    KC_IMP,
    KC_CLAW,
    W_LHALF,
    W_RHALF,
    W_THALF,
    W_BHALF,
    W_LTHRD,
    W_RTHRD,
    W_TTHRD,
    W_BTHRD,
    W_MAX,
    W_CENT,
    W_TLEFT,
    W_TRGHT,
    W_BLEFT,
    W_BRGHT,
};

#define RSE MO(_RSE)
#define LWR MO(_LWR)
#define MEHCAPS LCAG_T(KC_CAPS)
#define NUMENT LT(_NUM, KC_ENT)
#define NUMKCB LT(_NUM, KC_B)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS]  = {

/* _BASE
╭────────╮ ╭────────╮────────╮────────╮ ╭────────╮────────╮────────╮────────╮      ╭────────╭────────╭────────╭────────╮ ╭────────╭────────╭────────────────╮
│        │ │        │   !    │   @    │ │   #    │   $    │   %    │   ^    │      │    &   │    *   │    (   │    )   │ │    __  │    +   │                │
│  Mute  │ │   Esc  │    1   │    2   │ │    3   │    4   │    5   │    6   │      │   7    │   8    │   9    │   0    │ │   -    │   =    │   Backspace    │
╰──enc───╯╭╰────────╯─╮──────╯─╮─╭────╯─╰─╮──────╯─╮──────╯─╮──────╯─╮──────╯  ╭───╰────╭───╰────╭───╰────╭───╰────╮─╭─╯─╰────╭───╰────╭───╰────╭───────────╯╮
          │           │        │\│        │        │        │        │         │        │        │        │        │/│        │    {   │    }   │      |     │
          │    Tab    │    Q   │\│    W   │    E   │    R   │    T   │         │   Y    │   U    │   I    │   O    │/│   P    │   [    │   ]    │     \      │
        ╭─╰───────────╯─╮──────╯─╰─╭──────╯─╮──────╯─╮──────╯─╮──────╯─╮       ╰─╭──────╰─╭──────╰─╭──────╰─╭──────╯─╰─╭──────╰─╭──────╰─╭──────╰────────────╯╮
        │     (MEH)     │        │\│        │        │        │        │         │        │        │        │        │/│    :   │    "   │                    │
        │    Capslock   │    A   │\│    S   │    D   │    F   │    G   │         │   H    │   J    │   K    │   L    │/│   ;    │   '    │       Enter        │
       ╭╰───────────────╯───╮────╯─╰─╮─╭────╯───╮────╯───╮────╯───╮────╯───╮  ╭──╰─────╭──╰─────╭──╰─────╭──╰─────╮──╯─╰──────╭─╰──────╮─╰──────────╭─────────╯──╮
       │                    │        │ │        │        │        │        │  │ (NUM)  │        │        │    <   │  │    >   │    ?   │ ╭────────╮ │            │
       │       Shift        │    Z   │ │    X   │    C   │    V   │    B   │  │   B    │   N    │   M    │   ,    │  │   .    │   /    │ │        │ │   Shift    │
       ╰╭───────────╮───────╯╮───────╯ ╰─╭──────╯─╮──╭───╯────╮───╯───────╮╯  ╰────╭───╰───────╭╰───────╮╰─╭──────╯─╮╰────────╰────────╯ │   Up   │ ╰────────────╯
        │           │        │           │        │  │        │   (NUM)   │        │           │        │  │        │           ╭────────╰────────╭────────╮
        │    Ctrl   │   Alt  │           │   Cmd  │  │  (RSE) │   Enter   │        │   Space   │ (LRW)  │  │        │           │        │        │        │
        ╰───────────╯────────╯           ╰────────╯  ╰────────╯───────────╯        ╰───────────╰────────╯  ╰────────╯           │  Left  │  Down  │ Right  │
                                                                                                                                ╰────────╰────────╰────────╯
*/
[_BASE] = LAYOUT_alice(
    KC_MUTE,
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    MEHCAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    NUMKCB,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_RSFT,
    KC_LCTL, KC_LALT,          KC_LGUI, KC_RSE,  NUMENT,           KC_SPC,  KC_LWR,  KC_RALT,          KC_LEFT, KC_DOWN, KC_RGHT
),


/* _LWR
╭────────╮ ╭────────╮────────╮────────╮ ╭────────╮────────╮────────╮────────╮      ╭────────╭────────╭────────╭────────╮ ╭────────╭────────╭────────────────╮
│ Screen │ │   ~    │        │        │ │        │        │        │        │      │        │        │        │        │ │        │        │                │
│  Cap   │ │    `   │   F1   │   F2   │ │   F3   │   F4   │   F5   │   F6   │      │   F7   │   F8   │   F9   │  F10   │ │  F11   │  F12   │   Backspace    │
╰──enc───╯╭╰────────╯─╮──────╯─╮─╭────╯─╰─╮──────╯─╮──────╯─╮──────╯─╮──────╯  ╭───╰────╭───╰────╭───╰────╭───╰────╮─╭─╯─╰────╭───╰────╭───╰────╭───────────╯╮
          │           │        │\│        │        │        │        │         │        │        │        │        │/│        │    {   │    }   │      |     │
          │     ~     │    !   │\│    @   │    #   │    $   │    %   │         │    ^   │    &   │    *   │    (   │/│    )   │   [    │   ]    │     \      │
        ╭─╰───────────╯─╮──────╯─╰─╭──────╯─╮──────╯─╮──────╯─╮──────╯─╮       ╰─╭──────╰─╭──────╰─╭──────╰─╭──────╯─╰─╭──────╰─╭──────╰─╭──────╰────────────╯╮
        │               │        │\│ Save 4 │        │        │        │         │        │        │        │        │/│        │        │                    │
        │               │        │\│   Web  │    (   │    )   │        │         │        │        │        │        │/│        │        │                    │
       ╭╰───────────────╯───╮────╯─╰─╮─╭────╯───╮────╯───╮────╯───╮────╯───╮  ╭──╰─────╭──╰─────╭──╰─────╭──╰─────╮──╯─╰──────╭─╰──────╮─╰──────────╭─────────╯──╮
       │                    │        │ │        │        │        │        │  │        │        │        │        │  │        │        │ ╭────────╮ │            │
       │       Shift        │        │ │        │    {   │    }   │        │  │        │        │        │        │  │        │        │ │        │ │            │
       ╰╭───────────╮───────╯╮───────╯ ╰─╭──────╯─╮──╭───╯────╮───╯───────╮╯  ╰────╭───╰───────╭╰───────╮╰─╭──────╯─╮╰────────╰────────╯ │   Up   │ ╰────────────╯
        │           │        │           │        │  │        │           │        │           │        │  │        │           ╭────────╰────────╭────────╮
        │   Ctrl    │        │           │  LGUI  │  │  (RSE) │   Space   │        │           │ (LWR)  │  │        │           │        │        │        │
        ╰───────────╯────────╯           ╰────────╯  ╰────────╯───────────╯        ╰───────────╰────────╯  ╰────────╯           │  Left  │  Down  │ Right  │
                                                                                                                                ╰────────╰────────╰────────╯
*/
[_LWR] = LAYOUT_alice(
    SCRNCAP,
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______,
    _______, XXXXXXX, KC_CLAW, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,          _______,
    _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______,
    _______, _______,          KC_LGUI, _______, KC_SPC,           _______, _______, _______,          _______, _______, _______
),


/* _RSE
╭────────╮ ╭────────╮────────╮────────╮ ╭────────╮────────╮────────╮────────╮      ╭────────╭────────╭────────╭────────╮ ╭────────╭────────╭────────────────╮
│        │ │        │        │        │ │        │        │        │        │      │        │        │        │        │ │        │        │                │
│        │ │  Undo  │  Redo  │        │ │        │        │        │        │      │        │        │        │        │ │        │        │    Delete      │
╰──enc───╯╭╰────────╯─╮──────╯─╮─╭────╯─╰─╮──────╯─╮──────╯─╮──────╯─╮──────╯  ╭───╰────╭───╰────╭───╰────╭───╰────╮─╭─╯─╰────╭───╰────╭───╰────╭───────────╯╮
          │  Shift/   │        │\│        │        │        │        │         │        │  Prev  │   Up   │  Next  │/│        │        │        │            │
          │   Tab     │        │\│        │        │        │        │         │        │  Word  │        │  Word  │/│        │        │        │            │
        ╭─╰───────────╯─╮──────╯─╰─╭──────╯─╮──────╯─╮──────╯─╮──────╯─╮       ╰─╭──────╰─╭──────╰─╭──────╰─╭──────╯─╰─╭──────╰─╭──────╰─╭──────╰────────────╯╮
        │               │        │\│        │        │        │        │         │        │        │        │        │/│        │        │                    │
        │               │        │\│        │        │        │        │         │        │  Left  │  Down  │ Right  │/│        │        │                    │
       ╭╰───────────────╯───╮────╯─╰─╮─╭────╯───╮────╯───╮────╯───╮────╯───╮  ╭──╰─────╭──╰─────╭──╰─────╭──╰─────╮──╯─╰──────╭─╰──────╮─╰──────────╭─────────╯──╮
       │                    │        │ │        │        │        │        │  │        │  Line  │        │  Line  │  │        │        │ ╭────────╮ │            │
       │                    │        │ │        │        │        │ Bckspc │  │        │  Start │        │  End   │  │        │        │ │        │ │            │
       ╰╭───────────╮───────╯╮───────╯ ╰─╭──────╯─╮──╭───╯────╮───╯───────╮╯  ╰────╭───╰───────╭╰───────╮╰─╭──────╯─╮╰────────╰────────╯ │        │ ╰────────────╯
        │           │        │           │        │  │        │           │        │           │        │  │        │           ╭────────╰────────╭────────╮
        │           │        │           │        │  │  (RSE) │           │        │           │ (LWR)  │  │        │           │        │        │        │
        ╰───────────╯────────╯           ╰────────╯  ╰────────╯───────────╯        ╰───────────╰────────╯  ╰────────╯           │        │        │        │
                                                                                                                                ╰────────╰────────╰────────╯
*/
[_RSE] = LAYOUT_alice(
    PSTBRD,
    KC_UNDO, KC_REDO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
    KC_SFTB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PRVWD,KC_UP,   KC_NXTWD,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX, KC_LSTRT,XXXXXXX, KC_LEND, _______, _______, KC_PGUP, _______,
    _______, _______,          XXXXXXX, _______, XXXXXXX,          _______, _______, _______,          KC_HOME, KC_PGDN, KC_END
),


/* _ADJ
╭────────╮ ╭────────╮────────╮────────╮ ╭────────╮────────╮────────╮────────╮      ╭────────╭────────╭────────╭────────╮ ╭────────╭────────╭────────────────╮
│        │ │        │        │        │ │        │        │        │        │      │        │        │        │        │ │  RGB   │  RGB   │      RGB       │
│ Reset  │ │        │        │        │ │        │        │        │        │      │        │        │        │        │ │  I/O   │  RMod  │      Mod       │
╰──enc───╯╭╰────────╯─╮──────╯─╮─╭────╯─╰─╮──────╯─╮──────╯─╮──────╯─╮──────╯  ╭───╰────╭───╰────╭───╰────╭───╰────╮─╭─╯─╰────╭───╰────╭───╰────╭───────────╯╮
          │           │        │\│        │        │        │        │         │        │        │        │        │/│        │        │        │            │
          │           │        │\│        │        │        │        │         │        │        │        │        │/│        │        │        │            │
        ╭─╰───────────╯─╮──────╯─╰─╭──────╯─╮──────╯─╮──────╯─╮──────╯─╮       ╰─╭──────╰─╭──────╰─╭──────╰─╭──────╯─╰─╭──────╰─╭──────╰─╭──────╰────────────╯╮
        │               │        │\│        │        │        │        │         │        │        │        │        │/│        │        │                    │
        │               │        │\│        │        │        │        │         │        │        │        │        │/│        │        │                    │
       ╭╰───────────────╯───╮────╯─╰─╮─╭────╯───╮────╯───╮────╯───╮────╯───╮  ╭──╰─────╭──╰─────╭──╰─────╭──╰─────╮──╯─╰──────╭─╰──────╮─╰──────────╭─────────╯──╮
       │                    │        │ │        │        │        │        │  │        │        │        │        │  │        │        │ ╭────────╮ │            │
       │                    │        │ │        │        │        │        │  │        │        │        │        │  │        │        │ │  RGB   │ │            │
       ╰╭───────────╮───────╯╮───────╯ ╰─╭──────╯─╮──╭───╯────╮───╯───────╮╯  ╰────╭───╰───────╭╰───────╮╰─╭──────╯─╮╰────────╰────────╯ │  Hue+  │ ╰────────────╯
        │           │        │           │        │  │        │           │        │           │        │  │        │           ╭────────╰────────╭────────╮
        │           │        │           │        │  │        │           │        │           │        │  │        │           │  RGB   │  RGB   │  RGB   │
        ╰───────────╯────────╯           ╰────────╯  ╰────────╯───────────╯        ╰───────────╰────────╯  ╰────────╯           │  Val-  │  Hue-  │  Val+  │
                                                                                                                                ╰────────╰────────╰────────╯
*/
[_ADJ] = LAYOUT_alice(
    RESET,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_RMOD,RGB_MOD,
    XXXXXXX, XXXXXXX, XXXXXXX, W_TTHRD, XXXXXXX, XXXXXXX, XXXXXXX, W_TLEFT, W_THALF, W_TRGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, W_LTHRD, W_MAX,   W_RTHRD, XXXXXXX, XXXXXXX, W_LHALF, W_CENT,  W_RHALF, XXXXXXX, XXXXXXX,          XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, W_BTHRD, XXXXXXX, XXXXXXX, XXXXXXX, W_BLEFT, W_BHALF, W_BRGHT, XXXXXXX, XXXXXXX, RGB_HUI, XXXXXXX,
    XXXXXXX, XXXXXXX,          XXXXXXX, _______, XXXXXXX,          XXXXXXX, _______, XXXXXXX,          RGB_VAD, RGB_HUD, RGB_VAI
),


/* _NUM
╭────────╮ ╭────────╮────────╮────────╮ ╭────────╮────────╮────────╮────────╮      ╭────────╭────────╭────────╭────────╮ ╭────────╭────────╭────────────────╮
│        │ │        │        │        │ │        │        │        │        │      │        │        │        │        │ │        │        │                │
│  Mute  │ │        │        │        │ │        │        │        │        │      │        │        │        │        │ │        │        │                │
╰──enc───╯╭╰────────╯─╮──────╯─╮─╭────╯─╰─╮──────╯─╮──────╯─╮──────╯─╮──────╯  ╭───╰────╭───╰────╭───╰────╭───╰────╮─╭─╯─╰────╭───╰────╭───╰────╭───────────╯╮
          │           │   !    │\│   @    │   #    │   $    │   %    │         │    ^   │    &   │    *   │    (   │/│    )   │        │        │            │
          │           │    1   │\│    2   │    3   │    4   │    5   │         │   6    │   7    │   8    │   9    │/│   0    │        │        │            │
        ╭─╰───────────╯─╮──────╯─╰─╭──────╯─╮──────╯─╮──────╯─╮──────╯─╮       ╰─╭──────╰─╭──────╰─╭──────╰─╭──────╯─╰─╭──────╰─╭──────╰─╭──────╰────────────╯╮
        │               │   ^    │\│   &    │   *    │   (    │   )    │         │        │        │        │        │/│        │        │                    │
        │               │    6   │\│    7   │    8   │    9   │    0   │         │        │   4    │   5    │   6    │/│        │        │                    │
       ╭╰───────────────╯───╮────╯─╰─╮─╭────╯───╮────╯───╮────╯───╮────╯───╮  ╭──╰─────╭──╰─────╭──╰─────╭──╰─────╮──╯─╰──────╭─╰──────╮─╰──────────╭─────────╯──╮
       │                    │        │ │        │        │    <   │    >   │  │        │        │        │        │  │    <   │    >   │ ╭────────╮ │            │
       │                    │        │ │        │        │   ,    │   .    │  │        │   1    │   2    │   3    │  │   ,    │   .    │ │        │ │            │
       ╰╭───────────╮───────╯╮───────╯ ╰─╭──────╯─╮──╭───╯────╮───╯───────╮╯  ╰────╭───╰───────╭╰───────╮╰─╭──────╯─╮╰────────╰────────╯ │        │ ╰────────────╯
        │           │        │           │        │  │        │           │        │           │        │  │        │           ╭────────╰────────╭────────╮
        │           │        │           │        │  │  (RSE) │   Enter   │        │     0     │ (LWR)  │  │        │           │        │        │        │
        ╰───────────╯────────╯           ╰────────╯  ╰────────╯───────────╯        ╰───────────╰────────╯  ╰────────╯           │        │        │        │
                                                                                                                                ╰────────╰────────╰────────╯
*/
[_NUM] = LAYOUT_alice(
    _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX,          XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  XXXXXXX, KC_1,    KC_2,    KC_3,    KC_COMM, KC_DOT,  XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX,          XXXXXXX, _______, KC_ENT,           KC_0,    _______, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
),

};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        switch(biton32(layer_state)) {
        case _BASE:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;

        case _LWR:
            if (clockwise) {
                register_code16(KC_LGUI);
                register_code16(KC_LALT);
                tap_code(KC_RGHT);
                unregister_code16(KC_LGUI);
                unregister_code16(KC_LALT);
            } else {
                register_code16(KC_LGUI);
                register_code16(KC_LALT);
                tap_code(KC_LEFT);
                unregister_code16(KC_LGUI);
                unregister_code16(KC_LALT);
            }
            break;

        case _RSE:
            alt_tab_timer = timer_read();
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                register_code(KC_LGUI);
            }
            if (clockwise) {
                tap_code16(KC_TAB);
            } else {
                tap_code16(S(KC_TAB));
            }
            break;

        case _ADJ:
            if (clockwise) {
                rgblight_increase_hue();
            } else {
                rgblight_decrease_hue();
            }
            break;
        }

    }
    return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BASE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE);
            }
            return false;

        // case KC_GAME:
        //     if (record->event.pressed) {
        //         set_single_persistent_default_layer(_GAMING);
        //     }
        //     return false;

        case KC_LWR:
            if (record->event.pressed) {
                layer_on(_LWR);
                update_tri_layer(_LWR, _RSE, _ADJ);
            } else {
                layer_off(_LWR);
                update_tri_layer(_LWR, _RSE, _ADJ);
            }
            return false;

        case KC_RSE:
            if (record->event.pressed) {
                layer_on(_RSE);
                update_tri_layer(_LWR, _RSE, _ADJ);
            } else {
                layer_off(_RSE);
                update_tri_layer(_LWR, _RSE, _ADJ);
            }
            return false;

        case KC_ADJ:
            if (record->event.pressed) {
                layer_on(_ADJ);
            } else {
                layer_off(_ADJ);
            }
            return false;

        case KC_NUMROW:
            if (record->event.pressed) {
                layer_on(_NUM);
            } else {
                layer_off(_NUM);
            }
            return false;

        case KC_SFTB:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
                unregister_code(KC_LSFT);
            }
            break;

        case KC_PRVWD:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LEFT);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_LEFT);
            }
            break;

        case KC_NXTWD:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_RGHT);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_RGHT);
            }
            break;

        case KC_LSTRT:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LEFT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LEFT);
            }
            break;

        case KC_LEND:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_RGHT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_RGHT);
            }
            break;

        case SCRNCAP:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_4);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
                unregister_code(KC_4);
            }
            break;

        case KC_UNDO:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_Z);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_Z);
            }
            break;

        case KC_REDO:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                register_code(KC_Z);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
                unregister_code(KC_Z);
            }
            break;

        case PSTBRD:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LALT);
                register_code(KC_V);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
                unregister_code(KC_V);
            }
            break;

        case KC_IMP:
            if (record->event.pressed) {
                SEND_STRING("!important");
            }
            break;

        case KC_CLAW:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LALT);
                register_code(KC_LSFT);
                register_code(KC_S);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
                unregister_code(KC_S);
            }
            break;

        case W_LHALF:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LEFT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_LEFT);
            }
            break;

        case W_RHALF:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_RGHT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_RGHT);
            }
            break;

        case W_THALF:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_UP);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_UP);
            }
            break;

        case W_BHALF:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_DOWN);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_DOWN);
            }
            break;

        case W_LTHRD:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LCTL);
                register_code(KC_LEFT);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LEFT);
            }
            break;

        case W_RTHRD:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LCTL);
                register_code(KC_RGHT);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_RGHT);
            }
            break;

        case W_TTHRD:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LCTL);
                register_code(KC_UP);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_UP);
            }
            break;

        case W_BTHRD:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LCTL);
                register_code(KC_DOWN);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_DOWN);
            }
            break;

        case W_MAX:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LALT);
                register_code(KC_LCTL);
                register_code(KC_F);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_F);
            }
            break;

        case W_CENT:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LALT);
                register_code(KC_C);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
                unregister_code(KC_C);
            }
            break;

        case W_TLEFT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                register_code(KC_1);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
                unregister_code(KC_1);
            }
            break;

        case W_BLEFT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                register_code(KC_3);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
                unregister_code(KC_3);
            }
            break;

        case W_TRGHT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                register_code(KC_2);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
                unregister_code(KC_2);
            }
            break;

        case W_BRGHT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                register_code(KC_4);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
                unregister_code(KC_4);
            }
            break;
    }
    return true;
}


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;
}

static void render_logo_small(void) {
    static const char PROGMEM owl_logo[] = {
        // 'owl-8-bit-3', 32x38px
        0x00, 0x00, 0x00, 0x00, 0x88, 0xfe, 0xfe, 0x78, 0x70, 0x70, 0x70, 0x78, 0x78, 0xf8, 0xf8, 0xf8,
        0xf8, 0xf8, 0xf0, 0x70, 0x70, 0x70, 0x70, 0x78, 0x7c, 0xfe, 0xd8, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x3f, 0xff, 0xe1, 0xc0, 0x80, 0x80, 0x80, 0x86, 0x86, 0xc0, 0x61, 0x7f, 0x3f,
        0x7f, 0xf3, 0xc0, 0x80, 0x80, 0x80, 0x86, 0x86, 0x80, 0xe0, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xe0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xe0,
        0xf0, 0xfc, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00,
        0x20, 0x60, 0xe0, 0x83, 0x0f, 0x3f, 0x7f, 0xcf, 0xc1, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf0, 0xe7, 0x6f, 0x3f, 0x0f, 0x83, 0xc0, 0xc0, 0x80, 0x80,
        0x04, 0x04, 0x07, 0x0f, 0x1e, 0x1c, 0x1c, 0x1f, 0x3f, 0x33, 0x3f, 0x33, 0x31, 0x3f, 0x21, 0x3f,
        0x3f, 0x3f, 0x31, 0x31, 0x33, 0x31, 0x1f, 0x0f, 0x06, 0x06, 0x07, 0x07, 0x0f, 0x1f, 0x33, 0x33
    };
    oled_write_raw_P(owl_logo, sizeof(owl_logo));
}

bool oled_task_user(void) {
    oled_write_P(PSTR("\n"), false);
    render_logo_small();
    oled_set_cursor(0,7);
    // oled_write_P(PSTR("OWL\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("hoo\nhoooo"), false);
    oled_write_P(PSTR("-----"), false);
    // oled_write_P(PSTR("\n"), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base\nLayer"), false);
            break;
        case _LWR:
            oled_write_P(PSTR("SymblRow\n"), false);
            break;
        case _RSE:
            oled_write_P(PSTR("Navigation"), false);
            break;
        case _ADJ:
            oled_write_P(PSTR("Adjstments"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("NumbrRow\n"), false);
            break;
    }

    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);

    return false;
}

#endif

// Runs just one time when the keyboard initializes.
void matrix_scan_user(void) {
    static bool has_ran_yet = false;
    if (!has_ran_yet) {
        has_ran_yet = true;
        // rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);
        // rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv(HSV_PURPLE);
    }
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 750) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
      }
    }
};
