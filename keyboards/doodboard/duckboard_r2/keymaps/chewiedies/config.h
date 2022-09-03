#undef RGBLIGHT_ANIMATIONS
// #define RGBLIGHT_EFFECT_KNIGHT
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT

#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4

#ifdef OLED_ENABLE
  #undef OLED_TIMEOUT
  #define OLED_TIMEOUT 600000
  #define OLED_SCROLL_RIGHT
  #undef OLED_SCROLL_TIMEOUT
  #define OLED_SCROLL_TIMEOUT 60000
  #undef OLED_SCROLL_SPEED
  #define OLED_SCROLL_SPEED 3
#endif

#ifdef RGBLIGHT_ENABLE
  #undef RGBLIGHT_LIMIT_VAL
  #define RGBLIGHT_LIMIT_VAL 255
  #undef RGBLIGHT_LIMIT_SAT
  #define RGBLIGHT_LIMIT_SAT 255
  #undef RGBLIGHT_SAT_STEP
  #define RGBLIGHT_SAT_STEP 8
  #undef RGBLIGHT_VAL_STEP
  #define RGBLIGHT_VAL_STEP 8
  #undef RGBLIGHT_HUE_STEP
  #define RGBLIGHT_HUE_STEP 2
  #undef RGBLED_NUM
  #define RGBLED_NUM 24
  #define RGBLIGHT_SLEEP
#endif
