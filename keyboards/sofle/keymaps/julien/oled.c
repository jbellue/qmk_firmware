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

//Sets up what the OLED screens display.

#ifdef OLED_ENABLE

static void render_secondary_oled(void) {
    static const char PROGMEM qmk_logo[] = {
        0x2e,0x05,0xce,0xcf,0xd0,0xd1,0xd2,0x20,0x20,0x05,0x20,0x20,0x20,0x20,0x05,0x20,0x2e,0x07,0x05,0x2e,0x20,
        0x20,0x20,0xd3,0xd4,0xd5,0xd6,0xd7,0xd8,0xd9,0x20,0x20,0x05,0x20,0x2b,0x20,0x20,0x05,0x20,0x20,0x01,0x02,
        0x2b,0x20,0xda,0xdb,0xdc,0xdd,0xde,0xdf,0xbd,0x20,0x2e,0x20,0x20,0x05,0x08,0x20,0x06,0x05,0x20,0x03,0x04,
        0x20,0x2e,0xbe,0xbf,0x9d,0x9e,0x9f,0x20,0x2e,0x20,0x20,0x20,0x05,0x20,0x05,0x20,0x05,0x20,0x07,0x2e,0x05,
        0
    };

    oled_write_P(qmk_logo, false);
}

static void render_main_logo(const bool inverted) {
    static const char PROGMEM rebel_logo[] = {
        0x20, 0x20, 0x20, 0x20, 0x20,
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4,
        0x20, 0x20, 0x20, 0x20, 0x20, 0};
    oled_write_ln_P(rebel_logo, inverted);
}

static const char PROGMEM qwerty_off_1[] =  {0x85, 0x86, 0};
static const char PROGMEM qwerty_off_2[] =  {0xa5, 0xa6, 0};
static const char PROGMEM qwerty_on_1[] =   {0x8d, 0x8e, 0};
static const char PROGMEM qwerty_on_2[] =   {0xad, 0xae, 0};

static const char PROGMEM special_off_1[] = {0x87, 0x88, 0};
static const char PROGMEM special_off_2[] = {0xa7, 0xa8, 0};
static const char PROGMEM special_on_1[] =  {0x8f, 0x90, 0};
static const char PROGMEM special_on_2[] =  {0xaf, 0xb0, 0};

static const char PROGMEM nav_off_1[] = {0x89, 0x8a, 0};
static const char PROGMEM nav_off_2[] = {0xa9, 0xaa, 0};
static const char PROGMEM nav_on_1[] =  {0x91, 0x92, 0};
static const char PROGMEM nav_on_2[] =  {0xb1, 0xb2, 0};

static const char PROGMEM rgb_off_1[] = {0x8b, 0x8c, 0};
static const char PROGMEM rgb_off_2[] = {0xab, 0xac, 0};
static const char PROGMEM rgb_on_1[] =  {0x93, 0x94, 0};
static const char PROGMEM rgb_on_2[] =  {0xb3, 0xb4, 0};

// fillers between the modifier icons bleed into the icon frames
#define OFF_OFF_1 0xc5
#define OFF_OFF_2 0xc6
#define ON_OFF_1  0xc7
#define ON_OFF_2  0xc8
#define OFF_ON_1  0xc9
#define OFF_ON_2  0xca
//#define ON_ON_1   0xcb
//#define ON_ON_2   0xcc

// lock indicators borders
#define LOCK_LEFT_1  0x99
#define LOCK_LEFT_2  0xb9
#define LOCK_RIGHT_1 0x98
#define LOCK_RIGHT_2 0xb8
// lock indicators
#define LOCK_NUM_OFF_1    0x95
#define LOCK_NUM_OFF_2    0xb5
#define LOCK_NUM_ON_1     0x9a
#define LOCK_NUM_ON_2     0xba
#define LOCK_CAPS_OFF_1   0x96
#define LOCK_CAPS_OFF_2   0xb6
#define LOCK_CAPS_ON_1    0x9b
#define LOCK_CAPS_ON_2    0xbb
#define LOCK_SCROLL_OFF_1 0x97
#define LOCK_SCROLL_OFF_2 0xb7
#define LOCK_SCROLL_ON_1  0x9c
#define LOCK_SCROLL_ON_2  0xbc

// light effect border
// ╔═══╗    ╔═══╗
// ║ X ║ or ║ XX║
// ╚═══╝    ╚═══╝
static const char PROGMEM top_effect_border[] =    {0x0f, 0xcd, 0xcd, 0xcd, 0x09, 0};
static const char PROGMEM bottom_effect_border[] = {0x10, 0xcd, 0xcd, 0xcd, 0x0e, 0};
#define LEFT_BORDER 0x0b
#define RIGHT_BORDER 0x0c


static void render_main_oled(void) {
    const uint8_t highest_layer = get_highest_layer(layer_state);
    render_main_logo(highest_layer != _QWERTY);
    // Set the current layer tile;
    // line 1
    if (highest_layer == _QWERTY) {
        oled_write_P(qwerty_on_1, false);
        oled_write_char(ON_OFF_1, false);
    }
    else {
        oled_write_P(qwerty_off_1, false);
        oled_write_char((highest_layer == _LOWER) ? OFF_ON_1 : OFF_OFF_1, false);
    }
    if (highest_layer == _LOWER) {
        oled_write_P(special_on_1, false);
    }
    else {
        oled_write_P(special_off_1, false);
    }
    // line 2
    if (highest_layer == _QWERTY) {
        oled_write_P(qwerty_on_2, false);
        oled_write_char(ON_OFF_2, false);
    }
    else {
        oled_write_P(qwerty_off_2, false);
        oled_write_char((highest_layer == _LOWER) ? OFF_ON_2 : OFF_OFF_2, false);
    }
    if (highest_layer == _LOWER) {
        oled_write_P(special_on_2, false);
    }
    else {
        oled_write_P(special_off_2, false);
    }

    // line 3
    if (highest_layer == _RAISE) {
        oled_write_P(nav_on_1, false);
        oled_write_char(ON_OFF_1, false);
    }
    else {
        oled_write_P(nav_off_1, false);
        oled_write_char((highest_layer == _ADJUST) ? OFF_ON_1 : OFF_OFF_1, false);
    }
    if (highest_layer == _ADJUST) {
        oled_write_P(rgb_on_1, false);
    }
    else {
        oled_write_P(rgb_off_1, false);
    }
    // line 4
    if (highest_layer == _RAISE) {
        oled_write_P(nav_on_2, false);
        oled_write_char(ON_OFF_2, false);
    }
    else {
        oled_write_P(nav_off_2, false);
        oled_write_char((highest_layer == _ADJUST) ? OFF_ON_2 : OFF_OFF_2, false);
    }
    if (highest_layer == _ADJUST) {
        oled_write_ln_P(rgb_on_2, false);
    }
    else {
        oled_write_ln_P(rgb_off_2, false);
    }

    const led_t led_state = host_keyboard_led_state();
    oled_write_char(LOCK_LEFT_1, false);
    oled_write_char(led_state.num_lock    ? LOCK_NUM_ON_1    : LOCK_NUM_OFF_1,    false);
    oled_write_char(led_state.caps_lock   ? LOCK_CAPS_ON_1   : LOCK_CAPS_OFF_1,   false);
    oled_write_char(led_state.scroll_lock ? LOCK_SCROLL_ON_1 : LOCK_SCROLL_OFF_1, false);
    oled_write_char(LOCK_RIGHT_1, false);
    oled_write_char(LOCK_LEFT_2, false);
    oled_write_char(led_state.num_lock    ? LOCK_NUM_ON_2    : LOCK_NUM_OFF_2,    false);
    oled_write_char(led_state.caps_lock   ? LOCK_CAPS_ON_2   : LOCK_CAPS_OFF_2,   false);
    oled_write_char(led_state.scroll_lock ? LOCK_SCROLL_ON_2 : LOCK_SCROLL_OFF_2, false);
    oled_write_char(LOCK_RIGHT_2, false);

    // Host Keyboard RGB backlight status
    oled_write_P(top_effect_border, false);
    // oled_write_P(left_effect_border, false);
    const uint8_t led_mode = rgblight_get_mode();
    char effect_top_digit = led_mode > 9 ? '1' : ' ';
    char effect_lower_digit = led_mode % 10 + 0x30;
    if (led_mode > 9) {
        effect_top_digit = '1';
        effect_lower_digit = led_mode % 10 + 0x30;
    }
    else {
        effect_top_digit = led_mode % 10 + 0x30;
        effect_lower_digit = ' ';
    }
    static char led_buf[6] = {'\0'};
    led_buf[0] = LEFT_BORDER;
    led_buf[1] = ' ';
    led_buf[2] = effect_top_digit;
    led_buf[3] = effect_lower_digit;
    led_buf[4] = RIGHT_BORDER;
    oled_write(led_buf, false);
    // oled_write_P(right_effect_border, false);
    oled_write_P(bottom_effect_border, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_main_oled();
    } else {
        render_secondary_oled();
    }
    return false;
}

#endif
