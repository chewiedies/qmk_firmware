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

// #define CTLESC MT(MOD_LCTL, KC_ESC)
#define LCAGESC LCAG_T(KC_ESC)
#define RSFTENT RSFT_T(KC_ENT)
#define LCTLCAP LCTL_T(KC_CAPS)
#define NMRWMIN LT(_NUMROW,KC_MINS)
#define NMRWENT LT(_NUMROW,KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *                                     ╭────────╮                                                                         ╭────────╮                             
 *                            ╭────────╯        ╰────────╮                                                       ╭────────╯        ╰────────╮                    
 *                            │        │   E    │        ╰────────╮                                     ╭────────╯        │    I   │        │                    
 *          ╭────────╮────────╯   W    ╰────────╯   R    │        │                                     │        │    U   ╰────────╯    O   ╰────────╭────────╮  
 *          │        │        ╰────────╯        ╰────────╯   T    │                                     │    Y   ╰────────╯        ╰────────╯        │        │  
 *          │  Tab   │   Q    │        │   D    │        ╰────────╯ ╭────────╮               ╭────────╮ ╰────────╯        │    K   │        │    P   │ Bkspce │  
 *          ╰────────╯────────╯   S    ╰────────╯   F    │        │ │        │               │        │ │        │    J   ╰────────╯    L   ╰────────╰────────╯
 * ╭────────│  Esc   │        ╰────────╯        ╰────────╯   G    │ │   {    │               │    }   │ │    H   ╰────────╯    <   ╰────────╯    :   │    "   │────────╮
 * │  ` ~   │ (ctrl) │   A    │        │   C    │        ╰────────╯ ╰────────╯               ╰────────╯ ╰────────╯        │    ,   │    >   │    ;   │    '   │   |    │
 * │ (c/a/g)╰────────╯────────╯   X    ╰────────╯   V    │        │  ╭────────╮             ╭────────╮  │        │    M   ╰────────╯    .   ╰────────╰────────╯   \    │
 * ╰────────│        │        ╰────────╯        ╰────────╯   B    │  │        │             │    +   │  │    N   ╰────────╯        ╰────────╯    ?   │(rShift)│────────╯
 *          │ Shift  │   Z    │                ╭────────╮╰────────╯  │ Bkspce │             │   =    │  ╰────────╯╭────────╮                │    /   │ Enter  │
 *          ╰────────╯────────╯      ╭────────╮│        ╰────────╮   ╰────────╯             ╰────────╯   ╭────────╯        │╭────────╮      ╰────────╰────────╯
 *                                   │ Paste  ││  CMD   │        ╰────────╮                     ╭────────╯        │  ALT   ││        │                           
 *                                   │ Board  │╰────────╯  RSE   │        ╰────────╮   ╭────────╯        │  LWR   ╰────────╯│  Mute  │                           
 *                                   ╰─encodr─╯         ╰────────╯ Space  │ (num)  │   │ (num)  │ Space  ╰────────╯         ╰─encodr─╯                           
 *                                                               ╰────────╯ Enter  │   │  - _   ╰────────╯                                                       
 *                                                                        ╰────────╯   ╰────────╯                                                                
 *
 */
    [_QWERTY] = LAYOUT(                                                                 
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        LCAGESC, KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LCBR,               KC_RCBR, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,
                 KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_BSPC,               KC_EQL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFTENT,
                                   PSTBRD,  KC_LGUI, KC_RAISE,KC_SPC,  NMRWENT,               NMRWMIN, KC_SPC,  KC_LOWER,KC_RALT, KC_MUTE
    ),
    [_LOWER] = LAYOUT(     
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 KC_IMP , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                 KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        KC_CAPS, KC_MDAQ, XXXXXXX, KC_CLAW, KC_LPRN, KC_RPRN, KC_GRV,  KC_LBRC,               KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,
                 _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_TILD, _______,               _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______,
                                   SCRNCAP, KC_FONT, _______, _______, _______,               _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 KC_SFTB, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                                 XXXXXXX, KC_PRVWD,KC_UP,   KC_NXTWD,KC_PLUS, KC_DEL, 
        KC_UNDO, KC_REDO, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_LBRC,               KC_RBRC, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, KC_LSTRT,XXXXXXX, KC_LEND, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, _______, _______,               KC_BTN1, KC_BTN2, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(     
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 RGB_VAD, RGB_VAI, W_SMLR,  W_TTHRD, W_LRGR,  XXXXXXX,                                 XXXXXXX, W_TLEFT, W_THALF, W_TRGHT, XXXXXXX, XXXXXXX,
        RGB_RMOD,RGB_SAD, RGB_SAI, W_LTHRD, W_MAX,   W_RTHRD, XXXXXXX, W_LSCRN,               W_RSCRN, XXXXXXX, W_LHALF, W_CENT,  W_RHALF, XXXXXXX, XXXXXXX, RGB_MOD,
                 RGB_HUD, RGB_HUI, XXXXXXX, W_BTHRD, XXXXXXX, XXXXXXX, RGB_RMOD,             RGB_RMOD, XXXXXXX, W_BLEFT, W_BHALF, W_BRGHT, XXXXXXX, XXXXXXX,
                                   RGB_TOG, _______, XXXXXXX, _______, _______,               _______, _______, XXXXXXX, _______, RGB_TOG
    ),
    [_NUMROW] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,               KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______,
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  _______,               _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______
    ),
};


#ifdef OLED_ENABLE

static void render_logo(void) {

    static const char PROGMEM ava40_logo[] = {
        // 'ava40logo-01', 128x35px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0xfc, 
        0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 
        0xc0, 0xc0, 0x40, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfc, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf0, 0xf8, 0xfc, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xf0, 0x70, 0x70, 0x70, 0x70, 
        0x70, 0x70, 0x70, 0xf0, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfe, 0xff, 0x3f, 0x0f, 0x07, 
        0x0f, 0x3f, 0xff, 0xfe, 0xfc, 0xf0, 0xc0, 0x01, 0x07, 0x1f, 0x7f, 0xff, 0xfe, 0xf8, 0xe0, 0x80, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfc, 0xff, 0xff, 0x7f, 0x1f, 
        0x07, 0x81, 0xe0, 0xf8, 0xfe, 0xff, 0x3f, 0x1f, 0x07, 0x07, 0x1f, 0x7f, 0xff, 0xfc, 0xf0, 0xe0, 
        0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
        0xc0, 0xc0, 0xe0, 0xf0, 0xf8, 0x7c, 0x3e, 0x1f, 0x0f, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
        0x00, 0xe0, 0xf8, 0xfc, 0x3f, 0x0f, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 
        0xc0, 0x80, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x1f, 0x7e, 0xfc, 0xf8, 0xe0, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xfc, 0xff, 0xff, 0x7f, 0x77, 0x73, 0x70, 0x70, 0x70, 0x70, 
        0x70, 0x70, 0x70, 0x73, 0x77, 0x7f, 0x7f, 0xff, 0xfc, 0xf8, 0xe0, 0x81, 0x07, 0x1f, 0x7f, 0xff, 
        0xfe, 0xf8, 0xe0, 0x80, 0x00, 0x80, 0xe0, 0xf8, 0xff, 0xff, 0x3f, 0x1f, 0x07, 0xc1, 0xf0, 0xfc, 
        0xfe, 0xff, 0x7f, 0x7f, 0x73, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x71, 0x77, 0x7f, 0x7f, 
        0xff, 0xfe, 0xf8, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x40, 0x60, 0x70, 0x78, 0x7c, 0x7e, 0x7f, 0x7f, 
        0x7f, 0x7f, 0x7b, 0x79, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0xff, 0xff, 0xff, 0xff, 0xff, 0x78, 
        0x7f, 0xff, 0xff, 0xff, 0xf8, 0xfc, 0xfc, 0xfe, 0xf6, 0x84, 0xce, 0xdf, 0xff, 0xff, 0xff, 0xff, 
        0xfc, 0xf1, 0x83, 0x06, 0x8c, 0x9e, 0x3f, 0xfe, 0xfc, 0xf8, 0xf0, 0xff, 0xff, 0xff, 0x0c, 0x00, 
        0x00, 0x18, 0x1e, 0x1f, 0x1f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1f, 0x1f, 0x1f, 0x1e, 0x18, 0x10, 0x01, 
        0x07, 0x0f, 0x3f, 0xff, 0xff, 0xff, 0x3f, 0x0f, 0x03, 0x00, 0x18, 0x1c, 0x1f, 0x1f, 0x1f, 0x0f, 
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x03, 0x0f, 0x1f, 0x1f, 0x1f, 0x1c, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x3f, 0x3f, 0x3f, 0x1f, 0x00, 
        0x00, 0x01, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
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


// Runs just one time when the keyboard initializes.
void matrix_scan_user(void) {
    static bool has_ran_yet = false;
    if (!has_ran_yet) {
        has_ran_yet = true;
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 3); 
        // rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
        // rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        // rgblight_sethsv(HSV_YELLOW);
    }
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 750) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
      }
    }
};