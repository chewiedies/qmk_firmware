/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { B6 }
#define ENCODERS_PAD_B { C6 }
#define ENCODERS_PAD_A_RIGHT { B6 }
#define ENCODERS_PAD_B_RIGHT { C6 }
#define ENCODER_RESOLUTION 4
#endif

#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D2

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
  #define OLED_TIMEOUT 400000
#endif

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define MASTER_LEFT

#undef TAPPING_TERM
#define TAPPING_TERM 200
#define TAP_CODE_DELAY 20

#undef RGBLIGHT_LIMIT_VAL
#define RGBLIGHT_LIMIT_VAL 150
#undef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 2
#undef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_STATIC_LIGHT
// #define RGBLIGHT_EFFECT_BREATHING
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_SLEEP