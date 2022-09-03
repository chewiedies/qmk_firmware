/* Copyright 2020 Kyrre Havik Eriksen
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

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMROW
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
    W_TLEFT,
    W_TRGHT,
    W_BLEFT,
    W_BRGHT,
};

#define CTRLESC CTL_T(KC_ESC)
#define MEHTAB LCAG_T(KC_TAB)
#define SHFTENT RSFT_T(KC_ENT)
#define NUMENT LT(_NUMROW, KC_ENT)
#define NUMMINS LT(_NUMROW, KC_MINS)
#define RSE MO(_RAISE)
#define LWR MO(_LOWER)
#define ADJ MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *                            ╭────────╮                                                                      ╭────────╮                             
 *                   ╭────────╯        ╰────────╮                                                    ╭────────╯        ╰────────╮                    
 *                   │        │   E    │        ╰────────╮                                  ╭────────╯        │    I   │        │                    
 * ╭────────╮────────╯   W    ╰────────╯   R    │        │                                  │        │    U   ╰────────╯    O   ╰────────╭────────╮  
 * │  Tab   │        ╰────────╯        ╰────────╯   T    │                                  │    Y   ╰────────╯        ╰────────╯        │        │  
 * │ (Meh)  │   Q    │        │   D    │        ╰────────╯                                  ╰────────╯        │    K   │        │    P   │ Bkspce │  
 * ╰────────╯────────╯   S    ╰────────╯   F    │        │                                  │        │    J   ╰────────╯    L   ╰────────╰────────╯
 * │  Esc   │        ╰────────╯        ╰────────╯   G    │                                  │    H   ╰────────╯    <   ╰────────╯    :   │    "   │
 * │ (ctrl) │   A    │        │   C    │        ╰────────╯                                  ╰────────╯        │    ,   │    >   │    ;   │    '   │
 * ╰────────╯────────╯   X    ╰────────╯   V    │        │                                  │        │    M   ╰────────╯    .   ╰────────╰────────╯
 * │        │        ╰────────╯        ╰────────╯   B    │                                  │    N   ╰────────╯        ╰────────╯    ?   │(rShift)│
 * │ Shift  │   Z    │ Paste  │  CMD   │        ╰────────╯────────╮                ╭────────╰────────╯        │   ALT  │        │    /   │ Enter  │
 * ╰────────╯────────╯ Board  ╰────────╯  RSE   │        │        │                │        │        │   LWR  ╰────────╯  Mute  ╰────────╰────────╯
 *                   ╰──ENC───╯        ╰────────╯  Spc   │   {    │                │    }   │   Spc  ╰────────╯    |   ╰───ENC──╯                   
 *                            │ M_Play │        ╰────────╰────────╯                ╰────────╯────────╯    ~   │    \   │                               
 *                            ╰────────╯  Del   │        │  Ent   │                │   - _  │    +   │    `   ╰────────╯                                                                                                
 *                                     ╰────────╯  Bkscp │ (num)  │                │  (num) │    =   ╰────────╯                            
 *                                              ╰────────╰────────╯                ╰────────╯────────╯                                                                                                                                
 */

    [_QWERTY] = LAYOUT(
      MEHTAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      CTRLESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SHFTENT,
                        PSTBRD,  KC_LGUI, RSE,     KC_SPC,  KC_LCBR,                KC_RCBR, KC_SPC,  LWR,     KC_RALT, KC_MUTE,
                                 KC_MPLY, KC_DEL,  KC_BSPC, NUMENT,                 NUMMINS, KC_EQL,  KC_GRV,  KC_BSLS
    ),
    [_LOWER] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
      _______, XXXXXXX, KC_CLAW, KC_LPRN, KC_RPRN, XXXXXXX,                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
      _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX,                                  XXXXXXX, XXXXXXX, _______, _______, _______, _______,
                        SCRNCAP, _______, _______, _______, KC_LBRC,                KC_RBRC, _______, _______, _______, _______,
                                 _______, _______, _______, _______,                _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, W_TTHRD, XXXXXXX, RGB_HUD,                                  RGB_HUI, W_TLEFT, W_THALF, W_TRGHT, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, W_LTHRD, W_MAX,   W_RTHRD, RGB_VAD,                                  RGB_VAI, W_LHALF, W_CENT,  W_RHALF, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, W_BTHRD, XXXXXXX, RGB_SAD,                                  RGB_SAI, W_BLEFT, W_BHALF, W_BRGHT, XXXXXXX, XXXXXXX,
                        RGB_TOG, _______, _______, _______, _______,                _______, _______, XXXXXXX, XXXXXXX, RGB_TOG,
                                 _______, _______, _______, _______,                _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
      KC_SFTB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  XXXXXXX, KC_PRVWD,KC_UP,   KC_NXTWD,XXXXXXX, KC_DEL,
      KC_UNDO, KC_REDO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  XXXXXXX, KC_LSTRT,XXXXXXX, KC_LEND, XXXXXXX, _______,
                        KC_CAPS, _______, _______, _______, KC_LBRC,                KC_RBRC, _______, _______, XXXXXXX, _______,
                                 _______, _______, _______, _______,                _______, _______, _______, _______
    ),
    [_NUMROW] = LAYOUT(
      XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                                     XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, _______,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,                                   XXXXXXX, KC_1,    KC_2,    KC_3,    KC_COMM, KC_DOT, 
                        CALCAPP, _______, XXXXXXX, KC_PLUS, KC_MINS,                KC_MINS, KC_PLUS, KC_0,    _______, CALCAPP,
                                 _______, _______, _______, _______,                _______, _______, _______, _______
    ),  
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

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

        case CALCAPP:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_C);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
                unregister_code(KC_C);
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

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return OLED_ROTATION_270;
}

static void render_named_logo(void) {
  static const char PROGMEM raw_logo[] = {
    12, 60,252,252,252,236,236,140, 12, 28,248,192,  0,192,248,252,252,252,108, 12, 12,140,236, 60, 12,  0,  0,  0,248,252,252,252,236,204,204,204,204,204,204,204,204,204,204,204,204,140, 12,252,248,  0,  0,  0,252,252,252,252,236,236,236,204, 12, 60,240,192,  0,  0,  0,252,252,252,236,236, 12, 12, 12,252,248,  0,  0,192,224, 96, 48, 24, 24,140,140,132,196,196,196,196,132,140,140, 12, 24, 48, 48, 96,192,128,  0,  0,252,252,252,236,236,236,236,140, 28,120,224,128,  0,  0,252,252,252,252,236,236, 12, 12, 12,252,
    0,  0,  0,  3, 15,255,255,255,254,248,192,195,223,255,255, 63, 15,  1,224,248, 30,  7,  1,  0,  0,  0,  0,  0,255,255,255,255,255,255,  0,  0,  1, 63, 63, 51, 51, 51, 51, 51, 51, 51,243,  3,  1,  0,  0,  0,255,255,255,255,255,  1, 15,127,255,252,240,195, 15, 60,240,255,255,255,255,255,  0,  0,  0,255,255,254,255,255,255,127, 14,  2,195,247, 63, 31, 15, 15, 15, 15, 31, 63,255,255,254,252,248,224,  1,  3, 30,252,255,255,255,255,255,  3, 31,255,254,248,225,135, 30,120,255,255,255,255,255,255,  0,  0,  0,255, 
    0,  0,128,240,252,255,255,255, 63,  7,  1,227,127,255,255,255,248,224,  1,  7, 62,240,192,  0,  0,  0,  0,  0,255,255,255,255,255,255,  1,  3,  7,255,255,207,207,207,207,207,206,204,207,192,128,  0,  0,  0,255,255,255,255,255,  0,  0,  0,255,255, 15,127,255,252,240,227,143,127,255,255,  0,  0,  0,255,255, 63,255,255,255,254,240,192,131,135, 12, 24, 48, 48, 48, 48, 24, 28, 15,159,255, 63, 31,  7,128,192,120, 31,255,255,255,255,255,  0,  0,  0,255,255, 31,127,255,252,241,199, 31,127,255,255,  0,  0,  0,255,
    48, 62, 63, 63, 63, 63, 63, 56, 48, 60, 31,  3,  0,  3, 31, 63, 63, 63, 63, 60, 60, 56, 59, 63, 56,  0,  0,  0, 31, 63, 63, 63, 63, 63, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 56, 63, 31,  0,  0,  0, 63, 63, 63, 63, 63, 60, 56, 48, 63, 63,  0,  0,  0,  3, 31, 63, 63, 62, 61, 63, 60, 56, 48, 63, 31,  0,  0,  1,  7,  7, 15, 31, 31, 63, 63, 63, 62, 62, 62, 62, 63, 63, 63, 31, 31, 15, 14,  6,  3,  1,  0,  0, 63, 63, 63, 63, 63, 60, 56, 56, 63, 31,  0,  0,  1,  7, 31, 63, 63, 60, 63, 63, 60, 56, 48, 63
  };
  oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void render_status(void) {
  oled_write_P(PSTR("-----XENON-----\n\n\n\n"), false);

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
      case _NUMROW: 
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
    render_named_logo();
  }

  return true;
}
#endif


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
                tap_code16(S(KC_TAB));
            } else {
                tap_code16(KC_TAB);
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


// Runs just one time when the keyboard initializes.
void matrix_scan_user(void) {
    static bool has_ran_yet = false;
    if (!has_ran_yet) {
        has_ran_yet = true;
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 4); 
        // rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
        // rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        // rgblight_sethsv(HSV_CHARTREUSE);
    }
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 750) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
      }
    }
};