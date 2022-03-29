/*
Copyright 2021 Spencer Deven <splitlogicdesign@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#ifdef OLED_ENABLE
  #define OLED_DISPLAY_128X64
  #define OLED_TIMEOUT 400000
#endif

// #define ENCODER_DIRECTION_FLIP

#undef ENCODERS_PAD_A_RIGHT
#define ENCODERS_PAD_A_RIGHT { D2 }
#undef ENCODERS_PAD_B_RIGHT
#define ENCODERS_PAD_B_RIGHT { D4 }

#ifdef ENCODER_RESOLUTION
    #undef ENCODER_RESOLUTION
    #define ENCODER_RESOLUTIONS { 4, 4 }
#endif

/* media key slowdown for windows */
#define TAP_CODE_DELAY 20

/* rgb stuff */
#undef RGBLIGHT_LIMIT_VAL
#define RGBLIGHT_LIMIT_VAL 100
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

/* mouse stuff */
// #undef MOUSEKEY_INTERVAL
// #define MOUSEKEY_INTERVAL 16
