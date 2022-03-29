
 /* Copyright 2021 Dane Evans
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
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H


enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD,
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_TOP,
    KC_BOT,
    KC_REDO,
    PSTBRD,
    KC_SFTB,
    SCRNCAP,
    KC_IMP,
    KC_CLAW,
    CALCAPP,
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
    W_LSCRN,
    W_RSCRN,
    W_TLEFT,
    W_TRGHT,
    W_BLEFT,
    W_BRGHT,
    W_LRGR,
    W_SMLR,
    W_UNDO
};

// #define NUMTAB LT(_NUMPAD,KC_TAB)
#define NUMENT LT(_NUMPAD,KC_ENT)
#define RSFTENT RSFT_T(KC_ENT)
#define LSFTSPC LSFT_T(KC_SPC)
#define NUMMINS LT(_NUMPAD, KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: _QWERTY
 *                            ╭────────╮                                                                         ╭────────╮
 *                   ╭────────╯   #    ╰────────╮                                                       ╭────────╯    *   ╰────────╮
 *                   │   @    │   3    │   $    ╰────────╮                                     ╭────────╯    &   │    8   │    (   │
 * ╭────────╮────────╯   2    ╰────────╯   4    │   %    │                                     │    ^   │    7   ╰────────╯    9   ╰────────╭────────╮
 * │        │   !    ╰────────╯        ╰────────╯   5    │                                     │    6   ╰────────╯        ╰────────╯    )   │    ~   │
 * │  ESC   │   1    │        │   E    │        ╰────────╯                                     ╰────────╯        │    I   │        │    0   │    `   │
 * ╰────────╯────────╯   W    ╰────────╯   R    │        │                                     │        │    U   ╰────────╯    O   ╰────────╰────────╯
 * │        │        ╰────────╯        ╰────────╯   T    │                                     │    Y   ╰────────╯        ╰────────╯        │        │
 * │  TAB   │   Q    │        │   D    │        ╰────────╯                                     ╰────────╯        │    K   │        │    P   │ BKSPCE │
 * ╰────────╯────────╯   S    ╰────────╯   F    │        │                                     │        │    J   ╰────────╯    L   ╰────────╰────────╯
 * │        │        ╰────────╯        ╰────────╯   G    │                                     │    H   ╰────────╯    <   ╰────────╯    :   │    "   │
 * │  CTRL  │   A    │        │   C    │        ╰────────╯                                     ╰────────╯        │    ,   │    >   │    ;   │    '   │
 * ╰────────╯────────╯   X    ╰────────╯   V    │        │  ╭────────╮             ╭────────╮  │        │    M   ╰────────╯    .   ╰────────╰────────╯
 * │        │        ╰────────╯        ╰────────╯   B    │  │ Paste  │             │        │  │    N   ╰────────╯        ╰────────╯    ?   │ (Shift)│
 * │  SHIFT │   Z    │                ╭────────╮╰────────╯  │ Board  │             │  Mute  │  ╰────────╯╭────────╮                │    /   │  Enter │
 * ╰────────╯────────╯      ╭────────╮│        ╰────────╮   ╰─encodr─╯             ╰─encodr─╯   ╭────────╯   {    │╭────────╮      ╰────────╰────────╯
 *                          │        ││  CMD   │        ╰────────╮                     ╭────────╯        │   [    ││    }   │
 *                          │  ALT   │╰────────╯ (RSE)  │        ╰────────╮   ╭────────╯        │  (LWR) ╰────────╯│    ]   │
 *                          ╰────────╯         ╰────────╯ Space  │ (Num)  │   │   __   │  Space ╰────────╯         ╰────────╯
 *                                                      ╰────────╯ Enter  │   │   -    ╰────────╯
 *                                                               ╰────────╯   ╰────────╯
 */
  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                            KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                            KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                            KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    PSTBRD,                        KC_MUTE, KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFTENT,
                      KC_LALT, KC_LGUI, KC_RAISE,LSFTSPC, NUMENT,                        NUMMINS, KC_SPC, KC_LOWER,KC_LBRC, KC_RBRC
  ),

/*
 * Layer 2: _LOWER
 *                            ╭────────╮                                                                         ╭────────╮
 *                   ╭────────╯        ╰────────╮                                                       ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                                     ╭────────╯        │        │        │
 * ╭────────╮────────╯        ╰────────╯        │        │                                     │        │        ╰────────╯        ╰────────╭────────╮
 * │        │        ╰────────╯        ╰────────╯        │                                     │        ╰────────╯        ╰────────╯        │        │
 * │        │  !imp  │        │   #    │        ╰────────╯                                     ╰────────╯        │    *   │        │        │        │
 * ╰────────╯────────╯   @    ╰────────╯   $    │        │                                     │        │    &   ╰────────╯    (   ╰────────╰────────╯
 * │        │        ╰────────╯        ╰────────╯   %    │                                     │    ^   ╰────────╯        ╰────────╯        │        │
 * │        │   !    │        │   (    │        ╰────────╯                                     ╰────────╯        │        │        │    )   │ BKSPCE │
 * ╰────────╯────────╯  CLAW  ╰────────╯   )    │        │                                     │        │        ╰────────╯        ╰────────╰────────╯
 * │        │        ╰────────╯        ╰────────╯        │                                     │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │   {    │        ╰────────╯                                     ╰────────╯        │        │        │        │        │
 * ╰────────╯────────╯        ╰────────╯   }    │   |    │  ╭────────╮             ╭────────╮  │        │        ╰────────╯        ╰────────╰────────╯
 * │        │        ╰────────╯        ╰────────╯   \    │  │ Screen │             │        │  │        ╰────────╯        ╰────────╯        │        │
 * │        │        │                ╭────────╮╰────────╯  │  Cap   │             │        │  ╰────────╯╭────────╮                │        │        │
 * ╰────────╯────────╯      ╭────────╮│        ╰────────╮   ╰─encodr─╯             ╰─encodr─╯   ╭────────╯        │╭────────╮      ╰────────╰────────╯
 *                          │        ││        │        ╰────────╮                     ╭────────╯        │        ││        │
 *                          │        │╰────────╯        │   +    ╰────────╮   ╭────────╯        │        ╰────────╯│        │
 *                          ╰────────╯         ╰────────╯   =    │        │   │   __   │        ╰────────╯         ╰────────╯
 *                                                      ╰────────╯   +    │   │   -    ╰────────╯
 *                                                               ╰────────╯   ╰────────╯
 */

  [_LOWER] = LAYOUT(

    XXXXXXX, KC_IMP,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_CAPS, XXXXXXX, KC_CLAW, KC_LPRN, KC_RPRN, KC_LBRC,                                         KC_RBRC, KC_PLUS, KC_EQL,  KC_BSLS, KC_PIPE, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_BSLS, SCRNCAP,                       _______, KC_GRV,  KC_TILD, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______,                       KC_MINS, _______, _______, _______, _______
  ),

/*
 * Layer 3: _RAISE
 *                            ╭────────╮                                                                         ╭────────╮
 *                   ╭────────╯        ╰────────╮                                                       ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                                     ╭────────╯        │        │        │
 * ╭────────╮────────╯        ╰────────╯        │        │                                     │        │        ╰────────╯        ╰────────╭────────╮
 * │        │        ╰────────╯ Mouse  ╰────────╯        │                                     │        ╰────────╯        ╰────────╯        │        │
 * │  UNDO  │  REDO  │        │  Up    │        ╰────────╯                                     ╰────────╯  Prev  │   Up   │  Next  │        │        │
 * ╰────────╯────────╯        ╰────────╯        │        │                                     │  Page  │  Word  ╰────────╯  Word  ╰────────╰────────╯
 * │ SHIFT/ │        ╰────────╯ Mouse  ╰────────╯        │                                     │  Top   ╰────────╯        ╰────────╯        │        │
 * │  TAB   │        │ Mouse  │ Down   │ Mouse  ╰────────╯                                     ╰────────╯        │  Down  │        │        │ DELETE │
 * ╰────────╯────────╯ Left   ╰────────╯ Right  │        │                                     │        │  Left  ╰────────╯  Right ╰────────╰────────╯
 * │        │        ╰────────╯        ╰────────╯        │                                     │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │        │        ╰────────╯                                     ╰────────╯  Line  │        │  Line  │        │        │
 * ╰────────╯────────╯        ╰────────╯        │        │  ╭────────╮             ╭────────╮  │  Page  │  Start ╰────────╯  End   ╰────────╰────────╯
 * │        │        ╰────────╯        ╰────────╯ BKSPCE │  │        │             │        │  │  Bot   ╰────────╯        ╰────────╯        │        │
 * │        │        │                ╭────────╮╰────────╯  │        │             │        │  ╰────────╯╭────────╮                │        │        │
 * ╰────────╯────────╯      ╭────────╮│        ╰────────╮   ╰─encodr─╯             ╰─encodr─╯   ╭────────╯        │╭────────╮      ╰────────╰────────╯
 *                          │        ││        │        ╰────────╮                     ╭────────╯        │        ││        │
 *                          │        │╰────────╯        │        ╰────────╮   ╭────────╯        │        ╰────────╯│        │
 *                          ╰────────╯         ╰────────╯        │        │   │        │        ╰────────╯         ╰────────╯
 *                                                      ╰────────╯        │   │        ╰────────╯
 *                                                               ╰────────╯   ╰────────╯
 */

  [_RAISE] = LAYOUT(
    KC_UNDO, KC_REDO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_SFTB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         KC_TOP,  KC_PRVWD,KC_UP,   KC_NXTWD,XXXXXXX, KC_DEL,
    KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, _______,                       _______, KC_BOT,  KC_LSTRT,XXXXXXX, KC_LEND, XXXXXXX, _______,
                      _______, _______, _______, _______, _______,                       _______, LSFTSPC, _______, _______, _______
  ),

/*
 * Layer 4: _ADJUST
 *                            ╭────────╮                                                                         ╭────────╮
 *                   ╭────────╯        ╰────────╮                                                       ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                                     ╭────────╯        │        │        │
 * ╭────────╮────────╯        ╰────────╯        │        │                                     │        │        ╰────────╯        ╰────────╭────────╮
 * │  RGB   │  RGB   ╰────────╯ Window ╰────────╯        │                                     │        ╰────────╯ Window ╰────────╯        │        │
 * │  RMOD  │  MOD   │ Window │ Top1/3 │ Window ╰────────╯                                     ╰────────╯ Window │ Top1/2 │ Window │        │        │
 * ╰────────╯────────╯ Smallr ╰────────╯ Larger │        │                                     │        │ TopLft ╰────────╯ TopRgt ╰────────╰────────╯
 * │  RGB   │  RGB   ╰────────╯ Window ╰────────╯        │                                     │        ╰────────╯ Window ╰────────╯        │        │
 * │  VAL-  │  VAL+  │ Window │  Max   │ Window ╰────────╯                                     ╰────────╯ Window │ Center │ Window │        │        │
 * ╰────────╯────────╯ Lwr1/3 ╰────────╯ Rgt1/3 │        │                                     │        │ Lft1/2 ╰────────╯ Rgt1/2 ╰────────╰────────╯
 * │  RGB   │  RGB   ╰────────╯ Window ╰────────╯        │                                     │        ╰────────╯ Window ╰────────╯        │        │
 * │  SAT-  │  SAT+  │        │ Bot1/3 │        ╰────────╯                                     ╰────────╯ Window │ Bot1/2 │ Window │        │        │
 * ╰────────╯────────╯        ╰────────╯        │        │  ╭────────╮             ╭────────╮  │        │ BotLft ╰────────╯ BotRgt ╰────────╰────────╯
 * │  RGB   │  RGB   ╰────────╯        ╰────────╯        │  │  RGB   │             │   RGB  │  │        ╰────────╯        ╰────────╯        │        │
 * │  HUE-  │  HUE+  │                ╭────────╮╰────────╯  │  TOG   │             │   TOG  │  ╰────────╯╭────────╮                │        │        │
 * ╰────────╯────────╯      ╭────────╮│        ╰────────╮   ╰─encodr─╯             ╰─encodr─╯   ╭────────╯        │╭────────╮      ╰────────╰────────╯
 *                          │        ││        │        ╰────────╮                     ╭────────╯        │        ││        │
 *                          │        │╰────────╯        │        ╰────────╮   ╭────────╯        │        ╰────────╯│        │
 *                          ╰────────╯         ╰────────╯        │        │   │        │        ╰────────╯         ╰────────╯
 *                                                      ╰────────╯        │   │        ╰────────╯
 *                                                               ╰────────╯   ╰────────╯
 */

  [_ADJUST] = LAYOUT(
    RGB_RMOD,RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_VAD, RGB_VAI, W_SMLR,  W_TTHRD, W_LRGR,  XXXXXXX,                                         XXXXXXX, W_TLEFT, W_THALF, W_TRGHT, XXXXXXX, XXXXXXX,
    RGB_SAD, RGB_SAI, W_LTHRD, W_MAX,   W_RTHRD, XXXXXXX,                                         XXXXXXX, W_LHALF, W_CENT,  W_RHALF, XXXXXXX, XXXXXXX,
    RGB_HUD, RGB_HUI, XXXXXXX, W_BTHRD, XXXXXXX, XXXXXXX, RGB_TOG,                       RGB_TOG, XXXXXXX, W_BLEFT, W_BHALF, W_BRGHT, XXXXXXX, XXXXXXX,
                      _______, _______, XXXXXXX, _______, _______,                       _______, _______, XXXXXXX, _______, _______
  ),

/*
 * Layer 5: _NUMPAD
 *                            ╭────────╮                                                                         ╭────────╮
 *                   ╭────────╯        ╰────────╮                                                       ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                                     ╭────────╯  Num   │    /   │        │
 * ╭────────╮────────╯        ╰────────╯        │        │                                     │        │  Lock  ╰────────╯    *   ╰────────╭────────╮
 * │        │        ╰────────╯        ╰────────╯        │                                     │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │   3    │        ╰────────╯                                     ╰────────╯        │    8   │        │   -    │        │
 * ╰────────╯────────╯   2    ╰────────╯   4    │        │                                     │        │    7   ╰────────╯    9   ╰────────╰────────╯
 * │        │        ╰────────╯        ╰────────╯   5    │                                     │        ╰────────╯        ╰────────╯        │        │
 * │  TAB   │   1    │        │   8    │        ╰────────╯                                     ╰────────╯        │    5   │        │   +    │ BKSPCE │
 * ╰────────╯────────╯   7    ╰────────╯   9    │        │                                     │        │    4   ╰────────╯    6   ╰────────╰────────╯
 * │        │        ╰────────╯        ╰────────╯   0    │                                     │        ╰────────╯        ╰────────╯        │        │
 * │        │   6    │        │        │        ╰────────╯                                     ╰────────╯        │    2   │        │   =    │        │
 * ╰────────╯────────╯        ╰────────╯   .    │        │  ╭────────╮             ╭────────╮  │        │    1   ╰────────╯    3   ╰────────╰────────╯
 * │        │        ╰────────╯        ╰────────╯   ,    │  │        │             │  CALC  │  │        ╰────────╯        ╰────────╯        │        │
 * │        │        │                ╭────────╮╰────────╯  │        │             │  APP   │  ╰────────╯╭────────╮                │ Enter  │        │
 * ╰────────╯────────╯      ╭────────╮│        ╰────────╮   ╰─encodr─╯             ╰─encodr─╯   ╭────────╯        │╭────────╮      ╰────────╰────────╯
 *                          │        ││        │        ╰────────╮                     ╭────────╯        │    .   ││        │
 *                          │        │╰────────╯        │        ╰────────╮   ╭────────╯        │    0   ╰────────╯│    ,   │
 *                          ╰────────╯         ╰────────╯        │        │   │        │        ╰────────╯         ╰────────╯
 *                                                      ╰────────╯        │   │        ╰────────╯
 *                                                               ╰────────╯   ╰────────╯
 */

  [_NUMPAD] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         XXXXXXX, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOT,  KC_COMM, _______,                       CALCAPP, XXXXXXX, XXXXXXX, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______
  ),

/*
 * Base Layer: SAMPLE
 *                            ╭────────╮                                                                         ╭────────╮
 *                   ╭────────╯        ╰────────╮                                                       ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                                     ╭────────╯        │        │        │
 * ╭────────╮────────╯        ╰────────╯        │        │                                     │        │        ╰────────╯        ╰────────╭────────╮
 * │        │        ╰────────╯        ╰────────╯        │                                     │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │        │        ╰────────╯                                     ╰────────╯        │        │        │        │        │
 * ╰────────╯────────╯        ╰────────╯        │        │                                     │        │        ╰────────╯        ╰────────╰────────╯
 * │        │        ╰────────╯        ╰────────╯        │                                     │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │        │        ╰────────╯                                     ╰────────╯        │        │        │        │        │
 * ╰────────╯────────╯        ╰────────╯        │        │                                     │        │        ╰────────╯        ╰────────╰────────╯
 * │        │        ╰────────╯        ╰────────╯        │                                     │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │        │        ╰────────╯                                     ╰────────╯        │        │        │        │        │
 * ╰────────╯────────╯        ╰────────╯        │        │  ╭────────╮             ╭────────╮  │        │        ╰────────╯        ╰────────╰────────╯
 * │        │        ╰────────╯        ╰────────╯        │  │        │             │        │  │        ╰────────╯        ╰────────╯        │        │
 * │        │        │                ╭────────╮╰────────╯  │        │             │        │  ╰────────╯╭────────╮                │        │        │
 * ╰────────╯────────╯      ╭────────╮│        ╰────────╮   ╰─encodr─╯             ╰─encodr─╯   ╭────────╯        │╭────────╮      ╰────────╰────────╯
 *                          │        ││        │        ╰────────╮                     ╭────────╯        │        ││        │
 *                          │        │╰────────╯        │        ╰────────╮   ╭────────╯        │        ╰────────╯│        │
 *                          ╰────────╯         ╰────────╯        │        │   │        │        ╰────────╯         ╰────────╯
 *                                                      ╰────────╯        │   │        ╰────────╯
 *                                                               ╰────────╯   ╰────────╯
 * [_SAMPLE] = LAYOUT(
 *       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 *       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 *       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 *       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 *                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
 * ),
 */

};

#ifdef OLED_ENABLE

/* 32 * 32 logo */
static void render_logo(void) {
    static const char PROGMEM hell_logo[] = {0x00, 0x80, 0xc0, 0xc0, 0x60, 0x60, 0x30, 0x30, 0x18, 0x1c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0x78, 0x1e, 0x06, 0x00, 0x0c, 0x1c, 0x18, 0x30, 0x30, 0x60, 0x60, 0xc0, 0xc0, 0x80, 0x00, 0x01, 0x03, 0x07, 0x06, 0x0c, 0x0c, 0x18, 0x18, 0x30, 0x70, 0x60, 0x00, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x60, 0x70, 0x30, 0x18, 0x18, 0x0c, 0x0c, 0x06, 0x07, 0x03, 0x01, 0x00, 0xf8, 0xf8, 0x80, 0x80, 0x80, 0xf8, 0xf8, 0x00, 0x80, 0xc0, 0xc0, 0x40, 0xc0, 0xc0, 0x80, 0x00, 0xf8, 0xf8, 0x00, 0xf8, 0xf8, 0x00, 0x08, 0x38, 0x08, 0x00, 0x38, 0x08, 0x30, 0x08, 0x38, 0x00, 0x1f, 0x1f, 0x01, 0x01, 0x01, 0x1f, 0x1f, 0x00, 0x0f, 0x1f, 0x1a, 0x12, 0x1a, 0x1b, 0x0b, 0x00, 0x1f, 0x1f, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    oled_write_raw_P(hell_logo, sizeof(hell_logo));
}

/* 32 * 14 os logos */
// static const char PROGMEM windows_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xbc, 0xbe, 0xbe, 0x00, 0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static const char PROGMEM mac_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0xf6, 0xfb, 0xfb, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

/* Smart Backspace Delete */

/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       40

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }};

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }

    /* this fixes the screen on and off bug */
    // if (current_wpm > 0) {
    //     oled_on();
    //     anim_sleep = timer_read32();
    // } else if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
    //     oled_off();
    // }
}

/* KEYBOARD PET END */

static void print_logo_narrow(void) {
    render_logo();

    /* wpm counter */
    uint8_t n = get_current_wpm();
    char    wpm_str[4];
    oled_set_cursor(0, 14);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0, 15);
    oled_write(" wpm", false);
}

static void print_status_narrow(void) {
    /* Print current mode */
    oled_set_cursor(0, 0);
    // if (keymap_config.swap_lctl_lgui) {
         oled_write_raw_P(mac_logo, sizeof(mac_logo));
    // } else {
    //    oled_write_raw_P(windows_logo, sizeof(windows_logo));
    // }

    oled_set_cursor(0, 3);

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write("QWRTY", false);
            break;
        default:
            oled_write("UNDEF", false);
    }

    oled_set_cursor(0, 5);

    /* Print current layer */
    oled_write("LAYER", false);

    oled_set_cursor(0, 6);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Nump\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    /* caps lock */
    oled_set_cursor(0, 8);
    oled_write("CPSLK", led_usb_state.caps_lock);

    /* KEYBOARD PET RENDER START */

    render_luna(0, 13);

    /* KEYBOARD PET RENDER END */
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
    return false;
}

#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;

        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;

        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;

        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;

        case CALCAPP:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                register_code(KC_C);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
                unregister_code(KC_C);
            }
            break;

        case KC_SFTB:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
                unregister_code(KC_LSFT);
            }
            break;

        case KC_TOP:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_UP);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_UP);
            }
            break;

        case KC_BOT:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_DOWN);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_DOWN);
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

        case W_LSCRN:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LALT);
                register_code(KC_LCTL);
                register_code(KC_LEFT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LEFT);
            }
            break;

        case W_RSCRN:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LALT);
                register_code(KC_LCTL);
                register_code(KC_RGHT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_RGHT);
            }
            break;

        case W_UNDO:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LALT);
                register_code(KC_Z);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
                unregister_code(KC_Z);
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

        case W_LRGR:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                register_code(KC_RGHT);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
                unregister_code(KC_RGHT);
            }
            break;

        case W_SMLR:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                register_code(KC_LEFT);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
                unregister_code(KC_LEFT);
            }
            break;

        case KC_LGUI:
        case KC_RGUI:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;

        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
    }
    return true;
}

// Two Encoder Support
#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch(biton32(layer_state)) {
        case _QWERTY:
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
        case _LOWER:
            if (clockwise) {
                register_code16(KC_LGUI);
                tap_code(KC_GRV);
                unregister_code16(KC_LGUI);
            } else {
                register_code16(KC_LGUI);
                register_code16(KC_LSFT);
                tap_code(KC_GRV);
                unregister_code16(KC_LGUI);
                unregister_code16(KC_LSFT);
            }
            break;

        case _ADJUST:
            if (clockwise) {
                rgblight_step();
            } else {
                rgblight_step_reverse();
            }
            break;
        }

    } else if (index == 1) {
        switch(biton32(layer_state)) {
        case _QWERTY:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        case _RAISE:
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

        case _ADJUST:
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
