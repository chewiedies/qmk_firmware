#include QMK_KEYBOARD_H

#ifdef ENCODER_ENABLE
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
#endif

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUM,
};

// #define LOWER MO(_LOWER)
// #define RAISE MO(_RAISE)
#define ALTTAB  MT(MOD_LALT, KC_TAB)
#define ALTENT  MT(MOD_LALT, KC_ENT)
#define CMDESC  MT(MOD_LGUI, KC_ESC)
#define SFTSPC  MT(MOD_LSFT, KC_SPC)
#define SFTENT  MT(MOD_LSFT, KC_ENT)
#define NUMENT  LT(_NUM, KC_ENT)
#define NUMMIN  LT(_NUM, KC_MINS)
#define NUMBSP  LT(_NUM, KC_BSPC)
#define OSMALT  OSM(MOD_LALT)
#define OSMCTL  OSM(MOD_LCTL)
#define OSMGUI  OSM(MOD_LGUI)
#define OSMSFT  OSM(MOD_LSFT)
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
#define THECLAW LGUI(LSFT(LALT(KC_S)))
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
#define W_LSCRN LCTL(LGUI(LALT(KC_LEFT)))
#define W_RSCRN LCTL(LGUI(LALT(KC_RGHT)))

// Declare custom keycodes
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    KC_IMP,
    DRGSCRL,
    KC_ACCEL,
    // LGUIRSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * .--------------------------------------------------------------.        .--------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      |        | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     * | TAB    | Q      | W      | E      | R      | T      | [      |        | ]      | Y      | U      | I      | O      | P      | |\     |
     * |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     * | LCTRL  | A      | S      | D      | F      | G      | HOME   |        | PG UP  | H      | J      | K      | L      | ;      | '      |
     * |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    |        | PG DN  | N      | M      | ,      | .      | /      | SH/ENT |
     * '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
     *          | LGUI   | DEL    | ~`     | LALT   | SPACE  |        | FN     | SPACE  |        | LEFT   | DOWN   | UP     | RIGHT  |
     *          '--------------------------------------------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_classic(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_VOLD,           KC_VOLU, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        ALTTAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,           KC_RBRC, KC_Y,	   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        CMDESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINS,           KC_EQL,  KC_H,	   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_BSPC,           KC_DEL,  KC_N,	   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ALTENT,
                 XXXXXXX, XXXXXXX, XXXXXXX, RAISE,   SFTSPC,  NUMENT,  PSTBRD,   KC_SPC,  KC_SPC,  LOWER,   XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* RAISE
	 * .--------------------------------------------------------------.        .--------------------------------------------------------------.
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * '--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------+--------+--------+--------'
     *          |        |        |        |        |                 |        |                 |        |        |        |        |
     *          '--------------------------------------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_classic(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        SFTTAB,  XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,          XXXXXXX, PGTOP,   PRVWRD,  KC_UP,   NXTWRD,  XXXXXXX, KC_DEL,
        KCUNDO,  KCREDO,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX,          XXXXXXX, PGBOT,   LNBEG,   XXXXXXX, LNEND,   XXXXXXX, XXXXXXX,
                 _______, _______, _______, _______, _______, _______, _______, _______, KC_SPC,  _______, _______, _______, _______
    ),

    /* LOWER
	 * .--------------------------------------------------------------.        .--------------------------------------------------------------.
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * '--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------+--------+--------+--------'
     *          |        |        |        |        |                 |        |                 |        |        |        |        |
     *          '--------------------------------------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_classic(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_IMP,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX,          XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        CMDESC,  KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_LBRC, XXXXXXX,          XXXXXXX, KC_RBRC, KC_GRV,  XXXXXXX, KC_DQUO, KC_QUOT, XXXXXXX,
        KC_CAPS, KC_EQL,  KC_PLUS, KC_MINS, KC_UNDS, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, KC_TILD, XXXXXXX, KC_PIPE, KC_BSLS, THECLAW,
                 _______, _______, _______, _______, _______, _______, SCRNCAP, _______, _______, _______, _______, _______, _______
    ),

    /* ADJUST LAYER
	 * .--------------------------------------------------------------.        .--------------------------------------------------------------.
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * '--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------+--------+--------+--------'
     *          |        |        |        |        |                 |        |                 |        |        |        |        |
     *          '--------------------------------------------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_classic(
        RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD,         RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, W_LSCRN, W_SHOW,  W_TTHRD, XXXXXXX, XXXXXXX, RGB_HUD,          RGB_HUI, XXXXXXX, XXXXXXX, W_THALF, XXXXXXX, W_RSCRN, XXXXXXX,
        XXXXXXX, XXXXXXX, W_LTHRD, W_MAX,   W_RTHRD, XXXXXXX, RGB_VAD,          RGB_VAI, XXXXXXX, W_LHALF, W_CENT,  W_RHALF, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, W_BTHRD, XXXXXXX, XXXXXXX, RGB_SPD,          RGB_SPI, XXXXXXX, XXXXXXX, W_BHALF, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, _______, _______, _______, _______, _______, RGB_TOG, _______, _______, _______, _______, _______, _______
    ),

    /* NUM
	 * .--------------------------------------------------------------.        .--------------------------------------------------------------.
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * '--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------+--------+--------+--------'
     *          |        |        |        |        |                 |        |                 |        |        |        |        |
     *          '--------------------------------------------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_classic(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,          XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COLN, _______,
        _______, KC_EQL,  KC_PLUS, KC_MINS, KC_COMM, KC_DOT,  XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
    /* SAMPLE LAYER
	 * .--------------------------------------------------------------.        .--------------------------------------------------------------.
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * '--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------+--------+--------+--------'
     *          |        |        |        |        |                 |        |                 |        |        |        |        |
     *          '--------------------------------------------------------------------------------------------------------------------'
     *
    [_SAMPLE] = LAYOUT_classic(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )*/
};


// Custom Keycode Stuff
// uint16_t key_timer;
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
        // case LGUIRSE:
        //      if (record->event.pressed) {
        //         key_timer = timer_read();
        //         layer_on(_RAISE);
        //         update_tri_layer(_LOWER, _RAISE, _ADJUST);
        //     } else {
        //         layer_off(_RAISE);
        //         update_tri_layer(_LOWER, _RAISE, _ADJUST);
        //         if (timer_elapsed(key_timer) < TAPPING_TERM) {
        //             add_oneshot_mods(MOD_BIT(KC_LGUI));
        //         }
        //     }
        //     break;
    }

    return true;
}

// Encoder stuff
#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {  // Roller Encoder LEft
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

        case _RAISE:
            if (clockwise) {
                #if RGB_MATRIX_ENABLE
                    rgb_matrix_increase_hue();
                #endif
                #if RGBLIGHT_ENABLE
                    rgblight_increase_hue();
                #endif
            } else {
                #if RGB_MATRIX_ENABLE
                    rgb_matrix_decrease_hue();
                #endif
                #if RGBLIGHT_ENABLE
                    rgblight_decrease_hue();
                #endif
            }
            break;

        case _ADJUST:
            if (clockwise) {
                #if RGB_MATRIX_ENABLE
                    rgb_matrix_step();
                #endif
                #if RGBLIGHT_ENABLE
                    rgblight_step();
                #endif
            } else {
                #if RGB_MATRIX_ENABLE
                    rgb_matrix_step_reverse();
                #endif
                #if RGBLIGHT_ENABLE
                    rgblight_step_reverse();
                #endif
            }
            break;
        }
    }
    return true;
}

#endif

// Runs just one time when the keyboard initializes.
void matrix_scan_user(void) {
    static bool has_ran_yet = false;
    if (!has_ran_yet) {
        has_ran_yet = true;
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);
        rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
        // rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        // rgblight_sethsv(HSV_YELLOW);
    }

    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 900) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
      }
    }
};
