#include QMK_KEYBOARD_H
// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _NUMPAD,
    _TUNES,
    _MACRO,
    _RGB,
    _DFU
};

// Custom keycodes
enum custom_keycodes {
    FLUIDT = SAFE_RANGE,
    REMCALC,
    MQUERY,
    MQUERY2,
    USSSHP,
    LASTPASS,
    FMPASS,
    CALCAPP,
    YTMAPP,
    CMDAPP,
    BSPREV,
    BSNEXT,
    BSPAUS,
    BSTHDWN,
    BSTHUP,
    SRVRIP,
    SRVRIP2,
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

// How long (in milliseconds) to wait between animation steps for each of the "Solid color breathing" animations
const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {15, 7.5, 3.25, 1.125};

// How long (in milliseconds) to wait between animation steps for each of the "Swirling rainbow" animations
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {50, 25, 12.5};


// Tap dance stuff
// typedef struct {
//     bool    is_press_action;
//     uint8_t state;
// } tap;

// enum {
//     SINGLE_TAP = 1,
//     SINGLE_HOLD,
//     DOUBLE_SINGLE_TAP,
//     DOUBLE_HOLD,
//     DOUBLE_TAP,
// };

// Tap Dance Declarations
// enum {
//     TD_PLSENT,
//     TD_ENTRGBSTEP,
// };

// uint8_t cur_dance(qk_tap_dance_state_t *state);

// void dance_plsent_finished(qk_tap_dance_state_t *state, void *user_data);
// void dance_plsent_reset(qk_tap_dance_state_t *state, void *user_data);
// void dance_entrgbstep_finished(qk_tap_dance_state_t *state, void *user_data);
// void dance_entrgbstep_reset(qk_tap_dance_state_t *state, void *user_data);

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* NUMPAD
     *          .-----------------------------------.
     *          | CLEAR  |    *   |    /   |    -   |
     *          |--------+--------+--------+--------|
     *          |   7    |    8   |    9   |        |
     *          |--------+--------+--------+    +   |
     *          |   4    |    5   |    6   |        |
     * +--------|--------+--------+--------+--------|
     * |  CALC  |   1    |    2   |    3   |        |
     * +--------+-----------------+--------|  Enter |
     * | TO(1)  |        0        |  dot   |        |
     * .--------+-----------------+--------+--------.
     */
    [_NUMPAD] = LAYOUT(
                 KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
		         KC_7,    KC_8,    KC_9,    KC_PPLS,
		         KC_4,    KC_5,    KC_6,    KC_PPLS,
		CALCAPP, KC_1,    KC_2,    KC_3,    KC_ENT,
		TO(1),   KC_0,    KC_0,    KC_DOT,  KC_ENT
    ),

    /* TUNES
     *          .-----------------------------------.
     *          | YTMAPP | Pause  |  Prev  |  Next  |
     *          |--------+--------+--------+--------|
     *          | xxxxxx | xxxxxx | xxxxxx | xxxxxx |
     *          |--------+--------+--------+--------|
     *          | xxxxxx | xxxxxx | xxxxxx | xxxxxx |
     * +--------|--------+--------+--------+--------|
     * |  Mute  | xxxxxx | xxxxxx | xxxxxx |        |
     * +--------+-----------------+--------| BSTHUP |
     * | TO(2)  |     BSTHDWN     | xxxxxx |        |
     * .--------+-----------------+--------+--------.
     */
    [_TUNES] = LAYOUT(
                KC_MUTE,BSPAUS,  BSPREV,  BSNEXT,
		        KC_NO,  KC_NO,   KC_NO,   KC_NO,
		        KC_NO,  KC_NO,   KC_NO,   KC_NO,
		YTMAPP, KC_NO,  KC_NO,   KC_NO,   BSTHUP,
		TO(2),  KC_NO,  BSTHDWN, KC_NO,   BSTHUP
    ),

    /* MACROS
     *          .-----------------------------------.
     *          | xxxxxx | xxxxxx | xxxxxx | xxxxxx |
     *          |--------+--------+--------+--------|
     *          | FLUIDT | MQUERY | SRVRIP |        |
     *          |--------+--------+--------+ xxxxxx |
     *          | xxxxxx | xxxxxx |SRVRIP2 |        |
     * +--------|--------+--------+--------+--------|
     * | FMPASS | xxxxxx | xxxxxx | xxxxxx |        |
     * +--------+-----------------+--------|  Enter |
     * | TO(3)  |      xxxxxx     | xxxxxx |        |
     * .--------+-----------------+--------+--------.
     */
    [_MACRO] = LAYOUT(
                KC_NO,  KC_NO,    KC_NO,   KC_NO,
                FLUIDT, MQUERY,   SRVRIP,  SRVRIP2,
                KC_NO,  KC_NO,    KC_NO,   SRVRIP2,
        FMPASS, KC_NO,  KC_NO,    KC_NO,   KC_ENT,
        TO(3),  KC_NO,  KC_NO,    KC_NO,   KC_ENT
    ),

    /* RGB
     *          .-----------------------------------.
     *          | brite+ | color+ |  sat+  | xxxxxx |
     *          |--------+--------+--------+--------|
     *          | brite- | color- |  sat-  | xxxxxx |
     *          |--------+--------+--------+--------|
     *          | xxxxxx | xxxxxx | xxxxxx | xxxxxx |
     * +--------|--------+--------+--------+--------|
     * | rgb i/o| xxxxxx | xxxxxx | xxxxxx |        |
     * +--------+-----------------+--------| xxxxxx |
     * | TO(4)  |      xxxxxx     | xxxxxx |        |
     * .--------+-----------------+--------+--------.
     */
    [_RGB] = LAYOUT(
                 RGB_VAI, RGB_HUI, RGB_SAI, KC_NO,
                 RGB_VAD, RGB_HUD, RGB_SAD, KC_NO,
                 KC_NO,   KC_NO,   KC_NO,   KC_NO,
        RGB_TOG, KC_NO,   KC_NO,   KC_NO,   KC_NO,
        TO(4),   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

    /* DFU
     *          .-----------------------------------.
     *          | xxxxxx | xxxxxx | xxxxxx | xxxxxx |
     *          |--------+--------+--------+--------|
     *          | xxxxxx | xxxxxx | xxxxxx | xxxxxx |
     *          |--------+--------+--------+--------|
     *          | xxxxxx | xxxxxx | xxxxxx | xxxxxx |
     * +--------|--------+--------+--------+--------|
     * | RESET  | xxxxxx | xxxxxx | xxxxxx |        |
     * +--------+-----------------+--------| xxxxxx |
     * | TO(0)  |      xxxxxx     | xxxxxx |        |
     * .--------+-----------------+--------+--------.
     */
    [_DFU] = LAYOUT(
                 KC_NO, KC_NO, KC_NO, KC_NO,
                 KC_NO, KC_NO, KC_NO, KC_NO,
                 KC_NO, KC_NO, KC_NO, KC_NO,
        RESET, KC_NO, KC_NO, KC_NO, KC_NO,
        TO(0), KC_NO, KC_NO, KC_NO, KC_NO
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        switch(biton32(layer_state)) {
        case _NUMPAD:
            if (clockwise) {
                tap_code(KC_NLCK);
            } else {
                tap_code(KC_BSPC);
            }
            break;
        case _TUNES:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        case _MACRO:
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
        case _RGB:
            if (clockwise) {
                rgblight_step();
            } else {
                rgblight_step_reverse();
            }
            break;
        case _DFU:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        }
    }
    return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }


// WPM-responsive animation stuff here
// #define IDLE_FRAMES 2
// #define IDLE_SPEED 40 // below this wpm value your animation will idle

// #define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
// #define ANIM_SIZE 636 // number of bytes in array, minimize for adequate firmware size, max is 1024

// uint32_t anim_timer = 0;
// uint32_t anim_sleep = 0;
// uint8_t current_idle_frame = 0;

// Credit to u/Pop-X- for the initial code. You can find his commit here https://github.com/qmk/qmk_firmware/pull/9264/files#diff-303f6e3a7a5ee54be0a9a13630842956R196-R333.
// static void render_anim(void) {
//     static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {
//         {
//         0,  0,192,192,192,192,192,192,192,248,248, 30, 30,254,254,248,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,  3,  3,255,255,255,255,255,255,255,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,127,127,255,255,255,255,255,159,159,135,135,129,129,129, 97, 97, 25, 25,  7,  7,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1, 97, 97,127,  1,  1, 97, 97,127,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0
//         },
//         {
//         0,  0,128,128,128,128,128,128,128,240,240, 60, 60,252,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  7,  7,  7,  7,  7,255,255,254,254,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,255,255,255, 63, 63, 15, 15,  3,  3,  3,195,195, 51, 51, 15, 15,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3, 99, 99,127,  3,  3, 99, 99,127,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0
//         }
//     };

//     //assumes 1 frame prep stage
//     void animation_phase(void) {
//             current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
//             oled_write_raw_P(idle[abs((IDLE_FRAMES-1)-current_idle_frame)], ANIM_SIZE);
//     }

//         if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
//             anim_timer = timer_read32();
//             animation_phase();
//         }
//     }

static void render_duck(void) {

    static const char eight_bit_duck [] PROGMEM = {
        // '8-bit-duck', 32x33px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xee, 0x6f, 0x03, 0x03, 0x63, 0x43, 0x07, 0xfc, 0xfc,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x0c, 0x08, 0x08, 0x0c, 0x0e, 0x1e, 0xff, 0x1e, 0x0e, 0x3e, 0x3e, 0x3e, 0x3e, 0x00, 0x7f, 0xff,
        0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x1e,
        0x20, 0x60, 0x78, 0x78, 0x60, 0x60, 0x78, 0x60, 0x60, 0x78, 0x78, 0x61, 0x63, 0xe7, 0x7e, 0x3c,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0c, 0x1c, 0x10, 0x10, 0xf0, 0xf0, 0x80, 0x80, 0xf0,
        0x30, 0x10, 0xf0, 0xf0, 0x80, 0x80, 0xf0, 0x30, 0x10, 0x1c, 0x1c, 0x0f, 0x03, 0x03, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(eight_bit_duck, sizeof(eight_bit_duck));
}

bool oled_task_user(void) {
        // render_anim();
        render_duck();
        oled_set_cursor(0,6);
        oled_write_P(PSTR("DUCK\nBOARD\n"), false);
    oled_write_P(PSTR("-----\n"), false);
    // Host Keyboard Layer Status
    oled_write_P(PSTR("MODE\n"), false);
    oled_write_P(PSTR("\n"), false);

    switch (get_highest_layer(layer_state)) {
        case _NUMPAD:
            oled_write_P(PSTR("NUM\n"), false);
            break;
        case _TUNES:
            oled_write_P(PSTR("TUNES"), false);
            break;
        case _MACRO:
            oled_write_P(PSTR("MACRO"), false);
            break;
        case _RGB:
            oled_write_P(PSTR("RGB\n"), false);
            break;
        case _DFU:
            oled_write_P(PSTR("DFU\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
            break;
    }
    return false;
}
#endif

// Custom keycodes output
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FLUIDT:
            if (record->event.pressed) {
                SEND_STRING("@include fluid-type(rem-calc(),rem-calc());");
            }
            break;

        case MQUERY:
            if (record->event.pressed) {
                SEND_STRING("@media only screen and (max-width: #{rem-calc()}) {}");
            }
            break;

        case USSSHP:
            if (record->event.pressed) {
                SEND_STRING("pI3GLob*Y81zJUVhF2g$");
            }
            break;

        case SRVRIP:
            if (record->event.pressed) {
                SEND_STRING("205.186.152.92");
            }
            break;

        case SRVRIP2:
            if (record->event.pressed) {
                SEND_STRING("70.32.72.207");
            }
            break;

        case LASTPASS:
            if (record->event.pressed) {
                SEND_STRING("TJ$vH3qK7J3Y^S36&=+wGjvL");
            }
            break;

        case FMPASS:
            if (record->event.pressed) {
                SEND_STRING("uptown10157");
            }
            break;

        case CALCAPP:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                tap_code(KC_C);
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            break;

        case YTMAPP:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                tap_code(KC_Y);
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            break;

        // case CMDAPP:
        //     if (record->event.pressed) {
        //         register_code(KC_LGUI);
        //         register_code(KC_LSFT);
        //         register_code(KC_LCTL);
        //         tap_code(KC_O);
        //         unregister_code(KC_LGUI);
        //         unregister_code(KC_LSFT);
        //         unregister_code(KC_LCTL);
        //     }
        //     break;

        case BSPREV:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                tap_code(KC_PGDN);
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
            }
            break;

        case BSNEXT:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                tap_code(KC_PGUP);
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
            }
            break;

        case BSPAUS:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                tap_code(KC_SPC);
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
            }
            break;

        case BSTHDWN:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                tap_code(KC_D);
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
            }
            break;

        case BSTHUP:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                tap_code(KC_L);
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
            }
            break;
    }

    return true;
};

// Tap dance time
// uint8_t cur_dance(qk_tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed)
//             return SINGLE_TAP;
//         else
//             return SINGLE_HOLD;
//     } else if (state->count == 2) {
//         if (state->interrupted)
//             return DOUBLE_SINGLE_TAP;
//         else if (state->pressed)
//             return DOUBLE_HOLD;
//         else
//             return DOUBLE_TAP;
//     } else
//         return 8;
// }

// Create an instance of 'tap' for the 'x' tap dance.
// static tap xtap_state = {.is_press_action = true, .state = 0};

// void dance_plsent_finished(qk_tap_dance_state_t *state, void *user_data) {
//     xtap_state.state = cur_dance(state);
//     switch (xtap_state.state) {
//         case SINGLE_TAP:
//             register_code(KC_PPLS);  // plus
//             break;
//         case DOUBLE_TAP:
//             register_code(KC_ENT);  // enter
//             break;
//         case SINGLE_HOLD:
//             register_code(KC_NLCK);  // clear
//             break;
//         case DOUBLE_HOLD:
//             register_code(KC_LGUI);
//             register_code(KC_LSFT);
//             register_code(KC_LCTL);
//             tap_code(KC_C);  // launch calculator app
//             break;
//     }
// }

// void dance_plsent_reset(qk_tap_dance_state_t *state, void *user_data) {
//     switch (xtap_state.state) {
//         case SINGLE_TAP:
//             unregister_code(KC_PPLS);
//             break;
//         case DOUBLE_TAP:
//             unregister_code(KC_ENT);
//             break;
//         case SINGLE_HOLD:
//             unregister_code(KC_NLCK);
//             break;
//         case DOUBLE_HOLD:
//             unregister_code(KC_LGUI);
//             unregister_code(KC_LSFT);
//             unregister_code(KC_LCTL);
//             break;
//     }
//     xtap_state.state = 0;
// }

// void dance_entrgbstep_finished(qk_tap_dance_state_t *state, void *user_data) {
//     xtap_state.state = cur_dance(state);
//     switch (xtap_state.state) {
//         case SINGLE_TAP:
//             register_code(KC_ENT);  // enter
//             break;
//         case DOUBLE_TAP:
//             rgblight_step();  // rgb step
//             break;
//         case DOUBLE_HOLD:
//             rgblight_step_reverse(); // rgb step reverse
//             break;
//     }
// }

// void dance_entrgbstep_reset(qk_tap_dance_state_t *state, void *user_data) {
//     switch (xtap_state.state) {
//         case SINGLE_TAP:
//             unregister_code(KC_ENT);
//             break;
//         case DOUBLE_TAP:
//             // nothing to see here
//             break;
//         case DOUBLE_HOLD:
//             // nothing to see here
//             break;
//     }
//     xtap_state.state = 0;
// }

// qk_tap_dance_action_t tap_dance_actions[] = {
//     [TD_PLSENT]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_plsent_finished, dance_plsent_reset),
//     [TD_ENTRGBSTEP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_entrgbstep_finished, dance_entrgbstep_reset),
// };

// RGB/HSV Settings

// Runs just one time when the keyboard initializes.
void matrix_scan_user(void) {
    static bool has_ran_yet = false;
    if (!has_ran_yet) {
        has_ran_yet = true;
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv_noeeprom(HSV_YELLOW);
        // rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
    }
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 750) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
      }
    }
};

// uint32_t check;
// uint32_t layer_state_set_user(uint32_t state) {
//     switch (biton32(state)) {
//         case _NUMPAD:
//             rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
//             rgblight_sethsv_noeeprom(HSV_MAGENTA);
//             break;
//         case _FUNC:
//             rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
//             rgblight_sethsv_noeeprom(HSV_WHITE);
//             break;
//         case _MACRO:
//             rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
//             rgblight_sethsv_noeeprom(HSV_CHARTREUSE);
//             break;
//         case _RGB:
//             rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT);
//             // rgblight_sethsv_noeeprom(HSV_TEAL);
//             break;
//         case _DFU:
//             rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
//             rgblight_sethsv_noeeprom(HSV_RED);
//             break;
//     }
//     return state;
// };


 // void keyboard_post_init_user(void) {
  // Customise these values to debug
  // debug_enable=true;
  // debug_matrix=true;
  // debug_keyboard=true;
  // debug_mouse=true;
// }
