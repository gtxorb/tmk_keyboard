#include <avr/pgmspace.h>
#include "actionmap.h"
#include "actionmap_common.h"
#include "action_util.h"
#include "action_code.h"
#include "action_layer.h"
#include "wait.h"

#include <avr/wdt.h>

/* id for user defined functions */
enum function_id {
    RESET_LAYER_STATE,
    PROMICRO_RESET,
    PROMICRO_PROGRAM,
};

#define AC_FN1            ACTION_LAYER_ONESHOT(3)
#define AC_FN2            ACTION_LAYER_ONESHOT(4)
#define AC_FN3            ACTION_LAYER_ONESHOT(5)
#define AC_SSFT           ACTION_MODS_ONESHOT(MOD_LSFT)
#define AC_SFT_ENT        ACTION_MODS_TAP_KEY(MOD_LSFT, KC_ENT)

#define AC_FN0            ACTION_FUNCTION(RESET_LAYER_STATE)
#define AC_QWERTY         ACTION_DEFAULT_LAYER_SET(0)
#define AC_DVORAK         ACTION_DEFAULT_LAYER_SET(1)
#define AC_COLEMAK        ACTION_DEFAULT_LAYER_SET(2)

#define AC_PROMICRO_PROGRAM  ACTION_FUNCTION_TAP(PROMICRO_PROGRAM)
#define AC_PROMICRO_RESET    ACTION_FUNCTION_TAP(PROMICRO_RESET)

const uint16_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* qwerty */
    [0] = ACTIONMAP(
        /* left hand */
            GRV     , 1   , 2    , 3   , 4   , 5   ,
            TAB     , Q   , W    , E   , R   , T   ,
            CAPS    , A   , S    , D   , F   , G   ,
            LSFT    , Z   , X    , C   , V   , B   , ESC , ESC  ,
            LCTL    , LALT, PGUP , PGDN, LGUI, SPC , ENT , LBRC , RBRC ,
        /* right hand */
                                6    , 7    , 8    , 9    , 0    , BSPC ,
                                Y    , U    , I    , O    , P    , BSLS ,
                                H    , J    , K    , L    , SCLN , QUOT ,
                  HOME , END,   N    , M    , COMM , DOT  , SLSH , RSFT ,
            EQL , MINS , ENT,   SPC  , LEFT , UP   , DOWN , RGHT , ENT
    ),

};

void promicro_bootloader_jmp(bool program) {
    uint16_t *const bootKeyPtr = (uint16_t *)0x0800;

    // Value used by Caterina bootloader use to determine whether to run the
    // sketch or the bootloader programmer.
    uint16_t bootKey = program ? 0x7777 : 0;

    *bootKeyPtr = bootKey;

    // setup watchdog timeout
    wdt_enable(WDTO_60MS);

    while(1) {} // wait for watchdog timer to trigger
}

#define KPRINT_DELAY 1
void kput_char(char c) {
    uint8_t code = 0;
    uint8_t mods = 0;
    if ('a' <= c && c <= 'z') {
        code = (c - 'a') + KC_A;
    } else if ('A' <= c && c <= 'Z') {
        code = (c - 'A') + KC_A;
        mods = MOD_BIT(KC_LSHIFT);
    } else if ('0' <= c && c <= '9') {
        code = (c == '0') ? KC_0 : (c - '1') + KC_1;
    } else {
        switch (c) {
            case ' ': code = KC_SPACE; break;
            case '\n': code = KC_ENTER; break;
            case '\t': code = KC_TAB; break;
            case ';': code = KC_SCOLON; break;
            case ',': code = KC_COMMA; break;
            case '.': code = KC_DOT; break;
            case '/': code = KC_SLASH; break;
            case '\\': code = KC_BSLASH; break;
            case '[': code = KC_LBRACKET; break;
            case ']': code = KC_RBRACKET; break;
            case '-': code = KC_MINUS; break;
            case '=': code = KC_EQUAL; break;
            case '`': code = KC_GRAVE; break;
            case '\'': code = KC_QUOTE; break;
        }
        if (!code) {
            switch (c) {
                case ':': code = KC_SCOLON; break;
                case '<': code = KC_COMMA; break;
                case '>': code = KC_DOT; break;
                case '?': code = KC_SLASH; break;
                case '|': code = KC_BSLASH; break;
                case '{': code = KC_LBRACKET; break;
                case '}': code = KC_RBRACKET; break;
                case '_': code = KC_MINUS; break;
                case '+': code = KC_EQUAL; break;
                case '~': code = KC_GRAVE; break;
                case '"': code = KC_QUOTE; break;

                case '!': code = KC_1; break;
                case '@': code = KC_2; break;
                case '#': code = KC_3; break;
                case '$': code = KC_4; break;
                case '%': code = KC_5; break;
                case '^': code = KC_6; break;
                case '&': code = KC_7; break;
                case '*': code = KC_8; break;
                case '(': code = KC_9; break;
                case ')': code = KC_0; break;
            }
            mods = code ? MOD_BIT(KC_LSHIFT) : 0;
        }
    }
    if (!code) {
        code = KC_SLASH;
        mods = MOD_BIT(KC_LSHIFT);
    }

    // key down
    add_weak_mods(mods);
    register_code(code);

    wait_ms(KPRINT_DELAY);

    // key up
    del_weak_mods(mods);
    unregister_code(code);
    /* send_keyboard_report(); */
}

void kprint(char *s) {
    while(*s) {
        kput_char(*s);
        s++;
    }
}

/*
 * user defined action function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    uint8_t tap_count = record->tap.count;
    switch (id) {
        case RESET_LAYER_STATE:
            if (record->event.pressed) {
                if (!get_oneshot_locked_mods() && !get_oneshot_layer_state()) {
                    register_code(KC_ESC);
                }
            } else {
                if (!get_oneshot_locked_mods() && !get_oneshot_layer_state()) {
                    unregister_code(KC_ESC);
                } else {
                    reset_oneshot_layer();
                    clear_oneshot_locked_mods();
                    layer_clear();
                    clear_keyboard();
                }
            }
            break;
        case PROMICRO_RESET:
            if(tap_count == 5) {
                promicro_bootloader_jmp(false);
            }
            break;
        case PROMICRO_PROGRAM:
            if(tap_count == 5) {
                promicro_bootloader_jmp(true);
            }
            break;
        default:
            break;
    }
}

// vim:sw=4:
