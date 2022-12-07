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

// #define RAISE MO(_RAISE)
#define SFTSPC  MT(MOD_LSFT, KC_SPC)
#define SFTENT  MT(MOD_LSFT, KC_ENT)
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
    KC_IMP
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_QWERTY] = LAYOUT_wren(
        KC_PSLS, KC_7,    KC_8,    KC_9,      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,   KC_EQL,  KC_HOME, KC_END,  XXXXXXX,
        KC_PAST, KC_4,    KC_5,    KC_6,      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,   KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX,
        KC_PMNS, KC_1,    KC_2,    KC_3,      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,   XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,
        KC_PPLS, KC_0,    KC_DOT,  KC_EQL,    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,   KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
                                                                PSTBRD,  KC_LALT, KC_LGUI, KC_RAISE, SFTENT,     KC_SPC, KC_LOWER,KC_GRV,  KC_LALT, KC_MUTE
    ),

    /* Lower */
    [_LOWER] = LAYOUT_wren(
        _______, _______, _______, _______,   _______, KC_IMP,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______,   _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,   _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______,   _______, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_LBRC,                      KC_RBRC, KC_GRV,  XXXXXXX, KC_DQUO, KC_QUOT, _______,   XXXXXXX, _______, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______,   _______, KC_EQL,  KC_PLUS, KC_MINS, KC_UNDS, XXXXXXX,                      XXXXXXX, KC_TILD, _______, KC_PIPE, KC_BSLS, _______,   _______, _______, _______, XXXXXXX,
                                                                SCRNCAP, _______, _______, _______, _______,    _______, _______, _______, _______, THECLAW
    ),

    /* Raise */
    [_RAISE] = LAYOUT_wren(
        _______, _______, _______, _______,   KCUNDO,  KCREDO,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______,   SFTTAB,  XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                      PGTOP,   PRVWRD,  KC_UP,   NXTWRD,  XXXXXXX, KC_DEL,    _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______,   KC_CAPS, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,   XXXXXXX, _______, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______,   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,                      PGBOT,   LNBEG,   XXXXXXX, LNEND,   _______, _______,   _______, _______, _______, XXXXXXX,
                                                                _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    /* Adjust */
    [_ADJUST] = LAYOUT_wren(
        _______, _______, _______, _______,   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,    _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, KC_F12,    _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,   XXXXXXX, _______, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,   _______, _______, _______, XXXXXXX,
                                                            DF(_GAMING), _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    /* Gaming */
    [_GAMING] = LAYOUT_wren(
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

        case KC_IMP:
            if (record->event.pressed) {
                SEND_STRING("!important");
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
