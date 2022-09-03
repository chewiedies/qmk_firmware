#pragma once
#include "config_common.h"

// USB device descriptor parameter
#define PRODUCT         ursula

// key matrix size
// rows are doubled for split keyboards
#define MATRIX_ROWS 10
#define MATRIX_COLS 7

// wiring of each half
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2 }
#define DIODE_DIRECTION COL2ROW
//#define DIODE_DIRECTION ROW2COL

// communication between sides
#define USE_SERIAL
#define SOFT_SERIAL_PIN D2
#define SERIAL_USE_MULTI_TRANSACTION
#define EE_HANDS

// encoders
#define ENCODERS_PAD_A {B5}
#define ENCODERS_PAD_B {B6}
// #define ENCODER_RESOLUTIONS { 4, 4, 4, 1}

// OLED driver
#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
  #define OLED_TIMEOUT 60000
#endif

// RGB underglow and per key
#define RGB_DI_PIN D3
#ifdef RGB_DI_PIN
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLED_NUM 72
  #define RGBLED_SPLIT \
        { 36, 36 }
  #define RGBLIGHT_SPLIT
  #define RGBLIGHT_LIMIT_VAL 150
  #define RGBLIGHT_HUE_STEP 10
  #define RGBLIGHT_SAT_STEP 17
  #define RGBLIGHT_VAL_STEP 17
  #define RGBLIGHT_SLEEP
#endif
