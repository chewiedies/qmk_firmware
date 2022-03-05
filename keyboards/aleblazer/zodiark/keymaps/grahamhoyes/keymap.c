/*
Copyright 2021 Spencer Deven <splitlogicdesign@gmail.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

enum layers {
    _BASE,
    _MAC,
    _LOWER,
    _RAISE,
    _SHIFT,
};

enum custom_keycodes {
    KC_BASE = SAFE_RANGE,
    KC_MAC,
    KC_LOWER,
    KC_RAISE,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
};

// Key overrides for programmer dvorak shifted numbers
const key_override_t pd_perc_override = ko_make_basic(MOD_MASK_SHIFT, KC_AMPR, KC_PERC);
const key_override_t pd_7_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRACKET, KC_7);
const key_override_t pd_5_override = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_5);
const key_override_t pd_3_override = ko_make_basic(MOD_MASK_SHIFT, KC_RCBR, KC_3);
const key_override_t pd_1_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_1);
const key_override_t pd_9_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQUAL, KC_9);
const key_override_t pd_circ_override = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_CIRC);
const key_override_t pd_0_override = ko_make_basic(MOD_MASK_SHIFT, KC_ASTR, KC_0);
const key_override_t pd_2_override = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_2);
const key_override_t pd_4_override = ko_make_basic(MOD_MASK_SHIFT, KC_PLUS, KC_4);
const key_override_t pd_6_override = ko_make_basic(MOD_MASK_SHIFT, KC_RBRACKET, KC_6);
const key_override_t pd_8_override = ko_make_basic(MOD_MASK_SHIFT, KC_EXLM, KC_8);

const key_override_t **key_overrides = (const key_override_t *[]) {
    &pd_perc_override,
    &pd_7_override,
    &pd_5_override,
    &pd_3_override,
    &pd_1_override,
    &pd_9_override,
    &pd_circ_override,
    &pd_0_override,
    &pd_2_override,
    &pd_4_override,
    &pd_6_override,
    &pd_8_override,
    NULL
};

/*
[] = LAYOUT(
    _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ , _______
),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
      KC_AMPR , KC_LBRACKET , KC_LCBR   , KC_RCBR    , KC_LPRN     , KC_EQUAL ,                                         KC_ASTR , KC_RPRN , KC_PLUS , KC_RBRACKET , KC_EXLM  , KC_GRAVE ,
      KC_TAB  , KC_SCOLON   , KC_COMMA  , KC_DOT     , KC_P        , KC_Y     , KC_AT   ,                     KC_BSLS , KC_F    , KC_G    , KC_C    , KC_R        , KC_L     , KC_SLASH ,
      KC_ESC  , KC_A        , KC_O      , KC_E       , KC_U        , KC_I     , KC_HOME ,                     KC_END  , KC_D    , KC_H    , KC_T    , KC_N        , KC_S     , KC_MINUS ,
      KC_LSFT , KC_QUOTE    , KC_Q      , KC_J       , KC_K        , KC_X     , KC_LALT , KC_MUTE , RGB_TOG , KC_LGUI , KC_B    , KC_M    , KC_W    , KC_V        , KC_Z     , KC_RSFT  ,
      KC_LCTL , KC_MEH      , KC_PC_CUT , KC_PC_COPY , KC_PC_PASTE ,            KC_BSPC , KC_DEL  , KC_ENT  , KC_SPC  ,           KC_LEFT , KC_DOWN , KC_UP       , KC_RIGHT , KC_RCTRL
    ),

	[_LOWER] = LAYOUT(
      _______, KC_F1, KC_F2, KC_F3, KC_F4,   KC_F5,                                KC_F6,   KC_F7,   KC_F8, KC_F9, KC_F10, KC_F11,
      KC_PSLS, KC_P7, KC_P8, KC_P9, KC_NLCK, _______, _______,                   _______, _______, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_F12,
      KC_CAPS, KC_P4, KC_P5, KC_P6, KC_NLCK, _______, _______,                   _______, _______, _______, KC_P4, KC_P5, KC_P6, KC_NLCK,
      _______, KC_P1, KC_P2, KC_P3, _______, _______, _______, _______,  _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, _______,
      _______, KC_P0, KC_PDOT, KC_PENT, _______,     _______,  _______,   _______,    _______,   _______, KC_P0, KC_PDOT, KC_PENT, _______
      ),

	[_RAISE] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
      KC_PSLS, KC_P7, KC_P8, KC_P9, KC_NLCK, _______, _______,                    _______, _______, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_F12,
      KC_CAPS, KC_P4, KC_P5, KC_P6, KC_NLCK, _______, _______,                    _______, _______, _______, KC_P4, KC_P5, KC_P6, KC_NLCK,
      _______, KC_P1, KC_P2, KC_P3, _______, _______, _______, _______,  _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, _______,
      _______, KC_P0, KC_PDOT, KC_PENT, _______,    _______,   _______,  _______,    _______,    _______, KC_P0, KC_PDOT, KC_PENT, _______
      ),

};
#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _MAC:
            oled_write_ln_P(PSTR("Mac"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _MAC:
        case _BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    // oled_write_P(PSTR("\n\n"), false);
    // led_t led_usb_state = host_keyboard_led_state();
    // oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_90;
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
        case KC_BASE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE
                );
            }
            return false;
        case KC_MAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MAC);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
              rgblight_step();
        } else {
           rgblight_step_reverse();
        }
    }
    return true;
}

#endif
