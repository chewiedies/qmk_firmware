/*
qmk compile -kb avalanche/rev2 -km default_rev2
qmk flash -kb avalanche/rev2 -km default_rev2
*/

#include QMK_KEYBOARD_H

#ifdef PIMORONI_TRACKBALL_ENABLE
#include "pimoroni_trackball.h"
#endif

enum layer {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMROW,
}; 

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
#ifdef PIMORONI_TRACKBALL_ENABLE
uint8_t MOUSE_BUTTONS;
uint16_t trackball_led_timer;
#endif

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
    // HYPER,
    KC_SFTB,
    // CMDAPP,
    SCRNCAP,
    KC_IMP,
    // KC_FONT,
    KC_CLAW,
    // KC_MDAQ,
    W_LHALF,
    W_RHALF,
    W_THALF,
    W_BHALF,
    // W_LTHRD,
    // W_RTHRD,
    // W_TTHRD,
    // W_BTHRD,
    W_MAX,
    W_CENT,
    // W_LSCRN,
    // W_RSCRN,
    W_TLEFT,
    W_TRGHT,
    W_BLEFT,
    W_BRGHT,
    // W_LRGR,
    // W_SMLR,
    // W_UNDO
};


#define CTLESC MT(MOD_LCTL, KC_ESC)
#define LCAGGRV LCAG_T(KC_GRV)
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
        LCAGGRV, CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LCBR,               KC_RCBR, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,
                 KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_BSPC,               KC_EQL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFTENT,
                                   PSTBRD,  KC_LGUI, KC_RAISE,KC_SPC,  NMRWENT,               NMRWMIN, KC_SPC,  KC_LOWER,KC_RALT, KC_MUTE
    ),
    [_LOWER] = LAYOUT(     
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 KC_IMP , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                 KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        _______, _______, XXXXXXX, KC_CLAW, KC_LPRN, KC_RPRN, XXXXXXX, KC_LBRC,               KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,
                 _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, _______,               _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______,
                                   SCRNCAP, _______, _______, _______, _______,               _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 KC_SFTB, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                                 XXXXXXX, KC_PRVWD,KC_UP,   KC_NXTWD,KC_PLUS, KC_DEL, 
        KC_CAPS, KC_UNDO, KC_REDO, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_LBRC,               KC_RBRC, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, KC_LSTRT,XXXXXXX, KC_LEND, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, _______, _______,               KC_BTN1, KC_BTN2, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(     
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                 XXXXXXX, W_TLEFT, W_THALF, W_TRGHT, XXXXXXX, XXXXXXX,
        RGB_RMOD,RGB_SAD, RGB_SAI, XXXXXXX, W_MAX,   XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, W_LHALF, W_CENT,  W_RHALF, XXXXXXX, XXXXXXX, RGB_MOD,
                 RGB_HUD, RGB_HUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD,             RGB_RMOD, XXXXXXX, W_BLEFT, W_BHALF, W_BRGHT, XXXXXXX, XXXXXXX,
                                   RGB_TOG, _______, XXXXXXX, _______, _______,               _______, _______, XXXXXXX, _______, RGB_TOG
    ),
    [_NUMROW] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,               KC_MINS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______,
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,               _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______
    ),
};

#ifdef PIMORONI_TRACKBALL_ENABLE
void pointing_device_task() {
    report_mouse_t mouse_report = pointing_device_get_report();

    if (layer_state_is(_RAISE)) {
        mouse_report.buttons = MOUSE_BUTTONS;
    }

    trackball_set_timed_rgbw(0,0,0,80);

    if (!is_keyboard_left() || !is_keyboard_master()) {
        process_mouse(&mouse_report);
    }


    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            trackball_set_timed_rgbw(0,0,0,80);
            break;
        case _RAISE:
            trackball_set_rgbw(0,153,95,0);
            break;
        case _LOWER:
             trackball_set_rgbw(153,113,0,0);
            break;
        case _ADJUST:
            trackball_set_rgbw(153,0,110,0);
            break;
        case _NUMROW:
            trackball_set_rgbw(0,73,153,0);
            break;
        default:
            trackball_set_timed_rgbw(0,0,0,80);
    }


    if (layer_state_is(_RAISE)) {
        trackball_set_scrolling(true);
    } else {
        trackball_set_scrolling(false);
    }

    pointing_device_set_report(mouse_report);
    pointing_device_send();
}

#endif


#ifdef OLED_ENABLE

// static void render_logo(void) {
    
//     static const char PROGMEM gimli_logo[] = {
//         // 'gimli-logo', 128x32px
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0x7c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 
//         0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x1c, 0x1c, 0x0c, 0x0c, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x0f, 0x8f, 0x8f, 0xcf, 0xc6, 
//         0x02, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xff, 
//         0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x0f, 0x8f, 0x8f, 0xcf, 0xc6, 0x02, 0x00, 
//         0x18, 0x18, 0xb8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0x78, 0xfc, 0xfe, 0xfe, 0xff, 
//         0xff, 0xff, 0xff, 0xff, 0x7f, 0x7b, 0xf9, 0xf9, 0xf9, 0xf8, 0xf8, 0x78, 0xb8, 0x98, 0x18, 0x08, 
//         0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
//         0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf8, 0xf8, 0xfc, 0x7e, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7e, 0xfc, 0xf8, 0xf8, 0xf0, 
//         0xf0, 0xf8, 0xf8, 0xfc, 0x7e, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 
//         0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 
//         0x00, 0x00, 0xf0, 0xf0, 0xf8, 0xf8, 0x7c, 0x7e, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
//         0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x0f, 0x3f, 0x7f, 0x7f, 
//         0xff, 0xff, 0xff, 0xf7, 0xe7, 0xe7, 0xc7, 0x87, 0x87, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x06, 0x07, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x01, 0x01, 
//         0x01, 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 
//         0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf8, 0xf8, 0x7c, 0x7e, 0x3e, 0x3f, 0x1f, 0x0f, 0x00, 
//         0x00, 0x00, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x3f, 0x3e, 0x3e, 0x3c, 0x3c, 0x3c, 
//         0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x3f, 
//         0x1f, 0x1f, 0x0f, 0x07, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x00, 0x00
//     };
    
//     oled_write_raw_P(gimli_logo, sizeof(gimli_logo));
// }

// static void render_face(void) {
    
//     static const char PROGMEM gimli_face[] = {
//         // 'gimli-face', 32x72px
//         0x3f, 0x3f, 0x1f, 0x1f, 0x8f, 0x8f, 0xcf, 0xc7, 0xc7, 0xc7, 0xc7, 0x01, 0x00, 0x00, 0xf8, 0xf8, 
//         0xf8, 0x00, 0x01, 0x41, 0xe7, 0xc7, 0xc7, 0xc7, 0xc7, 0x8f, 0x8f, 0x1f, 0x1f, 0x3f, 0x7f, 0x7f, 
//         0x1e, 0x1e, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x00, 0x80, 0x30, 0x09, 0x01, 
//         0x09, 0x30, 0x80, 0x00, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x1e, 0x1c, 
//         0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x03, 0x20, 0xcc, 0x11, 0x38, 0x78, 0x44, 
//         0xc4, 0x60, 0x01, 0xcc, 0x20, 0x00, 0x0f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
//         0xff, 0xfe, 0xde, 0xce, 0xce, 0x1e, 0x1e, 0xde, 0xde, 0xde, 0x1e, 0x38, 0x31, 0xb2, 0x92, 0x92, 
//         0x92, 0xb2, 0x39, 0x7c, 0x3e, 0x9e, 0xde, 0xde, 0x5e, 0x1e, 0x8e, 0xce, 0xce, 0xfe, 0xff, 0xfe, 
//         0xf7, 0xef, 0xff, 0xff, 0xff, 0xef, 0xe6, 0xf6, 0xfb, 0xd9, 0x4c, 0x60, 0xff, 0xff, 0xff, 0xff, 
//         0xff, 0xff, 0xff, 0xf4, 0x6c, 0xd9, 0xfb, 0xf3, 0xf6, 0xef, 0xef, 0xff, 0xff, 0xff, 0xe7, 0xf3, 
//         0xf8, 0xf1, 0x01, 0x03, 0x07, 0xe3, 0xf1, 0x71, 0x31, 0x11, 0x18, 0x00, 0x00, 0x01, 0x01, 0x03, 
//         0x03, 0x01, 0x00, 0x00, 0x18, 0x11, 0x31, 0x71, 0xf1, 0xf1, 0xc3, 0x03, 0x01, 0x01, 0xf8, 0xf8, 
//         0x1f, 0x3f, 0x20, 0x00, 0x00, 0x3f, 0x03, 0x00, 0x80, 0x00, 0x00, 0x80, 0xc3, 0xc1, 0xc1, 0x01, 
//         0x83, 0xc1, 0xc1, 0x83, 0x00, 0x00, 0x80, 0x80, 0x01, 0x1f, 0x3f, 0x00, 0x00, 0x3f, 0x3f, 0x1f, 
//         0x1e, 0x00, 0x38, 0x38, 0x9c, 0xc6, 0x60, 0xff, 0xff, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
//         0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xfe, 0x62, 0xce, 0x9c, 0x38, 0x18, 0x00, 0x1f, 
//         0xfe, 0xf8, 0x07, 0x17, 0x13, 0x08, 0x1c, 0x3f, 0x3f, 0x7f, 0xf3, 0x80, 0x1f, 0x7f, 0xff, 0xff, 
//         0xff, 0xff, 0x7f, 0x07, 0xc1, 0x7f, 0x3f, 0x3f, 0x3f, 0x0c, 0x09, 0x17, 0x17, 0x03, 0xfe, 0xfe
//     };
    
//     oled_write_raw_P(gimli_face, sizeof(gimli_face));
// }

static void print_status_narrow(void) {
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
            oled_write_P(PSTR("> C: \\Navigate"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("> C: \\Symbols"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("> C: \\WinMgmnt"), false);
            break;
        case _NUMROW:
            oled_write_P(PSTR("> C: \\NumRow"), false);
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
        return OLED_ROTATION_180;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    // } else {
    //     render_logo();
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

        // case HYPER:
        //     if (record->event.pressed) {
        //         register_code(KC_LGUI);
        //         register_code(KC_LCTL);
        //         register_code(KC_LALT);
        //     } else {
        //         unregister_code(KC_LGUI);
        //         unregister_code(KC_LCTL);
        //         unregister_code(KC_LALT);
        //     }
        //     break;

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

        // case KC_FONT:
        //     if (record->event.pressed) {
        //         SEND_STRING("@include fluid-type(rem-calc(),rem-calc());");
        //         tap_code16(KC_LEFT);
        //         tap_code16(KC_LEFT);
        //         tap_code16(KC_LEFT);
        //     }
        //     break;

        // case KC_MDAQ:
        //     if (record->event.pressed) {
        //         SEND_STRING("@media #{$break}");
        //         tap_code16(KC_LEFT);
        //         tap_code16(KC_LEFT);
        //     }
        //     break;

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

        // case W_LTHRD:
        //     if (record->event.pressed) {
        //         register_code(KC_LALT);
        //         register_code(KC_LCTL);
        //         register_code(KC_LEFT);
        //     } else {
        //         unregister_code(KC_LALT);
        //         unregister_code(KC_LCTL); 
        //         unregister_code(KC_LEFT);
        //     }
        //     break;

        // case W_RTHRD:
        //     if (record->event.pressed) {
        //         register_code(KC_LALT);
        //         register_code(KC_LCTL);
        //         register_code(KC_RGHT);
        //     } else {
        //         unregister_code(KC_LALT);
        //         unregister_code(KC_LCTL);
        //         unregister_code(KC_RGHT);
        //     }
        //     break;

        // case W_TTHRD:
        //     if (record->event.pressed) {
        //         register_code(KC_LALT);
        //         register_code(KC_LCTL);
        //         register_code(KC_UP);
        //     } else {
        //         unregister_code(KC_LALT);
        //         unregister_code(KC_LCTL);
        //         unregister_code(KC_UP);
        //     }
        //     break;

        // case W_BTHRD:
        //     if (record->event.pressed) {
        //         register_code(KC_LALT);
        //         register_code(KC_LCTL);
        //         register_code(KC_DOWN);
        //     } else {
        //         unregister_code(KC_LALT);
        //         unregister_code(KC_LCTL);
        //         unregister_code(KC_DOWN);
        //     }
        //     break;

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

        // case W_LSCRN:
        //     if (record->event.pressed) {
        //         register_code(KC_LGUI);
        //         register_code(KC_LALT);
        //         register_code(KC_LCTL);
        //         register_code(KC_LEFT);
        //     } else {
        //         unregister_code(KC_LGUI);
        //         unregister_code(KC_LALT);
        //         unregister_code(KC_LCTL);
        //         unregister_code(KC_LEFT);
        //     }
        //     break;

        // case W_RSCRN:
        //     if (record->event.pressed) {
        //         register_code(KC_LGUI);
        //         register_code(KC_LALT);
        //         register_code(KC_LCTL);
        //         register_code(KC_RGHT);
        //     } else {
        //         unregister_code(KC_LGUI);
        //         unregister_code(KC_LALT);
        //         unregister_code(KC_LCTL);
        //         unregister_code(KC_RGHT);
        //     }
        //     break;
            
        // case W_UNDO:
        //     if (record->event.pressed) {
        //         register_code(KC_LGUI);
        //         register_code(KC_LALT);
        //         register_code(KC_Z);
        //     } else {
        //         unregister_code(KC_LGUI);
        //         unregister_code(KC_LALT); 
        //         unregister_code(KC_Z);
        //     }
        //     break;
            
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
        // rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 3); 
        // rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv(HSV_PURPLE);
    }
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 750) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
      }
    }
};