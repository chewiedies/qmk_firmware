#include QMK_KEYBOARD_H

#ifdef PIMORONI_TRACKBALL_ENABLE
#include "drivers/sensors/pimoroni_trackball.h"
#include "pointing_device.h"
#include "color.h"
#endif

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
    _NUM
};

#define ALTTAB  MT(MOD_LALT, KC_TAB)
#define CMDESC  MT(MOD_LGUI, KC_ESC)
#define SFTSPC  MT(MOD_LSFT, KC_SPC)
#define SFTENT  MT(MOD_LSFT, KC_ENT)
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
#define PSTBRD  LGUI(LALT(KC_V))
#define SCRNCAP LCTL(LGUI(LSFT(KC_4)))
#define CALCAPP LCTL(LGUI(LSFT(KC_C)))
#define GITAPP  LCTL(LGUI(LSFT(KC_G)))
#define THECLAW LCMD(LSFT(LALT(KC_S)))
#define W_LHALF LCTL(LGUI(KC_LEFT))
#define W_RHALF LCTL(LGUI(KC_RGHT))
#define W_THALF LCTL(LGUI(KC_UP))
#define W_BHALF LCTL(LGUI(KC_DOWN))
#define W_LTHRD LCTL(LALT(KC_LEFT))
#define W_RTHRD LCTL(LALT(KC_RGHT))
#define W_TTHRD LCTL(LALT(KC_UP))
#define W_BTHRD LCTL(LALT(KC_DOWN))
#define W_MAX   LCTL(LALT(LGUI(KC_F)))
#define W_CENT  LALT(LGUI(KC_C))
#define W_SHOW  LCTL(KC_DOWN)

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    KC_IMP
};

bool is_caps_lock_on;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* _QWERTY Keymap
 *                                    ┌───────┐                                                                          ┌───────┐
 *                                    │   #   ├───────┐                                                          ┌───────┤   *   │
 *                            ┌───────┤   3   │   $   ├───────┐                                          ┌───────┤   &   │   8   ├───────┐
 *           ┌────────┬───────┤   @   ├───────┤   4   │   %   ├───────┐                          ┌───────┤   ^   │   7   ├───────┤   (   ├───────┬─────────┐
 *           │        │   !   │   2   │       ├───────┤   5   │   -   │                          │   +   │   6   ├───────┤       │   9   │   )   │         │
 *           │  ESC   │   1   ├───────┤   E   │       ├───────┤   __  │                          │   =   ├───────┤       │   I   ├───────┤   0   │(Adjust) │
 *           ├────────┼───────┤       ├───────┤   R   │       ├───────┤                          ├───────┤       │   U   ├───────┤       ├───────┼─────────┤
 *           │        │       │   W   │       ├───────┤   T   │   ~   │                          │   |   │   Y   ├───────┤       │   O   │       │         │
 *           │  TAB   │   Q   ├───────┤   D   │       ├───────┤   `   │                          │   \   ├───────┤       │   K   ├───────┤   P   │ Bkspace │
 *           ├────────┼───────┤       ├───────┤   F   │       ├───────┤                          ├───────┤       │   J   ├───────┤       ├───────┼─────────┤
 *           │  ESC   │       │   S   │       ├───────┤   G   │       │                          │       │   H   ├───────┤   <   │   L   │   :   │    "    │
 *           │ (CMD)  │   A   ├───────┤   C   │       ├───────┤   {   │                          │   }   ├───────┤       │   ,   ├───────┤   ;   │    '    │
 *           ├────────┼───────┤       ├───────┤   V   │       ├───────┤                          ├───────┤       │   M   ├───────┤   >   ├───────┼─────────┤
 *           │        │       │   X   │       ├───────┤   B   │ MS    │                          │  MS   │   N   ├───────┤       │   .   │   ?   │  Enter  │
 *           │ (CTRL) │   Z   ├───────┤ (ALT) │       ├───────┤ LCLK  │                          │  RCLK ├───────┤       │ (ALT) ├───────┤   /   │ (Shift) │
 *           └────────┴───────┤       ├───────┤ (RSE) │ Space ├───────┤                          ├───────┤       │ (LWR) ├───────┤       ├───────┴─────────┘
 *                            │       │       └───────┤(Shift)│ Enter │                          │  -_   │ Space ├───────┘       │  Mute │
 *                            └───⍥───┘               └───────┤(NUMRW)│                          │(NUMRW)├───────┘               └───⍥───┘
 *                                                            └───────┘                          └───────┘
 */

[_QWERTY] = LAYOUT_rockon_bp(
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_MINS,                          KC_EQL,    KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_GRV,
    ALTTAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_BSPC,                          KC_BSLS,   KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    CMDESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_LCBR,                          KC_RCBR,   KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_BTN1,                          KC_BTN2,   KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SFTENT,
                        XXXXXXX,  KC_LALT,  RAISE,    SFTSPC,   NUMENT,    PSTBRD,     KC_MUTE,   NUMMIN,    KC_SPC,   LOWER,    KC_RALT,  XXXXXXX
),




/* _LOWER Keymap
 *                                    ┌───────┐                                                                          ┌───────┐
 *                                    │       ├───────┐                                                          ┌───────┤       │
 *                            ┌───────┤       │       ├───────┐                                          ┌───────┤       │       ├───────┐
 *           ┌────────┬───────┤       ├───────┤       │       ├───────┐                          ┌───────┤       │       ├───────┤       ├───────┬─────────┐
 *           │        │!import│       │       ├───────┤       │       │                          │       │       ├───────┤       │       │       │         │
 *           │        │    ant├───────┤   #   │       ├───────┤   _   │                          │   +   ├───────┤       │   *   ├───────┤       │(Adjust) │
 *           ├────────┼───────┤       ├───────┤   $   │       ├───────┤                          ├───────┤       │   &   ├───────┤       ├───────┼─────────┤
 *           │        │       │   @   │       ├───────┤   %   │       │                          │       │   ^   ├───────┤       │   (   │       │         │
 *           │        │   !   ├───────┤   (   │       ├───────┤   ~   │                          │   |   ├───────┤       │       ├───────┤   )   │ Bkspace │
 *           ├────────┼───────┤ Save4 ├───────┤   )   │       ├───────┤                          ├───────┤       │   `   ├───────┤       ├───────┼─────────┤
 *           │        │       │  Web  │       ├───────┤       │       │                          │       │   =   ├───────┤       │       │       │    "    │
 *           │  CAPS  │       ├───────┤   {   │       ├───────┤   [   │                          │   ]   ├───────┤       │       ├───────┤       │    '    │
 *           ├────────┼───────┤       ├───────┤   }   │       ├───────┤                          ├───────┤       │   ~   ├───────┤       ├───────┼─────────┤
 *           │        │       │       │       ├───────┤       │ MS    │                          │  MS   │   +   ├───────┤       │       │   |   │         │
 *           │        │       ├───────┤ (ALT) │       ├───────┤ LCLK  │                          │  RCLK ├───────┤       │       ├───────┤   \   │         │
 *           └────────┴───────┤ Scrn  ├───────┤ (RSE) │ Space ├───────┤                          ├───────┤       │ (LWR) ├───────┤       ├───────┴─────────┘
 *                            │ Grab  │       └───────┤(Shift)│       │                          │  -_   │ Space ├───────┘       │       │
 *                            └───⍥───┘               └───────┤(NUMRW)│                          │(NUMRW)├───────┘               └───⍥───┘
 *                                                            └───────┘                          └───────┘
 */
[_LOWER] = LAYOUT_rockon_bp(
    XXXXXXX,  KC_IMP,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_UNDS,                          KC_PLUS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_TILD,                          KC_PIPE,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
    KC_CAPS,  XXXXXXX,  THECLAW,  KC_LPRN,  KC_RPRN,  XXXXXXX,  KC_LBRC,                          KC_RBRC,  KC_EQL,   KC_GRV,   XXXXXXX,  XXXXXXX,  _______,  _______,
    _______,  XXXXXXX,  XXXXXXX,  KC_LCBR,  KC_RCBR,  XXXXXXX,  _______,                          _______,  KC_PLUS,  KC_TILD,  XXXXXXX,  XXXXXXX,  KC_BSLS,  XXXXXXX,
                        XXXXXXX,  _______,  _______,  _______,  _______,   SCRNCAP,    GITAPP,    _______,  _______,  _______,  _______,  XXXXXXX
),

/* _RAISE Keymap
 *                                    ┌───────┐                                                                          ┌───────┐
 *                                    │       ├───────┐                                                          ┌───────┤       │
 *                            ┌───────┤       │       ├───────┐                                          ┌───────┤       │       ├───────┐
 *           ┌────────┬───────┤       ├───────┤       │       ├───────┐                          ┌───────┤       │       ├───────┤       ├───────┬─────────┐
 *           │        │       │       │       ├───────┤       │       │                          │       │       ├───────┤       │       │       │         │
 *           │        │       ├───────┤       │       ├───────┤       │                          │       ├───────┤ Prev  │  Up   ├───────┤       │         │
 *           ├────────┼───────┤       ├───────┤       │       ├───────┤                          ├───────┤ Page  │ Word  ├───────┤ Next  ├───────┼─────────┤
 *           │ SHIFT/ │       │       │       ├───────┤       │       │                          │       │ Top   ├───────┤       │ Word  │       │         │
 *           │  TAB   │       ├───────┤       │       ├───────┤       │                          │       ├───────┤       │ Down  ├───────┤       │ Delete  │
 *           ├────────┼───────┤       ├───────┤       │       ├───────┤                          ├───────┤       │ Left  ├───────┤       ├───────┼─────────┤
 *           │        │       │       │       ├───────┤       │       │                          │       │       ├───────┤       │ Right │       │         │
 *           │ UNDO   │ REDO  ├───────┤       │       ├───────┤       │                          │       ├───────┤ Line  │       ├───────┤       │         │
 *           ├────────┼───────┤       ├───────┤       │       ├───────┤                          ├───────┤ Page  │ Beg   ├───────┤ Line  ├───────┼─────────┤
 *           │        │       │       │       ├───────┤       │       │                          │       │ Bot   ├───────┤       │ End   │       │ (Shift) │
 *           │ (CTRL) │       ├───────┤ (ALT) │       ├───────┤       │                          │       ├───────┤       │ (ALT) ├───────┤       │  Enter  │
 *           └────────┴───────┤       ├───────┤ (RSE) │ Space ├───────┤                          ├───────┤       │ (LWR) ├───────┤       ├───────┴─────────┘
 *                            │       │       └───────┤(Shift)│       │                          │  -_   │ Space ├───────┘       │       │
 *                            └───⍥───┘               └───────┤(NUMRW)│                          │(NUMRW)├───────┘               └───⍥───┘
 *                                                            └───────┘                          └───────┘
 */

[_RAISE] = LAYOUT_rockon_bp(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    SFTTAB,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                          XXXXXXX,  PGTOP,    PRVWRD,   KC_UP,    NXTWRD,   XXXXXXX,  KC_DEL,
    KCUNDO,   KCREDO,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                          XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSPC,  KC_DEL,                           XXXXXXX,  PGBOT,    LNBEG,    XXXXXXX,  LNEND,    XXXXXXX,  _______,
                        _______,  _______,  _______,  _______,  _______,   KC_BTN1,    KC_BTN2,   _______,  _______,  _______,  _______,  _______
),


/* _ADJUST Keymap
 *                                    ┌───────┐                                                                          ┌───────┐
 *                                    │       ├───────┐                                                          ┌───────┤       │
 *                            ┌───────┤  F3   │       ├───────┐                                          ┌───────┤       │  F8   ├───────┐
 *           ┌────────┬───────┤       ├───────┤  F4   │       ├───────┐                          ┌───────┤       │  F7   ├───────┤       ├───────┬─────────┐
 *           │        │       │  F2   │ W Top ├───────┤  F5   │  RGB  │                          │ RGB   │  F6   ├───────┤ W Top │  F9   │       │         │
 *           │ RESET  │  F1   ├───────┤ Third │       ├───────┤  I/O  │                          │ SAT+  ├───────┤       │ Half  ├───────┤  F10  │(Adjust) │
 *           ├────────┼───────┤ Show  ├───────┤       │       ├───────┤                          ├───────┤       │       ├───────┤       ├───────┼─────────┤
 *           │        │       │ Wndws │ W Ful ├───────┤       │  RGB  │                          │ RGB   │       ├───────┤ W     │  F11  │       │         │
 *           │        │       ├───────┤ Scrn  │ W Rght├───────┤  STEP-│                          │ STEP+ ├───────┤ W Lft │ Cntr  ├───────┤  F12  │         │
 *           ├────────┼───────┤ W Lft ├───────┤ Third │       ├───────┤                          ├───────┤       │ Half  ├───────┤ W Rght├───────┼─────────┤
 *           │        │       │ Third │ W Bot ├───────┤       │  RGB  │                          │ RGB   │       ├───────┤ W Bot │ Half  │       │         │
 *           │        │       ├───────┤ Third │       ├───────┤  HUE- │                          │ HUE+  ├───────┤       │ Half  ├───────┤       │         │
 *           ├────────┼───────┤       ├───────┤       │       ├───────┤                          ├───────┤       │       ├───────┤       ├───────┼─────────┤
 *           │        │       │       │       ├───────┤       │  RGB  │                          │ RGB   │       ├───────┤       │       │       │         │
 *           │ (CTRL) │       ├───────┤ (ALT) │       ├───────┤  VAL- │                          │ VAL+  ├───────┤       │ (ALT) ├───────┤       │         │
 *           └────────┴───────┤       ├───────┤ (RSE) │ Space ├───────┤                          ├───────┤       │ (LWR) ├───────┤       ├───────┴─────────┘
 *                            │       │       └───────┤(Shift)│  RGB  │                          │ RGB   │ Space ├───────┘       │       │
 *                            └───⍥───┘               └───────┤  SPD- │                          │ SPD+  ├───────┘               └───⍥───┘
 *                                                            └───────┘                          └───────┘
 */
[_ADJUST] = LAYOUT_rockon_bp(
    RESET,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    RGB_TOG,                          RGB_SAI,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   _______,
    XXXXXXX,  XXXXXXX,  W_SHOW,   W_TTHRD,  XXXXXXX,  XXXXXXX,  RGB_RMOD,                         RGB_MOD,  XXXXXXX,  XXXXXXX,  W_THALF,  KC_F11,   KC_F12,   XXXXXXX,
    XXXXXXX,  XXXXXXX,  W_LTHRD,  W_MAX,    W_RTHRD,  XXXXXXX,  RGB_HUD,                          RGB_HUI,  XXXXXXX,  W_LHALF,  W_CENT,   W_RHALF,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  W_BTHRD,  XXXXXXX,  XXXXXXX,  RGB_VAD,                          RGB_VAI,  XXXXXXX,  XXXXXXX,  W_BHALF,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                        XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  RGB_SPD,   _______,    _______,   RGB_SPI,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX
),



/*
 *  _NUM Keymap
 *                                    ┌───────┐                                                                          ┌───────┐
 *                                    │       ├───────┐                                                          ┌───────┤       │
 *                            ┌───────┤       │       ├───────┐                                          ┌───────┤       │       ├───────┐
 *           ┌────────┬───────┤       ├───────┤       │       ├───────┐                          ┌───────┤       │       ├───────┤       ├───────┬─────────┐
 *           │        │       │       │       ├───────┤       │       │                          │       │       ├───────┤       │       │       │         │
 *           │        │       ├───────┤   3   │       ├───────┤   -   │                          │   =   ├───────┤       │   8   ├───────┤       │         │
 *           ├────────┼───────┤       ├───────┤   4   │       ├───────┤                          ├───────┤       │   7   ├───────┤       ├───────┼─────────┤
 *           │        │       │   2   │       ├───────┤   5   │       │                          │       │   6   ├───────┤       │   9   │       │         │
 *           │        │   1   ├───────┤   8   │       ├───────┤   +   │                          │       ├───────┤       │       ├───────┤   0   │ Bkspace │
 *           ├────────┼───────┤       ├───────┤   9   │       ├───────┤                          ├───────┤       │       ├───────┤       ├───────┼─────────┤
 *           │        │       │   7   │       ├───────┤   0   │       │                          │       │       ├───────┤       │       │       │    "    │
 *           │        │   6   ├───────┤       │       ├───────┤   =   │                          │       ├───────┤       │       ├───────┤   :   │    '    │
 *           ├────────┼───────┤       ├───────┤   ,   │       ├───────┤                          ├───────┤       │       ├───────┤       ├───────┼─────────┤
 *           │        │       │       │       ├───────┤   .   │       │                          │       │       ├───────┤       │       │       │         │
 *           │        │       ├───────┤ (ALT) │       ├───────┤       │                          │       ├───────┤       │ (ALT) ├───────┤       │  Enter  │
 *           └────────┴───────┤       ├───────┤ (RSE) │ Space ├───────┤                          ├───────┤       │ (LWR) ├───────┤       ├───────┴─────────┘
 *                            │       │       └───────┤(Shift)│ Enter │                          │  -_   │ Space ├───────┘       │       │
 *                            └───⍥───┘               └───────┤(NUMRW)│                          │(NUMRW)├───────┘               └───⍥───┘
 *                                                            └───────┘                          └───────┘
 */
[_NUM] = LAYOUT_rockon_bp(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MINS,                          KC_EQL,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
    XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_PLUS,                          XXXXXXX,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    XXXXXXX,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_EQL,                           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_COLN,  _______,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_COMM,  KC_DOT,   XXXXXXX,                          XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,
                        _______,  _______,  _______,  _______,  _______,   CALCAPP,    CALCAPP,   _______,  _______,  _______,  _______,  _______
)
};


// Key Overrides
const key_override_t lcurlybrace_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_LBRC);
const key_override_t rcurlybrace_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_RCBR, KC_RBRC);


// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &lcurlybrace_key_override,
    &rcurlybrace_key_override,
    NULL // Null terminate the array of overrides!
};


// Two Encoder Support
#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {  // LEFT ENCODER
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
                register_code16(KC_LGUI);
                tap_code(KC_GRV);
                unregister_code16(KC_LGUI);
            } else {
                register_code16(KC_LGUI);
                register_code16(KC_LSFT);
                tap_code(KC_GRV);
                unregister_code16(KC_LGUI);
                unregister_code16(KC_LSFT);
            }
            break;

        case _RAISE:
            if (clockwise) {
                rgb_matrix_step();
            } else {
                rgb_matrix_step_reverse();
            }
            break;

        case _ADJUST:
            if (clockwise) {
                rgb_matrix_increase_hue();
            } else {
                rgb_matrix_decrease_hue();
            }
            break;
        }
    } else if (index == 1) {  // RIGHT ENCODER
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
        // case _LOWER:
        //     if (clockwise) {

        //     } else {

        //     }
        //     break;
        case _ADJUST:
            if (clockwise) {
                rgb_matrix_increase_val();
            } else {
                rgb_matrix_decrease_val();
            }
            break;
        }
    }
    return true;
}

#endif


void keyboard_post_init_user(void) {
    is_caps_lock_on = false;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CAPSLOCK:
            if (record->event.pressed) {
                if (is_caps_lock_on) {
                    is_caps_lock_on = false;
                } else {
                    is_caps_lock_on = true;
                }
            }
            break;
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
    }

    return true;
}


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
      return OLED_ROTATION_180;
}

static void print_status(void) {
    oled_write_ln_P(PSTR("\n"), false);
    // Print current mode
    oled_write_ln_P(PSTR("welc0me chewiedies..."), false);
    oled_write_ln_P(PSTR("\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("init -kb rockon_bp-v1"), false);

    oled_write_ln_P(PSTR("\n"), false);

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
        case _NUM:
            oled_write_P(PSTR("> C:\\NumRow"), false);
            break;
        default:
            oled_write_ln_P(PSTR("> C: \\Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

bool oled_task_user(void) {
    print_status();
    return true;
}

#endif


// Runs just one time when the keyboard initializes.
void matrix_scan_user(void) {
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 750) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
      }
    }
};
