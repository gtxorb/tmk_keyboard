/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"
#include "keymap_common.h"


/* const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP(
        /* left hand */
            GRV     , 1   , 2    , 3   , 4   , 5   ,
            TAB     , Q   , W    , E   , R   , T   ,
            CAPS    , A   , S    , D   , F   , G   ,
            LSFT    , Z   , X    , C   , V   , B   , ESC , FN0  ,
            LCTL    , LALT, PGUP , PGDN, LGUI, SPC , ENT , LBRC , RBRC ,
        /* right hand */
            BSPC    , 0   , 9    , 8   , 7   , 6   ,
            BSLS    , P   , O    , I   , U   , Y   ,
            SCLN    , QUOT, L    , K   , J   , H   ,
            RSFT    , SLSH, DOT  , COMM, M   , N   , END , HOME ,
            ENT     , RGHT, DOWN , UP  , LEFT, SPC , ENT , MINS , EQL
        ),
    KEYMAP(
        /* left hand */
            GRV     , 1   , 2    , 3   , 4   , 5   ,
            TAB     , Q   , W    , E   , R   , T   ,
            CAPS    , A   , S    , D   , F   , G   ,
            LSFT    , Z   , X    , C   , V   , B   , ESC , ESC  ,
            LCTL    , LALT, PGUP , PGDN, LGUI, SPC , ENT , LBRC , RBRC ,
        /* right hand */
            BSPC    , 0   , 9    , 8   , 7   , 6   ,
            BSLS    , P   , O    , I   , U   , Y   ,
            SCLN    , QUOT, L    , K   , J   , H   ,
            RSFT    , SLSH, DOT  , COMM, M   , N   , END , HOME ,
            ENT     , RGHT, DOWN , UP  , LEFT, SPC , ENT , MINS , EQL
        )

};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    ACTION_LAYER_SET_CLEAR(0), // FN0 (L0)
    ACTION_LAYER_TAP_TOGGLE(3), // FN1 (L1)
    ACTION_LAYER_TAP_TOGGLE(4), // FN2 (fn)
    ACTION_LAYER_TAP_TOGGLE(5), // FN3 (media)

    ACTION_MODS_ONESHOT(MOD_LSFT), // FN4 (sticky L shift)
    ACTION_MODS_ONESHOT(MOD_RSFT), // FN5 (sticky R shift)
    ACTION_MODS_TAP_KEY(MOD_LSFT, KC_ENT), // FN6
    ACTION_LAYER_TAP_KEY(1, KC_TAB), // FN7

    ACTION_LAYER_SET_CLEAR(6), // FN8 (mirrored)
    ACTION_LAYER_TAP_TOGGLE(7), // FN9 (L1 mirrored)
    ACTION_LAYER_TAP_TOGGLE(8), // FN10 (fn mirrored)
    ACTION_LAYER_TAP_TOGGLE(9), // FN11 (media mirrored)
    ACTION_DEFAULT_LAYER_SET(0), // FN12 Switch base layer to Qwerty
    ACTION_DEFAULT_LAYER_SET(1), // FN13 Switch base layer to Dvorak
    ACTION_DEFAULT_LAYER_SET(2), // FN14 Switch base layer to Colemak
    ACTION_LAYER_TOGGLE(6), // FN15 (mirrored)
};
