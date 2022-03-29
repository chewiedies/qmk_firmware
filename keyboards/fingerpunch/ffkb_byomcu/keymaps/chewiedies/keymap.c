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
#define ALTTAB  MT(MOD_LALT, KC_TAB)
#define ALTENT  MT(MOD_LALT, KC_ENT)
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
    KC_IMP,
    // KC_PRVWD,
    // KC_NXTWD,
    // KC_LSTRT,
    // KC_LEND,
    // KC_TOPP,
    // KC_BOTP,
    // KC_REDO,
    // PSTBRD,
    // KC_SFTB,
    // SCRNCAP,
    // KC_CLAW,
    // W_LHALF,
    // W_RHALF,
    // W_THALF,
    // W_BHALF,
    // W_LTHRD,
    // W_RTHRD,
    // W_TTHRD,
    // W_BTHRD,
    // W_MAX,
    // W_CENT,
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

/* Base Layer: _QWERTY
 *                            ╭────────╮                                                            ╭────────╮
 *                   ╭────────╯        ╰────────╮                                          ╭────────╯        ╰────────╮
 *                   │        │   E    │        ╰────────╮                        ╭────────╯        │    I   │        │
 *          ╭────────╯   W    ╰────────╯   R    │        │                        │        │    U   ╰────────╯    O   ╰────────╮
 *          │        ╰────────╯        ╰────────╯   T    │                        │    Y   ╰────────╯        ╰────────╯        │
 * ╭────────╮   Q    │        │   D    │        ╰────────╯                        ╰────────╯        │    K   │        │    P   ╰────────╮
 * │ (ALT)  ╰────────╯   S    ╰────────╯   F    │        │                        │        │    J   ╰────────╯    L   ╰────────╯        │
 * │  Tab   │        ╰────────╯        ╰────────╯   G    │                        │    H   ╰────────╯    <   ╰────────╯    :   │ Bkspce │
 * ╰────────╯   A    │        │   C    │        ╰────────╯                        ╰────────╯        │    ,   │    >   │    ;   ╰────────╯
 * │ (CMD)  ╰────────╯   X    ╰────────╯   V    │        │       ╭────────╮       │        │    M   ╰────────╯    .   ╰────────╯    "   │
 * │  Esc   │        ╰────────╯        ╰────────╯   B    │       │ Paste  │       │    N   ╰────────╯        ╰────────╯    ?   │    '   │
 * ╰────────╯   Z    │                          ╰────────╯       │ Board  │       ╰────────╯                          │    /   ╰────────╯
 * │        ╰────────╯    ╭────────╮    ╭────────╮               ╰─encodr─╯               ╭────────╮    ╭────────╮    ╰────────╯(Shift) │
 * │  CTRL  │             │        │    │        ╰────────╮                      ╭────────╯        │    │ Paste  │             │ Enter  │
 * ╰────────╯             │  Mute  │    │  RSE   │ (Shift)╰────────╮    ╭────────╯        │  Mute  │    │ Board  │             ╰────────╯
 *                        ╰─encodr─╯    ╰────────╯ Space  │ (num)  │    │  (num) │  LWR   ╰────────╯    ╰─encodr─╯
 *                                               ╰────────╯ Enter  │    │  - _   ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 */
[_QWERTY] = LAYOUT_ffkb(
    ALTTAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,              KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,     KC_BSPC,
    CMDESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,              KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
    KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,              KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  ALTENT,
                        KC_MUTE,  RAISE,    SFTSPC,   NUMENT,            NUMMIN,  KC_SPC,   LOWER,    KC_MUTE,
                                                                PSTBRD
),


/* Layer: _RAISE
 *                            ╭────────╮                                                            ╭────────╮
 *                   ╭────────╯        ╰────────╮                                          ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                        ╭────────╯        │        │        │
 *          ╭────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╮
 *          │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │
 * ╭────────╮        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╮
 * │ Shift/ ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │ Tab    │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯  Redo  │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╯
 * │        ╰────────╯        ╰────────╯        │        │       ╭────────╮       │        │        ╰────────╯        ╰────────╯        │
 * │  Undo  │        ╰────────╯        ╰────────╯ Bkspce │       │        │       │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │                          ╰────────╯       │        │       ╰────────╯                          │        ╰────────╯
 * │        ╰────────╯    ╭────────╮    ╭────────╮               ╰─encodr─╯               ╭────────╮    ╭────────╮    ╰────────╯        │
 * │        │             │        │    │        ╰────────╮                      ╭────────╯        │    │        │             │        │
 * ╰────────╯             │        │    │  RSE   │        ╰────────╮    ╭────────╯(Shift) │   LWR  │    │        │             ╰────────╯
 *                        ╰─encodr─╯    ╰────────╯        │        │    │        │ Space  ╰────────╯    ╰─encodr─╯
 *                                               ╰────────╯        │    │        ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 */

[_RAISE] = LAYOUT_ffkb(
    SFTTAB,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           PGTOP,    PRVWRD,   KC_UP,    NXTWRD,   XXXXXXX,  KC_DEL,
    KCUNDO,   KCREDO,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSPC,           PGBOT,    LNBEG,    XXXXXXX,  LNEND,    XXXXXXX,  XXXXXXX,
                        _______,  _______,  _______,  _______,           XXXXXXX,  SFTSPC,   _______,  _______,
                                                                _______
),


/* Layer: _LOWER
 *                            ╭────────╮                                                            ╭────────╮
 *                   ╭────────╯        ╰────────╮                                          ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                        ╭────────╯        │        │        │
 *          ╭────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╮
 *          │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │
 * ╭────────╮        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╮
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╯
 * │        ╰────────╯        ╰────────╯        │        │       ╭────────╮       │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │       │        │       │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │                          ╰────────╯       │        │       ╰────────╯                          │        ╰────────╯
 * │        ╰────────╯    ╭────────╮    ╭────────╮               ╰─encodr─╯               ╭────────╮    ╭────────╮    ╰────────╯        │
 * │        │             │        │    │        ╰────────╮                      ╭────────╯        │    │        │             │        │
 * ╰────────╯             │        │    │        │        ╰────────╮    ╭────────╯        │        │    │        │             ╰────────╯
 *                        ╰─encodr─╯    ╰────────╯        │        │    │        │        ╰────────╯    ╰─encodr─╯
 *                                               ╰────────╯        │    │        ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 */

[_LOWER] = LAYOUT_ffkb(
    KC_IMP,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,           KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
    CMDESC,   XXXXXXX,  THECLAW,  KC_LPRN,  KC_RPRN,  KC_LCBR,           KC_RCBR,  KC_EQL,   KC_GRV,   XXXXXXX,  KC_BSLS,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LBRC,           KC_RBRC,  KC_PLUS,  KC_TILD,  XXXXXXX,  KC_PIPE,  XXXXXXX,
                        SCRNCAP,  _______,  _______,  _______,           _______,  KC_LSFT,  _______,  XXXXXXX,
                                                                _______
),


/* Layer: _ADJUST
 *                            ╭────────╮                                                            ╭────────╮
 *                   ╭────────╯        ╰────────╮                                          ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                        ╭────────╯        │        │        │
 *          ╭────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╮
 *          │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │
 * ╭────────╮        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╮
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╯
 * │        ╰────────╯        ╰────────╯        │        │       ╭────────╮       │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │       │        │       │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │                          ╰────────╯       │        │       ╰────────╯                          │        ╰────────╯
 * │        ╰────────╯    ╭────────╮    ╭────────╮               ╰─encodr─╯               ╭────────╮    ╭────────╮    ╰────────╯        │
 * │        │             │        │    │        ╰────────╮                      ╭────────╯        │    │        │             │        │
 * ╰────────╯             │        │    │        │        ╰────────╮    ╭────────╯        │        │    │        │             ╰────────╯
 *                        ╰─encodr─╯    ╰────────╯        │        │    │        │        ╰────────╯    ╰─encodr─╯
 *                                               ╰────────╯        │    │        ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 */

[_ADJUST] = LAYOUT_ffkb(
    XXXXXXX,  XXXXXXX,  W_SHOW,   W_TTHRD,  XXXXXXX,  RGB_RMOD,          RGB_MOD,  XXXXXXX,  W_THALF,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  W_LTHRD,  W_MAX,    W_RTHRD,  RGB_HUD,           RGB_HUI,  W_LHALF,  W_CENT,   W_RHALF,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  W_BTHRD,  XXXXXXX,  RGB_VAD,           RGB_VAI,  XXXXXXX,  W_BHALF,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                        XXXXXXX,  _______,  XXXXXXX,  RGB_SPD,           RGB_SPI,  XXXXXXX,  _______,  XXXXXXX,
                                                                RGB_TOG
),


/* Layer: _NUM
 *                            ╭────────╮                                                            ╭────────╮
 *                   ╭────────╯        ╰────────╮                                          ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                        ╭────────╯        │        │        │
 *          ╭────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╮
 *          │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │
 * ╭────────╮        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╮
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╯
 * │        ╰────────╯        ╰────────╯        │        │       ╭────────╮       │        │        ╰────────╯        ╰────────╯        │q
 * │        │        ╰────────╯        ╰────────╯        │       │        │       │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │                          ╰────────╯       │        │       ╰────────╯                          │        ╰────────╯
 * │        ╰────────╯    ╭────────╮    ╭────────╮               ╰─encodr─╯               ╭────────╮    ╭────────╮    ╰────────╯        │
 * │        │             │        │    │        ╰────────╮                      ╭────────╯        │    │        │             │        │
 * ╰────────╯             │        │    │        │        ╰────────╮    ╭────────╯        │        │    │        │             ╰────────╯
 *                        ╰─encodr─╯    ╰────────╯        │        │    │        │        ╰────────╯    ╰─encodr─╯
 *                                               ╰────────╯        │    │        ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 */
[_NUM] =  LAYOUT_ffkb(
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,              KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    _______,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,
    _______,  KC_EQL,   KC_PLUS,  KC_MINS,  KC_COMM,  KC_DOT,            XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,
                        _______,  _______,  SFTSPC,   _______,           _______,  SFTSPC,   _______,  _______,
                                                                _______
)

/* Layer: SAMPLE
 *                            ╭────────╮                                                            ╭────────╮
 *                   ╭────────╯        ╰────────╮                                          ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                        ╭────────╯        │        │        │
 *          ╭────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╮
 *          │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │
 * ╭────────╮        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╮
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │        │        │        ╰────────╯                        ╰────────╯        │        │        │        ╰────────╯
 * │        ╰────────╯        ╰────────╯        │        │       ╭────────╮       │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │       │        │       │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │                          ╰────────╯       │        │       ╰────────╯                          │        ╰────────╯
 * │        ╰────────╯    ╭────────╮    ╭────────╮               ╰─encodr─╯               ╭────────╮    ╭────────╮    ╰────────╯        │
 * │        │             │        │    │        ╰────────╮                      ╭────────╯        │    │        │             │        │
 * ╰────────╯             │        │    │        │        ╰────────╮    ╭────────╯        │        │    │        │             ╰────────╯
 *                        ╰─encodr─╯    ╰────────╯        │        │    │        │        ╰────────╯    ╰─encodr─╯
 *                                               ╰────────╯        │    │        ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 *
 *[_SAMPLE] = LAYOUT_ffkb(
 *  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 *  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 *  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 *                      XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,
 *                                                              _______
 *),
 */
};


bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFTSPC:
            return true;
        default:
            return false;
    }
}


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
    }

    return true;
}


// Three Encoder Support
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

    } else if (index == 1) {  // Roller Encoder Right
        switch(biton32(layer_state)) {
        case _QWERTY:
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
                tap_code(KC_RGHT);
            } else {
                tap_code(KC_LEFT);
            }
            break;

        case _LOWER:
            if (clockwise) {
                rgb_matrix_increase_val();
            } else {
                rgb_matrix_decrease_val();
            }
            break;

        case _ADJUST:
            if (clockwise) {
                rgb_matrix_increase_speed();
            } else {
                rgb_matrix_decrease_speed();
            }
            break;
        }
    } else if (index == 2) {  // Central Encoder
        switch(biton32(layer_state)) {
        case _QWERTY:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        // case _RAISE:
        //     if (clockwise) {
        //
        //     } else {
        //
        //     }
        //     break;
        // case _LOWER:
        //     if (clockwise) {
        //
        //     } else {
        //
        //     }
        //     break;
        case _ADJUST:
            if (clockwise) {
                rgb_matrix_step();
            } else {
                rgb_matrix_step_reverse();
            }
            break;
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
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 750) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
      }
    }
};
