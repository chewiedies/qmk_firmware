#ifdef PERMISSIVE_HOLD
    #undef PERMISSIVE_HOLD
#endif

#ifdef IGNORE_MOD_TAP_INTERRUPT
    #undef IGNORE_MOD_TAP_INTERRUPT
#endif

#ifdef TAPPING_FORCE_HOLD
    #undef TAPPING_FORCE_HOLD
#endif

#ifdef TAPPING_FORCE_HOLD_PER_KEY
    #undef TAPPING_FORCE_HOLD_PER_KEY
#endif

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLED_NUM 12

    #undef RGBLED_SPLIT
    #define RGBLED_SPLIT { 6, 6 }

    #undef RGBLIGHT_HUE_STEP
    #define RGBLIGHT_HUE_STEP 4

    #define RGBLIGHT_LED_MAP { 0,1,2,3,4,5,11,10,9,8,7,6 }

    #define RGBLIGHT_EFFECT_KNIGHT
#endif

#ifdef RGB_MATRIX_ENABLE
    #undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180  /* The maximum brightness level for RGB_MATRIX */
#endif

#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 180
#endif

#ifdef OLED_ENABLE
    #define OLED_FONT_H  "./lib/glcdfont.c"
    #define OLED_DISPLAY_128X64
    #define OLED_TIMEOUT 60000
#endif

#undef EE_HANDS
#define MASTER_LEFT

#undef ENCODERS_PAD_A
#undef ENCODERS_PAD_B
#define ENCODERS_PAD_A {B6}
#define ENCODERS_PAD_B {B5}
#define ENCODERS_PAD_A_RIGHT {B6}
#define ENCODERS_PAD_B_RIGHT {B5}

#undef ENCODER_RESOLUTION
#undef ENCODER_RESOLUTIONS
#define ENCODER_RESOLUTIONS { 2,2,2,2 }
