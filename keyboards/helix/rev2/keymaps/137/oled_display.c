/* Copyright 2020 yushakobo
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

#include <stdio.h>
#include <string.h>
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

//assign the right code to your layers for OLED display
#define L_BASE 0
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)

#define L_QWERTY (1<<_QWERTY)
#define L_COLEMAK (1<<_COLEMAK)
#define L_DVORAK (1<<_DVORAK)

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_0;
    } else {
        return OLED_ROTATION_0;
    }
}

// static void render_layer_status(void) {
//     char buf[10];
//     snprintf(buf, sizeof(buf), "%04lx", default_layer_state | layer_state);
//     oled_write(buf, false);
// }

void render_status(void) {
    // static const char os_logo[][2][3] PROGMEM = {{{0x95,0x96,0},{0xb5,0xb6,0}},{{0x97,0x98,0},{0xb7,0xb8,0}}};
    // if (is_mac_mode()) {
    //     oled_write_P(os_logo[0][0], false);
    //     oled_write_P(PSTR("\n"), false);
    //     oled_write_P(os_logo[0][1], false);
    // } else {
    //     oled_write_P(os_logo[1][0], false);
    //     oled_write_P(PSTR("\n"), false);
    //     oled_write_P(os_logo[1][1], false);
    // }

    render_helix_logo();

    static const char map_logo[][2] PROGMEM = {{0x03,0},{0x05,0},{0x06,0}};

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(map_logo[0], false);
            oled_write_P(PSTR(" "), false);
            break;
        case _COLEMAK:
            oled_write_P(map_logo[1], false);
            oled_write_P(PSTR(" "), false);
            break;
        case _DVORAK:
            oled_write_P(map_logo[2], false);
            oled_write_P(PSTR(" "), false);
            break;
    }

    static const char mode_logo[][2] PROGMEM = {{0x13,0},{0x23,0},{0x12,0},{0x7f,0}};

    led_t led_state = host_keyboard_led_state();

    if (led_state.caps_lock) {
        oled_write_P(mode_logo[0], false);
        oled_write_P(PSTR(" "), false);
    }

    if (led_state.num_lock) {
        oled_write_P(mode_logo[1], false);
        oled_write_P(PSTR(" "), false);
    }

    if (led_state.scroll_lock) {
        oled_write_P(mode_logo[2], false);
        oled_write_P(PSTR(" "), false);
    }

    if (!is_mac_mode()) {
        oled_write_P(mode_logo[3], false);
        oled_write_P(PSTR(" "), false);
    }

    static const char layer_logo[][2] PROGMEM = {{0x20,0},{0x18,0},{0x19,0},{0x1c,0}};

    switch (get_highest_layer(layer_state)) {
        case _LOWER:
            oled_write_P(layer_logo[1], false);
            oled_write_P(PSTR(" "), false);
            break;
        case _RAISE:
            oled_write_P(layer_logo[2], false);
            oled_write_P(PSTR(" "), false);
            break;
        case _ADJUST:
            oled_write_P(layer_logo[3], false);
            oled_write_P(PSTR(" "), false);
            break;
    }

    oled_advance_page(true);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_helix_logo();
    }
    return false;
}
