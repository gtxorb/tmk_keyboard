#ifndef KEYMAP_H
#define KEYMAP_H

/* #define SHIFT(key) ACTION_MODS_KEY(MOD_LSFT, key) */
/* #define CTRL(key)  ACTION_MODS_KEY(MOD_LCTL, key) */
/* #define ALT(key)   ACTION_MODS_KEY(MOD_LALT, key) */
/* #define GUI(key)   ACTION_MODS_KEY(MOD_LGUI, key) */

#define SHIFT(key) ACTION(ACT_MODS, (MOD_LSFT << 8) | (key))
#define CTRL(key) ACTION(ACT_MODS, (MOD_LCTL << 8) | (key))
#define ALT(key) ACTION(ACT_MODS, (MOD_LALT << 8) | (key))
#define GUI(key) ACTION(ACT_MODS, (MOD_LGUI << 8) | (key))

#define KEYMAP( \
    K00, K01, K02, K03, K04, K05, \
    K10, K11, K12, K13, K14, K15, \
    K20, K21, K22, K23, K24, K25, \
    K30, K31, K32, K33, K34, K35, K36, K37, \
    K40, K41, K42, K43, K44, K45, K46, K47, K48,\
\
    K50, K51, K52, K53, K54, K55, \
    K60, K61, K62, K63, K64, K65, \
    K70, K71, K72, K73, K74, K75, \
    K80, K81, K82, K83, K84, K85, K86, K87, \
    K90, K91, K92, K93, K94, K95, K96, K97, K98 \
) { \
    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_NO,    KC_NO,    KC_NO },    \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_NO,    KC_NO,    KC_NO },    \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_NO,    KC_NO,    KC_NO },    \
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37, KC_NO },    \
    { KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_##K46, KC_##K47, KC_##K47 }, \
\
    { KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54, KC_##K55, KC_NO,    KC_NO,    KC_NO },    \
    { KC_##K60, KC_##K61, KC_##K62, KC_##K63, KC_##K64, KC_##K65, KC_NO,    KC_NO,    KC_NO },    \
    { KC_##K70, KC_##K71, KC_##K72, KC_##K73, KC_##K74, KC_##K75, KC_NO,    KC_NO,    KC_NO },    \
    { KC_##K80, KC_##K81, KC_##K82, KC_##K83, KC_##K84, KC_##K85, KC_##K86, KC_##K87, KC_NO },    \
    { KC_##K90, KC_##K91, KC_##K92, KC_##K93, KC_##K94, KC_##K95, KC_##K96, KC_##K97, KC_##K98 }  \
}


#endif
