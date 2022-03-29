 /* Copyright 2021 Dane Evans
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
  #pragma once


//#define USE_MATRIX_I2C

/* Select hand configuration */

///https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/


#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// #define CUSTOM_FONT

// #define CUSTOM_LAYER_READ //if you remove this it causes issues - needs better guarding

// #define TAPPING_FORCE_HOLD

#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 250
#endif

#define PERMISSIVE_HOLD

// #define ENCODER_DIRECTION_FLIP

#define RGBLIGHT_SLEEP
// #define RGBLIGHT_LAYERS

/* ws2812 RGB LED */
#define RGB_DI_PIN D3


// #undef ENCODERS_PAD_A
// #undef ENCODERS_PAD_B
// #undef ENCODERS_PAD_A_RIGHT
// #undef ENCODERS_PAD_B_RIGHT

// #define ENCODERS_PAD_A { F4 }
// #define ENCODERS_PAD_B { F5 }
// #define ENCODERS_PAD_A_RIGHT { F5 }
// #define ENCODERS_PAD_B_RIGHT { F4 }
#ifdef ENCODER_RESOLUTION
    #undef ENCODER_RESOLUTION
    #define ENCODER_RESOLUTIONS { 2, 2 }
#endif

#ifdef OLED_TIMEOUT
    #undef OLED_TIMEOUT
    #define OLED_TIMEOUT 120000
#endif

#ifdef OLED_BRIGHTNESS
    #undef OLED_BRIGHTNESS
    #define OLED_BRIGHTNESS 120
#endif

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM

    //#define RGBLIGHT_ANIMATIONS
    #define RGBLIGHT_STATIC_LIGHT
	//#define RGBLIGHT_EFFECT_BREATHING
	// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
	//#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
	//#define RGBLIGHT_EFFECT_SNAKE
	//#define RGBLIGHT_EFFECT_KNIGHT
	//#define RGBLIGHT_EFFECT_CHRISTMAS
	//#define RGBLIGHT_EFFECT_STATIC_GRADIENT
	//#define RGBLIGHT_EFFECT_RGB_TEST
	//#define RGBLIGHT_EFFECT_ALTERNATING
	//#define RGBLIGHT_EFFECT_TWINKLE

    #define RGBLED_NUM 58
	//#define RGBLED_SPLIT
	#define RGBLED_SPLIT { 29, 29 }
	//#define RGBLED_NUM 30
    #define RGBLIGHT_LIMIT_VAL 150
    #define RGBLIGHT_HUE_STEP 2
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 8
#endif
