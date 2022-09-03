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
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base Layer: _QWERTY
 *                            ╭────────╮                                                                        ╭────────╮
 *                   ╭────────╯        ╰────────╮          ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮          ╭────────╯        ╰────────╮
 *                   │        │   E    │        ╰────────╮ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ╭────────╯        │    I   │        │
 *          ╭────────╯   W    ╰────────╯   R    │        ├─╯                                ╰─┤        │    U   ╰────────╯    O   ╰────────╮
 * ╭────────│        ╰────────╯        ╰────────╯   T    │                                    │    Y   ╰────────╯        ╰────────╯        ╰────────╮
 * │ (ALT)  │   Q    │        │   D    │        ╰────────╯                                    ╰────────╯        │    K   │        │    P   │        │
 * │  Tab   ╰────────╯   S    ╰────────╯   F    │        │                                    │        │    J   ╰────────╯    L   ╰────────╯ Bkspce │
 * ╰────────╯        ╰────────╯        ╰────────╯   G    │                                    │    H   ╰────────╯    <   ╰────────╯    :   ╰────────╯
 * │ (CMD)  │   A    │        │   C    │        ╰────────╯                                    ╰────────╯        │    ,   │    >   │    ;   │    "   │
 * │  Esc   ╰────────╯   X    ╰────────╯   V    │        │                                    │        │    M   ╰────────╯    .   ╰────────╯    '   │
 * ╰────────╯        ╰────────╯||||||||╰────────╯   B    │ ╭────────╮              ╭────────╮ │    N   ╰────────╯||||||| ╰────────╯    ?   ╰────────╯
 * │        │   Z    │ ||||||||╭────────╮|||||||╰────────╯ │        │              │        │ ╰────────╯|||||||╭────────╮|||||||| │    /   │(SHIFT) │
 * │  CTRL  ╰────────╯╭────────╯        ╰────────╮|||||||| │   {    │              │    }   │ ||||||||╭────────╯        │────────╮╰────────╯ Enter  │
 * ╰────────╯         │ Paste  │  CMD   │        ╰────────╮╰────────╯              ╰────────╯╭────────╯        │  ALT   │        │         ╰────────╯
 *                    │ Board  ╰────────╯ _RAISE │ (SHIFT)╰────────╮                ╭────────╯        │ _LOWER ╰────────╯  Mute  │
 *                    ╰encoder0╯        ╰────────╯ Space  │ (_NUM) │                │ (_NUM) │  Space ╰────────╯        ╰encoder3╯
 *                                               ╰────────╯ Enter  │                │ Bkspce ╰────────╯
 *                                                        ╰────────╯                ╰────────╯
 */

[_QWERTY] = LAYOUT(
//╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷      ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
   KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
   ALTTAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
   CMDESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
   KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_LCBR,         KC_RCBR,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,
                       PSTBRD,   XXXXXXX,  RAISE,    SFTSPC,   NUMENT,          KC_BSPC,  KC_SPC,   LOWER,    XXXXXXX,  KC_MUTE
),


/* Layer: _RAISE
 *                            ╭────────╮                                                                        ╭────────╮
 *                   ╭────────╯        ╰────────╮          ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮          ╭────────╯        ╰────────╮
 *                   │        │  Vol-  │        ╰────────╮ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ╭────────╯  Prev  │   Up   │  Next  │
 *          ╭────────╯  Mute  ╰────────╯  Vol+  │        ├─╯                                ╰─┤  Page  │  Word  ╰────────╯  Word  ╰────────╮
 * ╭────────│        ╰────────╯        ╰────────╯        │                                    │  Top   ╰────────╯        ╰────────╯        ╰────────╮
 * │ Shift/ │        │        │        │        ╰────────╯                                    ╰────────╯        │  Down  │        │        │        │
 * │  Tab   ╰────────╯        ╰────────╯        │        │                                    │        │  Left  ╰────────╯ Right  ╰────────╯ Delete │
 * ╰────────╯        ╰────────╯        ╰────────╯        │                                    │        ╰────────╯        ╰────────╯        ╰────────╯
 * │        │  Redo  │        │        │        ╰────────╯                                    ╰────────╯  Line  │        │  Line  │        │        │
 * │  Undo  ╰────────╯        ╰────────╯        │        │                                    │  Page  │  Beg   ╰────────╯  End   ╰────────╯        │
 * ╰────────╯        ╰────────╯||||||||╰────────╯  Bkspc │ ╭────────╮              ╭────────╮ │  Bot   ╰────────╯||||||||╰────────╯        ╰────────╯
 * │        │        │ ||||||||╭────────╮|||||||╰────────╯ │        │              │        │ ╰────────╯|||||||╭────────╮|||||||| │        │        │
 * │        ╰────────╯╭────────╯        ╰────────╮|||||||| │   [    │              │    ]   │ ||||||||╭────────╯        │────────╮╰────────╯        │
 * ╰────────╯         │ Paste  │ BLANK  │        ╰────────╮╰────────╯              ╰────────╯╭────────╯        │  BLANK │        │         ╰────────╯
 *                    │ Board  ╰────────╯ _RAISE │        ╰────────╮                ╭────────╯        │        ╰────────╯        │
 *                    ╰encoder0╯        ╰────────╯  Shift │        │                │        │        ╰────────╯        ╰encoder3╯
 *                                               ╰────────╯  Enter │                │ Delete ╰────────╯
 *                                                        ╰────────╯                ╰────────╯
 *
 */
 [_RAISE] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷      ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    SFTTAB,   XXXXXXX,  KC_MUTE,  KC_VOLD,  KC_VOLU,  XXXXXXX,                             PGTOP,    PRVWRD,   KC_UP,    NXTWRD,   XXXXXXX,  KC_DEL,
    KCUNDO,   KCREDO,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                             XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSPC,  KC_LBRC,         KC_RBRC,  PGBOT,    LNBEG,    XXXXXXX,  LNEND,    XXXXXXX,  XXXXXXX,
                        KC_CAPS,  _______,  _______,  _______,  KC_ENT,          KC_DEL,   _______,  _______,  _______,  W_SHOW
 ),


 /* Layer: _LOWER
 *                            ╭────────╮                                                                        ╭────────╮
 *                   ╭────────╯        ╰────────╮          ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮          ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ╭────────╯        │        │        │
 *          ╭────────╯        ╰────────╯        │        ├─╯                                ╰─┤        │        ╰────────╯        ╰────────╮
 * ╭────────│        ╰────────╯        ╰────────╯        │                                    │        ╰────────╯        ╰────────╯        ╰────────╮
 * │        │        │        │        │        ╰────────╯                                    ╰────────╯        │        │        │        │        │
 * │        ╰────────╯        ╰────────╯        │        │                                    │        │        ╰────────╯        ╰────────╯        │
 * ╰────────╯        ╰────────╯        ╰────────╯        │                                    │        ╰────────╯        ╰────────╯        ╰────────╯
 * │        │        │        │        │        ╰────────╯                                    ╰────────╯        │        │        │        │        │
 * │        ╰────────╯        ╰────────╯        │        │                                    │        │        ╰────────╯        ╰────────╯        │
 * ╰────────╯        ╰────────╯||||||||╰────────╯        │ ╭────────╮              ╭────────╮ │        ╰────────╯||||||||╰────────╯        ╰────────╯
 * │        │        │ ||||||||╭────────╮|||||||╰────────╯ │        │              │        │ ╰────────╯|||||||╭────────╮|||||||| │        │        │
 * │        ╰────────╯╭────────╯        ╰────────╮|||||||| │        │              │        │ ||||||||╭────────╯        │────────╮╰────────╯        │
 * ╰────────╯         │        │        │        ╰────────╮╰────────╯              ╰────────╯╭────────╯        │        │        │         ╰────────╯
 *                    │        ╰────────╯        │        ╰────────╮                ╭────────╯        │        ╰────────╯        │
 *                    ╰encoder0╯        ╰────────╯        │        │                │        │        ╰────────╯        ╰encoder3╯
 *                                               ╰────────╯        │                │        ╰────────╯
 *                                                        ╰────────╯                ╰────────╯
 *
 */
 [_LOWER] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷      ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_IMP,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                             KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
    CMDESC,   KC_LPRN,  KC_RPRN,  KC_LCBR,  KC_RCBR,  KC_LBRC,                             KC_RBRC,  KC_GRV,   XXXXXXX,  KC_DQUO,  KC_QUOT,  XXXXXXX,
    XXXXXXX,  KC_EQL,   KC_PLUS,  KC_MINS,  KC_UNDS,  XXXXXXX,  KC_LBRC,         KC_RBRC,  XXXXXXX,  KC_TILD,  XXXXXXX,  KC_PIPE,  KC_BSLS,  XXXXXXX,
                        SCRNCAP,  _______,  _______,  _______,  _______,         _______,  _______,  _______,  _______,  THECLAW
 ),


 /* Layer: _ADJUST
 *                            ╭────────╮                                                                        ╭────────╮
 *                   ╭────────╯        ╰────────╮          ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮          ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ╭────────╯        │        │        │
 *          ╭────────╯        ╰────────╯        │        ├─╯                                ╰─┤        │        ╰────────╯        ╰────────╮
 * ╭────────│        ╰────────╯        ╰────────╯        │                                    │        ╰────────╯        ╰────────╯        ╰────────╮
 * │        │        │        │        │        ╰────────╯                                    ╰────────╯        │        │        │        │        │
 * │        ╰────────╯        ╰────────╯        │        │                                    │        │        ╰────────╯        ╰────────╯        │
 * ╰────────╯        ╰────────╯        ╰────────╯        │                                    │        ╰────────╯        ╰────────╯        ╰────────╯
 * │        │        │        │        │        ╰────────╯                                    ╰────────╯        │        │        │        │        │
 * │        ╰────────╯        ╰────────╯        │        │                                    │        │        ╰────────╯        ╰────────╯        │
 * ╰────────╯        ╰────────╯||||||||╰────────╯        │ ╭────────╮              ╭────────╮ │        ╰────────╯||||||||╰────────╯        ╰────────╯
 * │        │        │ ||||||||╭────────╮|||||||╰────────╯ │        │              │        │ ╰────────╯|||||||╭────────╮|||||||| │        │        │
 * │        ╰────────╯╭────────╯        ╰────────╮|||||||| │        │              │        │ ||||||||╭────────╯        │────────╮╰────────╯        │
 * ╰────────╯         │        │        │        ╰────────╮╰────────╯              ╰────────╯╭────────╯        │        │        │         ╰────────╯
 *                    │        ╰────────╯        │        ╰────────╮                ╭────────╯        │        ╰────────╯        │
 *                    ╰encoder0╯        ╰────────╯        │        │                │        │        ╰────────╯        ╰encoder3╯
 *                                               ╰────────╯        │                │        ╰────────╯
 *                                                        ╰────────╯                ╰────────╯
 *
 */
 [_ADJUST] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷      ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  W_SHOW,   W_TTHRD,  XXXXXXX,  RGB_RMOD,                            RGB_MOD,  XXXXXXX,  W_THALF,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  W_LTHRD,  W_MAX,    W_RTHRD,  RGB_HUD,                             RGB_HUI,  W_LHALF,  W_CENT,   W_RHALF,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  W_BTHRD,  XXXXXXX,  RGB_VAD,  XXXXXXX,         XXXXXXX,  RGB_VAI,  XXXXXXX,  W_BHALF,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                        RGB_TOG,  _______,  _______,  _______,  _______,         _______,  _______,  _______,  _______,  RGB_TOG
 ),


 /* Layer: _NUM
 *                            ╭────────╮                                                                        ╭────────╮
 *                   ╭────────╯        ╰────────╮          ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮          ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ╭────────╯        │        │        │
 *          ╭────────╯        ╰────────╯        │        ├─╯                                ╰─┤        │        ╰────────╯        ╰────────╮
 * ╭────────│        ╰────────╯        ╰────────╯        │                                    │        ╰────────╯        ╰────────╯        ╰────────╮
 * │        │        │        │        │        ╰────────╯                                    ╰────────╯        │        │        │        │        │
 * │        ╰────────╯        ╰────────╯        │        │                                    │        │        ╰────────╯        ╰────────╯        │
 * ╰────────╯        ╰────────╯        ╰────────╯        │                                    │        ╰────────╯        ╰────────╯        ╰────────╯
 * │        │        │        │        │        ╰────────╯                                    ╰────────╯        │        │        │        │        │
 * │        ╰────────╯        ╰────────╯        │        │                                    │        │        ╰────────╯        ╰────────╯        │
 * ╰────────╯        ╰────────╯||||||||╰────────╯        │ ╭────────╮              ╭────────╮ │        ╰────────╯||||||||╰────────╯        ╰────────╯
 * │        │        │ ||||||||╭────────╮|||||||╰────────╯ │        │              │        │ ╰────────╯|||||||╭────────╮|||||||| │        │        │
 * │        ╰────────╯╭────────╯        ╰────────╮|||||||| │        │              │        │ ||||||||╭────────╯        │────────╮╰────────╯        │
 * ╰────────╯         │        │        │        ╰────────╮╰────────╯              ╰────────╯╭────────╯        │        │        │         ╰────────╯
 *                    │        ╰────────╯        │        ╰────────╮                ╭────────╯        │        ╰────────╯        │
 *                    ╰encoder0╯        ╰────────╯        │        │                │        │        ╰────────╯        ╰encoder3╯
 *                                               ╰────────╯        │                │        ╰────────╯
 *                                                        ╰────────╯                ╰────────╯
 *
 */
 [_NUM] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷      ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    _______,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_COLN,  _______,
    _______,  KC_EQL,   KC_PLUS,  KC_MINS,  KC_COMM,  KC_DOT,   XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,
                        _______,  _______,  _______,  _______,  _______,         _______,  _______,  _______,  _______,  _______
 ),


/* Layer: _SAMPLE
 *                            ╭────────╮                                                                        ╭────────╮
 *                   ╭────────╯        ╰────────╮          ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮          ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ╭────────╯        │        │        │
 *          ╭────────╯        ╰────────╯        │        ├─╯                                ╰─┤        │        ╰────────╯        ╰────────╮
 * ╭────────│        ╰────────╯        ╰────────╯        │                                    │        ╰────────╯        ╰────────╯        ╰────────╮
 * │        │        │        │        │        ╰────────╯                                    ╰────────╯        │        │        │        │        │
 * │        ╰────────╯        ╰────────╯        │        │                                    │        │        ╰────────╯        ╰────────╯        │
 * ╰────────╯        ╰────────╯        ╰────────╯        │                                    │        ╰────────╯        ╰────────╯        ╰────────╯
 * │        │        │        │        │        ╰────────╯                                    ╰────────╯        │        │        │        │        │
 * │        ╰────────╯        ╰────────╯        │        │                                    │        │        ╰────────╯        ╰────────╯        │
 * ╰────────╯        ╰────────╯||||||||╰────────╯        │ ╭────────╮              ╭────────╮ │        ╰────────╯||||||||╰────────╯        ╰────────╯
 * │        │        │ ||||||||╭────────╮|||||||╰────────╯ │        │              │        │ ╰────────╯|||||||╭────────╮|||||||| │        │        │
 * │        ╰────────╯╭────────╯        ╰────────╮|||||||| │        │              │        │ ||||||||╭────────╯        │────────╮╰────────╯        │
 * ╰────────╯         │        │        │        ╰────────╮╰────────╯              ╰────────╯╭────────╯        │        │        │         ╰────────╯
 *                    │        ╰────────╯        │        ╰────────╮                ╭────────╯        │        ╰────────╯        │
 *                    ╰encoder0╯        ╰────────╯        │        │                │        │        ╰────────╯        ╰encoder3╯
 *                                               ╰────────╯        │                │        ╰────────╯
 *                                                        ╰────────╯                ╰────────╯
 *
 *
 *[_SAMPLE] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷      ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
 *   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 *   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 *   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 *   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 *                       _______,  _______,  _______,  _______,  _______,         _______,  _______,  _______,  _______,  _______
 *),
 */
};


// Custom Keycode Output
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


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {

    if (is_keyboard_master()) {
        return OLED_ROTATION_90;
    } else {
	    return OLED_ROTATION_270;
    }
}
static void render_logo(void) {
  static const char PROGMEM tentacles_logo[] = {
    // 'tentacles2-oled', 64x128px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x80, 0x60, 0x30, 0x50, 0x28, 0x88, 0xcc, 0x4c, 0xc4, 0x84, 0x0c, 0x48, 0xd8, 0x90,
    0x30, 0x60, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x0c, 0x06, 0x02, 0x02, 0x07, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x3e, 0xc3, 0x80, 0xfc, 0x06, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x05, 0x6e, 0x9e,
    0xb0, 0xe0, 0x01, 0x1f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x78, 0x06,
    0x03, 0x00, 0x00, 0x02, 0x00, 0x00, 0x80, 0x74, 0x1e, 0x07, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0x58, 0xec, 0x77,
    0x1b, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xc0, 0xe0, 0x90, 0x50, 0xf0, 0x2c, 0x2e, 0x11, 0x94, 0x4b, 0x81, 0x40, 0x60, 0x30,
    0x18, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0e,
    0x18, 0x60, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x08, 0x03, 0x06, 0x18, 0x30, 0x40, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x60, 0xe0, 0xdc, 0x12,
    0x29, 0x17, 0x04, 0x00, 0xa2, 0x71, 0x38, 0x1c, 0x8e, 0x67, 0x23, 0x11, 0x90, 0xd0, 0x70, 0x30,
    0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0,
    0x40, 0xa0, 0xa1, 0xe3, 0x7c, 0x20, 0x60, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0f, 0xb8,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x99, 0x7e, 0xf2, 0x07, 0x02, 0x00,
    0xe0, 0xcc, 0x38, 0x03, 0x01, 0x00, 0x00, 0x7f, 0xf3, 0x40, 0x00, 0x07, 0x3f, 0x30, 0x20, 0xe0,
    0xc0, 0x60, 0x60, 0x60, 0x20, 0xb0, 0xf0, 0x78, 0x78, 0x3c, 0x3e, 0x1e, 0xdf, 0x4d, 0x4e, 0x06,
    0x87, 0x43, 0x01, 0x00, 0x02, 0x11, 0x08, 0x00, 0x00, 0x80, 0x40, 0x20, 0x50, 0x22, 0x9c, 0xdf,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x8d, 0x18, 0x79, 0x00, 0x00, 0x00,
    0x03, 0x27, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x04, 0x0c, 0x0c, 0x08, 0x08,
    0x08, 0x8c, 0x6c, 0x1e, 0x07, 0x01, 0x00, 0x00, 0x02, 0x01, 0xd0, 0x01, 0x00, 0x02, 0x20, 0xc0,
    0x60, 0x20, 0x10, 0x10, 0x18, 0x18, 0x0c, 0x0c, 0x04, 0x04, 0x82, 0x83, 0x83, 0x83, 0x81, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x13, 0x22, 0xdc, 0x81, 0x04,
    0x40, 0x00, 0x00, 0x07, 0x18, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0,
    0x3e, 0x01, 0x00, 0x00, 0x02, 0x00, 0x80, 0x00, 0x00, 0x03, 0x20, 0xe0, 0x18, 0x0e, 0x03, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xf1, 0x1c, 0x06, 0x03, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x19, 0xf7,
    0xe0, 0xc0, 0x00, 0x80, 0xc1, 0x60, 0x26, 0x38, 0xa0, 0xe0, 0x60, 0xf0, 0xd8, 0x48, 0x4c, 0xcf,
    0x4c, 0x78, 0xb8, 0xfb, 0x70, 0x70, 0xf0, 0x90, 0x90, 0x90, 0xb7, 0xff, 0xc0, 0x80, 0xc0, 0x40,
    0x80, 0x80, 0x80, 0x00, 0x00, 0x03, 0x0c, 0x18, 0x60, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xd0, 0x78, 0x24,
    0xe2, 0x52, 0xcb, 0x6f, 0x3d, 0x97, 0x5b, 0x0f, 0x06, 0x02, 0x03, 0x02, 0x02, 0x06, 0x03, 0x03,
    0x81, 0x80, 0x81, 0x81, 0x02, 0x02, 0x01, 0x01, 0x03, 0x03, 0x04, 0x04, 0x07, 0x03, 0x03, 0x02,
    0x02, 0x04, 0x04, 0x07, 0x06, 0x07, 0x0d, 0x09, 0x09, 0x1e, 0x0e, 0x07, 0x06, 0x06, 0x05, 0x05,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xee, 0x73, 0xd0, 0x4c, 0x6f, 0xdb,
    0x8c, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x18, 0x1c, 0x1c, 0xf2, 0x02, 0x02,
    0x02, 0x02, 0x02, 0x0e, 0x1e, 0x7e, 0xde, 0x8e, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x4c, 0x08,
    0x08, 0x08, 0x18, 0x18, 0x18, 0x18, 0x30, 0x70, 0x70, 0xf0, 0xb0, 0x30, 0x38, 0x98, 0x38, 0x18,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x61, 0xc0, 0x63, 0xbf, 0xc8, 0x58, 0xff,
    0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xbf, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x0c, 0x18, 0x32, 0x64, 0xcc, 0x98,
    0x10, 0x20, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x01, 0x03, 0x06, 0x0c, 0x09, 0x1a,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x33, 0xc3, 0xc7, 0x7f, 0x08, 0x91,
    0xc7, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0c, 0x18, 0x3f, 0x4c, 0xc8, 0x88,
    0x10, 0x18, 0x18, 0x08, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x24, 0x04, 0x04, 0x04, 0x04, 0x04,
    0x09, 0x4a, 0x1e, 0x3c, 0x70, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8e, 0xfb, 0xe3, 0xc6, 0x8d,
    0x9b, 0x24, 0x88, 0x11, 0xc7, 0xf8, 0x30, 0x20, 0x60, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x01,
    0x03, 0x03, 0x06, 0x06, 0x04, 0x04, 0x0c, 0x00, 0x08, 0x08, 0x08, 0x10, 0x10, 0x10, 0x30, 0x30,
    0x20, 0x00, 0x40, 0x80, 0x80, 0x80, 0x07, 0x1f, 0xff, 0xfe, 0xf8, 0xe0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0x98, 0xfe, 0xe7, 0xf1, 0x5d, 0xdf, 0xb3,
    0xcf, 0x6d, 0x19, 0x09, 0x13, 0x17, 0x3f, 0x76, 0xf4, 0xbc, 0x38, 0x3f, 0x7f, 0xe6, 0xe7, 0x46,
    0x4e, 0xcc, 0xd8, 0x70, 0x60, 0xe0, 0xa0, 0x20, 0x20, 0x60, 0x70, 0xc0, 0xa0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x47, 0x0f, 0x1f, 0x3f, 0x60, 0x80, 0x00, 0x00
  };
  oled_write_raw_P(tentacles_logo, sizeof(tentacles_logo));
}

static void render_status(void) {

    oled_write_ln_P(PSTR("$su\ninit -kb\nursula_40\n\n"), false);
    oled_write_ln_P(PSTR("welc0me\nchewiedies"), false);

    oled_write_ln_P(PSTR("\n\n\n"), false);

    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CAPS"), led_usb_state.caps_lock);

    oled_write_ln_P(PSTR("\n"), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR(">_ BASE\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR(">_ NAV\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR(">_ SYMBLS\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR(">_ CONFIG\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR(">_ NUMROW\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR(">_ ERR0R"), false);
    }
}

bool oled_task_user(void) {
      if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();
    }
    return false;
}

#endif

// Two Encoder Support
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
                register_code16(KC_LGUI);
                register_code16(KC_LALT);
                tap_code16(KC_RGHT);
                unregister_code16(KC_LGUI);
                unregister_code16(KC_LALT);
            } else {
                register_code16(KC_LGUI);
                register_code16(KC_LALT);
                tap_code16(KC_LEFT);
                unregister_code16(KC_LGUI);
                unregister_code16(KC_LALT);
            }
            break;

        case _RAISE:
            if (clockwise) {
                tap_code16(KC_PGDN);
            } else {
                tap_code16(KC_PGUP);
            }
            break;

        case _ADJUST:
            if (clockwise) {
                #ifdef RGBLIGHT_ENABLE
                    rgblight_step();
                #endif
            } else {
                #ifdef RGBLIGHT_ENABLE
                    rgblight_step_reverse();
                #endif
            }
            break;
        }
    } else if (index == 1) {

        switch(biton32(layer_state)) {
        case _QWERTY:
            if (!clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        case _RAISE:
            if (!clockwise) {
                tap_code16(G(KC_GRV));
            } else {
                tap_code16(G(S(KC_GRV)));
            }
            break;
        case _LOWER:
            if (!clockwise) {
                tap_code16(KC_END);
            } else {
                tap_code16(KC_HOME);
            }
            break;

        case _ADJUST:
            if (clockwise) {
                #ifdef RGBLIGHT_ENABLE
                    rgblight_increase_val();
                #endif
            } else {
                #ifdef RGBLIGHT_ENABLE
                    rgblight_decrease_val();
                #endif
            }
            break;
        }
    } else if (index == 2) {

        if (!clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }

    } else if (index == 3) {
        if (!clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

#endif


void matrix_scan_user(void) {

    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 900) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
      }
    }

}
