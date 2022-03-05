/* Copyright 2021 Walter Hanley
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

// Lower board power consumption to boost compatibility
// #define USB_MAX_POWER_CONSUMPTION 250

/* media key slowdown for windows */
#define TAP_CODE_DELAY 20

#define RGB_DI_PIN D5

// define encoders
#undef ENCODERS_PAD_A
#define ENCODERS_PAD_A { B4 }
#undef ENCODERS_PAD_B
#define ENCODERS_PAD_B { E6 }
#undef ENCODERS_PAD_A_RIGHT
#define ENCODERS_PAD_A_RIGHT { E6 }
#undef ENCODERS_PAD_B_RIGHT
#define ENCODERS_PAD_B_RIGHT { B4 }

#define ENCODER_RESOLUTION 2

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
// #define USE_I2C
#define USE_SERIAL
#ifdef SOFT_SERIAL_PIN
  #undef SOFT_SERIAL_PIN 
  #define SOFT_SERIAL_PIN D1 
#endif

/* rgb stuff */
#ifdef RGBLIGHT_ENABLE
#define RGBLED_NUM 14
#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT { 7, 7 }
#define RGBLIGHT_LIMIT_VAL 150
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_STATIC_LIGHT
// #define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_BREATHE_MAX 125
// #define RGBLIGHT_EFFECT_BREATHE_CENTER 1.7
#define RGBLIGHT_SLEEP
#endif