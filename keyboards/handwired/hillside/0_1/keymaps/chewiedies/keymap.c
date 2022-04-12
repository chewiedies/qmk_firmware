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
#define CALCAPP LCTL(LGUI(LSFT(KC_C)))
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

/* Layer: _QWERTY
 *                            ╭────────╮                                                                                   ╭────────╮
 *                   ╭────────╯        ╰────────╮                                                                 ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                                               ╭────────╯        │        │        │
 * ╭────────╭────────╯        ╰────────╯        │        │                                               │        │        ╰────────╯        ╰────────╮────────╮
 * │        │        ╰────────╯        ╰────────╯        │                                               │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │        │        ╰────────╯                                               ╰────────╯        │        │        │        │        │
 * ╰────────╰────────╯        ╰────────╯        │        │                                               │        │        ╰────────╯        ╰────────╯────────╯
 * │        │        ╰────────╯        ╰────────╯        │                                               │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │        │        ╰────────╯                                               ╰────────╯        │        │        │        │        │
 * ╰────────╰────────╯        ╰────────╯        │        │ ╭────────╮                         ╭────────╮ │        │        ╰────────╯        ╰────────╯────────╯
 * │        │        ╰────────╯        ╰────────╯        │ │        │                         │        │ │        ╰────────╯        ╰────────╯        │        │
 * │        │        │╭────────╮       ╭────────╰────────╯ │        │                         │        │ ╰────────╯────────╮       ╭────────╮│        │        │
 * ╰────────╰────────╯│        │       │        ╰────────╮ ╰────────╯                         ╰────────╯ ╭────────╯        │       │        │╰────────╯────────╯
 *                    │        │       │        │        ╰────────╮                             ╭────────╯        │        │       │        │
 *                    ╰─encodr─╯       ╰────────╯        │        ╰────────╮           ╭────────╯        │        ╰────────╯       ╰─encodr─╯
 *                                              ╰────────╯        │        │           │        │        ╰────────╯
 *                                                       ╰────────╯        │           │        ╰────────╯
 *                                                                ╰────────╯           ╰────────╯
 *
 */
[_QWERTY] = LAYOUT(
  ALTTAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                                 KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,     KC_BSPC,
  CMDESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                                 KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
  KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_BSPC,                          KC_EQL,   KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  ALTENT,
                      PSTBRD,             KC_LCBR,  RAISE,    SFTSPC,   NUMENT,       NUMMIN,   KC_SPC,   LOWER,    KC_RCBR,            KC_MUTE
),


/* Layer: _RAISE
 *                            ╭────────╮                                                                                   ╭────────╮
 *                   ╭────────╯        ╰────────╮                                                                 ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                                               ╭────────╯        │        │        │
 * ╭────────╭────────╯        ╰────────╯        │        │                                               │        │        ╰────────╯        ╰────────╮────────╮
 * │        │        ╰────────╯        ╰────────╯        │                                               │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │        │        ╰────────╯                                               ╰────────╯        │        │        │        │        │
 * ╰────────╰────────╯        ╰────────╯        │        │                                               │        │        ╰────────╯        ╰────────╯────────╯
 * │        │        ╰────────╯        ╰────────╯        │                                               │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │        │        ╰────────╯                                               ╰────────╯        │        │        │        │        │
 * ╰────────╰────────╯        ╰────────╯        │        │ ╭────────╮                         ╭────────╮ │        │        ╰────────╯        ╰────────╯────────╯
 * │        │        ╰────────╯        ╰────────╯        │ │        │                         │        │ │        ╰────────╯        ╰────────╯        │        │
 * │        │        │╭────────╮       ╭────────╰────────╯ │        │                         │        │ ╰────────╯────────╮       ╭────────╮│        │        │
 * ╰────────╰────────╯│        │       │        ╰────────╮ ╰────────╯                         ╰────────╯ ╭────────╯        │       │        │╰────────╯────────╯
 *                    │        │       │        │        ╰────────╮                             ╭────────╯        │        │       │        │
 *                    ╰─encodr─╯       ╰────────╯        │        ╰────────╮           ╭────────╯        │        ╰────────╯       ╰─encodr─╯
 *                                              ╰────────╯        │        │           │        │        ╰────────╯
 *                                                       ╰────────╯        │           │        ╰────────╯
 *                                                                ╰────────╯           ╰────────╯
 *
 */
[_RAISE] = LAYOUT(
  SFTTAB,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                              PGTOP,    PRVWRD,   KC_UP,    NXTWRD,   XXXXXXX,  KC_DEL,
  KCUNDO,   KCREDO,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                              XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSPC,  XXXXXXX,                          XXXXXXX,  PGBOT,    LNBEG,    XXXXXXX,  LNEND,    XXXXXXX,  XXXXXXX,
                      XXXXXXX,            XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,      XXXXXXX,  SFTSPC,   _______,  XXXXXXX,            XXXXXXX
),


/* Layer: _LOWER
 *                            ╭────────╮                                                                                   ╭────────╮
 *                   ╭────────╯        ╰────────╮                                                                 ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                                               ╭────────╯        │        │        │
 * ╭────────╭────────╯        ╰────────╯        │        │                                               │        │        ╰────────╯        ╰────────╮────────╮
 * │        │        ╰────────╯        ╰────────╯        │                                               │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │        │        ╰────────╯                                               ╰────────╯        │        │        │        │        │
 * ╰────────╰────────╯        ╰────────╯        │        │                                               │        │        ╰────────╯        ╰────────╯────────╯
 * │        │        ╰────────╯        ╰────────╯        │                                               │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │        │        ╰────────╯                                               ╰────────╯        │        │        │        │        │
 * ╰────────╰────────╯        ╰────────╯        │        │ ╭────────╮                         ╭────────╮ │        │        ╰────────╯        ╰────────╯────────╯
 * │        │        ╰────────╯        ╰────────╯        │ │        │                         │        │ │        ╰────────╯        ╰────────╯        │        │
 * │        │        │╭────────╮       ╭────────╰────────╯ │        │                         │        │ ╰────────╯────────╮       ╭────────╮│        │        │
 * ╰────────╰────────╯│        │       │        ╰────────╮ ╰────────╯                         ╰────────╯ ╭────────╯        │       │        │╰────────╯────────╯
 *                    │        │       │        │        ╰────────╮                             ╭────────╯        │        │       │        │
 *                    ╰─encodr─╯       ╰────────╯        │        ╰────────╮           ╭────────╯        │        ╰────────╯       ╰─encodr─╯
 *                                              ╰────────╯        │        │           │        │        ╰────────╯
 *                                                       ╰────────╯        │           │        ╰────────╯
 *                                                                ╰────────╯           ╰────────╯
 *
 */
[_LOWER] = LAYOUT(
  KC_IMP,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                                              KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
  CMDESC,   XXXXXXX,  THECLAW,  KC_LPRN,  KC_RPRN,  KC_LCBR,                                              KC_RCBR,  KC_EQL,   KC_GRV,   XXXXXXX,  KC_BSLS,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LBRC,  XXXXXXX,                          XXXXXXX,  KC_RBRC,  KC_PLUS,  KC_TILD,  XXXXXXX,  KC_PIPE,  XXXXXXX,
                      SCRNCAP,            _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,            XXXXXXX
),


/* Layer: _ADJUST
 *                            ╭────────╮                                                                                   ╭────────╮
 *                   ╭────────╯        ╰────────╮                                                                 ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                                               ╭────────╯        │        │        │
 * ╭────────╭────────╯        ╰────────╯        │        │                                               │        │        ╰────────╯        ╰────────╮────────╮
 * │        │        ╰────────╯        ╰────────╯        │                                               │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │        │        ╰────────╯                                               ╰────────╯        │        │        │        │        │
 * ╰────────╰────────╯        ╰────────╯        │        │                                               │        │        ╰────────╯        ╰────────╯────────╯
 * │        │        ╰────────╯        ╰────────╯        │                                               │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │        │        ╰────────╯                                               ╰────────╯        │        │        │        │        │
 * ╰────────╰────────╯        ╰────────╯        │        │ ╭────────╮                         ╭────────╮ │        │        ╰────────╯        ╰────────╯────────╯
 * │        │        ╰────────╯        ╰────────╯        │ │        │                         │        │ │        ╰────────╯        ╰────────╯        │        │
 * │        │        │╭────────╮       ╭────────╰────────╯ │        │                         │        │ ╰────────╯────────╮       ╭────────╮│        │        │
 * ╰────────╰────────╯│        │       │        ╰────────╮ ╰────────╯                         ╰────────╯ ╭────────╯        │       │        │╰────────╯────────╯
 *                    │        │       │        │        ╰────────╮                             ╭────────╯        │        │       │        │
 *                    ╰─encodr─╯       ╰────────╯        │        ╰────────╮           ╭────────╯        │        ╰────────╯       ╰─encodr─╯
 *                                              ╰────────╯        │        │           │        │        ╰────────╯
 *                                                       ╰────────╯        │           │        ╰────────╯
 *                                                                ╰────────╯           ╰────────╯
 *
 */
[_ADJUST] = LAYOUT(
  XXXXXXX,  XXXXXXX,  W_SHOW,   W_TTHRD,  XXXXXXX,  RGB_TOG,                                              RGB_TOG,  XXXXXXX,  W_THALF,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  W_LTHRD,  W_MAX,    W_RTHRD,  RGB_HUD,                                              RGB_HUI,  W_LHALF,  W_CENT,   W_RHALF,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  W_BTHRD,  XXXXXXX,  RGB_VAD,  RGB_RMOD,                         RGB_MOD,  RGB_VAI,  XXXXXXX,  W_BHALF,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                      XXXXXXX,            _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,            XXXXXXX
),


/* Layer: _NUM
 *                            ╭────────╮                                                                                   ╭────────╮
 *                   ╭────────╯        ╰────────╮                                                                 ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                                               ╭────────╯        │        │        │
 * ╭────────╭────────╯        ╰────────╯        │        │                                               │        │        ╰────────╯        ╰────────╮────────╮
 * │        │        ╰────────╯        ╰────────╯        │                                               │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │        │        ╰────────╯                                               ╰────────╯        │        │        │        │        │
 * ╰────────╰────────╯        ╰────────╯        │        │                                               │        │        ╰────────╯        ╰────────╯────────╯
 * │        │        ╰────────╯        ╰────────╯        │                                               │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │        │        ╰────────╯                                               ╰────────╯        │        │        │        │        │
 * ╰────────╰────────╯        ╰────────╯        │        │ ╭────────╮                         ╭────────╮ │        │        ╰────────╯        ╰────────╯────────╯
 * │        │        ╰────────╯        ╰────────╯        │ │        │                         │        │ │        ╰────────╯        ╰────────╯        │        │
 * │        │        │╭────────╮       ╭────────╰────────╯ │        │                         │        │ ╰────────╯────────╮       ╭────────╮│        │        │
 * ╰────────╰────────╯│        │       │        ╰────────╮ ╰────────╯                         ╰────────╯ ╭────────╯        │       │        │╰────────╯────────╯
 *                    │        │       │        │        ╰────────╮                             ╭────────╯        │        │       │        │
 *                    ╰─encodr─╯       ╰────────╯        │        ╰────────╮           ╭────────╯        │        ╰────────╯       ╰─encodr─╯
 *                                              ╰────────╯        │        │           │        │        ╰────────╯
 *                                                       ╰────────╯        │           │        ╰────────╯
 *                                                                ╰────────╯           ╰────────╯
 *
 */
[_NUM] = LAYOUT(
  _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                                 KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
  _______,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,                                                 XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,
  _______,  KC_EQL,   KC_PLUS,  KC_MINS,  KC_COMM,  KC_DOT,   XXXXXXX,                          XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,
                      CALCAPP,            _______,  _______,  SFTSPC,   _______,      _______,  SFTSPC,   _______,  _______,            XXXXXXX
)


/* Layer: SAMPLE
 *                            ╭────────╮                                                                                   ╭────────╮
 *                   ╭────────╯        ╰────────╮                                                                 ╭────────╯        ╰────────╮
 *                   │        │        │        ╰────────╮                                               ╭────────╯        │        │        │
 * ╭────────╭────────╯        ╰────────╯        │        │                                               │        │        ╰────────╯        ╰────────╮────────╮
 * │        │        ╰────────╯        ╰────────╯        │                                               │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │        │        ╰────────╯                                               ╰────────╯        │        │        │        │        │
 * ╰────────╰────────╯        ╰────────╯        │        │                                               │        │        ╰────────╯        ╰────────╯────────╯
 * │        │        ╰────────╯        ╰────────╯        │                                               │        ╰────────╯        ╰────────╯        │        │
 * │        │        │        │        │        ╰────────╯                                               ╰────────╯        │        │        │        │        │
 * ╰────────╰────────╯        ╰────────╯        │        │ ╭────────╮                         ╭────────╮ │        │        ╰────────╯        ╰────────╯────────╯
 * │        │        ╰────────╯        ╰────────╯        │ │        │                         │        │ │        ╰────────╯        ╰────────╯        │        │
 * │        │        │╭────────╮       ╭────────╰────────╯ │        │                         │        │ ╰────────╯────────╮       ╭────────╮│        │        │
 * ╰────────╰────────╯│        │       │        ╰────────╮ ╰────────╯                         ╰────────╯ ╭────────╯        │       │        │╰────────╯────────╯
 *                    │        │       │        │        ╰────────╮                             ╭────────╯        │        │       │        │
 *                    ╰─encodr─╯       ╰────────╯        │        ╰────────╮           ╭────────╯        │        ╰────────╯       ╰─encodr─╯
 *                                              ╰────────╯        │        │           │        │        ╰────────╯
 *                                                       ╰────────╯        │           │        ╰────────╯
 *                                                                ╰────────╯           ╰────────╯
 *
 *
 *[_SAMPLE] = LAYOUT(
 * XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 * XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 * XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
 *                     XXXXXXX,            _______,  XXXXXXX,  XXXXXXX, XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,            XXXXXXX
 *),
 */
};


#ifdef OLED_ENABLE

/* 32 * 32 logo */
static void render_logo(void) {
    static const char PROGMEM hell_logo[] = {0x00, 0x80, 0xc0, 0xc0, 0x60, 0x60, 0x30, 0x30, 0x18, 0x1c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0x78, 0x1e, 0x06, 0x00, 0x0c, 0x1c, 0x18, 0x30, 0x30, 0x60, 0x60, 0xc0, 0xc0, 0x80, 0x00, 0x01, 0x03, 0x07, 0x06, 0x0c, 0x0c, 0x18, 0x18, 0x30, 0x70, 0x60, 0x00, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x60, 0x70, 0x30, 0x18, 0x18, 0x0c, 0x0c, 0x06, 0x07, 0x03, 0x01, 0x00, 0xf8, 0xf8, 0x80, 0x80, 0x80, 0xf8, 0xf8, 0x00, 0x80, 0xc0, 0xc0, 0x40, 0xc0, 0xc0, 0x80, 0x00, 0xf8, 0xf8, 0x00, 0xf8, 0xf8, 0x00, 0x08, 0x38, 0x08, 0x00, 0x38, 0x08, 0x30, 0x08, 0x38, 0x00, 0x1f, 0x1f, 0x01, 0x01, 0x01, 0x1f, 0x1f, 0x00, 0x0f, 0x1f, 0x1a, 0x12, 0x1a, 0x1b, 0x0b, 0x00, 0x1f, 0x1f, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    oled_write_raw_P(hell_logo, sizeof(hell_logo));
}

/* 32 * 14 os logos */
// static const char PROGMEM windows_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xbc, 0xbe, 0xbe, 0x00, 0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static const char PROGMEM mac_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0xf6, 0xfb, 0xfb, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

/* Smart Backspace Delete */

/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       40

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }};

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }

    /* this fixes the screen on and off bug */
    // if (current_wpm > 0) {
    //     oled_on();
    //     anim_sleep = timer_read32();
    // } else if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
    //     oled_off();
    // }
}

/* KEYBOARD PET END */

static void print_logo_narrow(void) {
    render_logo();

    /* wpm counter */
    uint8_t n = get_current_wpm();
    char    wpm_str[4];
    oled_set_cursor(0, 14);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0, 15);
    oled_write(" wpm", false);
}

static void print_status_narrow(void) {
    /* Print current mode */
    oled_set_cursor(0, 0);
    // if (keymap_config.swap_lctl_lgui) {
         oled_write_raw_P(mac_logo, sizeof(mac_logo));
    // } else {
    //    oled_write_raw_P(windows_logo, sizeof(windows_logo));
    // }

    oled_set_cursor(0, 3);

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write("QWRTY", false);
            break;
        default:
            oled_write("UNDEF", false);
    }

    oled_set_cursor(0, 5);

    /* Print current layer */
    oled_write("LAYER", false);

    oled_set_cursor(0, 6);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Navi\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Symb\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    /* caps lock */
    oled_set_cursor(0, 8);
    oled_write("CPSLK", led_usb_state.caps_lock);

    /* KEYBOARD PET RENDER START */

    render_luna(0, 13);

    /* KEYBOARD PET RENDER END */
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
    return false;
}

#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_RAISE, _LOWER, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_RAISE, _LOWER, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_RAISE, _LOWER, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_RAISE, _LOWER, _ADJUST);
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
        case KC_LGUI:
        case KC_RGUI:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;

        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
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
                rgblight_step();
            } else {
                rgblight_step_reverse();
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
                rgblight_increase_val();
            } else {
                rgblight_decrease_val();
            }
            break;

        case _ADJUST:
            if (clockwise) {
                rgblight_increase_speed();
            } else {
                rgblight_decrease_speed();
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
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 3);
        // rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
        // rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        // rgblight_sethsv(HSV_PURPLE);
    }
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 750) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
      }
    }
};
