#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |    ; |   '    |
 * |--------+------+------+------+------+------| 　　　|           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |    / | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      | CTRL |  ALT | LGUI |                                       | RGUI |      |   [  |   ]  |   `  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Copy | Paste|       |      | 1Pass|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |   ←  |       |   ↑  |      |      |
 *                                 | Space|  TAB |------|       |------|  BS  |Enter |
 *                                 |      |      |   →  |       |   ↓  |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,    KC_1,   KC_2,     KC_3,     KC_4,   KC_5,   KC_NO,
        KC_DELT,   KC_Q,   KC_W,     KC_E,     KC_R,   KC_T,   TG(1),
        KC_LCTRL,  KC_A,   KC_S,     KC_D,     KC_F,   KC_G,
        KC_LSFT,   KC_Z,   KC_X,     KC_C,     KC_V,   KC_B,   KC_NO,
        KC_NO,     KC_NO,  KC_LCTRL, KC_LALT,  KC_LGUI,

                                                KC_M(0), KC_M(1),
                                                         KC_RIGHT,
                                         KC_SPC, KC_TAB, KC_LEFT,

        // right hand 
        KC_RGHT,  KC_6,  KC_7,    KC_8,     KC_9,    KC_0,     KC_MINS,
        TG(1),    KC_Y,  KC_U,    KC_I,     KC_O,    KC_P,     KC_BSLS,
                  KC_H,  KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
        KC_NO,    KC_N,  KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
                         KC_RGUI, KC_NO,    KC_LBRC, KC_RBRC,  KC_GRV,

        KC_LALT, KC_M(2),
        KC_PGUP,
        KC_PGDN, KC_TAB, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | (TS)ESC |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | (TS)Del |   !  |   @  |   {  |   }  |   |  |  L0  |           |  L0  |   Up |   7  |   8  |   9  |   *  |        |
 * |---------+------+------+------+------+------| (TS) |           | (TS) |------+------+------+------+------+--------|
 * | (TS)LCTR|   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LShift |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      | CTRL |  ALT | LGUI |                                       | RGUI |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |(TS)CP|(TS)PA|       |　　　 |1Pass |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | (TS) | (TS) |   ←  |       |   ↑  | (TS) |(TS)  |
 *                                 | Space| TAB  |------|       |------|  BS  |Enter |
 *                                 |      |      |   →  |       |   ↓  |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
       KC_TRNS,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_PIPE,  KC_TRNS,
       KC_TRNS,  KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,  KC_GRV,
       KC_TRNS,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILD,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                          RGB_MOD, KC_TRNS,
                                 					               KC_TRNS,
                         					     KC_TRNS, KC_TRNS, KC_TRNS,

       // right hand
       KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KCF12,    KC_TRNS,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR,  KC_TRNS,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS,  KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS,  KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,   KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
    case 0:
        if (record->event.pressed) {
            return MACRO(D(LGUI), T(C), U(LGUI), END); // コピー
        }
        break;
    case 1:
        if (record->event.pressed) {        
            return MACRO(D(LGUI), T(V), U(LGUI), END); // ペースト
        }
        break;
    case 2:
        if (record->event.pressed) {        
            return MACRO(D(RGUI), T(V), U(LGUI), END); // ペースト
        }
    break;
    }
    return MACRO_NONE;
}
