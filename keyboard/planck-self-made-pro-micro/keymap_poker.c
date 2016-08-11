#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP(
        ESC, Q,   W,   E,   R,   T,   Y,   U,   I,    O,    P,    BSLS, BSPC, \
        TAB, A,   S,   D,   F,   G,   H,   J,   K,    L,    SCLN, QUOT, ENT,  \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM, DOT,  SLSH, UP,   RSFT, \
        LCTL,LALT,PGUP,PGDN,LGUI,SPC, ENT, FN0, LBRC, RBRC, LEFT, DOWN, RGHT),
    /* 1: colemak */
    KEYMAP(
        1,   2,   3,   4,   5,   6,   7,   8,    9,    0,   MINS, EQL,  BSPC, \
        TAB, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,   F9,   F10,  F11,  F12,  \
        LSFT,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,COMM, DOT,  SLSH, UP,   RSFT, \
        LCTL,LALT,PGUP,PGDN,LGUI,SPC, ENT, FN0, LBRC, RBRC, LEFT, DOWN, RGHT)
};
const uint16_t PROGMEM fn_actions[] = {
    /* Poker Layout */
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Layout selector
};
