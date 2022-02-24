/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#define TAPPING_TERM 200

#define COMBO_COUNT 3

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
  #undef OLED_TIMEOUT
  #define OLED_TIMEOUT 600000
#endif

#ifdef RGBLIGHT_ENABLE
  #undef  RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_STATIC_LIGHT
  // #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_KNIGHT
  // #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  // #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  // #define RGBLIGHT_EFFECT_TWINKLE
  #undef RGBLIGHT_LED_MAP
  #define RGBLIGHT_LED_MAP { 0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13 }
  #define RGBLIGHT_SLEEP
  #define RGBLIGHT_HUE_STEP 2
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif
