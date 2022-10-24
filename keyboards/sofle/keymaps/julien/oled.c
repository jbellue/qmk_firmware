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
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_ln_P(qmk_logo, false);
}

static void render_main_logo(void) {
    static const char PROGMEM rebel_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_ln_P(rebel_logo, false);
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
static const char PROGMEM off_off_1[] = {0xc5, 0};
static const char PROGMEM off_off_2[] = {0xc6, 0};
static const char PROGMEM on_off_1[] =  {0xc7, 0};
static const char PROGMEM on_off_2[] =  {0xc8, 0};
static const char PROGMEM off_on_1[] =  {0xc9, 0};
static const char PROGMEM off_on_2[] =  {0xca, 0};
//static const char PROGMEM on_on_1[] = {0xcb, 0};
//static const char PROGMEM on_on_2[] = {0xcc, 0};

// lock indicators borders
static const char PROGMEM lock_left_1[] =       {0x99, 0};
static const char PROGMEM lock_left_2[] =       {0xb9, 0};
static const char PROGMEM lock_right_1[] =      {0x98, 0};
static const char PROGMEM lock_right_2[] =      {0xb8, 0};
// lock indicators
static const char PROGMEM lock_num_off_1[] =    {0x95, 0};
static const char PROGMEM lock_num_off_2[] =    {0xb5, 0};
static const char PROGMEM lock_num_on_1[] =     {0x9a, 0};
static const char PROGMEM lock_num_on_2[] =     {0xba, 0};
static const char PROGMEM lock_caps_off_1[] =   {0x96, 0};
static const char PROGMEM lock_caps_off_2[] =   {0xb6, 0};
static const char PROGMEM lock_caps_on_1[] =    {0x9b, 0};
static const char PROGMEM lock_caps_on_2[] =    {0xbb, 0};
static const char PROGMEM lock_scroll_off_1[] = {0x97, 0};
static const char PROGMEM lock_scroll_off_2[] = {0xb7, 0};
static const char PROGMEM lock_scroll_on_1[] =  {0x9c, 0};
static const char PROGMEM lock_scroll_on_2[] =  {0xbc, 0};

//full line separator
static const char PROGMEM line_separator[] =  {0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0};


static void render_main_oled(void) {
    render_main_logo();
    // Set the current layer tile
    const uint8_t highest_layer = get_highest_layer(layer_state);
    // line 1
    if (highest_layer == _QWERTY) {
        oled_write_P(qwerty_on_1, false);
        oled_write_P(on_off_1, false);
    }
    else {
        oled_write_P(qwerty_off_1, false);
        oled_write_P((highest_layer == _LOWER) ? off_on_1 : off_off_1, false);
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
        oled_write_P(on_off_2, false);
    }
    else {
        oled_write_P(qwerty_off_2, false);
        oled_write_P((highest_layer == _LOWER) ? off_on_2 : off_off_2, false);
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
        oled_write_P(on_off_1, false);
    }
    else {
        oled_write_P(nav_off_1, false);
        oled_write_P((highest_layer == _ADJUST) ? off_on_1 : off_off_1, false);
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
        oled_write_P(on_off_2, false);
    }
    else {
        oled_write_P(nav_off_2, false);
        oled_write_P((highest_layer == _ADJUST) ? off_on_2 : off_off_2, false);
    }
    if (highest_layer == _ADJUST) {
        oled_write_ln_P(rgb_on_2, false);
    }
    else {
        oled_write_ln_P(rgb_off_2, false);
    }

    const led_t led_state = host_keyboard_led_state();
    oled_write_P(lock_left_1, false);
    oled_write_P(led_state.num_lock    ? lock_num_on_1    : lock_num_off_1,    false);
    oled_write_P(led_state.caps_lock   ? lock_caps_on_1   : lock_caps_off_1,   false);
    oled_write_P(led_state.scroll_lock ? lock_scroll_on_1 : lock_scroll_off_1, false);
    oled_write_P(lock_right_1, false);
    oled_write_P(lock_left_2, false);
    oled_write_P(led_state.num_lock    ? lock_num_on_2    : lock_num_off_2,    false);
    oled_write_P(led_state.caps_lock   ? lock_caps_on_2   : lock_caps_off_2,   false);
    oled_write_P(led_state.scroll_lock ? lock_scroll_on_2 : lock_scroll_off_2, false);
    oled_write_ln_P(lock_right_2, false);

    // Host Keyboard RGB backlight status
    oled_write_ln_P(line_separator, false);
    const uint8_t led_mode = rgblight_get_mode();
    oled_write_P((led_mode < 10) ? PSTR("Light   ") : PSTR("Light  "), false);

    static char led_buf[4] = {'\0'};
    itoa((uint8_t)rgblight_get_mode(), led_buf, 10);
    oled_write(led_buf, false);
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
