// #define IGNORE_MOD_TAP_INTERRUPT
// #define PERMISSIVE_HOLD
// #define TAPPING_FORCE_HOLD_PER_KEY

#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 250
#endif

#ifdef ENCODER_RESOLUTION
    #undef ENCODER_RESOLUTION
    #define ENCODER_RESOLUTIONS { 4, 4 }
#endif

// #undef ENCODERS_PAD_A
// #define ENCODERS_PAD_A {B7, F1, D0}

// #undef ENCODERS_PAD_B
// #define ENCODERS_PAD_B {D5, B6, D1}

/* media key slowdown for windows */
#define TAP_CODE_DELAY 20

/* rgb stuff */
#undef RGBLIGHT_LIMIT_VAL
#define RGBLIGHT_LIMIT_VAL 200
#undef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 4
#undef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_STATIC_LIGHT
// #define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_BREATHE_MAX 125
// #define RGBLIGHT_EFFECT_BREATHE_CENTER 1.7
#define RGBLIGHT_SLEEP

/* oled stuff */
#ifdef OLED_ENABLE
    #ifdef OLED_TIMEOUT
        #undef OLED_TIMEOUT
        #define OLED_TIMEOUT 120000
    #endif

    #ifdef OLED_BRIGHTNESS
        #undef OLED_BRIGHTNESS
        #define OLED_BRIGHTNESS 120
    #endif
#endif
