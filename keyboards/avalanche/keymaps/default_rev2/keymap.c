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
    W_BRGHT,
    W_LRGR,
    W_SMLR,
    W_UNDO
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
                 KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
                 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_GRV,  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LCBR,   KC_RCBR, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_MUTE,
                 KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_BSPC,   KC_EQL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
                                   PSTBRD,  KC_LGUI, KC_RAISE,KC_SPC,  KC_ENT,    KC_MINS, KC_SPC,  KC_LOWER,KC_RALT, KC_MUTE
    ),
    [_LOWER] = LAYOUT(
                 KC_IMP,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                 _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        KC_MDAQ, _______, XXXXXXX, KC_CLAW, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC,   KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_F12,
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,   _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______,
                                   SCRNCAP, KC_FONT, _______, _______, _______,   _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
                 KC_UNDO, KC_REDO, _______, _______, _______, _______,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 KC_SFTB, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_PRVWD,KC_UP,   KC_NXTWD,KC_PLUS, KC_DEL, 
_______, LCTL_T(KC_CAPS), XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_LBRC,   KC_RBRC, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, XXXXXXX, KC_CUT,  KC_COPY, KC_PASTE,XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, KC_LSTRT,XXXXXXX, KC_LEND, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, _______, _______,   KC_BTN1, KC_BTN2, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD,                     RGB_VAI, RGB_SAI, RGB_HUI, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, W_SMLR,  W_TTHRD, W_LRGR,  XXXXXXX,                     XXXXXXX, W_TLEFT, W_THALF, W_TRGHT, XXXXXXX, XXXXXXX,
        RGB_RMOD,XXXXXXX, XXXXXXX, W_LTHRD, W_MAX,   W_RTHRD, XXXXXXX, W_LSCRN,   W_RSCRN, XXXXXXX, W_LHALF, W_CENT,  W_RHALF, XXXXXXX, XXXXXXX, RGB_MOD,
                 XXXXXXX, XXXXXXX, XXXXXXX, W_BTHRD, XXXXXXX, XXXXXXX, RGB_RMOD,  RGB_MOD, XXXXXXX, W_BLEFT, W_BHALF, W_BRGHT, XXXXXXX, XXXXXXX,
                                   _______, _______, XXXXXXX, _______, _______,   _______, _______, XXXXXXX, _______, _______
    ),
};


#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
    // static const char PROGMEM qmk_logo[] = {
    //     0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    //     0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    //     0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    // };
    // oled_write_P(qmk_logo, false);
    
    static const char PROGMEM avalanche_logo[] = {
        // 'avalanche-logo', 128x32px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 
        0x80, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x40, 0xc0, 0xc0, 0xc0, 
        0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 
        0xe0, 0x00, 0x60, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
        0xc0, 0x00, 0x00, 0x40, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
        0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 
        0xfe, 0xfe, 0x02, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xfc, 0xff, 0xff, 0xff, 0x3f, 
        0x8f, 0xe3, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xfe, 0xe0, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xfb, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x07, 0x07, 0x07, 0x07, 0x7f, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xe3, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x7e, 0xfe, 0xfe, 0xfe, 
        0xfe, 0xfe, 0xfe, 0x3e, 0x3c, 0x3c, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0xe3, 0xf8, 0xfe, 
        0xff, 0xff, 0xff, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xef, 0xe0, 0xe0, 0xe0, 0xe0, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x3f, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0x0f, 0x3f, 0x7f, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xe0, 0xc0, 0xc0, 0xc0, 0xc7, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0x3f, 0xff, 
        0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf8, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x20, 0x38, 0x3c, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x07, 0x01, 0x08, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
        0x0f, 0x07, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x01, 0x04, 0x07, 0x07, 0x07, 0x07, 
        0x07, 0x03, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
        0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 
        0x03, 0x03, 0x03, 0x02, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 
        0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x00, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x01, 
        0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x3e, 0x3c, 0x30, 0x00, 0x00
    };
    
    oled_write_raw_P(avalanche_logo, sizeof(avalanche_logo));
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR("MAC"), false);

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
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
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
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
                SEND_STRING("@media #{$break}");
                tap_code16(KC_LEFT);
                tap_code16(KC_LEFT);
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
void encoder_update_user(uint8_t index, bool clockwise) {
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
}

// Runs just one time when the keyboard initializes.
void matrix_scan_user(void) {
    static bool has_ran_yet = false;
    if (!has_ran_yet) {
        has_ran_yet = true;
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 3); 
        // rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
        // rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        // rgblight_sethsv(HSV_TEAL);
    }
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 750) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
      }
    }
};