
/*
qmk compile -kb avalanche/rev2 -km default_rev2
qmk flash -kb avalanche/rev2 -km default_rev2
*/

#include QMK_KEYBOARD_H

enum layer {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMROW,
}; 

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Layer: QWERTY
 *                                     ╭────────╮                                                                         ╭────────╮                                                  
 *                            ╭────────╯   #    ╰────────╮                                                       ╭────────╯    *   ╰────────╮                                     
 *                            │   @    │   3    │   $    ╰────────╮                                     ╭────────╯    &   │    8   │    (   │                              
 *          ╭────────╮────────╯   2    ╰────────╯   4    │   %    │                                     │    ^   │    7   ╰────────╯    9   ╰────────╭────────╮  
 *          │        │   !    ╰────────╯        ╰────────╯   5    │                                     │    6   ╰────────╯        ╰────────╯    )   │    _   │  
 *          │  Esc   │   1    │        │   E    │        ╰────────╯                                     ╰────────╯        │    I   │        │    0   │   -    │  
 *          ╰────────╯────────╯   W    ╰────────╯   R    │        │                                     │        │    U   ╰────────╯    O   ╰────────╰────────╯  
 *          │        │        ╰────────╯        ╰────────╯   T    │                                     │    Y   ╰────────╯        ╰────────╯        │        │  
 *          │  Tab   │   Q    │        │   D    │        ╰────────╯ ╭────────╮               ╭────────╮ ╰────────╯        │    K   │        │    P   │ Bkspce │  
 * ╭────────╯────────╯────────╯   S    ╰────────╯   F    │        │ │        │               │        │ │        │    J   ╰────────╯    L   ╰────────╰────────╰────────╮
 * │  ` ~   │  Esc   │        ╰────────╯        ╰────────╯   G    │ │   {    │               │    }   │ │    H   ╰────────╯    <   ╰────────╯    :   │    "   │   |    │
 * │ (c/a/g)│ (ctrl) │   A    │        │   C    │        ╰────────╯ ╰────────╯               ╰────────╯ ╰────────╯        │    ,   │    >   │    ;   │    '   │   \    │
 * ╰────────╮────────╯────────╯   X    ╰────────╯   V    │        │  ╭────────╮             ╭────────╮  │        │    M   ╰────────╯    .   ╰────────╰────────╭────────╯
 *          │        │        ╰────────╯        ╰────────╯   B    │  │        │             │    +   │  │    N   ╰────────╯        ╰────────╯    ?   │(rShift)│
 *          │ Shift  │   Z    │                ╭────────╮╰────────╯  │ Bkspce │             │   =    │  ╰────────╯╭────────╮                │    /   │ Enter  │
 *          ╰────────╯────────╯      ╭────────╮│        ╰────────╮   ╰────────╯             ╰────────╯   ╭────────╯        │╭────────╮      ╰────────╰────────╯
 *                                   │ Paste  ││  CMD   │        ╰────────╮                     ╭────────╯        │  ALT   ││        │                           
 *                                   │ Board  │╰────────╯  RSE   │        ╰────────╮   ╭────────╯        │  LWR   ╰────────╯│  Mute  │                           
 *                                   ╰─encodr─╯         ╰────────╯ Space  │ (num)  │   │ (num)  │ Space  ╰────────╯         ╰─encodr─╯                           
 *                                                               ╰────────╯ Enter  │   │  - _   ╰────────╯                                                       
 *                                                                        ╰────────╯   ╰────────╯                                                                
 */
    [_QWERTY] = LAYOUT(                                                                                                                                                            
                 KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
                 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
 LCAG_T(KC_GRV), KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LCBR,             KC_RCBR, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUMROW,
                 KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_BSPC,             KC_EQL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
                                   PSTBRD,  KC_LGUI, KC_RAISE,KC_SPC,LT(_NUMROW, KC_ENT),LT(_NUMROW, KC_MINS),KC_SPC,  KC_LOWER,KC_RALT, KC_MUTE
    ),

/*
 * Layer: LOWER
 *                                     ╭────────╮                                                                         ╭────────╮                                                  
 *                            ╭────────╯        ╰────────╮                                                       ╭────────╯        ╰────────╮                                     
 *                            │        │   F3   │        ╰────────╮                                     ╭────────╯        │   F8   │        │                              
 *          ╭────────╮────────╯   F2   ╰────────╯   F4   │        │                                     │        │   F7   ╰────────╯   F9   ╰────────╭────────╮  
 *          │        │        ╰────────╯        ╰────────╯   F5   │                                     │   F6   ╰────────╯        ╰────────╯        │        │  
 *          │  IMP   │   F1   │        │   #    │        ╰────────╯                                     ╰────────╯        │   *    │        │  F10   │  F11   │  
 *          ╰────────╯────────╯   @    ╰────────╯   $    │        │                                     │        │   &    ╰────────╯   (    ╰────────╰────────╯  
 *          │        │        ╰────────╯        ╰────────╯   %    │                                     │   ^    ╰────────╯        ╰────────╯        │        │  
 *          │  Tab   │   !    │  Save  │   (    │        ╰────────╯ ╭────────╮               ╭────────╮ ╰────────╯        │        │        │    )   │ Bckspc │  
 * ╭────────╯────────╯────────╯  4Web  ╰────────╯   )    │        │ │   {    │               │    }   │ │        │        ╰────────╯        ╰────────╰────────╰────────╮
 * │        │        │        ╰────────╯        ╰────────╯        │ │   [    │               │    ]   │ │        ╰────────╯    <   ╰────────╯    :   │    "   │        │
 * │ MEDIAQ │  Ctrl  │        │        │   {    │        ╰────────╯ ╰─encodr─╯               ╰─encodr─╯ ╰────────╯        │    ,   │    >   │    ;   │    '   │  F12   │
 * ╰────────╮────────╯────────╯        ╰────────╯   }    │        │  ╭────────╮             ╭────────╮  │        │        ╰────────╯    .   ╰────────╰────────╭────────╯
 *          │        │        ╰────────╯        ╰────────╯        │  │        │             │    +   │  │        ╰────────╯        ╰────────╯    ?   │(rShift)│
 *          │ Shift  │        │                ╭────────╮╰────────╯  │ Bckspc │             │    =   │  ╰────────╯╭────────╮                │    /   │  Enter │
 *          ╰────────╯────────╯      ╭────────╮│        ╰────────╮   ╰────────╯             ╰────────╯   ╭────────╯        │╭────────╮      ╰────────╰────────╯
 *                                   │        ││  FONT  │        ╰────────╮                     ╭────────╯        │  Alt   ││        │                           
 *                                   │SCRNCAP │╰────────╯  RSE   │        ╰────────╮   ╭────────╯        │  LWR   ╰────────╯│  Mute  │                           
 *                                   ╰────────╯         ╰────────╯ Space  │        │   │    _   │  Space ╰────────╯         ╰────────╯                           
 *                                                               ╰────────╯ Enter  │   │   -    ╰────────╯                                                       
 *                                                                        ╰────────╯   ╰────────╯                                                                
 */
    [_LOWER] = LAYOUT(                                                                                                                                                 
                 KC_IMP,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                 KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                 _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                               KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        _______, _______, XXXXXXX, KC_CLAW, KC_LPRN, KC_RPRN, XXXXXXX, KC_LBRC,             KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_F12,
                 _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, _______,             _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______,
                                   SCRNCAP, _______, _______, _______, _______,             _______, _______, _______, _______, _______
    ),

/*
 * Layer: RAISE
 *                                     ╭────────╮                                                                         ╭────────╮                                                  
 *                            ╭────────╯        ╰────────╮                                                       ╭────────╯        ╰────────╮                                     
 *                            │        │        │        ╰────────╮                                     ╭────────╯        │        │        │                              
 *          ╭────────╮────────╯        ╰────────╯        │        │                                     │        │        ╰────────╯        ╰────────╭────────╮  
 *          │        │        ╰────────╯ Mouse  ╰────────╯        │                                     │        ╰────────╯        ╰────────╯        │        │  
 *          │  UNDO  │  REDO  │        │  Up    │        ╰────────╯                                     ╰────────╯  Prev  │   Up   │  Next  │        │        │  
 *          ╰────────╯────────╯        ╰────────╯        │        │                                     │        │  Word  ╰────────╯  Word  ╰────────╰────────╯  
 *          │ Shift+ │        ╰────────╯ Mouse  ╰────────╯        │                                     │        ╰────────╯        ╰────────╯        │        │  
 *          │  Tab   │        │ Mouse  │ Down   │ Mouse  ╰────────╯ ╭────────╮               ╭────────╮ ╰────────╯        │  Down  │        │        │        │  
 * ╭────────╯────────╯────────╯ Left   ╰────────╯ Rght   │        │ │   {    │               │    }   │ │        │  Left  ╰────────╯  Rght  ╰────────╰────────╰────────╮
 * │  ` ~   │ (Ctrl) │        ╰────────╯        ╰────────╯        │ │   [    │               │    ]   │ │        ╰────────╯        ╰────────╯        │        │        │
 * │(c/a/g) │ CAPS   │        │        │        │        ╰────────╯ ╰─encodr─╯               ╰─encodr─╯ ╰────────╯  Line  │        │  Line  │        │        │        │
 * ╰────────╮────────╯────────╯        ╰────────╯        │        │  ╭────────╮             ╭────────╮  │        │  Strt  ╰────────╯  End   ╰────────╰────────╭────────╯
 *          │        │        ╰────────╯        ╰────────╯        │  │        │             │        │  │        ╰────────╯        ╰────────╯        │        │
 *          │ Shift  │        │                ╭────────╮╰────────╯  │        │             │        │  ╰────────╯╭────────╮                │        │        │
 *          ╰────────╯────────╯      ╭────────╮│        ╰────────╮   ╰────────╯             ╰────────╯   ╭────────╯        │╭────────╮      ╰────────╰────────╯
 *                                   │ paste  ││  Cmd   │        ╰────────╮                     ╭────────╯        │  Alt   ││        │                           
 *                                   │ board  │╰────────╯  RSE   │        ╰────────╮   ╭────────╯  Rght  │  LWR   ╰────────╯│  Mute  │                           
 *                                   ╰────────╯         ╰────────╯ Space  │        │   │  Left  │  Clck  ╰────────╯         ╰────────╯                           
 *                                                               ╰────────╯ Enter  │   │  Clck  ╰────────╯                                                       
 *                                                                        ╰────────╯   ╰────────╯                                                                
 */
    [_RAISE] = LAYOUT(
                 KC_UNDO, KC_REDO, _______, _______, _______, _______,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 KC_SFTB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, KC_PRVWD,KC_UP,   KC_NXTWD,XXXXXXX, KC_DEL, 
_______, LCTL_T(KC_CAPS), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC,             KC_RBRC, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, KC_LSTRT,XXXXXXX, KC_LEND, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, _______, _______,             XXXXXXX, XXXXXXX, _______, _______, _______
    ),

/*
 * Layer: ADJUST
 *                                     ╭────────╮                                                                         ╭────────╮                                                  
 *                            ╭────────╯  RGB   ╰────────╮                                                       ╭────────╯  RGB   ╰────────╮                                     
 *                            │        │  HUE-  │  RGB   ╰────────╮                                     ╭────────╯  RGB   │  HUE+  │        │                              
 *          ╭────────╮────────╯        ╰────────╯  SAT-  │  RGB   │                                     │  RGB   │  SAT+  ╰────────╯        ╰────────╭────────╮  
 *          │        │        ╰────────╯        ╰────────╯  VAL-  │                                     │  VAL+  ╰────────╯        ╰────────╯        │        │  
 *          │        │        │        │        │        ╰────────╯                                     ╰────────╯        │        │        │        │        │  
 *          ╰────────╯────────╯        ╰────────╯        │        │                                     │        │        ╰────────╯        ╰────────╰────────╯  
 *          │        │        ╰────────╯        ╰────────╯        │                                     │        ╰────────╯        ╰────────╯        │        │  
 *          │        │        │        │        │        ╰────────╯ ╭────────╮               ╭────────╮ ╰────────╯        │        │        │        │        │  
 * ╭────────╯────────╯────────╯        ╰────────╯        │        │ │  RGB   │               │  RGB   │ │        │        ╰────────╯        ╰────────╰────────╰────────╮
 * │ RGB    │        │        ╰────────╯        ╰────────╯        │ │  I/O   │               │  I/O   │ │        ╰────────╯        ╰────────╯        │        │  RGB   │
 * │ RMOD   │        │        │        │        │        ╰────────╯ ╰─encodr─╯               ╰─encodr─╯ ╰────────╯        │        │        │        │        │  MOD   │
 * ╰────────╮────────╯────────╯        ╰────────╯        │        │  ╭────────╮             ╭────────╮  │        │        ╰────────╯        ╰────────╰────────╭────────╯
 *          │        │        ╰────────╯        ╰────────╯        │  │  RGB   │             │  RGB   │  │        ╰────────╯        ╰────────╯        │        │
 *          │        │        │                ╭────────╮╰────────╯  │  MOD-  │             │  MOD+  │  ╰────────╯╭────────╮                │        │        │
 *          ╰────────╯────────╯      ╭────────╮│        ╰────────╮   ╰────────╯             ╰────────╯   ╭────────╯        │╭────────╮      ╰────────╰────────╯
 *                                   │ paste  ││  Cmd   │        ╰────────╮                     ╭────────╯        │  Alt   ││        │                           
 *                                   │ board  │╰────────╯  RSE   │        ╰────────╮   ╭────────╯  Rght  │  LWR   ╰────────╯│  Mute  │                           
 *                                   ╰────────╯         ╰────────╯ Space  │        │   │  Left  │  Clck  ╰────────╯         ╰────────╯                           
 *                                                               ╰────────╯ Enter  │   │  Clck  ╰────────╯                                                       
 *                                                                        ╰────────╯   ╰────────╯                                                                
 */

    [_ADJUST] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD,                               RGB_VAI, RGB_SAI, RGB_HUI, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, W_TTHRD, XXXXXXX, XXXXXXX,                               XXXXXXX, W_TLEFT, W_THALF, W_TRGHT, XXXXXXX, XXXXXXX,
        RGB_RMOD,XXXXXXX, XXXXXXX, W_LTHRD, W_MAX,   W_RTHRD, XXXXXXX, RGB_TOG,             RGB_TOG, XXXXXXX, W_LHALF, W_CENT,  W_RHALF, XXXXXXX, XXXXXXX, RGB_MOD,
                 XXXXXXX, XXXXXXX, XXXXXXX, W_BTHRD, XXXXXXX, XXXXXXX, RGB_RMOD,            RGB_MOD, XXXXXXX, W_BLEFT, W_BHALF, W_BRGHT, XXXXXXX, XXXXXXX,
                                   _______, _______, XXXXXXX, _______, _______,             _______, _______, XXXXXXX, _______, _______
    ),



/*
 * Layer: NUMROW
 *                                     ╭────────╮                                                                         ╭────────╮                                                  
 *                            ╭────────╯        ╰────────╮                                                       ╭────────╯        ╰────────╮                                     
 *                            │        │        │        ╰────────╮                                     ╭────────╯        │        │        │                              
 *          ╭────────╮────────╯        ╰────────╯        │        │                                     │        │        ╰────────╯        ╰────────╭────────╮  
 *          │        │        ╰────────╯        ╰────────╯        │                                     │        ╰────────╯        ╰────────╯        │        │  
 *          │  Esc   │        │        │   3    │        ╰────────╯                                     ╰────────╯        │    8   │        │        │ Bckspc │  
 *          ╰────────╯────────╯   2    ╰────────╯   4    │        │                                     │        │    7   ╰────────╯    9   ╰────────╰────────╯  
 *          │        │        ╰────────╯        ╰────────╯   5    │                                     │    6   ╰────────╯        ╰────────╯        │    :   │  
 *          │  Tab   │   1    │        │   8    │        ╰────────╯ ╭────────╮               ╭────────╮ ╰────────╯        │    5   │        │    0   │    ;   │  
 * ╭────────╯────────╯────────╯   7    ╰────────╯   9    │        │ │        │               │        │ │        │    4   ╰────────╯    6   ╰────────╰────────╰────────╮
 * │        │        │        ╰────────╯        ╰────────╯   0    │ │        │               │        │ │        ╰────────╯        ╰────────╯        │        │    |   │
 * │        │  Ctrl  │   6    │        │        │   <    ╰────────╯ ╰─encodr─╯               ╰─encodr─╯ ╰────────╯        │    2   │        │        │  Enter │    \   │
 * ╰────────╮────────╯────────╯        ╰────────╯   ,    │   >    │  ╭────────╮             ╭────────╮  │        │    1   ╰────────╯    3   ╰────────╰────────╭────────╯
 *          │        │        ╰────────╯        ╰────────╯   .    │  │        │             │        │  │        ╰────────╯        ╰────────╯    <   │    >   │
 *          │  Shift │        │                ╭────────╮╰────────╯  │        │             │        │  ╰────────╯╭────────╮                │    ,   │    .   │
 *          ╰────────╯────────╯      ╭────────╮│        ╰────────╮   ╰────────╯             ╰────────╯   ╭────────╯   <    │╭────────╮      ╰────────╰────────╯
 *                                   │ paste  ││  Cmd   │        ╰────────╮                     ╭────────╯        │   .    ││        │                           
 *                                   │ board  │╰────────╯        │        ╰────────╮   ╭────────╯  Rght  │   0    ╰────────╯│  Mute  │                           
 *                                   ╰────────╯         ╰────────╯ Space  │        │   │  Left  │  Clck  ╰────────╯         ╰────────╯                           
 *                                                               ╰────────╯ Enter  │   │  Clck  ╰────────╯                                                       
 *                                                                        ╰────────╯   ╰────────╯         
 */           

    [_NUMROW] = LAYOUT(
                _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        XXXXXXX,XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,             _______, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, _______, _______,
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  _______,             _______, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_COMM, KC_DOT, 
                                  _______, _______, XXXXXXX, _______, _______,             _______, _______, KC_0,    _______, _______
    ),                   

/*
 * Base Layer: SAMPLE
 *                                     ╭────────╮                                                                         ╭────────╮                                                  
 *                            ╭────────╯        ╰────────╮                                                       ╭────────╯        ╰────────╮                                     
 *                            │        │        │        ╰────────╮                                     ╭────────╯        │        │        │                              
 *          ╭────────╮────────╯        ╰────────╯        │        │                                     │        │        ╰────────╯        ╰────────╭────────╮  
 *          │        │        ╰────────╯        ╰────────╯        │                                     │        ╰────────╯        ╰────────╯        │        │  
 *          │        │        │        │        │        ╰────────╯                                     ╰────────╯        │        │        │        │        │  
 *          ╰────────╯────────╯        ╰────────╯        │        │                                     │        │        ╰────────╯        ╰────────╰────────╯  
 *          │        │        ╰────────╯        ╰────────╯        │                                     │        ╰────────╯        ╰────────╯        │        │  
 *          │        │        │        │        │        ╰────────╯ ╭────────╮               ╭────────╮ ╰────────╯        │        │        │        │        │  
 * ╭────────╯────────╯────────╯        ╰────────╯        │        │ │        │               │        │ │        │        ╰────────╯        ╰────────╰────────╰────────╮
 * │        │        │        ╰────────╯        ╰────────╯        │ │        │               │        │ │        ╰────────╯        ╰────────╯        │        │        │
 * │        │        │        │        │        │        ╰────────╯ ╰─encodr─╯               ╰─encodr─╯ ╰────────╯        │        │        │        │        │        │
 * ╰────────╮────────╯────────╯        ╰────────╯        │        │  ╭────────╮             ╭────────╮  │        │        ╰────────╯        ╰────────╰────────╭────────╯
 *          │        │        ╰────────╯        ╰────────╯        │  │        │             │        │  │        ╰────────╯        ╰────────╯        │        │
 *          │        │        │                ╭────────╮╰────────╯  │        │             │        │  ╰────────╯╭────────╮                │        │        │
 *          ╰────────╯────────╯      ╭────────╮│        ╰────────╮   ╰────────╯             ╰────────╯   ╭────────╯        │╭────────╮      ╰────────╰────────╯
 *                                   │        ││        │        ╰────────╮                     ╭────────╯        │        ││        │                           
 *                                   │        │╰────────╯        │        ╰────────╮   ╭────────╯        │        ╰────────╯│        │                           
 *                                   ╰────────╯         ╰────────╯        │        │   │        │        ╰────────╯         ╰────────╯                           
 *                                                               ╰────────╯        │   │        ╰────────╯                                                       
 *                                                                        ╰────────╯   ╰────────╯                                             
 * [_SAMPLE] = LAYOUT(
 *         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 *         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 * XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 *         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 *                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
 * ),                   
 */
};


#ifdef OLED_ENABLE

static void render_logo(void) {

    static const char PROGMEM ava40_logo[] = {
        // 'ava60logo-01', 128x35px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0xfc, 
        0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 
        0xc0, 0xc0, 0x40, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfc, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf8, 0xfe, 0xff, 0x7f, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xf0, 0x70, 0x70, 0x70, 0x70, 
        0x70, 0x70, 0x70, 0xf0, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfe, 0xff, 0x3f, 0x0f, 0x07, 
        0x0f, 0x3f, 0xff, 0xfe, 0xfc, 0xf0, 0xc0, 0x01, 0x07, 0x1f, 0x7f, 0xff, 0xfe, 0xf8, 0xe0, 0x80, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfc, 0xff, 0xff, 0x7f, 0x1f, 
        0x07, 0x81, 0xe0, 0xf8, 0xfe, 0xff, 0x3f, 0x1f, 0x07, 0x07, 0x1f, 0x7f, 0xff, 0xfc, 0xf0, 0xe0, 
        0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 
        0xf8, 0xfe, 0xff, 0xff, 0xff, 0xe7, 0xf3, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 0x80, 
        0x00, 0xe0, 0xf8, 0xfc, 0x3f, 0x0f, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 
        0xc0, 0x80, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x1f, 0x7e, 0xfc, 0xf8, 0xe0, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xfc, 0xff, 0xff, 0x7f, 0x77, 0x73, 0x70, 0x70, 0x70, 0x70, 
        0x70, 0x70, 0x70, 0x73, 0x77, 0x7f, 0x7f, 0xff, 0xfc, 0xf8, 0xe0, 0x81, 0x07, 0x1f, 0x7f, 0xff, 
        0xfe, 0xf8, 0xe0, 0x80, 0x00, 0x80, 0xe0, 0xf8, 0xff, 0xff, 0x3f, 0x1f, 0x07, 0xc1, 0xf0, 0xfc, 
        0xfe, 0xff, 0x7f, 0x7f, 0x73, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x71, 0x77, 0x7f, 0x7f, 
        0xff, 0xfe, 0xf8, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0xff, 0xff, 0xff, 
        0x1f, 0x07, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x07, 0x3f, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xf8, 0xfc, 0xfc, 0xfe, 0xf6, 0x84, 0xce, 0xdf, 0xff, 0xff, 0xff, 0xff, 
        0xfc, 0xf1, 0x83, 0x06, 0x8c, 0x9e, 0x3f, 0xfe, 0xfc, 0xf8, 0xf0, 0xff, 0xff, 0xff, 0x0c, 0x00, 
        0x00, 0x18, 0x1e, 0x1f, 0x1f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1f, 0x1f, 0x1f, 0x1e, 0x18, 0x10, 0x01, 
        0x07, 0x0f, 0x3f, 0xff, 0xff, 0xff, 0x3f, 0x0f, 0x03, 0x00, 0x18, 0x1c, 0x1f, 0x1f, 0x1f, 0x0f, 
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x03, 0x0f, 0x1f, 0x1f, 0x1f, 0x1c, 0x10, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x3f, 0x7f, 0xff, 
        0xfc, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xf8, 0xfe, 0xff, 0x7f, 
        0x3f, 0x0f, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 
        0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(ava40_logo, sizeof(ava40_logo));
}

static void print_status(void) {
    // Print current mode
    oled_write_ln_P(PSTR("welc0me chewiedies..."), false);
    // Print current layer
    oled_write_ln_P(PSTR("init -kb avalanche/v4"), false);
    // oled_write_ln_P(PSTR("\n"), false);
    // render_face();
    // oled_set_cursor(0,12);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("> C:\\Base"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("> C:\\Navigate"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("> C:\\Symbols"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("> C:\\WinMgmnt"), false);
            break;
        case _NUMROW:
            oled_write_P(PSTR("> C:\\NumRow"), false);
            break;
        default:
            oled_write_ln_P(PSTR("> C: \\Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

static void print_status_right(void) {
    oled_set_cursor(0,6);
    // oled_write_ln_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("chewiedies@ava ~> v4"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_180;
    } else { 
        return OLED_ROTATION_180;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status();
    } else {
        render_logo();
        print_status_right();
    }
    return true;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;

        // case KC_GAME:
        //     if (record->event.pressed) {
        //         set_single_persistent_default_layer(_GAMING);
        //     }
        //     return false;

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

        case KC_NUMROW: 
            if (record->event.pressed) {
                layer_on(_NUMROW);
            } else {
                layer_off(_NUMROW);
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
                tap_code(KC_RGHT);
            } else {
                tap_code(KC_LEFT);
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

// Lighting layers
// const rgblight_segment_t PROGMEM chewies_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {7, 4, HSV_RED}, // Light 2 LEDs, starting with 35 and ending on 36
//     {44, 4, HSV_RED}  // Light 2 LEDs
// );
// const rgblight_segment_t PROGMEM chewies_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS( // default layer
//     {7, 4, HSV_PURPLE}, // Light 2 LEDs
//     {44, 4, HSV_PURPLE}  // Light 2 LEDs
// );
// const rgblight_segment_t PROGMEM chewies_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS( // Raise layer
//     {7, 4, HSV_BLUE}, // Light 2 LEDs
//     {44, 4, HSV_BLUE}//,  // Light 2 LEDs
//     //{45, 1, HSV_TEAL},  // Light 1 LED under I
//     //{51, 3, HSV_TEAL}  // Light 3 LEDs under J,K,L
// );


// // The array of lighting layers. Latter layers take precedence.
// const rgblight_segment_t* const PROGMEM chewies_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     chewies_capslock_layer,
//     chewies_layer1_layer, // Overrides caps lock layer
//     chewies_layer2_layer
    
// );

// // enable the lighting layers
// void keyboard_post_init_user(void) {
//     rgblight_layers = chewies_rgb_layers;
// }

// // turn on caps lock lighting layer
// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(0, led_state.caps_lock);
//     return true;
// }

// // default state
// // layer_state_t default_layer_state_set_user(layer_state_t state) {
// //     rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
// //     return state;
// // }

// // Raise and Lower states
// layer_state_t layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
//     rgblight_set_layer_state(3, layer_state_cmp(state, _LOWER));
//     return state;
// }

// Runs just one time when the keyboard initializes.
void matrix_scan_user(void) {
    static bool has_ran_yet = false;
    if (!has_ran_yet) {
        has_ran_yet = true;
        // rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 4); 
        // rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv(HSV_CHARTREUSE);
    }
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 750) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
      }
    }
};