
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

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {36+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
	{1, 6, hsv}, \
    {36+1, 6, hsv}
#define SET_NUMPAD(hsv)     \
	{36+15, 5, hsv},\
	  {36+22, 3, hsv},\
	  {36+27, 3, hsv}
#define SET_LAYER_ID(hsv) 	\
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {36+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {1, 6, hsv}, \
    {36+1, 6, hsv}
	/* {7, 4, hsv}, \ */
	/* {35+ 7, 4, hsv}, \ */
	/* {25, 2, hsv}, \ */
	/* {35+ 25, 2, hsv} */


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
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    PSTBRD,       KC_MUTE, KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFTENT,
                      KC_LALT, KC_LGUI, KC_RAISE,KC_SPC,  NUMENT,       KC_MINS, KC_SPC, KC_LOWER,KC_LBRC, KC_RBRC
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
  
    XXXXXXX, KC_IMP,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    _______, XXXXXXX, KC_CLAW, KC_LPRN, KC_RPRN, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
    _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_BSLS, SCRNCAP,      _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______,
                      _______, _______, _______, KC_EQL,  KC_PLUS,      KC_MINS, _______, _______, _______, _______
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
    KC_UNDO, KC_REDO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_SFTB, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                        KC_TOP,  KC_PRVWD,KC_UP,   KC_NXTWD,XXXXXXX, KC_DEL, 
    _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                        XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, _______,      _______, KC_BOT,  KC_LSTRT,XXXXXXX, KC_LEND, XXXXXXX, _______,
                      _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______
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
    RGB_RMOD,RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_VAD, RGB_VAI, W_SMLR,  W_TTHRD, W_LRGR,  XXXXXXX,                        XXXXXXX, W_TLEFT, W_THALF, W_TRGHT, XXXXXXX, XXXXXXX,
    RGB_SAD, RGB_SAI, W_LTHRD, W_MAX,   W_RTHRD, XXXXXXX,                        XXXXXXX, W_LHALF, W_CENT,  W_RHALF, XXXXXXX, XXXXXXX,
    RGB_HUD, RGB_HUI, XXXXXXX, W_BTHRD, XXXXXXX, XXXXXXX, RGB_TOG,      RGB_TOG, XXXXXXX, W_BLEFT, W_BHALF, W_BRGHT, XXXXXXX, XXXXXXX,
                      _______, _______, XXXXXXX, _______, _______,      _______, _______, XXXXXXX, _______, _______
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
 * │        │        │          ╭────────╮      ╰────────╯  │        │             │  APP   │  ╰────────╯      ╭────────╮          │ Enter  │        │
 * ╰────────╯────────╯╭────────╮│        ╰────────╮         ╰─encodr─╯             ╰─encodr─╯         ╭────────╯        │╭────────╮╰────────╰────────╯
 *                    │        ││        │        ╰────────╮                                 ╭────────╯        │    .   ││        │                           
 *                    │        │╰────────╯        │        ╰────────╮               ╭────────╯        │    0   ╰────────╯│    ,   │                           
 *                    ╰────────╯         ╰────────╯        │        │               │        │        ╰────────╯         ╰────────╯                           
 *                                                ╰────────╯        │               │        ╰────────╯                                                       
 *                                                         ╰────────╯               ╰────────╯                                                              
 */

  [_NUMPAD] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_BSPC,
    XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                           XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PEQL, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOT,  KC_COMM, _______,      CALCAPP, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PENT, XXXXXXX,
                      _______, _______, _______, _______, _______,      _______, _______, KC_P0,   KC_PDOT, KC_COMM
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

#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_GREEN)

);

// _NUM,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_TEAL)

);
// _SYMBOL,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_BLUE)

    );
// _COMMAND,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PURPLE)
);

//_NUMPAD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_YELLOW)
	// SET_INDICATORS(HSV_YELLOW),
    // SET_UNDERGLOW(HSV_YELLOW),
	// SET_NUMPAD(HSV_BLUE),
    // {7, 4, HSV_ORANGE},
    // {25, 2, HSV_ORANGE},
    // {36+6, 4, HSV_ORANGE},
    // {36+25, 2, HSV_ORANGE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_qwerty_lights,
	layer_num_lights,// overrides layer 1
	layer_symbol_lights,
    layer_command_lights,
	layer_numpad_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));
	rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
	rgblight_set_layer_state(4, layer_state_cmp(state, _NUMPAD));
    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

	rgblight_mode(10);// haven't found a way to set this in a more useful way

}
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Soflev2.1\nRGB"), false);

    oled_write_ln_P(PSTR(""), false);

	//snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)


    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwert"), false);
            break;

        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
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
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
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
    }
    return true;
}

// Two Encoder Support
#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch(biton32(layer_state)) {
        case _QWERTY:
            if (clockwise) {
                tap_code16(KC_WH_R);
            } else {
                tap_code16(KC_WH_L);
            }
            break;

        case _LOWER:
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
        rgblight_sethsv(HSV_YELLOW);
    }
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 750) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
      }
    }
};