#include QMK_KEYBOARD_H

#ifdef PIMORONI_TRACKBALL_ENABLE
#include "drivers/sensors/pimoroni_trackball.h"
#include "pointing_device.h"
#include "color.h"
#endif

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUM
};

#define NUMENT LT(_NUM, KC_ENT)
#define NUMMIN LT(_NUM, KC_MINS)
#define SFTENT MT(MOD_RSFT, KC_ENT)
#define CTLESC MT(MOD_LCTL, KC_ESC)
#define SFTSPC MT(MOD_LSFT, KC_SPC)
// #define LOWER MO(_LOWER)
// #define RAISE MO(_RAISE)
#define ALTTAB  MT(MOD_LALT, KC_TAB)
#define ALTENT  MT(MOD_LALT, KC_ENT)
#define CMDESC  MT(MOD_LGUI, KC_ESC)
#define SFTSPC  MT(MOD_LSFT, KC_SPC)
#define NUMENT  LT(_NUM, KC_ENT)
#define NUMMIN  LT(_NUM, KC_MINS)
#define KCUNDO  LGUI(KC_Z)
#define KCREDO  LGUI(LSFT(KC_Z))
#define SFTTAB  LSFT(KC_TAB)
#define PRVWRD  LALT(KC_LEFT)
#define NXTWRD  LALT(KC_RGHT)
#define LNBEG   LGUI(KC_LEFT)
#define LNEND   LGUI(KC_RGHT)
#define PGTOP   LGUI(KC_UP)
#define PGBOT   LGUI(KC_DOWN)


enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
};

bool is_caps_lock_on;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_rockon(
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_VOLD,            KC_VOLU,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_MINS,            KC_EQL,   KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_LBRC,            KC_RBRC,  KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_BSPC,            KC_DEL,   KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SFTENT,
                        KC_LCTL,  KC_LGUI,  RAISE,    SFTSPC,   NUMENT,             KC_BSPC,  KC_SPC,   LOWER,    ADJUST,   KC_RALT
),


[_LOWER] = LAYOUT_rockon(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_TILD,            KC_PIPE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_UNDS,            KC_PLUS,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
    XXXXXXX,  KC_LPRN,  KC_RPRN,  KC_LBRC,  KC_RBRC,  XXXXXXX,  KC_LCBR,            KC_RCBR,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  KC_EQL,   KC_PLUS,  KC_MINS,  KC_UNDS,  KC_COMM,  KC_DOT,             _______,  XXXXXXX,  KC_TILD,  KC_GRV,   KC_PIPE,  KC_BSLS,  XXXXXXX,
                        _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  XXXXXXX,  _______
),


[_RAISE] = LAYOUT_rockon(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_DEL,
    SFTTAB,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  PGTOP,    PRVWRD,   KC_UP,    NXTWRD,   XXXXXXX,  XXXXXXX,
    KCUNDO,   KCREDO,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LBRC,            KC_RBRC,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_DEL,   KC_BSPC,  XXXXXXX,            XXXXXXX,  PGBOT,    LNBEG,    XXXXXXX,  LNEND,    XXXXXXX,  KC_RSFT,
                        _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______
),


[_ADJUST] =  LAYOUT_rockon(
    XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    RGB_TOG,           RGB_SAI,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   _______,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_RMOD,          RGB_MOD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F11,   KC_F12,   XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_HUD,           RGB_HUI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_VAD,           RGB_VAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                        XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  RGB_SPD,           RGB_SPI,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX
),


[_NUM] =  LAYOUT_rockon(
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     _______,           _______,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    XXXXXXX,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_COLN,  _______,
    _______,  KC_EQL,   KC_PLUS,  KC_MINS,  KC_UNDS,  KC_COMM,  KC_DOT,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
                        _______,  _______,  XXXXXXX,  _______,  XXXXXXX,           XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,   XXXXXXX
)
};

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
    }

    return true;
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
      return OLED_ROTATION_180;
}

static void print_status(void) {
    // oled_write_ln_P(PSTR("\n"), false);
    // Print current mode
    oled_write_ln_P(PSTR("welc0me teenya..."), false);
    // oled_write_ln_P(PSTR("\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("init -kb rockon-v1\n\n"), false);

    // oled_write_ln_P(PSTR("\n"), false);

    // oled_set_cursor(0,12);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Layer: Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Layer: Navigate\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Layer: Symbols\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Layer: Function\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Layer: NumRow\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Layer: Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CAPS"), led_usb_state.caps_lock);
}

bool oled_task_user(void) {
    print_status();
    return false;
}

#endif
