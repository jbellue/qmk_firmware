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
    _SYMBOL,
    _NAVIGATION,
    _ADJUST
};

#define SFT_SPC LSFT_T(KC_SPC)
#define SFT_ENT RSFT_T(KC_ENT)
#define SYM_BCS LT(_SYMBOL, KC_BSPC)
#define NAV_DEL LT(_NAVIGATION, KC_DEL)

#ifdef OLED_ENABLE
    #include "oled.c"
#endif

#ifdef ENCODER_ENABLE
	#include "encoder.c"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ╭──────┬──────┬──────┬──────┬──────┬──────╮                         ╭──────┬──────┬──────┬──────┬──────┬──────╮
 * │ ESC  │   1  │   2  │   3  │   4  │   5  ├───────╮    E    ╭───────┤   6  │   7  │   8  │   9  │   0  │  =   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ VolUp │<   N   >│ Prev  ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  ├───────┤    C    ├───────┤   Y  │   U  │   I  │   O  │   P  │  -   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ Mute  │<   O   >│ Play  ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │   `  │   A  │   S  │   D  │   F  │   G  ├───────┤    D    ├───────┤   H  │   J  │   K  │   L  │   ;  │  '   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ VolDn │<   E   >│ Next  ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │   [  │   Z  │   X  │   C  │   V  │   B  ├───┬───┴───╮R╭───┴───┬───┤   N  │   M  │   ,  │   .  │   /  │  ]   │
 * ╰──────┴──────┼──────┼──────┼──────┼──────┤  / LShift/   \RShift \  ├──────┼──────┼──────┼──────┼──────┴──────╯
 *               │ LGUI │ LAlt │ LCTR │SymBcs│ /[Space]/     \[Enter]\ │HiDel │ RCTR │ RAlt │ RGUI │
 *               ╰──────┴──────┴──────┴──────┴────────╯       ╰────────┴──────┴──────┴──────┴──────╯
 */

[_QWERTY] = LAYOUT(
  KC_ESC,  KC_1, KC_2,    KC_3,    KC_4,     KC_5,                            KC_6,    KC_7,     KC_8,    KC_9,   KC_0,    KC_EQL,
  KC_TAB,  KC_Q, KC_W,    KC_E,    KC_R,     KC_T,    KC_VOLU,       KC_MPRV, KC_Y,    KC_U,     KC_I,    KC_O,   KC_P,    KC_MINS,
  KC_GRV,  KC_A, KC_S,    KC_D,    KC_F,     KC_G,    KC_MUTE,       KC_MPLY, KC_H,    KC_J,     KC_K,    KC_L,   KC_SCLN, KC_QUOT,
  KC_LBRC, KC_Z, KC_X,    KC_C,    KC_V,     KC_B,    KC_VOLD,       KC_MNXT, KC_N,    KC_M,     KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                 KC_LGUI, KC_LALT, KC_LCTRL, SYM_BCS, SFT_SPC,       SFT_ENT, NAV_DEL, KC_RCTRL, KC_RALT, KC_RGUI
),

/* SYMBOL
 * ╭──────┬──────┬──────┬──────┬──────┬──────╮                         ╭──────┬──────┬──────┬──────┬──────┬──────╮
 * │KC_NUB│  F1  │  F2  │  F3  │  F4  │  F5  ├───────╮    E    ╭───────┤  F6  │  F7  │  F8  │  F9  │ F10  │ F11  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤       │<   N   >│       ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ├───────┤    C    ├───────┤      │      │      │      │      │ F12  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤       │<   O   >│       ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ├───────┤    D    ├───────┤      │      │      │      │      │  \|  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤       │<   E   >│       ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ├───┬───┴───╮R╭───┴───┬───┤      │      │      │      │      │  #~  │
 * ╰──────┴──────┼──────┼──────┼──────┼──────┤  / LShift/   \RShift \  ├──────┼──────┼──────┼──────┼──────┴──────╯
 *               │      │      │      │SymBcs│ /[Space]/     \[Enter]\ │HiDel │      │      │      │
 *               ╰──────┴──────┴──────┴──────┴────────╯       ╰────────┴──────┴──────┴──────┴──────╯
 */
[_SYMBOL] = LAYOUT(
  KC_NUBS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, KC_F12,
  _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, KC_NUBS,
  _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, KC_BSLS,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* NAVIGATION
 * ╭──────┬──────┬──────┬──────┬──────┬──────╮                         ╭──────┬──────┬──────┬──────┬──────┬──────╮
 * │      │      │      │      │      │      ├───────╮    E    ╭───────┤      │      │      │      │      │PrntSc│
 * ├──────┼──────┼──────┼──────┼──────┼──────┤       │<   N   >│       ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ├───────┤    C    ├───────┤PG UP │ Home │  ↑   │ End  │ Ins  │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤       │<   O   >│       ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │ Caps ├───────┤    D    ├───────┤PG DN │  ←   │  ↓   │  →   │ Menu │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤       │<   E   >│       ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ├───┬───┴───╮R╭───┴───┬───┤      │Ctrl← │      │Ctrl→ │      │      │
 * ╰──────┴──────┼──────┼──────┼──────┼──────┤  / Space /   \ Enter \  ├──────┼──────┼──────┼──────┼──────┴──────╯
 *               │      │      │      │SymBcs│ /       /     \       \ │HiDel |      │      │      │
 *               ╰──────┴──────┴──────┴──────┴────────╯       ╰────────┴──────┴──────┴──────┴──────╯
 */
[_NAVIGATION] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______,    _______, _______,    _______, KC_PSCR,
  _______, _______, _______, _______, _______, _______, _______,    _______, KC_PGUP, KC_HOME,    KC_UP  , KC_END,     KC_INS,  _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, KC_PGDN, KC_LEFT,    KC_DOWN, KC_RGHT,    KC_APP,  _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, C(KC_LEFT), _______, C(KC_RGHT), _______, _______,
                    _______, _______, _______, _______, _______,    _______, _______, _______,    _______, _______
),
/* ADJUST
 * ╭──────┬──────┬──────┬──────┬──────┬──────╮                         ╭──────┬──────┬──────┬──────┬──────┬──────╮
 * │Toggle│      │      │      │      │      ├───────╮    E    ╭───────┤      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ Hue + │<   N   >│RGB prv├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ├───────┤    C    ├───────┤      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤       │<   O   >│Toggle ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ Sat+ │ Bri+ │ Spe+ │      │      ├───────┤    D    ├───────┤      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ Hue - │<   E   >│RGB nxt├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ Sat- │ Bri- │ Spe- │      │      ├───┬───┴───╮R╭───┴───┬───┤      │      │      │      │      │      │
 * ╰──────┴──────┼──────┼──────┼──────┼──────┤  /       /   \       \  ├──────┼──────┼──────┼──────┼──────┴──────╯
 *               │      │      │      │SymBcs│ /       /     \       \ │HiDel │      │      │      │
 *               ╰──────┴──────┴──────┴──────┴────────╯       ╰────────┴──────┴──────┴──────┴──────╯
 */
[_ADJUST] = LAYOUT(
  RGB_TOG,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI,        RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  RGB_SAI,  RGB_VAI, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX,        RGB_TOG,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  RGB_SAD,  RGB_VAD, RGB_SPD, XXXXXXX, XXXXXXX, RGB_HUD,        RGB_MOD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,        XXXXXXX,  _______, XXXXXXX, XXXXXXX, XXXXXXX
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYMBOL, _NAVIGATION, _ADJUST);
}

