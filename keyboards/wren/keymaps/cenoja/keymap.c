/* Copyright 2021 Walter Hanley
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

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

#define ADJ MO(_ADJUST)
#define RSFTENT RSFT_T(KC_ENT)
#define LCTLCAP LCTL_T(KC_CAPS)

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAMING
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_GAME,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_REDO,
    PSTBRD,
    HYPER,
    KC_SFTB,
    CMDAPP,
    SCRNCAP,
    KC_IMP,
    KC_FONT,
    KC_CLAW,
    KC_MDAQ,
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
    W_BRGHT
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_QWERTY] = LAYOUT(
        KC_PSLS, KC_7,    KC_8,    KC_9,      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,   KC_EQL,  KC_HOME, KC_END,  XXXXXXX,
        KC_PAST, KC_4,    KC_5,    KC_6,      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,   KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX,
        KC_PMNS, KC_1,    KC_2,    KC_3,      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,   XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,
        KC_PPLS, KC_0,    KC_DOT,  KC_EQL,    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,   KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
                                                                PSTBRD,  KC_LGUI, KC_SPC,  KC_RAISE, KC_ENT,     KC_SPC, KC_LOWER,KC_MINS, KC_LALT, KC_MUTE
    ),

    /* Lower */
    [_LOWER] = LAYOUT(
        _______, _______, _______, _______,   _______, KC_IMP,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______,   _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,   _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______,   _______, XXXXXXX, KC_CLAW, KC_LPRN, KC_RPRN, KC_GRV,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,   XXXXXXX, _______, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______,   _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_BSLS,                      XXXXXXX, XXXXXXX, _______, _______, _______, _______,   _______, _______, _______, XXXXXXX,
                                                                SCRNCAP, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    /* Raise */
    [_RAISE] = LAYOUT(
        _______, _______, _______, _______,   KC_UNDO, KC_REDO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______,   KC_SFTB, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                      KC_BTN1, KC_PRVWD,KC_UP,   KC_NXTWD,XXXXXXX, KC_DEL,    _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______,   KC_CAPS, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      KC_BTN2, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,   XXXXXXX, _______, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______,   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,                      _______, KC_LSTRT,XXXXXXX, KC_LEND, _______, _______,   _______, _______, _______, XXXXXXX,
                                                                _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    /* Adjust */
    [_ADJUST] = LAYOUT(
        _______, _______, _______, _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______,   _______, _______, XXXXXXX, W_TTHRD, XXXXXXX, _______,                      _______, W_TLEFT, W_THALF, W_TRGHT, XXXXXXX, XXXXXXX,   _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______,   _______, _______, W_LTHRD, W_MAX,   W_RTHRD, _______,                      _______, W_LHALF, W_CENT,  W_RHALF, XXXXXXX, XXXXXXX,   XXXXXXX, _______, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______,   _______, _______, _______, W_BTHRD, _______, _______,                      _______, W_BLEFT, W_BHALF, W_BRGHT, XXXXXXX, XXXXXXX,   _______, _______, _______, XXXXXXX,
                                                            DF(_GAMING), _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    /* Gaming */
    [_GAMING] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,      KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,   KC_EQL,  KC_HOME, KC_END,  XXXXXXX,
        KC_TAB,  KC_H,    KC_W,    KC_E,      KC_R,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_0,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,   KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX,
        KC_LSFT, KC_A,    KC_S,    KC_D,      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,   XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,
        KC_LCTL, KC_0,    XXXXXXX, KC_B,      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,   KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
                                                             DF(_QWERTY),KC_SPC,  XXXXXXX, KC_RAISE, KC_ENT,     KC_SPC, KC_LOWER,KC_MINS, KC_LALT, KC_MUTE
    ),
};

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

        case HYPER:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
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
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch(biton32(layer_state)) {
        case _QWERTY:
        case _GAMING:
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

        // case _ADJUST:
        //     if (clockwise) {
        //         rgblight_step();
        //     } else {
        //         rgblight_step_reverse();
        //     }
        //     break;
        }
        
    } else if (index == 1) {
        switch(biton32(layer_state)) {
        case _QWERTY:
        case _GAMING:
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
        
        // case _ADJUST:
        //     if (clockwise) { 
        //         rgblight_increase_hue();
        //     } else {
        //         rgblight_decrease_hue();
        //     }
        //     break;
        }
    }
    return true;
}


// Runs just one time when the keyboard initializes.
void matrix_scan_user(void) {
    // static bool has_ran_yet = false;
    // if (!has_ran_yet) {
    //     has_ran_yet = true;
    //     rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 3); 
    //     // rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
    //     // rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    //     // rgblight_sethsv(HSV_YELLOW);
    // }
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 750) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
      }
    }
};