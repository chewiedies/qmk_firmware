/*

                                        █         █    █            ▄▄▄▀▀▀▀▀▀▄▄▄        █▀▀▀▀▀▀▀▀▀▀█
                                        █        █     █          ▄▀            ▀▄      █          █
                                        █       █      █        ▄▀                ▀▄    █          █
                                        █      █       █        █                  █    █          █
                                        █     █        █       █                    █   █          █
                                        █    █         █       █                    █   █▄▄▄▄▄▄▄▄▄▄█
                                        █   █ █        █       █                    █   █      █
                                        █  █   █       █        █                  █    █       █
                                        █ █     █      █        ▀▄                ▄▀    █        █
                                        ██       █     █          ▀▄            ▄▀      █         █
                                        █         █    █▄▄▄▄▄▄▄▄    ▀▀▀▄▄▄▄▄▄▀▀▀        █          █

                                        ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
                                        C H E W I E D I E S

*/
#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#include "klor.h"
#ifdef HAPTIC_ENABLE
#include "drivers/haptic/DRV2605L.h"
#endif

#ifdef ENCODER_ENABLE
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
#endif

bool is_num_active = false;
uint16_t num_active_timer = 0;


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                                      │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                                 │
// └───────────────────────────────────────────────────────────┘

enum klor_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUM,
};

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                             │
// └───────────────────────────────────────────────────────────┘

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    NUMROW,
    KC_IMP,
    OS_SWAP,
    KCSAVE,
    KCCOPY,
    KCPSTE,
    //KCCUT,
    KCUNDO,
    KCREDO,
};

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s                         │
// └───────────────────────────────────────────────────────────┘

// #define LOWER MO(_LOWER)
// #define RAISE MO(_RAISE)
#define ALTTAB  MT(MOD_LALT, KC_TAB)
#define ALTENT  MT(MOD_LALT, KC_ENT)
#define CMDESC  MT(MOD_LGUI, KC_ESC)
#define SFTSPC  MT(MOD_LSFT, KC_SPC)
#define SFTENT  MT(MOD_LSFT, KC_ENT)
#define CTLLCBR MT(MOD_LCTL, KC_LCBR)
#define ALTRCBR MT(MOD_LALT, KC_RCBR)
#define NUMENT  LT(_NUM, KC_ENT)
#define NUMMIN  LT(_NUM, KC_MINS)
// #define OSMALT  OSM(MOD_LALT)
// #define OSMCTL  OSM(MOD_LCTL)
// #define OSMGUI  OSM(MOD_LGUI)
// #define OSMSFT  OSM(MOD_LSFT)
// #define KCUNDO  LGUI(KC_Z)
// #define KCREDO  LGUI(LSFT(KC_Z))
#define KCCUT   LGUI(KC_X)
// #define SFTTAB  LSFT(KC_TAB)
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

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

   ┌───────────────────────────────────────────────────────────┐
   │ q w e r t y                                               │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                                          ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    Q    │    W    │    E    │    R    │    T    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    Y    │    U    │    I    │    O    │    P    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │(ALT)TAB │    A    │    S    │    D    │    F    │    G    ├─╯  ╭────────╮              ╭────────╮  ╰─┤    H    │    J    │    K    │    L    │   ; :   │   ' "   │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤    │ PSTBRD │              │  MUTE  │    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │(CMD)ESC │    Z    │    X    │    C    │    V    │    B    │    ╰────────╯              ╰────────╯    │    N    │    M    │   , <   │   . >   │   / ?   │  ENTER  │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┬─────────┐  ┌─────────┬─────────┼─────────┼─────────┼─────────┴─────────┴─────────┴─────────┘
                                           │ (RAISE) │(SFT)SPC │(NUM)ENT │ (CTL) { │  │ } (ALT) │  BKSPC  │  SPACE  │ (LOWER) │
                                           └─────────┴─────────┴─────────┴─────────┘  └─────────┴─────────┴─────────┴─────────┘ */

   [_QWERTY] = LAYOUT_polydactyl(
 //        ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷      ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
                      KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
            ALTTAB,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
            CMDESC,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     PSTBRD,          KC_MUTE,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,
                                          RAISE,    SFTSPC,   NUMROW,   CTLLCBR,         ALTRCBR,  KC_BSPC,  KC_SPC,   LOWER
   ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

   ┌───────────────────────────────────────────────────────────┐
   │ r a i s e                                                 │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                                          ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │         │   MUTE  │   VOL+  │   VOL-  │         │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │  PGTOP  │  PRVWRD │   UP    │  NXTWRD │         │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │  UNDO   │         │   SAVE  │         │         │         ├─╯  ╭────────╮              ╭────────╮  ╰─┤         │  LEFT   │  DOWN   │  RIGHT  │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤    │ PSTBRD │              │  MUTE  │    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │  REDO   │         │   CUT   │   COPY  │  PASTE  │  BKSPC  │    ╰────────╯              ╰────────╯    │  PGBOT  │  LNBEG  │         │  LNEND  │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┬─────────┐  ┌─────────┬─────────┼─────────┼─────────┼─────────┴─────────┴─────────┴─────────┘
                                           │ (RAISE) │(SFT)SPC │(NUM)ENT │    [    │  │    ]    │  DELETE │  SPACE  │ (LOWER) │
                                           └─────────┴─────────┴─────────┴─────────┘  └─────────┴─────────┴─────────┴─────────┘ */

   [_RAISE] = LAYOUT_polydactyl(
 //        ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷      ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
                      XXXXXXX,  KC_MUTE,  KC_VOLD,  KC_VOLU,  XXXXXXX,                             PGTOP,    PRVWRD,   KC_UP,    NXTWRD,   XXXXXXX,
            KCUNDO,   XXXXXXX,  KCSAVE,   XXXXXXX,  XXXXXXX,  XXXXXXX,                             XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,
            KCREDO,   XXXXXXX,  KCCUT,    KCCOPY,   KCPSTE,   KC_BSPC,  _______,         KC_CAPS,  PGBOT,    LNBEG,    XXXXXXX,  LNEND,    XXXXXXX,  XXXXXXX,
                                          _______,  _______,  _______,  KC_LBRC,         KC_RBRC,  KC_DEL,   _______,  _______
 ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

   ┌───────────────────────────────────────────────────────────┐
   │ l o w e r                                                 │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                                          ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    !    │    @    │    #    │    $    │    %    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    ^    │    &    │    *    │    (    │    )    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │(ALT)TAB │    (    │    )    │    {    │    }    │    [    ├─╯  ╭────────╮              ╭────────╮  ╰─┤    ]    │    `    │    ~    │    "    │    '    │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤    │PRNTSCRN│              │THECLAW │    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │(CMD)ESC │    =    │    +    │    -    │    _    │         │    ╰────────╯              ╰────────╯    │         │         │         │    |    │    /    │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┬─────────┐  ┌─────────┬─────────┼─────────┼─────────┼─────────┴─────────┴─────────┴─────────┘
                                           │ (RAISE) │(SFT)SPC │(NUM)ENT │    [    │  │    ]    │  BKSPC  │  SPACE  │ (LOWER) │
                                           └─────────┴─────────┴─────────┴─────────┘  └─────────┴─────────┴─────────┴─────────┘ */

   [_LOWER] = LAYOUT_polydactyl(
 //        ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷      ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
                      KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                             KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,
            _______,  KC_LPRN,  KC_RPRN,  KC_LCBR,  KC_RCBR,  KC_LBRC,                             KC_RBRC,  KC_GRV,   KC_TILD,  KC_DQUO,  KC_QUOT,  XXXXXXX,
            _______,  KC_EQL,   KC_PLUS,  KC_MINS,  KC_UNDS,  XXXXXXX,  SCRNCAP,         THECLAW,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PIPE,  KC_BSLS,  XXXXXXX,
                                          _______,  _______,  _______,  KC_LBRC,         KC_RBRC,  _______,  _______,  _______
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

   ┌───────────────────────────────────────────────────────────┐
   │ a d j u s t                                               │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                                          ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │         │         │         │         │         │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │         │         │         │         │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │         │         │         │         │         ├─╯  ╭────────╮              ╭────────╮  ╰─┤         │         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤    │ PSTBRD │              │  MUTE  │    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         │         │    ╰────────╯              ╰────────╯    │         │         │         │         │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┬─────────┐  ┌─────────┬─────────┼─────────┼─────────┼─────────┴─────────┴─────────┴─────────┘
                                           │ (RAISE) │(SFT)SPC │(NUM)ENT │    [    │  │    ]    │  BKSPC  │  SPACE  │ (LOWER) │
                                           └─────────┴─────────┴─────────┴─────────┘  └─────────┴─────────┴─────────┴─────────┘ */

   [_ADJUST] = LAYOUT_polydactyl(
 //        ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷      ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
                      HPT_TOG,  W_SHOW,   W_TTHRD,  XXXXXXX,  RGB_RMOD,                            RGB_MOD,  XXXXXXX,  W_THALF,  XXXXXXX,  AU_TOG,
            HPT_ON,   HPT_MODI, W_LTHRD,  W_MAX,    W_RTHRD,  RGB_HUD,                             RGB_HUI,  W_LHALF,  W_CENT,   W_RHALF,  XXXXXXX,  XXXXXXX,
            HPT_OFF,  HPT_MODD, XXXXXXX,  W_BTHRD,  XXXXXXX,  RGB_VAD,  QK_BOOT,         QK_BOOT,  RGB_VAI,  XXXXXXX,  W_BHALF,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                          _______,  OS_SWAP,  RGB_SPD,  XXXXXXX,         XXXXXXX,  RGB_SPI,  XXXXXXX,  _______
 ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

   ┌───────────────────────────────────────────────────────────┐
   │ n u m r o w                                               │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                                          ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    1    │    2    │    3    │    4    │    5    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    6    │    7    │    8    │    9    │    0    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │    6    │    7    │    8    │    9    │    0    ├─╯  ╭────────╮              ╭────────╮  ╰─┤         │         │         │         │    :    │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤    │ PSTBRD │              │  MUTE  │    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │    =    │    +    │    -    │    ,    │    .    │    ╰────────╯              ╰────────╯    │         │         │   , <   │   . >   │   / ?   │   ' "   │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┬─────────┐  ┌─────────┬─────────┼─────────┼─────────┼─────────┴─────────┴─────────┴─────────┘
                                           │ (RAISE) │(SFT)SPC │(NUM)ENT │    [    │  │    ]    │  BKSPC  │  SPACE  │ (LOWER) │
                                           └─────────┴─────────┴─────────┴─────────┘  └─────────┴─────────┴─────────┴─────────┘ */

   [_NUM] = LAYOUT_polydactyl(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
              KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                          KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    _______,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,                          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_COLN,  _______,
    _______,  KC_EQL,   KC_PLUS,  KC_MINS,  KC_COMM,  KC_DOT,   _______,   _______,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,
                                  _______,  _______,  SFTSPC,   _______,   _______,  _______,  _______,  _______
 )

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ t e m p l a t e   p o l y d a c t y l                     │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │         │         │         │         │         │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │         │         │         │         │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │         │         │         │         │         ├─╯                ╰─┤         │         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         │         ││        ││        ││         │         │         │         │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         │         ││         │         │         │         │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘

   [_TEMPLATE] = LAYOUT_polydactyl(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
              _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,
                                  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______
 )
*/
};


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ H A P T I C   F E E D B A C K                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

void keyboard_post_init_user(void) {
  // Call the post init code.
  #if HAPTIC_ENABLE
    haptic_disable(); // disables per key haptic feedback by default
  #endif //HAPTIC ENABLE
}


// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   s o u n d s                                 │
// └───────────────────────────────────────────────────────────┘

#ifdef AUDIO_ENABLE
  #define MAC_SOUND W__NOTE(_DS6), Q__NOTE(_DS5), H__NOTE(_AS5), H__NOTE(_GS5), H__NOTE(_DS5), H__NOTE(_DS6), H__NOTE(_AS5)
  #define WINXP_SOUND S__NOTE(_CS5), B__NOTE(_C5)
  // #define ONE_SOUND E__NOTE(_A5), E__NOTE(_A6), E__NOTE(_REST), E__NOTE(_A5), E__NOTE(_A6)
  // #define TWO_SOUND E__NOTE(_D4), E__NOTE(_E4)
  // #define SAVE_SOUND E__NOTE(_E6), E__NOTE(_A6), ED_NOTE(_E7)
  #define SAVE_SOUND Q__NOTE(_G5), Q__NOTE(_A6), Q__NOTE(_E7)
  // #define LAYER_SOUND E__NOTE(_A5), E__NOTE(_A6)
  #define COPY_SOUND E__NOTE(_GS6), E__NOTE(_A6), S__NOTE(_REST), Q__NOTE(_E7)
  #define CUT_SOUND E__NOTE(_A3), E__NOTE(_A3),  E__NOTE(_REST), E__NOTE(_A5), E__NOTE(_A6)
  #define PASTE_SOUND Q__NOTE(_E7), E__NOTE(_A6), E__NOTE(_GS6), E__NOTE(_REST), E__NOTE(_GS6)
  #define UNDO_SOUND E__NOTE(_A3), E__NOTE(_B3)
  #define REDO_SOUND E__NOTE(_B3), Q__NOTE(_E7)
  #define CAPS_SOUND E__NOTE(_A3), E__NOTE(_B3)

  float winxp_song[][2] = SONG(WINXP_SOUND);
  float mac_song[][2] = SONG(MAC_SOUND);
  // float one_sound[][2] = SONG(ONE_SOUND);
  // float two_sound[][2] = SONG(TWO_SOUND);
  float save_sound[][2] = SONG(SAVE_SOUND);
  // float layer_sound[][2] = SONG(LAYER_SOUND);
  float copy_sound[][2] = SONG(COPY_SOUND);
  float paste_sound[][2] = SONG(PASTE_SOUND);
  float cut_sound[][2] = SONG(CUT_SOUND);
  float undo_sound[][2] = SONG(UNDO_SOUND);
  float redo_sound[][2] = SONG(REDO_SOUND);
  float caps_sound[][2] = SONG(CAPS_SOUND);
#endif


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ O L E D                                                                                                                                    │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

#ifdef OLED_ENABLE

// ┌───────────────────────────────────────────────────────────┐
// │ o l e d   g r a p h i c s                                 │
// └───────────────────────────────────────────────────────────┘

void render_os_lock_status(void) {
    static const char PROGMEM sep_v[] = {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0};
    static const char PROGMEM sep_h1[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM sep_h2[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM face_1[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xE1, 0};
    static const char PROGMEM face_2[] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xE1, 0};
    static const char PROGMEM os_m_1[] = {0x95, 0x96, 0};
    static const char PROGMEM os_m_2[] = {0xB5, 0xB6, 0};
    static const char PROGMEM os_w_1[] = {0x97, 0x98, 0};
    static const char PROGMEM os_w_2[] = {0xB7, 0xB8, 0};
    // static const char PROGMEM s_lock[] = {0x8F, 0x90, 0};
    // static const char PROGMEM n_lock[] = {0x91, 0x92, 0};
    static const char PROGMEM c_lock[] = {0x93, 0x94, 0};
    static const char PROGMEM b_lock[] = {0xE1, 0xE1, 0};
    #ifdef AUDIO_ENABLE
      static const char PROGMEM aud_en[] = {0xAF, 0xB0, 0};
      static const char PROGMEM aud_di[] = {0xCF, 0xD0, 0};
    #endif
    #ifdef HAPTIC_ENABLE
      static const char PROGMEM hap_en[] = {0xB1, 0xB2, 0};
    #endif

// os mode status ────────────────────────────────────────┐

    oled_write_ln_P(sep_v, false);

    if (keymap_config.swap_lctl_lgui) {
        // oled_write_P(os_m_1, false); // ──── MAC
        oled_write_P(os_w_1, false); // ──── WIN
    } else {
        // oled_write_P(os_w_1, false); // ──── WIN
        oled_write_P(os_m_1, false); // ──── MAC
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_1, false);

    if (keymap_config.swap_lctl_lgui) {
        // oled_write_P(os_m_2, false); // ──── MAC
        oled_write_P(os_w_2, false); // ──── WIN
    } else {
        // oled_write_P(os_w_2, false); // ──── WIN
        oled_write_P(os_m_2, false); // ──── MAC
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_2, false);
    oled_write_ln_P(sep_v, false);


// lock key layer status ─────────────────────────────────┐

    led_t led_usb_state = host_keyboard_led_state();

    if (led_usb_state.caps_lock) {
        oled_write_P(c_lock, false); // ─── CAPSLOCK
        #ifdef HAPTIC_ENABLE
            PLAY_SONG(caps_sound);
        #endif
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.num_lock) {
        oled_write_P(b_lock, false); // ──── NUMLOCK
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.scroll_lock) { // ─ SCROLLLOCK
        oled_write_P(b_lock, false);
    } else {
        oled_write_P(b_lock, false);
    }

// hardware feature status ──────────────────────────────┐

    oled_write_P(sep_h2, false);

    #ifndef AUDIO_ENABLE
        oled_write_P(b_lock, false);
    #endif
    #ifndef HAPTIC_ENABLE
        oled_write_P(b_lock, false);
    #endif

    #ifdef AUDIO_ENABLE // ────────────────── AUDIO
        if (is_audio_on()) {
          oled_write_P(aud_en, false);
        } else {
          oled_write_P(aud_di, false);
        }
    #endif // AUDIO ENABLE

     #ifdef HAPTIC_ENABLE // ─────────────── HAPTIC
        oled_write_P(hap_en, false);
     #endif // HAPTIC ENABLE
}


// layer status ──────────────────────────────────────────┐
static void print_status(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("> C:\\BASE"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("> C:\\NAVIGATE"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("> C:\\SYMBOLS"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("> C:\\CONFIG"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("> C:\\NUMROW"), false);
            break;
        default:
            oled_write_ln_P(PSTR("> C:\\UNDEF"), false);
    }
}


// ┌───────────────────────────────────────────────────────────┐
// │ o l e d   r o t a t i o n                                 │
// └───────────────────────────────────────────────────────────┘

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

// ┌───────────────────────────────────────────────────────────┐
// │ w r i t e   t o   o l e d                                 │
// └───────────────────────────────────────────────────────────┘

bool oled_task_user(void) {

    if (is_keyboard_master()) {  // ────────────────────────── PRIMARY SIDE

        // layer status ──────────────────────────────────────────────────┐
        print_status();
        render_os_lock_status();

    } else {  // ─────────────────────────────────────────── SECONDARY SIDE

        // KLOR face ─────────────────────────────────────────────────────┐

        static const char PROGMEM klor_face[] = {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
            0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0,
            0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        oled_write_raw_P(klor_face, sizeof(klor_face));
    }
    return false;
}
#endif // OLED_ENABLE


// ┌───────────────────────────────────────────────────────────┐
// │ m a c r o s                                               │
// └───────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case OS_SWAP:
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                  keymap_config.swap_lctl_lgui = true;  // ─── MAC
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(winxp_song);
                  #endif // AUDIO_ENABLE
                }
                else {
                  keymap_config.swap_lctl_lgui = false; // ─── WIN
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(mac_song);
                  #endif // AUDIO_ENABLE
                }
            // #ifdef HAPTIC_ENABLE
            //     DRV_pulse(pulsing_strong);
            // #endif
            eeconfig_update_keymap(keymap_config.raw);
            clear_keyboard();  // ──── clear to prevent stuck keys
            return false;
            }
        case KC_IMP:
            if (record->event.pressed) {
                SEND_STRING(" !important;");
            }
            break;
        case KCSAVE:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_S);
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(save_sound);
                #endif
            } else {
                unregister_code(KC_LGUI);
            }
            break;
        // case KCCUT:
        //     if (record->event.pressed) {
        //         register_code(KC_LGUI);
        //         tap_code(KC_X);
        //         #ifdef AUDIO_ENABLE
        //             PLAY_SONG(cut_sound);
        //         #endif
        //     } else {
        //         unregister_code(KC_LGUI);
        //     }
        //     break;
        case KCCOPY:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_C);
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(copy_sound);
                #endif
            } else {
                unregister_code(KC_LGUI);
            }
            break;
        case KCPSTE:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_V);
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(paste_sound);
                #endif
            } else {
                unregister_code(KC_LGUI);
            }
            break;
        case KCUNDO:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_Z);
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(undo_sound);
                #endif
            } else {
                unregister_code(KC_LGUI);
            }
            break;
        case KCREDO:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                tap_code(KC_Z);
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(redo_sound);
                #endif
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
            }
            break;
        case NUMROW:
            if (record->event.pressed) {
                num_active_timer = timer_read();
                if(!is_num_active) {
                    is_num_active = true;
                    layer_on(_NUM);
                }

            } else {
                layer_off(_NUM);
                if (timer_elapsed(num_active_timer) < 200) {
                    tap_code(KC_ENT);
                    is_num_active = false;
                }
            }
            return false;

// ┌───────────────────────────────────────────────────────────┐
// │ l a y e r                                                 │
// └───────────────────────────────────────────────────────────┘

        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
                #ifdef HAPTIC_ENABLE
                  DRV_pulse(transition_hum);
                #endif // HAPTIC_ENABLE
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                #ifdef HAPTIC_ENABLE
                    DRV_pulse(pulsing_strong);
                #endif // HAPTIC_ENABLE
                // #ifdef AUDIO_ENABLE
                //     PLAY_SONG(layer_sound);
                // #endif
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                #ifdef HAPTIC_ENABLE
                  DRV_pulse(pulsing_strong);
                #endif
                // #ifdef AUDIO_ENABLE
                //     PLAY_SONG(layer_sound);
                // #endif
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
                // #ifdef HAPTIC_ENABLE
                //   DRV_pulse(sharp_tick2_80);
                // #endif
            } else {
                layer_off(_ADJUST);
            }
            return false;
    }


    return true;
}


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ E N C O D E R                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// Two Encoder Support
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
                register_code(KC_PGDN);
            } else {
                register_code(KC_PGUP);
            }
            break;

        case _ADJUST:
            if (clockwise) {
                #ifdef RGB_MATRIX_ENABLE
                    rgb_matrix_step();
                #endif
            } else {
                #ifdef RGB_MATRIX_ENABLE
                    rgb_matrix_step_reverse();
                #endif
            }
            break;
        }

    } else if (index == 1) {  // Roller Encoder Right
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
                register_code(KC_END);
            } else {
                register_code(KC_HOME);
            }
            break;
        case _LOWER:
            if (clockwise) {
                #ifdef RGB_MATRIX_ENABLE
                    rgb_matrix_increase_speed();
                #endif
            } else {
                #ifdef RGB_MATRIX_ENABLE
                    rgb_matrix_decrease_speed();
                #endif
            }
            break;

        case _ADJUST:
            if (clockwise) {
                #ifdef RGB_MATRIX_ENABLE
                    rgb_matrix_increase_val();
                #endif
            } else {
                #ifdef RGB_MATRIX_ENABLE
                    rgb_matrix_decrease_val();
                #endif
            }
            break;
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
    if (is_num_active) {
        if (timer_elapsed(num_active_timer) > 200) {
            #ifdef HAPTIC_ENABLE
                DRV_pulse(pulsing_strong);
            #endif
            is_num_active = false;
        }
    }
}



