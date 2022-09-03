/* Copyright 2020 Kyrre Havik Eriksen
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


#undef ENCODER_DIRECTION_FLIP
   
#ifdef OLED_ENABLE
  #define OLED_DISPLAY_128X32
  #define OLED_TIMEOUT 400000
#endif

#define TAP_CODE_DELAY 20

#define RGB_DI_PIN D3

#ifdef RGBLIGHT_ENABLE
  #define RGBLED_NUM 28
  #define RGBLED_SPLIT { 14, 14 }
  #undef  RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_STATIC_LIGHT
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  // #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  // #define RGBLIGHT_EFFECT_TWINKLE
  // #undef  RGBLIGHT_LED_MAP
  // #define RGBLIGHT_LED_MAP { 3,4,5,9,8,6,7,2,1,0,13,14,15,19,18,16,17,12,11,10 }
  #define RGBLIGHT_SLEEP
  #define RGBLIGHT_HUE_STEP 2
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK
