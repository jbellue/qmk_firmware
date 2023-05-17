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

#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

#ifdef OLED_ENABLE
    #include "oled.c"
#endif

#ifdef ENCODER_ENABLE
	#include "encoder.c"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ╭──────┬──────┬──────┬──────┬──────┬──────╮                         ╭──────┬──────┬──────┬──────┬──────┬──────╮
 * │  `   │   1  │   2  │   3  │   4  │   5  ├───────╮    E    ╭───────┤   6  │   7  │   8  │   9  │   0  │  -   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ VolUp │<   N   >│ Prev  ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ ESC  │   Q  │   W  │   E  │   R  │   T  ├───────┤    C    ├───────┤   Y  │   U  │   I  │   O  │   P  │ Bspc │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ Mute  │<   O   >│ Play  ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   A  │   S  │   D  │   F  │   G  ├───────┤    D    ├───────┤   H  │   J  │   K  │   L  │   ;  │  '   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ VolDn │<   E   >│ Next  ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │LShift│   Z  │   X  │   C  │   V  │   B  ├───┬───┴───╮R╭───┴───┬───┤   N  │   M  │   ,  │   .  │   /  │RShift│
 * ╰──────┴──────┼──────┼──────┼──────┼──────┤  / Space /   \ Enter \  ├──────┼──────┼──────┼──────┼──────┴──────╯
 *               │ LGUI │ LAlt │ LCTR │MO LOW│ /       /     \       \ │MORAIS│ RCTR │ RAlt │ RGUI │
 *               ╰──────┴──────┴──────┴──────┴────────╯       ╰────────┴──────┴──────┴──────┴──────╯
 */

[_QWERTY] = LAYOUT(
  KC_GRV,  KC_1, KC_2,    KC_3,    KC_4,     KC_5,                               KC_6,       KC_7,     KC_8,    KC_9,   KC_0,    KC_MINS,
  KC_ESC,  KC_Q, KC_W,    KC_E,    KC_R,     KC_T,       KC_VOLU,       KC_MPRV, KC_Y,       KC_U,     KC_I,    KC_O,   KC_P,    KC_BSPC,
  KC_TAB,  KC_A, KC_S,    KC_D,    KC_F,     KC_G,       KC_MUTE,       KC_MPLY, KC_H,       KC_J,     KC_K,    KC_L,   KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z, KC_X,    KC_C,    KC_V,     KC_B,       KC_VOLD,       KC_MNXT, KC_N,       KC_M,     KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                 KC_LGUI, KC_LALT, KC_LCTRL, MO(_LOWER), KC_SPC,        KC_ENT , MO(_RAISE), KC_RCTRL, KC_RALT, KC_RGUI
),
/* COLEMAK
 * ╭──────┬──────┬──────┬──────┬──────┬──────╮                         ╭──────┬──────┬──────┬──────┬──────┬──────╮
 * │  `   │   1  │   2  │   3  │   4  │   5  ├───────╮    E    ╭───────┤   6  │   7  │   8  │   9  │   0  │  -   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ VolUp │<   N   >│ Prev  ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ ESC  │   Q  │   W  │   F  │   P  │   G  ├───────┤    C    ├───────┤   J  │   L  │   U  │   Y  │   :  │ Bspc │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ Mute  │<   O   >│ Play  ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   A  │   R  │   S  │   T  │   D  ├───────┤    D    ├───────┤   H  │   N  │   E  │   I  │   O  │  '   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ VolDn │<   E   >│ Next  ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │LShift│   Z  │   X  │   C  │   V  │   B  ├───┬───┴───╮R╭───┴───┬───┤   K  │   M  │   ,  │   .  │   /  │RShift│
 * ╰──────┴──────┼──────┼──────┼──────┼──────┤  / Space /   \ Enter \  ├──────┼──────┼──────┼──────┼──────┴──────╯
 *               │ LGUI │ LAlt │ LCTR │MO LOW│ /       /     \       \ │MORAIS│ RCTR │ RAlt │ RGUI │
 *               ╰──────┴──────┴──────┴──────┴────────╯       ╰────────┴──────┴──────┴──────┴──────╯
 */

[_COLEMAK] = LAYOUT(
  KC_GRV,  KC_1, KC_2,    KC_3,    KC_4,     KC_5,                               KC_6,       KC_7,     KC_8,    KC_9,   KC_0,    KC_MINS,
  KC_ESC,  KC_Q, KC_W,    KC_F,    KC_P,     KC_G,       KC_VOLU,       KC_MPRV, KC_J,       KC_L,     KC_U,    KC_Y,   KC_SCLN, KC_BSPC,
  KC_TAB,  KC_A, KC_R,    KC_S,    KC_T,     KC_D,       KC_MUTE,       KC_MPLY, KC_H,       KC_K,     KC_E,    KC_I,   KC_O,    KC_QUOT,
  KC_LSFT, KC_Z, KC_X,    KC_C,    KC_V,     KC_B,       KC_VOLD,       KC_MNXT, KC_K,       KC_M,     KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                 KC_LGUI, KC_LALT, KC_LCTRL, MO(_LOWER), KC_SPC,        KC_ENT , MO(_RAISE), KC_RCTRL, KC_RALT, KC_RGUI
),

/* LOWER
 * ╭──────┬──────┬──────┬──────┬──────┬──────╮                         ╭──────┬──────┬──────┬──────┬──────┬──────╮
 * │KC_NUB│  F1  │  F2  │  F3  │  F4  │  F5  ├───────╮    E    ╭───────┤  F6  │  F7  │  F8  │  F9  │ F10  │ F11  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤       │<   N   >│       ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │   1  │   2  │   3  │   4  │   5  ├───────┤    C    ├───────┤   6  │   7  │   8  │   9  │   0  │ F12  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤       │<   O   >│       ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │   !  │   @  │   #  │   $  │   %  ├───────┤    D    ├───────┤   ^  │   &  │   *  │   (  │   )  │   |  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤       │<   E   >│       ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │  =   │  -   │  +   │   {  │   }  ├───┬───┴───╮R╭───┴───┬───┤   [  │   ]  │   ;  │   :  │   \  │      │
 * ╰──────┴──────┼──────┼──────┼──────┼──────┤  / Space /   \ Enter \  ├──────┼──────┼──────┼──────┼──────┴──────╯
 *               │      │      │      │      │ /       /     \       \ │ADJUST│      │      │      │
 *               ╰──────┴──────┴──────┴──────┴────────╯       ╰────────┴──────┴──────┴──────┴──────╯
 */
[_LOWER] = LAYOUT(
  KC_NUBS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,       _______, KC_6,        KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,       _______, KC_CIRC,     KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC,     KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                    _______, _______, _______, XXXXXXX, _______,       _______, TO(_ADJUST), _______, _______, _______
),
/* RAISE
 * ╭──────┬──────┬──────┬──────┬──────┬──────╮                         ╭──────┬──────┬──────┬──────┬──────┬──────╮
 * │      │      │      │      │      │      ├───────╮    E    ╭───────┤      │      │      │      │      │PrntSc│
 * ├──────┼──────┼──────┼──────┼──────┼──────┤WheelUp│<   N   >│       ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │LClick│Mouse↑│RClick│      ├───────┤    C    ├───────┤PG UP │ Home │  ↑   │ End  │ Ins  │ Del  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤MidClck│<   O   >│       ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │Mouse←│Mouse↓│Mouse→│ Caps ├───────┤    D    ├───────┤PG DN │  ←   │  ↓   │  →   │ Menu │ Bspc │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤WheelDn│<   E   >│       ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ├───┬───┴───╮R╭───┴───┬───┤      │Ctrl← │      │Ctrl→ │      │      │
 * ╰──────┴──────┼──────┼──────┼──────┼──────┤  / Space /   \ Enter \  ├──────┼──────┼──────┼──────┼──────┴──────╯
 *               │      │      │      │ADJUST│ /       /     \       \ │      │      │      │      │
 *               ╰──────┴──────┴──────┴──────┴────────╯       ╰────────┴──────┴──────┴──────┴──────╯
 */
[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______, _______,    _______, _______,    _______, KC_PSCR,
  _______, XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX,    KC_WH_U,    _______, KC_PGUP, KC_HOME,    KC_UP  , KC_END,     KC_INS,  KC_DEL,
  _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_CAPS,    KC_BTN3,    _______, KC_PGDN, KC_LEFT,    KC_DOWN, KC_RGHT,    KC_APP,  KC_BSPC,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_WH_D,    _______, XXXXXXX, C(KC_LEFT), XXXXXXX, C(KC_RGHT), XXXXXXX, _______,
                    _______, _______, _______,TO(_ADJUST), _______,    _______, XXXXXXX, _______,    _______, _______
),
/* ADJUST
 * ╭──────┬──────┬──────┬──────┬──────┬──────╮                         ╭──────┬──────┬──────┬──────┬──────┬──────╮
 * │Toggle│      │      │      │      │      ├───────╮    E    ╭───────┤      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ Hue + │<   N   >│RGB prv├──────┼──────┼──────┼──────┼──────┼──────┤
 * │QWERTY│COLEMA│      │      │      │      ├───────┤    C    ├───────┤      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤       │<   O   >│Toggle ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ Sat+ │ Bri+ │ Spe+ │      │      ├───────┤    D    ├───────┤      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ Hue - │<   E   >│RGB nxt├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ Sat- │ Bri- │ Spe- │      │      ├───┬───┴───╮R╭───┴───┬───┤      │      │      │      │      │      │
 * ╰──────┴──────┼──────┼──────┼──────┼──────┤  /       /   \       \  ├──────┼──────┼──────┼──────┼──────┴──────╯
 *               │      │      │      │TG ADJ│ /       /     \       \ │TG ADJ│      │      │      │
 *               ╰──────┴──────┴──────┴──────┴────────╯       ╰────────┴──────┴──────┴──────┴──────╯
 */
[_ADJUST] = LAYOUT(
  RGB_TOG,     XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  DF(_QWERTY), DF(_COLEMAK), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RGB_HUI,        RGB_RMOD, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,     RGB_SAI,      RGB_VAI, RGB_SPI, XXXXXXX, XXXXXXX,     XXXXXXX,        RGB_TOG,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,     RGB_SAD,      RGB_VAD, RGB_SPD, XXXXXXX, XXXXXXX,     RGB_HUD,        RGB_MOD,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX, TG(_ADJUST), XXXXXXX,        XXXXXXX,  TG(_ADJUST), XXXXXXX, XXXXXXX, XXXXXXX
)
};
