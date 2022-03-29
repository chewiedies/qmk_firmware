#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _GAMING 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  GAMING,
  LOWER,
  RAISE,
  ADJUST,
  KC_PRVWD,
  KC_NXTWD,
  KC_LSTRT,
  KC_LEND,
  KC_PTBD,
  KC_SFTB,
  KC_MDIAQ,
  KC_IMP,
  KC_REDO,
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
  W_LSCRN,
  W_RSCRN,
  W_TLEFT,
  W_TRGHT,
  W_BLEFT,
  W_BRGHT,
  W_LRGR,
  W_SMLR,
  W_UNDO
};

#define EISU LCAG_T(KC_BSLS)

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |  +   |                    |   =  |   6  |   7  |   8  |   9  |   0  |  -   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |  ~   |                    |   `  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | C/A/G|   A  |   S  |   D  |   F  |   G  |  {   |                    |   }  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Bksp | Enter|      | Vol- | Vol+ |   N  |   M  |   ,  |   .  |   /  | Enter|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space| Enter|||||||| Bksp | Space| Raise|||||||| Home | PgUp | PgDn | End  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    RGB_RMOD,                       RGB_MOD, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_GRV,                         KC_EQL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    EISU,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                        KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_BSPC,                        KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT), \
    KC_LCTL, KC_LALT, KC_PTBD, KC_LGUI,          RAISE,   KC_SPC,   KC_ENT,      KC_BSPC, KC_SPC,  LOWER,            KC_HOME, KC_PGUP, KC_PGDN, KC_END \
  ),

  /* Gaming */
  [_GAMING] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_H,                           RGB_MOD, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, \
    KC_TAB,  XXXXXXX, KC_W,    KC_E,    KC_R,    KC_6,    KC_9,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    EISU,    KC_A,    KC_S,    KC_D,    XXXXXXX, KC_7,    KC_0,                           XXXXXXX, KC_H,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_8,    KC_B,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_LSFT, KC_LALT, KC_M,    KC_LGUI,          RAISE,   KC_SPC, KC_ESC,         KC_ENT, KC_SPC,  LOWER,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
  ),
  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, KC_CLAW, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, _______, _______,          RAISE,   XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, LOWER,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_UNDO, KC_REDO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PLUS,  \
    KC_SFTB, KC_IMP,  KC_MDIAQ,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_PLUS, KC_CIRC, KC_PRVWD,KC_UP,   KC_NXTWD, KC_RPRN, KC_DEL, \
    EISU,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_BSPC, KC_H,    KC_LEFT, KC_DOWN, KC_RGHT,  KC_COLN, KC_DQT , \
    KC_LSFT, XXXXXXX, KC_CUT,  KC_COPY, KC_PASTE,XXXXXXX, KC_SPC ,                        KC_ENT , KC_N,    KC_LSTRT,XXXXXXX, KC_LEND,  KC_QUES, KC_RSFT, \
    KC_LCTL, KC_LALT, KC_PTBD, KC_LGUI,          RAISE,   KC_SPC ,KC_DEL,         KC_BSPC,KC_ENT , LOWER,            KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|  INC|   DEC|      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______, RGB_HUD,                       RGB_HUI, _______, _______, _______, _______, _______, _______, \
    _______, _______, W_SMLR,  W_TTHRD, W_LRGR,  _______, _______,                       _______, _______, W_TLEFT, W_THALF, W_TRGHT, _______, _______, \
    KC_CAPS, _______, W_LTHRD, W_MAX,   W_RTHRD, _______, W_LSCRN,                       W_RSCRN, _______, W_LHALF, W_CENT,  W_RHALF, _______, _______, \
    _______, W_UNDO,  _______, W_BTHRD, _______, _______, _______,                       _______, _______, W_BLEFT, W_BHALF, W_BRGHT, _______, _______, \
    _______, _______, _______, _______,          _______, _______, QWERTY,       GAMING, _______, _______,          _______, _______, _______, _______  \
  )
};


#ifdef OLED_ENABLE

static void render_logo2(void) {

    static const char PROGMEM ergodash_logonopcb[] = {
        // 'ergodash-logo-nopcb-01', 128x18px
        0x00, 0x00, 0xfe, 0xfe, 0xfe, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x06, 0x06, 0x06,
        0x06, 0x0e, 0xfe, 0xfe, 0xde, 0x9c, 0x9c, 0x9c, 0xb8, 0xf8, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xc0,
        0xfc, 0xfe, 0xfe, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x8e,
        0xfe, 0xfe, 0x8e, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0xfe,
        0xfe, 0xfe, 0x0e, 0x1c, 0x1c, 0x38, 0x38, 0x38, 0x70, 0x70, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0,
        0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xb8, 0xb8, 0x9c, 0x9c, 0x8e, 0xfe, 0xfe, 0xc0,
        0xc0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xb8, 0x9c, 0x9c, 0x9c, 0xde, 0xfe, 0xfe, 0x80, 0x80,
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xfe, 0xfe, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x7f, 0xff, 0xff, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe0, 0xe0, 0xe0,
        0xe0, 0xe0, 0xff, 0xff, 0x67, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x1d, 0x39, 0x39, 0x39, 0x71,
        0x7f, 0xff, 0xff, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe3,
        0xff, 0xff, 0xff, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xff,
        0xff, 0x7f, 0x70, 0x70, 0x38, 0x38, 0x1c, 0x1c, 0x0e, 0x0e, 0x0e, 0x07, 0x07, 0x03, 0x03, 0x03,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x7f, 0xff, 0x73,
        0x71, 0x39, 0x39, 0x39, 0x1d, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x07, 0x7f, 0x7f, 0x03, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x7f, 0xff, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(ergodash_logonopcb, sizeof(ergodash_logonopcb));
}
static void render_logo(void) {

    static const char PROGMEM ergodash_logo[] = {
        // 'ergodash-logo2-01', 128x64px
        0x00, 0x00, 0xfe, 0xfe, 0xfe, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x06, 0x06, 0x06,
        0x06, 0x0e, 0xfe, 0xfe, 0xde, 0x9c, 0x9c, 0x9c, 0xb8, 0xf8, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xc0,
        0xfc, 0xfe, 0xfe, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x8e,
        0xfe, 0xfe, 0x8e, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0xfe,
        0xfe, 0xfe, 0x0e, 0x1c, 0x1c, 0x38, 0x38, 0x38, 0x70, 0x70, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0,
        0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xb8, 0xb8, 0x9c, 0x9c, 0x8e, 0xfe, 0xfe, 0xc0,
        0xc0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xb8, 0x9c, 0x9c, 0x9c, 0xde, 0xfe, 0xfe, 0x80, 0x80,
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xfe, 0xfe, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x7f, 0xff, 0xff, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe0, 0xe0, 0xe0,
        0xe0, 0xe0, 0xff, 0xff, 0x67, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x1d, 0x39, 0x39, 0x39, 0x71,
        0x7f, 0xff, 0xff, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe3,
        0xff, 0xff, 0xff, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xff,
        0xff, 0x7f, 0x70, 0x70, 0x38, 0x38, 0x1c, 0x1c, 0x0e, 0x0e, 0x0e, 0x07, 0x07, 0x03, 0x03, 0x03,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x7f, 0xff, 0x73,
        0x71, 0x39, 0x39, 0x39, 0x1d, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x07, 0x7f, 0x7f, 0x03, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x7f, 0xff, 0x00, 0x00, 0x00,
        0x08, 0x00, 0x14, 0x78, 0x48, 0xc4, 0xc4, 0x68, 0x38, 0x14, 0x1c, 0x18, 0x10, 0x10, 0x10, 0x10,
        0x14, 0x14, 0x18, 0x18, 0x10, 0x1c, 0x18, 0x10, 0x30, 0x68, 0xd0, 0xa0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0x84, 0x04, 0x04, 0x04, 0x04, 0x08, 0x10, 0x30, 0x60, 0x44, 0xcc, 0x48, 0x50,
        0x70, 0x60, 0xc0, 0x80, 0x04, 0x00, 0x88, 0x10, 0x00, 0x00, 0x00, 0x04, 0xfc, 0xfc, 0x00, 0x00,
        0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0xb0, 0x98, 0x88, 0x84, 0x84,
        0x80, 0x80, 0x80, 0x44, 0xa4, 0x5c, 0x20, 0x10, 0x0c, 0x08, 0x88, 0xc4, 0x64, 0x30, 0x10, 0x08,
        0x04, 0x00, 0x08, 0x08, 0x04, 0x00, 0x80, 0xc0, 0x60, 0x70, 0x5c, 0x70, 0x60, 0x70, 0x70, 0x50,
        0x40, 0x98, 0x44, 0x20, 0x14, 0x00, 0x08, 0x04, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x30, 0x10, 0x08,
        0x90, 0x70, 0x30, 0xb0, 0xd0, 0x30, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x6c, 0x44, 0x44,
        0x4c, 0x38, 0x30, 0x30, 0x20, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x06, 0x0c,
        0x18, 0x31, 0x22, 0x22, 0x21, 0x20, 0x20, 0x21, 0x22, 0x66, 0xc8, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x1e, 0x98, 0x00, 0x00, 0x1f, 0x1f, 0x00, 0x00,
        0x80, 0x1f, 0x18, 0x00, 0x00, 0x1e, 0x1f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x20, 0x1f, 0x18, 0x0c, 0x06, 0x03, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x81, 0xc0, 0x60, 0x20, 0x10, 0x18, 0x08, 0x88, 0xc8, 0x48, 0xc8,
        0xc8, 0x88, 0x18, 0x1c, 0x26, 0x22, 0x22, 0x26, 0x1e, 0x19, 0x01, 0x08, 0x04, 0x02, 0x00, 0x01,
        0x80, 0x82, 0x83, 0x81, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x50, 0x10, 0x50, 0xe0, 0x40,
        0x40, 0x80, 0x20, 0x20, 0x20, 0x40, 0x00, 0x81, 0x03, 0x06, 0x04, 0x78, 0xb8, 0x98, 0x88, 0x98,
        0xf0, 0x60, 0x40, 0x40, 0x40, 0x60, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x87, 0x8f, 0x88, 0x88, 0x88,
        0x88, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x88, 0x88, 0x00, 0x00, 0x00,
        0x88, 0x88, 0x8c, 0x84, 0x82, 0x83, 0x81, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xe0, 0xb0, 0x98, 0x8c,
        0x84, 0x84, 0x84, 0x86, 0x87, 0x85, 0x84, 0x84, 0x84, 0x84, 0x84, 0x87, 0x8d, 0x88, 0x98, 0x98,
        0x88, 0x87, 0x82, 0x80, 0xc0, 0xe0, 0xb0, 0x98, 0x1c, 0x14, 0x12, 0x13, 0x11, 0x11, 0x11, 0x29,
        0x20, 0x20, 0x20, 0x20, 0x21, 0xa3, 0xe6, 0x6c, 0x28, 0x18, 0x08, 0x08, 0x08, 0x88, 0x49, 0x49,
        0x49, 0xc8, 0x88, 0x88, 0x88, 0x89, 0x89, 0x8e, 0x8d, 0x8a, 0x8c, 0x8c, 0x88, 0x89, 0x89, 0xc8,
        0x68, 0x38, 0x18, 0x08, 0x08, 0x08, 0x08, 0x88, 0xc8, 0xc8, 0xc8, 0xc8, 0xc8, 0xcc, 0xcc, 0xcc,
        0xcc, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xcc, 0x4c, 0x00, 0x00, 0x00,
        0xcc, 0x88, 0x08, 0x00, 0x11, 0x23, 0x46, 0x8c, 0x18, 0x10, 0x10, 0x10, 0x10, 0x18, 0x3c, 0x26,
        0x62, 0x26, 0x3c, 0x78, 0xc1, 0x82, 0x04, 0x09, 0x02, 0x14, 0x04, 0x04, 0x04, 0x0c, 0x12, 0x02,
        0x14, 0x20, 0x28, 0x30, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x0c, 0x0c, 0x08, 0x08, 0x08, 0x08,
        0x02, 0x82, 0x82, 0x02, 0x03, 0x41, 0xe0, 0x30, 0x10, 0x30, 0xe0, 0xc0, 0x43, 0x47, 0x4c, 0x48,
        0x48, 0x4c, 0x47, 0x43, 0x40, 0x20, 0x30, 0x18, 0x0c, 0x06, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xfc, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x07, 0x8f, 0x07, 0x03, 0x07, 0x9f, 0x9f, 0x07, 0x03,
        0x07, 0x9f, 0x0f, 0x03, 0x03, 0x8f, 0x9f, 0x07, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x01, 0xfa, 0x76, 0x8c, 0x18, 0x30, 0x21, 0x21, 0xa0, 0xa0, 0x20, 0x40, 0xc2, 0x80,
        0x0c, 0x08, 0x30, 0x60, 0xc0, 0xa1, 0xc3, 0x02, 0x04, 0x0c, 0x18, 0x30, 0x30, 0x58, 0xcc, 0x8c,
        0xcc, 0x78, 0x30, 0x20, 0x20, 0x20, 0x20, 0x20, 0x30, 0x38, 0x24, 0x32, 0x38, 0x25, 0x65, 0x45,
        0x03, 0x01, 0x00, 0x80, 0xf8, 0x08, 0x04, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0xe0, 0x30,
        0x18, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0xa0, 0x50, 0x20, 0x10, 0x10, 0x90,
        0x90, 0x60, 0x30, 0x18, 0x08, 0x8c, 0xc6, 0x63, 0x31, 0x10, 0x08, 0x84, 0xe7, 0x31, 0x10, 0x08,
        0x0c, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0x06, 0xec, 0x08, 0x18, 0x30, 0x60, 0xc0, 0xc0, 0x40,
        0x40, 0x40, 0x40, 0xc0, 0x81, 0x02, 0x05, 0x02, 0x02, 0x52, 0x97, 0x54, 0x23, 0x00, 0x00, 0x01,
        0x03, 0x06, 0x1c, 0x28, 0xd8, 0xb0, 0x60, 0xc0, 0xc0, 0x40, 0x40, 0xc0, 0xc0, 0x40, 0x40, 0x40,
        0x40, 0x40, 0x40, 0x40, 0x40, 0x60, 0xf0, 0x98, 0x08, 0x08, 0xf0, 0x60, 0x40, 0x80, 0x80, 0x40
    };
    oled_write_raw_P(ergodash_logo, sizeof(ergodash_logo));
}

void print_status(void) {
    // ergodash logo, master side
    render_logo2();

    // move cursor beneath logo
    oled_set_cursor(0,2);
    oled_write_P(PSTR("\n"), false);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Mode: Qwerty\n"), false);
            break;
        case _GAMING:
            oled_write_ln_P(PSTR("Mode: Terraria\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    // oled_write_P(PSTR("\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Layer: Base\n\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Layer: Raise\n\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Layer: Lower\n\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Layer: Adjust\n\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CAPS"), led_usb_state.caps_lock);
}

// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     if (is_keyboard_master()) {
//         return OLED_ROTATION_90;
//     } else {
//         return OLED_ROTATION_180;
//     }
//     return rotation;
// }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status();
    } else {
       render_logo();
    }
    return false;
}

#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch(biton32(layer_state)) {
        case _QWERTY:
        case _GAMING:
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
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_UP);
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
        case _GAMING:
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
    return false;
}
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAMING);
      }
      return false;
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
    case KC_COPY:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_C);
        } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_C);
        }
        break;
    case KC_PASTE:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_V);
        } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_V);
        }
        break;
    case KC_CUT:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_X);
        } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_X);
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
    case KC_PTBD:
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

    case KC_MDIAQ:
        if (record->event.pressed) {
            SEND_STRING("@media #{$break}");
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

    case W_LSCRN:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LALT);
            register_code(KC_LCTL);
            register_code(KC_LEFT);
        } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            unregister_code(KC_LEFT);
        }
        break;

    case W_RSCRN:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LALT);
            register_code(KC_LCTL);
            register_code(KC_RGHT);
        } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            unregister_code(KC_RGHT);
        }
        break;

    case W_UNDO:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LALT);
            register_code(KC_Z);
        } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_LALT);
            unregister_code(KC_Z);
        }
        break;

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

    case W_LRGR:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_RGHT);
        } else {
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_RGHT);
        }
        break;

    case W_SMLR:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_LEFT);
        } else {
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_LEFT);
        }
        break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_scan_user(void) {
    static bool has_ran_yet = false;
    if (!has_ran_yet) {
        has_ran_yet = true;
        // rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 3);
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv(HSV_TEAL);
    }
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 750) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
      }
    }
};
