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
 * │ (CMD)  ╰────────╯   X    ╰────────╯   V    │        │                        │        │    M   ╰────────╯    .   ╰────────╯    "   │
 * │  Esc   │        ╰────────╯        ╰────────╯   B    │                        │    N   ╰────────╯        ╰────────╯    ?   │    '   │
 * ╰────────╯   Z    │                          ╰────────╯                        ╰────────╯                          │    /   ╰────────╯
 * │        ╰────────╯                  ╭────────╮                                        ╭────────╮                  ╰────────╯(Shift) │
 * │  CTRL  │                           │        ╰────────╮                      ╭────────╯        │                           │ Enter  │
 * ╰────────╯                           │  RSE   │ (Shift)╰────────╮    ╭────────╯        │  Mute  │                           ╰────────╯
 *                                      ╰────────╯ Space  │ (num)  │    │  (num) │  LWR   ╰────────╯
 *                                               ╰────────╯ Enter  │    │  - _   ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 */
[_QWERTY] = LAYOUT_split_3x6_3(
    ALTTAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,              KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,     KC_BSPC,
    CMDESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,              KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
    KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,              KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  ALTENT,
                                  RAISE,    SFTSPC,   NUMENT,            NUMMIN,  KC_SPC,   LOWER
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
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │  Undo  │        ╰────────╯        ╰────────╯ Bkspce │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │                          ╰────────╯                        ╰────────╯                          │        ╰────────╯
 * │        ╰────────╯                  ╭────────╮                                        ╭────────╮                  ╰────────╯        │
 * │        │                           │        ╰────────╮                      ╭────────╯        │                           │        │
 * ╰────────╯                           │  RSE   │        ╰────────╮    ╭────────╯(Shift) │   LWR  │                           ╰────────╯
 *                                      ╰────────╯        │        │    │        │ Space  ╰────────╯
 *                                               ╰────────╯        │    │        ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 */

[_RAISE] = LAYOUT_split_3x6_3(
    SFTTAB,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           PGTOP,    PRVWRD,   KC_UP,    NXTWRD,   XXXXXXX,  KC_DEL,
    KCUNDO,   KCREDO,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSPC,           PGBOT,    LNBEG,    XXXXXXX,  LNEND,    XXXXXXX,  XXXXXXX,
                                  _______,  _______,  _______,           XXXXXXX,  SFTSPC,   _______
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
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │                          ╰────────╯                        ╰────────╯                          │        ╰────────╯
 * │        ╰────────╯                  ╭────────╮                                        ╭────────╮                  ╰────────╯        │
 * │        │                           │        ╰────────╮                      ╭────────╯        │                           │        │
 * ╰────────╯                           │        │        ╰────────╮    ╭────────╯        │        │                           ╰────────╯
 *                                      ╰────────╯        │        │    │        │        ╰────────╯
 *                                               ╰────────╯        │    │        ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 */

[_LOWER] = LAYOUT_split_3x6_3(
    KC_IMP,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,           KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
    CMDESC,   XXXXXXX,  THECLAW,  KC_LPRN,  KC_RPRN,  KC_LCBR,           KC_RCBR,  KC_EQL,   KC_GRV,   XXXXXXX,  KC_BSLS,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LBRC,           KC_RBRC,  KC_PLUS,  KC_TILD,  XXXXXXX,  KC_PIPE,  XXXXXXX,
                                  _______,  _______,  _______,           _______,  KC_LSFT,  _______
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
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │                          ╰────────╯                        ╰────────╯                          │        ╰────────╯
 * │        ╰────────╯                  ╭────────╮                                        ╭────────╮                  ╰────────╯        │
 * │        │                           │        ╰────────╮                      ╭────────╯        │                           │        │
 * ╰────────╯                           │        │        ╰────────╮    ╭────────╯        │        │                           ╰────────╯
 *                                      ╰────────╯        │        │    │        │        ╰────────╯
 *                                               ╰────────╯        │    │        ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 */

[_ADJUST] = LAYOUT_split_3x6_3(
    XXXXXXX,  XXXXXXX,  W_SHOW,   W_TTHRD,  XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  W_THALF,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  W_LTHRD,  W_MAX,    W_RTHRD,  XXXXXXX,           XXXXXXX,  W_LHALF,  W_CENT,   W_RHALF,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  W_BTHRD,  XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  W_BHALF,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                  _______,  XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  _______
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
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │q
 * │        │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │                          ╰────────╯                        ╰────────╯                          │        ╰────────╯
 * │        ╰────────╯                  ╭────────╮                                        ╭────────╮                  ╰────────╯        │
 * │        │                           │        ╰────────╮                      ╭────────╯        │                           │        │
 * ╰────────╯                           │        │        ╰────────╮    ╭────────╯        │        │                           ╰────────╯
 *                                      ╰────────╯        │        │    │        │        ╰────────╯
 *                                               ╰────────╯        │    │        ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 */
[_NUM] =  LAYOUT_split_3x6_3(
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,              KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    _______,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,
    _______,  KC_EQL,   KC_PLUS,  KC_MINS,  KC_COMM,  KC_DOT,            XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,
                                  _______,  SFTSPC,   _______,           _______,  SFTSPC,   _______
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
 * │        ╰────────╯        ╰────────╯        │        │                        │        │        ╰────────╯        ╰────────╯        │
 * │        │        ╰────────╯        ╰────────╯        │                        │        ╰────────╯        ╰────────╯        │        │
 * ╰────────╯        │                          ╰────────╯                        ╰────────╯                          │        ╰────────╯
 * │        ╰────────╯                  ╭────────╮                                        ╭────────╮                  ╰────────╯        │
 * │        │                           │        ╰────────╮                      ╭────────╯        │                           │        │
 * ╰────────╯                           │        │        ╰────────╮    ╭────────╯        │        │                           ╰────────╯
 *                                      ╰────────╯        │        │    │        │        ╰────────╯
 *                                               ╰────────╯        │    │        ╰────────╯
 *                                                        ╰────────╯    ╰────────╯
 *
 *[_SAMPLE] = LAYOUT_split_3x6_3(
 *  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 *  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 *  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 *                                _______,  XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  _______
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
