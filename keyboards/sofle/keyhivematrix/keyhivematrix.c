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
led_config_t g_led_config = {
    {
        {  33,   32,  24,  23,  14,  13          },
        {  34,   31,  25,  22,  15,  12,  NO_LED },
        {  35,   30,  26,  21,  16,  11,  NO_LED },
        {  36,   29,  27,  20,  17,  10,  NO_LED },
        {    NO_LED,  28,  19,  18,  9,   8      },

        {  70,  69,  61,  60,  51,  50          },
        {  71,  68,  62,  59,  52,  49,  NO_LED },
        {  72,  67,  63,  58,  53,  48,  NO_LED },
        {  73,  66,  64,  57,  54,  47,  NO_LED },
        {            65,  56,  55,  46,  45     }
    },
    {
        // Left side underglow
        { 71,  13}, { 45,  13}, { 19,  17}, { 19,  42}, { 45,  39}, { 71,  39}, { 36,  59}, {101,  56},
        // Left side Matrix
        { 97,  64}, { 87,  58}, { 84,  44}, { 84,  31}, { 84,  18}, { 84,   5},
        { 71,   3}, { 71,  16}, { 71,  29}, { 71,  42}, { 71,  55},
        { 58,  53}, { 58,  40}, { 58,  27}, { 58,  14}, { 58,   1},
        { 45,   3}, { 45,  16}, { 45,  29}, { 45,  42}, { 45,  55},
        { 32,  45}, { 32,  32}, { 32,  19}, { 32,   6},
        { 19,   6}, { 19,  19}, { 19,  32}, { 19,  45},


        // Right side underglow
        {152,  13}, {178,  13}, {204,  17}, {204,  42}, {178,  39}, {152,  39}, {187,  59}, {122,  56},
        // Right side Matrix
        {126,  64}, {136,  58}, {139,  44}, {139,  31}, {139,  18}, {139,   5},
        {152,   3}, {152,  16}, {152,  29}, {152,  42}, {152,  55},
        {165,  53}, {165,  40}, {165,  27}, {165,  14}, {165,   1},
        {178,   3}, {178,  16}, {178,  29}, {178,  42}, {178,  55},
        {191,  45}, {191,  32}, {191,  19}, {191,   6},
        {204,   6}, {204,  19}, {204,  32}, {204,  45},





    },
    {
        LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
        LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_MODIFIER,
        LED_FLAG_MODIFIER,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_MODIFIER,
        LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,  LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,

        LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
        LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_MODIFIER,
        LED_FLAG_MODIFIER,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_MODIFIER,
        LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,  LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,
    }
};

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}
#endif
