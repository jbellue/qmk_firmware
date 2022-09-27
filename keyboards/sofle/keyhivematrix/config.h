/* Copyright
 *   2021 solartempest
 *   2021 QMK
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

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFC32
#define PRODUCT_ID      0x1287 //Original is 0x0287 but we do not want to load default VIA keymap as it has errors for the bottom row
#define DEVICE_VER      0x0002
#define MANUFACTURER    Keyhive
#define PRODUCT         Sofle_Julien

// Set which side is master
#define MASTER_LEFT

// Key matrix size
// Rows are doubled-up. Added extra column for rotary encoder VIA mapping.
#define MATRIX_ROWS  10
#define MATRIX_COLS  7

// wiring of each half
#define MATRIX_ROW_PINS           { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS           { B6, B2, B3, B1, F7, F6, NO_PIN } // A virtual pin is needed for the encoder key matrix in via.
#define MATRIX_ROW_PINS_RIGHT     { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS_RIGHT     { F6, F7, B1, B3, B2, B6, NO_PIN } // A virtual pin is needed for the encoder key matrix in via.
#define DIODE_DIRECTION           COL2ROW
#define DEBOUNCE                  6
#define SPLIT_TRANSPORT_MIRROR

// Encoder support
#define ENCODERS_PAD_A            { F5 }
#define ENCODERS_PAD_B            { F4 }
#define ENCODERS_PAD_A_RIGHT      { F4 }
#define ENCODERS_PAD_B_RIGHT      { F5 }
#define ENCODER_RESOLUTIONS       { 4 }
#define ENCODER_RESOLUTIONS_RIGHT { 2 }

#define SOFT_SERIAL_PIN           D2  // Communication between sides

// OLED settings
#define OLED_TIMEOUT    80000
#define OLED_BRIGHTNESS 90
#define SPLIT_OLED_ENABLE

#ifdef RGB_MATRIX_ENABLE
#    define RGB_DI_PIN        D3
#    define RGBLED_NUM        74 // Number of LEDs
#    define DRIVER_LED_TOTAL  RGBLED_NUM
#    define RGB_MATRIX_SPLIT  { 37, 37 }
#endif
