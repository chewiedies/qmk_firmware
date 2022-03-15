#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4

#ifdef RGBLIGHT_ENABLE
  #undef RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_STATIC_LIGHT
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  #define RGBLIGHT_LIMIT_VAL 220
  #define RGBLIGHT_HUE_STEP 3
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 4
  #define RGBLIGHT_SLEEP
#endif