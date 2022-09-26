 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

// Disabled to save space
#define NO_ACTION_ONESHOT  // 332
#define NO_ACTION_MACRO    // 0
#define NO_ACTION_FUNCTION // 0
#define DISABLE_LEADER     // 0

#define LAYER_STATE_8BIT
//#define NO_ACTION_TAPPING
#define NO_MUSIC_MODE

// Tapping settings
#define TAP_CODE_DELAY            10
#define TAPPING_TOGGLE            2   //Tap TT twice to toggle layer
#define TAPPING_TERM              160 //Tapping duration in ms

// Add RGB underglow
// by defining in the keyboard, incompatible keymaps will fail to compile.
#ifdef RGB_MATRIX_ENABLE
// The number of LEDs connected
#    define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#    define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
//#    define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
//#    define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 160 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10

#     undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_BREATHING
#     undef ENABLE_RGB_MATRIX_BAND_SAT
#     undef ENABLE_RGB_MATRIX_BAND_VAL
#     undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#     undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#     undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#     undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#     undef ENABLE_RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#     undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#     undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#     undef ENABLE_RGB_MATRIX_DUAL_BEACON
#     undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#     undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_RAINDROPS
#     undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#     undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#     undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#     undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define ENABLE_RGB_MATRIX_SPLASH
#    define ENABLE_RGB_MATRIX_MULTISPLASH
#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif
