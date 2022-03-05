#include QMK_KEYBOARD_H

#ifdef ENCODER_ENABLE
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
#endif

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUM,
};

// #define LOWER MO(_LOWER)
// #define RAISE MO(_RAISE)
#define ALTTAB MT(MOD_LALT, KC_TAB)
#define ALTENT MT(MOD_LALT, KC_ENT)
#define CMDESC MT(MOD_LGUI, KC_ESC)
#define SFTSPC MT(MOD_LSFT, KC_SPC)
#define SFTENT MT(MOD_LSFT, KC_ENT)
#define NUMENT LT(_NUM, KC_ENT)
#define NUMMIN LT(_NUM, KC_MINS)

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_TOPP,
    KC_BOTP,
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
    // W_LSCRN,
    // W_RSCRN,
    // W_TLEFT,
    // W_TRGHT,
    // W_BLEFT,
    // W_BRGHT,
    // W_LRGR,
    // W_SMLR,
    // W_UNDO
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * | ALT/ |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * | TAB  |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * | ESC/ |   A  |   S  |   D  |   F  |   G  |   |ALTTAB|  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * | CMD  |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * | CTL  |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  | SFT  |
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT_ffkb(
    ALTTAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,              KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,     KC_BSPC,
    CMDESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,              KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
    KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,              KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  ALTENT,
                        KC_MUTE,  RAISE,    SFTSPC,   NUMENT,            NUMMIN,  KC_SPC,   LOWER,    LCTL(KC_BSPC),
                                                                KC_MUTE
),


/* Raise
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |      |
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * | Home | Left | Down |  Up  | Right| End  |   |ALTTAB|  |      |   -  |   =  |   [  |   ]  |      |
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * |      |      | PgDn | PgUp |      |      |             |      |      |      |      |      |      |
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

[_RAISE] = LAYOUT_ffkb(
    KC_SFTB,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           KC_TOPP,  KC_PRVWD, KC_UP,    KC_NXTWD, XXXXXXX,  KC_DEL,
    KC_UNDO,  KC_REDO,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,
    KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSPC,           KC_BOTP,  KC_LSTRT, XXXXXXX,  KC_LEND,  XXXXXXX,  KC_RSFT,
                        _______,  _______,  _______,  _______,           _______,  _______,  _______,  _______,
                                                                _______
),


/* Lower
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |ALTTAB|  |      |   _  |   +  |   {  |   }  |      |
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * |      |  Caps|      |      |      |      |             |      |      |      |   |  |   "  |      |
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_LOWER] = LAYOUT_ffkb(
    XXXXXXX,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,           KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
    KC_IMP,   XXXXXXX,  KC_CLAW,  KC_LPRN,  KC_RPRN,  KC_LCBR,           KC_RCBR,  KC_PLUS,  KC_EQL,   KC_GRV,   KC_BSLS,  XXXXXXX,
    KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LBRC,           KC_RBRC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                        SCRNCAP,  _______,  _______,  _______,           _______,  _______,  _______,  XXXXXXX,
                                                                _______
),


/* Adjust
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |ALTTAB|  |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * |      |  Caps|      |      |      |      |             |      |      |      |   |  |   "  |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_ADJUST] = LAYOUT_ffkb(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  W_TTHRD,  XXXXXXX,  RGB_RMOD,          RGB_MOD,  XXXXXXX,  W_THALF,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  W_LTHRD,  W_MAX,    W_RTHRD,  RGB_HUD,           RGB_HUI,  W_LHALF,  W_CENT,   W_RHALF,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  W_BTHRD,  XXXXXXX,  RGB_VAD,           RGB_VAI,  XXXXXXX,  W_BHALF,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                        XXXXXXX,  _______,  XXXXXXX,  RGB_SPD,           RGB_SPI,  XXXXXXX,  _______,  XXXXXXX,
                                                                RGB_TOG
),


/* Numrow

 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |             |  6   |  7   |  8   |  9   |  0   |      |
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * |      |   6  |   7  |   8  |   9  |   0  |   |ALTTAB|  |      |      |      |      |      |      |
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_NUM] =  LAYOUT_ffkb(
    XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,              KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    XXXXXXX,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,
    KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_COMM,  KC_DOT,            XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,
                        _______,  _______,  _______,  _______,           _______,  _______,  _______,  _______,
                                                                _______
)
};



// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
        case KC_IMP:
            if (record->event.pressed) {
                SEND_STRING(" !important;");
            } else {

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
        case KC_TOPP:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_UP);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_UP);
            }
            break;
        case KC_BOTP:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_DOWN);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_DOWN);
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
    }

    return true;
}


// Three Encoder Support
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
    } else if (index == 2) {
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

        case _LOWER:
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

#endif

// #ifdef OLED_ENABLE


// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//       return OLED_ROTATION_180;
// }


// // Commenting out logo as it takes up a lot of space :(
// static void render_logo(void) {
//     // ffkb logo, 128x64px
//     static const char PROGMEM ffkb_logo[] = {
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xe0, 0xc0, 0x80,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x80, 0xc0, 0xe0, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
//   0xfe, 0x02, 0x02, 0x02, 0x82, 0x06, 0x0e, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xfe, 0xff, 0xff, 0x0f, 0x07, 0x0f, 0x1f,
//   0x3e, 0x7c, 0xf8, 0xf0, 0xe0, 0xc0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
//   0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xc0, 0xe0, 0xf0, 0xf8, 0x7c, 0x3e,
//   0x1f, 0x0f, 0x07, 0x0f, 0xff, 0xff, 0xfe, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x02, 0x82,
//   0x82, 0xc2, 0xe2, 0xde, 0x0e, 0x0e, 0x06, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//   0xff, 0x02, 0x02, 0x07, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xe0, 0xf8, 0xfc, 0x7e,
//   0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03, 0x07, 0x0f, 0x1f, 0x3f,
//   0x7e, 0xfc, 0xf8, 0xe0, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x1f,
//   0x7f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
//   0x07, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xf0, 0xf8, 0xff, 0x7f, 0x1f, 0x87, 0x83, 0x80, 0x80,
//   0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
//   0x80, 0x80, 0x83, 0x87, 0x1f, 0x7f, 0xff, 0xf8, 0xf0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x04, 0x04,
//   0x04, 0x05, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0,
//   0xe0, 0x20, 0x20, 0x20, 0x20, 0x60, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x08, 0x18, 0x3c, 0x3e, 0x7f, 0xff, 0xff, 0xff, 0xef, 0xcf, 0x8f, 0x87, 0x07, 0x07, 0x07, 0x07,
//   0x07, 0xe7, 0xe7, 0xe7, 0xc7, 0x07, 0x07, 0x0f, 0x3f, 0xfe, 0xfc, 0xf0, 0xc0, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfc, 0xfe, 0x3f, 0x0f, 0x07, 0x07, 0xc7, 0xe7, 0xe7, 0xe7, 0x07,
//   0x07, 0x07, 0x07, 0x07, 0x87, 0x8f, 0xcf, 0xef, 0xef, 0xff, 0xff, 0x7f, 0x3e, 0x3c, 0x18, 0x08,
//   0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x20, 0x20,
//   0x60, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//   0xff, 0x20, 0x20, 0x70, 0xf8, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0f, 0x1f, 0x1e, 0x3e, 0x7c,
//   0xf8, 0xf1, 0xf1, 0xe1, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00,
//   0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe1, 0xf1, 0xf1, 0xf8,
//   0x7c, 0x3e, 0x1e, 0x1f, 0x0f, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x20, 0x20,
//   0x20, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xcf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
//   0x7f, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7e, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3c, 0x3c,
//   0x3c, 0x3c, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x7e, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x40, 0x40,
//   0x40, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x0e,
//   0x0e, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

// };
//     oled_write_raw_P(ffkb_logo, sizeof(ffkb_logo));

// }

// void oled_task_user(void) {
//     // If you don't want to display the logo, switch
//     if (false) {
//         //render_status();
//     } else if (true) {
//         render_logo();
//     } else {
//         //render_logo_text();
//     }
// }

// #endif


// Runs just one time when the keyboard initializes.
void matrix_scan_user(void) {
    // static bool has_ran_yet = false;
    // if (!has_ran_yet) {
        // has_ran_yet = true;
        // rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);
        // rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
        // rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        // rgblight_sethsv(HSV_CHARTREUSE);
    // }
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 750) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
      }
    }
};
