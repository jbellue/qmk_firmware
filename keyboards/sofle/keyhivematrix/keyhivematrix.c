/* Copyright 2021 Carlos Martins
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

#include "keyhivematrix.h"

#ifdef RGB_MATRIX_ENABLE
  // Physical Layout
  // Columns
  // 0  1  2  3  4  5  6  7  8  9  10 11 12 13
  //                                           ROWS
  // 12 13 22 23 32 33       33 32 23 22 13 12  0
  //    02    03    04       04    03    02
  // 11 14 21 24 31 34       34 31 24 21 14 11  1
  //                01       01
  // 10 15 20 25 30 35       35 30 25 20 15 10  2
  //
  // 09 16 19 26 29 36       36 29 26 19 16 09  3
  //
  //     08 17 18 27 28     28 27 18 17 08      4
  //    07    06    05       05    06    07

led_config_t g_led_config = {
    {
        {  10,  11,  19,  20,  29,  30          },
        {  9,   12,  18,  21,  28,  31,  NO_LED },
        {  8,   13,  17,  22,  27,  32,  NO_LED },
        {  7,   14,  16,  23,  26,  33,  NO_LED },
        {            15,  24,  25,  34,  35     },

        {  46,  47,  55,  56,  65,  66          },
        {  45,  48,  54,  57,  64,  67,  NO_LED },
        {  44,  49,  53,  58,  63,  68,  NO_LED },
        {  43,  50,  52,  59,  62,  69,  NO_LED },
        {            51,  60,  61,  70,  71     }
    },
    {
        // Left side underglow
        { 91,  12}, { 64,  12}, { 36,  16}, { 36,  43}, { 64,  39}, { 91,  39}, {121,  56},
        // Left side Matrix
        { 36,   5}, { 50,   5}, { 64,   2}, { 78,   0}, { 91,   2}, {103,   4},
        { 36,  19}, { 50,  19}, { 64,  15}, { 78,  13}, { 91,  15}, {103,  17},
        { 36,  32}, { 50,  32}, { 64,  28}, { 78,  26}, { 91,  28}, {103,  30},
        { 36,  46}, { 50,  46}, { 64,  41}, { 78,  39}, { 91,  41}, {103,  43},
                                { 64,  54}, { 78,  52}, { 91,  54}, {107,  58}, {117,  64},


        // Right side underglow
        {142,  56}, {208,  39}, {176,  39}, {144,  43}, {136,  16}, {168,  12}, {200,  12},
        // Right side Matrix
        {230,   5}, {216,   5}, {202,   2}, {188,   0}, {174,   2}, {160,   4},
        {230,  19}, {216,  19}, {202,  15}, {188,  13}, {174,  15}, {160,  17},
        {230,  32}, {216,  32}, {202,  28}, {188,  26}, {174,  28}, {160,  30},
        {230,  46}, {216,  46}, {202,  41}, {188,  39}, {174,  41}, {160,  43}, 
                                {202,  54}, {188,  52}, {174,  54}, {156,  58}, {147,  64},
                    
                     
                    
                    
         
    },
    {
        LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
        LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
        LED_FLAG_MODIFIER,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
        LED_FLAG_MODIFIER,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
        LED_FLAG_MODIFIER,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
                                                LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,

        LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
                            LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
                            LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_MODIFIER,
                            LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
                            LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_MODIFIER,
        LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER
    }
};

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}
#endif
