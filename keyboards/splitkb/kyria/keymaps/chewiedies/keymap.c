/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include <stdio.h>

// layer names
enum layers {
    _QWERTY = 0,
    _LWR = 1,
    _RSE = 2,
    _WINMAN = 3,
    _NMRW = 4,
};

// custom keycodes
enum custom_keycodes {
    KC_SFTB = SAFE_RANGE,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    PSTBD,
    KC_IMP,
    KC_CLAW,
    KC_MDAQ,
    KC_FONT,
    KC_REMC,
    KC_TOP,
    KC_BOT,
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
    W_UNDO,
    KC_REDO,
    SCRNCAP,
    CALCAPP,
};

// combos and chords
#ifdef COMBO_ENABLE
enum combo_events {
    QUE_BSLS,
    SPCEQL_BS,
    SPCMINS_ENT
};

const uint16_t PROGMEM quesbsls_combo[] = {KC_SLSH, KC_BSLS, COMBO_END};
const uint16_t PROGMEM spceql_bs[]      = {KC_SPC,  KC_EQL,  COMBO_END};
const uint16_t PROGMEM spcmins_ent[]    = {KC_SPC, KC_MINS, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [QUE_BSLS]      = COMBO_ACTION(quesbsls_combo),
    [SPCEQL_BS]     = COMBO_ACTION(spceql_bs),
    [SPCMINS_ENT]   = COMBO_ACTION(spcmins_ent)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
    case QUE_BSLS:
        if (pressed) {
            tap_code(KC_ENT);
        }
        break;
    case SPCEQL_BS:
        if (pressed) {
            tap_code(KC_BSPC);
        }
        break;
    case SPCMINS_ENT:
        if (pressed) {
            tap_code(KC_ENT);
        }
        break;
    }
};
#endif

// tap dance stuff
#ifdef TAP_DANCE_ENABLE

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_SINGLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_TAP,
};

// tap dance declarations
enum {
  TD_IMP,
  TD_MDAQ,
  TD_LBRC,
  TD_RBRC,
  TD_SASSV
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

void dance_imp_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_imp_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_mdaq_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_mdaq_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_lbrc_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_lbrc_reset(qk_tap_dance_state_t *state, void *user_data);
void dance_rbrc_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_rbrc_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_sassv_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_sassv_reset(qk_tap_dance_state_t *state, void *user_data);

#define TDIMP TD(TD_IMP)                                
#define TDMDAQ TD(TD_MDAQ)
#define TDLBRC TD(TD_LBRC)
#define TDRBRC TD(TD_RBRC)
#define TDSASSV TD(TD_SASSV)

#endif

// custom mods
#define NMRWENT LT(_NMRW,KC_ENT)
#define MORAISE MO(_RSE)
#define MOLOWER MO(_LWR)
#define LTNMRW LT(_NMRW,KC_MINS)
#define CTLESC MT(MOD_LCTL, KC_ESC)
#define LCAGTAB LCAG_T(KC_TAB)

// alt/tab stuff
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

// wpm stuff
#ifdef WPM_ENABLE
char wpm_str[10];
// uint16_t wpm_graph_timer = 0;
#endif


// layer keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *                            ╭────────╮                                                                                ╭────────╮                             
 *                   ╭────────╯        ╰────────╮                                                              ╭────────╯        ╰────────╮                    
 *                   │        │   E    │        ╰────────╮                                            ╭────────╯        │    I   │        │                    
 * ╭────────╮────────╯   W    ╰────────╯   R    │        │                                            │        │    U   ╰────────╯    O   ╰────────╭────────╮  
 * │        │        ╰────────╯        ╰────────╯   T    │                                            │    Y   ╰────────╯        ╰────────╯        │        │  
 * │  Tab   │   Q    │        │   D    │        ╰────────╯                                            ╰────────╯        │    K   │        │    P   │ Bkspce │  
 * ╰────────╯────────╯   S    ╰────────╯   F    │        │                                            │        │    J   ╰────────╯    L   ╰────────╰────────╯  
 * │  Esc   │        ╰────────╯        ╰────────╯   G    │                                            │    H   ╰────────╯    <   ╰────────╯    :   │    "   │  
 * │ (ctrl) │   A    │        │   C    │        ╰────────╯                                            ╰────────╯        │    ,   │    >   │    ;   │    '   │  
 * ╰────────╯────────╯   X    ╰────────╯   V    │        │ ╭────────╮                      ╭────────╮ │        │    M   ╰────────╯    .   ╰────────╰────────╯  
 * │        │        ╰────────╯        ╰────────╯   B    │ │   +    ╰────────╮    ╭────────╯    _   │ │    N   ╰────────╯        ╰────────╯    ?  ent   |   │  
 * │ Shift  │   Z    │                ╭────────╮╰────────╯ │   =    │        │    │        │   -    │ ╰────────╯╭────────╮                │    /   er   \   │  
 * ╰────────╯────────╯      ╭────────╮│        ╰────────╮  ╰┤Bck├───╯   {    │    │    }   ╰───┤Ent├╯  ╭────────╯        │╭────────╮      ╰────────╰────────╯  
 *                          │ Paste  ││  CMD   │        ╰───┤Spc├╮  ╰────────╯    ╰────────╯  ╭┤er ├───╯        │  ALT   ││        │                           
 *                          │ Board  │╰────────╯  RSE   │        ╰────────╮          ╭────────╯        │  LWR   ╰────────╯│  Mute  │                           
 *                          ╰─encodr─╯         ╰────────╯ Space  │        │          │    _   │ Space  ╰────────╯         ╰─encodr─╯                           
 *                                                      ╰────────╯ Enter  │          │   -    ╰────────╯                                                       
 *                                                               ╰────────╯          ╰────────╯                                                                
 *
 */
    [_QWERTY] = LAYOUT(
      LCAGTAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                              KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
      CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                              KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_EQL,  KC_LCBR,      KC_RCBR,  KC_MINS, KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_BSLS,
                                 PSTBD,   KC_LGUI, MORAISE, KC_SPC,  NMRWENT,      LTNMRW,   KC_SPC,  MOLOWER,  KC_LALT,  KC_MUTE
    ),


/*
 * Lower Layer: Symbols 
 *                            ╭────────╮                                                                                ╭────────╮                             
 *                   ╭────────╯        ╰────────╮                                                              ╭────────╯        ╰────────╮                    
 *                   │        │   #    │        ╰────────╮                                            ╭────────╯        │    *   │        │                    
 * ╭────────╮────────╯   @    ╰────────╯   $    │        │                                            │        │    &   ╰────────╯    (   ╰────────╭────────╮  
 * │        │        ╰────────╯        ╰────────╯   %    │                                            │    ^   ╰────────╯        ╰────────╯        │    -   │  
 * │  !imp  │   !    │ Save4  │   (    │        ╰────────╯                                            ╰────────╯        │        │        │    )   │   -    │  
 * ╰────────╯────────╯ Web    ╰────────╯   )    │        │                                            │        │        ╰────────╯        ╰────────╰────────╯  
 * │        │        ╰────────╯        ╰────────╯   `    │                                            │        ╰────────╯    <   ╰────────╯    :   │    "   │  
 * │  Undo  │  Redo  │        │   {    │        ╰────────╯                                            ╰────────╯        │    ,   │    >   │    ;   │   '    │  
 * ╰────────╯────────╯        ╰────────╯   }    │        │ ╭────────╮                      ╭────────╮ │        │        ╰────────╯    .   ╰────────╰────────╯  
 * │        │        ╰────────╯        ╰────────╯   ~    │ │   +    ╰────────╮    ╭────────╯    _   │ │        ╰────────╯        ╰────────╯    ?   │    |   │  
 * │ Shift  │  ALT   │                ╭────────╮╰────────╯ │   =    │        │    │        │   -    │ ╰────────╯╭────────╮                │    /   │    \   │  
 * ╰────────╯────────╯      ╭────────╮│        ╰────────╮  ╰────────╯   [    │    │    ]   ╰────────╯  ╭────────╯        │╭────────╮      ╰────────╰────────╯  
 *                          │  Scrn  ││Remcalc │        ╰────────╮  ╰────────╯    ╰────────╯  ╭────────╯   LWR  │   ALT  ││        │                           
 *                          │  Cap   │╰────────╯  RSE   │        ╰────────╮          ╭────────╯        │████████╰────────╯│  Mute  │                           
 *                          ╰─encodr─╯         ╰────────╯@mediaq │  Font  │          │        │ Space  ╰────────╯         ╰─encodr─╯                           
 *                                                      ╰────────╯  Mixin │          │        ╰────────╯                                                       
 *                                                               ╰────────╯          ╰────────╯                                                                
 *
 */
    [_LWR] = LAYOUT( 
      KC_IMP,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
      KC_UNDO, KC_REDO, KC_CLAW, KC_LPRN, KC_RPRN, KC_GRV,                                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
      _______, KC_LALT, XXXXXXX, KC_LCBR, KC_RCBR, KC_TILD, KC_EQL,  KC_LBRC,      KC_RBRC, KC_MINS, XXXXXXX, XXXXXXX, _______, _______, _______, _______,
                                 SCRNCAP, KC_REMC, _______, KC_MDAQ, KC_FONT,      _______, KC_SPC,  _______, _______, _______
    ),



/*
 * Raise Layer: Mouse, navigation
 *                            ╭────────╮                                                                                ╭────────╮                             
 *                   ╭────────╯ Mouse  ╰────────╮                                                              ╭────────╯  Arrow ╰────────╮                    
 *                   │ Left   │   ↑    │ Right  ╰────────╮                                            ╭────────╯  Prev  │    ↑   │  Next  │                    
 * ╭────────╮────────╯ Click  ╰────────╯ Click  │        │                                            │  Page  │  Word  ╰────────╯  Word  ╰────────╭────────╮  
 * │ Shift/ │        ╰────────╯ Mouse  ╰────────╯        │                                            │  Top   ╰────────╯  Arrow ╰────────╯        │        │  
 * │  Tab   │        │ Mouse  │   ↓    │ Mouse  ╰────────╯                                            ╰────────╯  Arrow │    ↓   │  Arrow │        │ Delete │  
 * ╰────────╯────────╯   ←    ╰────────╯   →    │        │                                            │        │    ←   ╰────────╯    →   ╰────────╰────────╯  
 * │        │        ╰────────╯        ╰────────╯        │                                            │        ╰────────╯        ╰────────╯        │        │  
 * │ Undo   │  Redo  │        │        │        ╰────────╯                                            ╰────────╯  Line  │        │  Line  │        │        │  
 * ╰────────╯────────╯        ╰────────╯        │        │ ╭────────╮                      ╭────────╮ │  Page  │  Start ╰────────╯  End   ╰────────╰────────╯  
 * │        │        ╰────────╯        ╰────────╯        │ │        ╰────────╮    ╭────────╯        │ │  Btm   ╰────────╯        ╰────────╯        │        │  
 * │ Shift  │  ALT   │                ╭────────╮╰────────╯ │        │        │    │        │        │ ╰────────╯╭────────╮                │        │        │  
 * ╰────────╯────────╯      ╭────────╮│        ╰────────╮  ╰────────╯   [    │    │    ]   ╰────────╯  ╭────────╯        │╭────────╮      ╰────────╰────────╯  
 *                          │ Paste  ││        │  RSE   ╰────────╮  ╰────────╯    ╰────────╯  ╭────────╯        │   ALT  ││        │                           
 *                          │ Board  │╰────────╯████████│        ╰────────╮          ╭────────╯ Right  │   LWR  ╰────────╯│  Mute  │                           
 *                          ╰─encodr─╯         ╰────────╯ Space  │        │          │ Left   │ Click  ╰────────╯         ╰─encodr─╯                           
 *                                                      ╰────────╯ Enter  │          │ Click  ╰────────╯                                                       
 *                                                               ╰────────╯          ╰────────╯                                                                
 *
 */
    [_RSE] = LAYOUT(
      KC_SFTB, XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX,                                           KC_TOP,  KC_PRVWD, KC_UP,   KC_NXTWD, XXXXXXX, KC_DEL,
      KC_UNDO, KC_REDO, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                                           XXXXXXX, KC_LEFT,  KC_DOWN, KC_RGHT,  XXXXXXX, XXXXXXX,
      _______, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC,       KC_RBRC, XXXXXXX, KC_BOT,  KC_LSTRT, XXXXXXX, KC_LEND,  XXXXXXX, XXXXXXX,
                                 _______, _______, _______, XXXXXXX, XXXXXXX,       KC_BTN1, KC_BTN2, _______, _______, _______
    ),



/*
 * Adjust Layer: Window Management, RGB adjustments
 *                            ╭────────╮                                                                                ╭────────╮                             
 *                   ╭────────╯  Top   ╰────────╮                                                              ╭────────╯  Top   ╰────────╮                    
 *                   │ Window │  Thrd  │ Window ╰────────╮                                            ╭────────╯  Top   │  Half  │  Top   │                    
 * ╭────────╮────────╯ Smallr ╰────────╯ Larger │        │                                            │        │  Left  ╰────────╯  Right ╰────────╭────────╮  
 * │        │        ╰────────╯ Window ╰────────╯        │                                            │        ╰────────╯ Window ╰────────╯        │        │  
 * │        │        │  Left  │  Max   │  Rght  ╰────────╯                                            ╰────────╯  Left  │ Center │  Right │        │        │  
 * ╰────────╯────────╯  Thrd  ╰────────╯  Thrd  │        │                                            │        │  Half  ╰────────╯  Half  ╰────────╰────────╯  
 * │        │        ╰────────╯  Bot   ╰────────╯        │                                            │        ╰────────╯  Bot   ╰────────╯        │        │  
 * │        │        │        │  Thrd  │        ╰────────╯                                            ╰────────╯  Bot   │  Half  │  Bot   │        │        │  
 * ╰────────╯────────╯        ╰────────╯        │        │ ╭────────╮                      ╭────────╮ │        │  Left  ╰────────╯  Right ╰────────╰────────╯  
 * │        │        ╰────────╯        ╰────────╯        │ │ Window ╰────────╮    ╭────────╯ Window │ │        ╰────────╯        ╰────────╯        │        │  
 * │        │        │                ╭────────╮╰────────╯ │ LScrn  │  RGB   │    │  RGB   │ RScrn  │ ╰────────╯╭────────╮                │        │        │  
 * ╰────────╯────────╯      ╭────────╮│        ╰────────╮  ╰────────╯  I/O   │    │  I/O   ╰────────╯  ╭────────╯        │╭────────╮      ╰────────╰────────╯  
 *                          │        ││        │  RSE   ╰────────╮  ╰────────╯    ╰────────╯  ╭────────╯   LWR  │        ││        │                           
 *                          │        │╰────────╯████████│  RGB   ╰────────╮          ╭────────╯  RGB   │████████╰────────╯│        │                           
 *                          ╰─encodr─╯         ╰────────╯  Val ↓ │  RGB   │          │  RGB   │  Val ↑ ╰────────╯         ╰─encodr─╯                           
 *                                                      ╰────────╯  Val ↑ │          │  Val ↓ ╰────────╯                                                       
 *                                                               ╰────────╯          ╰────────╯                                                                
 *
 */
    [_WINMAN] = LAYOUT(
      XXXXXXX, XXXXXXX, W_SMLR,  W_TTHRD, W_LRGR,  XXXXXXX,                                           XXXXXXX, W_TLEFT, W_THALF, W_TRGHT, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, W_LTHRD, W_MAX,   W_RTHRD, XXXXXXX,                                           XXXXXXX, W_LHALF, W_CENT,  W_RHALF, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, W_BTHRD, XXXXXXX, XXXXXXX, W_LSCRN, RGB_TOG,       RGB_TOG, W_RSCRN, XXXXXXX, W_BLEFT, W_BHALF, W_BRGHT, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, _______, RGB_VAD, RGB_VAI,       RGB_VAD, RGB_VAI, _______, XXXXXXX, XXXXXXX
    ),


/*
 * Numrow Layer
 *                            ╭────────╮                                                                                ╭────────╮                             
 *                   ╭────────╯        ╰────────╮                                                              ╭────────╯        ╰────────╮                    
 *                   │        │   3    │        ╰────────╮                                            ╭────────╯        │    8   │        │                    
 * ╭────────╮────────╯   2    ╰────────╯   4    │        │                                            │        │    7   ╰────────╯    9   ╰────────╭────────╮  
 * │        │        ╰────────╯        ╰────────╯   5    │                                            │    6   ╰────────╯        ╰────────╯        │        │  
 * │  Tab   │   1    │        │   8    │        ╰────────╯                                            ╰────────╯        │    3   │        │    0   │Backspce│  
 * ╰────────╯────────╯   7    ╰────────╯   9    │        │                                            │        │    4   ╰────────╯    4   ╰────────╰────────╯  
 * │  Esc   │        ╰────────╯        ╰────────╯   0    │                                            │        ╰────────╯        ╰────────╯    :   │    "   │  
 * │ (CTRL) │   6    │        │        │        ╰────────╯                                            ╰────────╯        │    2   │        │    ;   │    '   │  
 * ╰────────╯────────╯  ALT   ╰────────╯        │        │ ╭────────╮                      ╭────────╮ │        │    1   ╰────────╯   3    ╰────────╰────────╯  
 * │        │        ╰────────╯        ╰────────╯   .    │ │   +    ╰────────╮    ╭────────╯    _   │ │    .   ╰────────╯        ╰────────╯    ?   │    |   │  
 * │ Shift  │  CTRL  │                ╭────────╮╰────────╯ │   =    │        │    │        │   -    │ ╰────────╯╭────────╮                │    /   │    \   │  
 * ╰────────╯────────╯      ╭────────╮│        ╰────────╮  ╰────────╯   {    │    │    }   ╰────────╯  ╭────────╯        │╭────────╮      ╰────────╰────────╯  
 *                          │ Paste  ││  CMD   │        ╰────────╮  ╰────────╯    ╰────────╯  ╭────────╯        │    0   ││  Calc  │                           
 *                          │ Board  │╰────────╯  RSE   │        ╰────────╮          ╭────────╯        │   LWR  ╰────────╯│  App   │                           
 *                          ╰─encodr─╯         ╰────────╯ Space  │        │          │  - _   │  Space ╰────────╯         ╰─encodr─╯                           
 *                                                      ╰────────╯ Enter  │          │████████╰────────╯                                                       
 *                                                               ╰────────╯          ╰────────╯                                                                
 *
 */
    [_NMRW] = LAYOUT(
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                                             XXXXXXX, KC_4,    KC_5,    KC_6,    _______,  _______,
      _______, KC_LCTL, KC_LALT, XXXXXXX, XXXXXXX, KC_DOT,  _______, _______,      _______, _______, KC_DOT,  KC_1,    KC_2,    KC_3,    _______, _______,
                                 _______, _______, _______, _______, _______,      _______, _______, _______, KC_0,    CALCAPP
    ),


/*
 * Layer Template
 *                            ╭────────╮                                                                                ╭────────╮                             
 *                   ╭────────╯        ╰────────╮                                                              ╭────────╯        ╰────────╮                    
 *                   │        │        │        ╰────────╮                                            ╭────────╯        │        │        │                    
 * ╭────────╮────────╯        ╰────────╯        │        │                                            │        │        ╰────────╯        ╰────────╭────────╮  
 * │        │        ╰────────╯        ╰────────╯        │                                            │        ╰────────╯        ╰────────╯        │        │  
 * │        │        │        │        │        ╰────────╯                                            ╰────────╯        │        │        │        │        │  
 * ╰────────╯────────╯        ╰────────╯        │        │                                            │        │        ╰────────╯        ╰────────╰────────╯  
 * │        │        ╰────────╯        ╰────────╯        │                                            │        ╰────────╯        ╰────────╯        │        │  
 * │        │        │        │        │        ╰────────╯                                            ╰────────╯        │        │        │        │        │  
 * ╰────────╯────────╯        ╰────────╯        │        │ ╭────────╮                      ╭────────╮ │        │        ╰────────╯        ╰────────╰────────╯  
 * │        │        ╰────────╯        ╰────────╯        │ │        ╰────────╮    ╭────────╯        │ │        ╰────────╯        ╰────────╯        │        │  
 * │        │        │                ╭────────╮╰────────╯ │        │        │    │        │        │ ╰────────╯╭────────╮                │        │        │  
 * ╰────────╯────────╯      ╭────────╮│        ╰────────╮  ╰────────╯        │    │        ╰────────╯  ╭────────╯        │╭────────╮      ╰────────╰────────╯  
 *                          │        ││        │        ╰────────╮  ╰────────╯    ╰────────╯  ╭────────╯        │        ││        │                           
 *                          │        │╰────────╯        │        ╰────────╮          ╭────────╯        │        ╰────────╯│        │                           
 *                          ╰─encodr─╯         ╰────────╯        │        │          │        │        ╰────────╯         ╰─encodr─╯                           
 *                                                      ╰────────╯        │          │        ╰────────╯                                                       
 *                                                               ╰────────╯          ╰────────╯                                                                
 */
/*  [_LAYERINDEX] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                          _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                          _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______
    ),
*/

};


// oled time
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}


static void render_status(void) {
    oled_write_ln_P(PSTR("Kyria          rev1.4\n"), false);
    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Layer: Qwerty\n"), false);
            break;
        case _LWR:
            oled_write_ln_P(PSTR("Layer: Symbols and\n       Macros"), false);
            break;
        case _RSE:
            oled_write_ln_P(PSTR("Layer: Mouse &\n       Arrows/Nav"), false);
            break;
        case _WINMAN:
            oled_write_ln_P(PSTR("Layer: Window\n       Manager"), false);
            break; 
        case _NMRW:
            oled_write_ln_P(PSTR("Layer: Number Row\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Layer: Undefined\n"), false);
    }

    // Host Keyboard LED Status
    // uint8_t led_usb_state = host_keyboard_leds();
    // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);

    #ifdef WPM_ENABLE
    // Write WPM
    sprintf(wpm_str, "WPM: %03d", get_current_wpm());
    oled_write_ln_P(PSTR("\n"), false);
    oled_write(wpm_str, false);
    #endif
}


void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        // render_wpm_graph();
        render_kyria_logo();
    }
}
#endif

// tri layer state
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LWR, _RSE, _WINMAN);
}

// custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

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

        case KC_SFTB:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_TAB);
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

        case KC_COPY:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_C);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_C);
            }
            break;

        case KC_PASTE:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_V);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_V);
            }
            break;

        case KC_CUT:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_X);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_X);
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

        case PSTBD:
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

        case KC_IMP:
            if (record->event.pressed) {
                SEND_STRING("!important");
            }
        break;

        case KC_FONT:
            if (record->event.pressed) {
                SEND_STRING("@include fluid-type(rem-calc(),rem-calc());");
                tap_code16(KC_LEFT);
                tap_code16(KC_LEFT);
                tap_code16(KC_LEFT);
            }
            break;

        case KC_MDAQ:
            if (record->event.pressed) {
                SEND_STRING("@media #{$break} {}");
                tap_code16(KC_LEFT);
            }
            break;

        case KC_REMC:
            if (record->event.pressed) {
                SEND_STRING("rem-calc()");
                tap_code16(KC_LEFT);
            }
            break;

        case SCRNCAP:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                register_code(KC_4);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
                unregister_code(KC_4);
            }
            break;

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


// tap dance time
#ifdef TAP_DANCE_ENABLE
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    } else return 8;
}

// create instance of 'tap' for the 'x' tap dance
static tap xtap_state = {
    .is_press_action = true,
    .state = 0
};


// TD_IMP dance
void dance_imp_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch(xtap_state.state) {
        case SINGLE_TAP:
            register_code16(KC_EXLM);
            break;
        case DOUBLE_TAP:
            SEND_STRING("!important");
            break;
    }
}
void dance_imp_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch(xtap_state.state) {
        case SINGLE_TAP:
            unregister_code16(KC_EXLM);
            break;
        case DOUBLE_TAP:
            // do nothing
            break;
    }
    xtap_state.state = 0;
}


// TD_MDAQ dance
void dance_mdaq_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch(xtap_state.state) {
        case SINGLE_TAP:
            register_code16(KC_AT);
            break;
        case DOUBLE_TAP:
            SEND_STRING("@media #{$break} {}");
            tap_code16(KC_LEFT);
            tap_code16(KC_LEFT);
            tap_code16(KC_LEFT);
            tap_code16(KC_LEFT);
            break;
        case SINGLE_HOLD:
            SEND_STRING("@include fluid-type(rem-calc(),rem-calc());");
            tap_code16(KC_LEFT);
            tap_code16(KC_LEFT);
            tap_code16(KC_LEFT);
            break;
        case DOUBLE_HOLD:
            SEND_STRING("@include transition(all, $timing, $easing, $delay);");
            break;
    }
}
void dance_mdaq_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch(xtap_state.state) {
        case SINGLE_TAP:
            unregister_code16(KC_AT);
            break;
        case DOUBLE_TAP:
            // do nothing
            break;
        case SINGLE_HOLD:
            // do nothing
            break;
        case DOUBLE_HOLD:
            // do nothing
            break;
    }
    xtap_state.state = 0;
}


// TD_LBRC dance
void dance_lbrc_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch(xtap_state.state) {
        case SINGLE_TAP:
            register_code16(KC_LCBR);
            break;
        case DOUBLE_TAP:
            register_code16(KC_LBRC);
            break;
    }
}
void dance_lbrc_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch(xtap_state.state) {
        case SINGLE_TAP:
            unregister_code16(KC_LCBR);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_LBRC);
            break;
    }
    xtap_state.state = 0;
}


// TD_RBRC dance
void dance_rbrc_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch(xtap_state.state) {
        case SINGLE_TAP:
            register_code16(KC_RCBR);
            break;
        case DOUBLE_TAP:
            register_code16(KC_RBRC);
            break;
    }
}
void dance_rbrc_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch(xtap_state.state) {
        case SINGLE_TAP:
            unregister_code16(KC_RCBR);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_RBRC);
            break;
    }
    xtap_state.state = 0;
}


// TD_SASSV dance
void dance_sassv_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch(xtap_state.state) {
        case SINGLE_TAP:
            register_code16(KC_HASH);
            break;
        case DOUBLE_TAP:
            SEND_STRING("#{}");
            tap_code16(KC_LEFT);
            break;
    }
}
void dance_sassv_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch(xtap_state.state) {
        case SINGLE_TAP:
            unregister_code16(KC_HASH);
            break;
        case DOUBLE_TAP:
            // do nothing
            break;
    }
    xtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_IMP]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_imp_finished, dance_imp_reset),
    [TD_MDAQ]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_mdaq_finished, dance_mdaq_reset),
    [TD_LBRC]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lbrc_finished, dance_lbrc_reset),
    [TD_RBRC]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_rbrc_finished, dance_rbrc_reset),
    [TD_SASSV]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_sassv_finished, dance_sassv_reset)
};
#endif

// encoder time
#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { 
        switch(biton32(layer_state)) {
            case _QWERTY:
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
            case _NMRW:
            case _LWR:
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
            case _WINMAN:
                if (clockwise) {
                    rgblight_step();
                } else {
                    rgblight_step_reverse();
                }
            break;
        }
    }
    // right half
    else if (index == 1) {
        switch(biton32(layer_state)) {
            case _QWERTY:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            break;
            case _RSE:
                if (clockwise) {
                    register_code16(KC_LGUI);
                    register_code16(KC_LSFT);
                    tap_code(KC_Z);
                    unregister_code16(KC_LGUI);
                    unregister_code16(KC_LSFT);
                } else {
                    register_code16(KC_LGUI);
                    tap_code(KC_Z);
                    unregister_code16(KC_LGUI);
                }
            break;
            case _WINMAN:
                if (clockwise) { 
                    rgblight_increase_hue();
                } else {
                    rgblight_decrease_hue();
                }
            break;
        }
    }
}
#endif

// runs just one time when the keyboard initializes
void matrix_scan_user(void) {
    static bool has_ran_yet = false;
    if (!has_ran_yet) {
        has_ran_yet = true;
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 4); 
        // rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        // rgblight_sethsv(HSV_YELLOW);
    }
    if (is_alt_tab_active) {
        // if ( timer_elapsed(alt_tab_timer) > TAPPING_TERM ) { // way too fast (tapping term is 200ms in config.h)
        // if (timer_elapsed(alt_tab_timer) > 750) { // a tad too slow
        if (timer_elapsed(alt_tab_timer) > 500) {
            unregister_code(KC_LGUI);
            is_alt_tab_active = false;
        }
    }
}