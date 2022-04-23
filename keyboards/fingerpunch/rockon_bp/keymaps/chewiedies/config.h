#ifdef RGB_MATRIX_ENABLE
  #undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
  #undef RGB_MATRIX_STARTUP_SPD
  #define RGB_MATRIX_STARTUP_SPD 60
  #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE

  #define ENABLE_RGB_MATRIX_ALPHAS_MODS
  #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
  #define ENABLE_RGB_MATRIX_BREATHING
  #define ENABLE_RGB_MATRIX_BAND_SAT
  // #define ENABLE_RGB_MATRIX_BAND_VAL
  // #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
  // #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
  // #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
  // #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
  #define ENABLE_RGB_MATRIX_CYCLE_ALL
  #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
  #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
  // #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
  // #define ENABLE_RGB_MATRIX_DUAL_BEACON
  // #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
  // #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
  // #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
  #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
  // #define ENABLE_RGB_MATRIX_RAINDROPS
  // #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
  // #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
  // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
  // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
  // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
  // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
  // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
  // #define ENABLE_RGB_MATRIX_SPLASH
  // #define ENABLE_RGB_MATRIX_MULTISPLASH
  // #define ENABLE_RGB_MATRIX_SOLID_SPLASH
  // #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

#ifdef RGBLIGHT_ENABLE
  #undef RGBLIGHT_HUE_STEP
  #define RGBLIGHT_HUE_STEP 4
  #undef RGBLIGHT_VAL_STEP
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 120
#endif

#undef POINTING_DEVICE_ROTATION_270
#define POINTING_DEVICE_ROTATION_90

#define CIRQUE_PINNACLE_TAPPING_TERM 150
#define CIRQUE_PINNACLE_TOUCH_DEBOUNCE 100
#define CIRQUE_PINNACLE_X_LOWER 200
#define CIRQUE_PINNACLE_X_UPPER 1919
#define CIRQUE_PINNACLE_Y_LOWER 200
#define CIRQUE_PINNACLE_Y_UPPER 1471

#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4

#define ENCODER_DIRECTION_FLIP
