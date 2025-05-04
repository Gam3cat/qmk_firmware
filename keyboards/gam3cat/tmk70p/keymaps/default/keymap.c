/*Copyright 2021 @Gam3cat

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#include QMK_KEYBOARD_H
#include "version.h"

#define FN_CAPS LT(1, KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*#### Base Layer.
    *  ┌───┐┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐┌───┬───┬───┐
    *  │ESC││`  │1  │2  │3  │4  │5  │6  │7  │8  │9  │0  │-  │=  │BACKSPC││VOL│HME│PUP│
    *  ├───┤├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤├───┼───┼───┤
    *  │F1 ││TAB  │Q  │W  │E  │R  │T  │Y  │U  │I  │O  │P  │[  │]  │\    ││DEL│END│PDN│
    *  ├───┤├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤└───┴───┴───┘
    *  │F2 ││FnCAPS│A  │S  │D  │F  │G  │H  │J  │K  │L  │;  │'  │ENTER   │
    *  ├───┤├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤    ┌───┐
    *  │F3 ││SHIFT   │Z  │X  │C  │V  │B  │N  │M  │,  │.  │/  │Shift     │    │↑  │
    *  ├───┤├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─────┤┌───┼───┼───┐
    *  │F4 ││CTRL │WIN│ALT  │       SPACE               │ALT  │(1)│CTRL ││←  │↓  │→  │
    *  └───┘└─────┴───┴─────┴───────────────────────────┴─────┴───┴─────┘└───┴───┴───┘
    */
    [0] = LAYOUT(
        KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_MUTE, KC_HOME, KC_PGUP,
        KC_F1,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,  KC_END,  KC_PGDN,
        KC_F2,   FN_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_F3,   KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                            KC_UP,
        KC_F4,   KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                                      KC_RALT, MO(1),   KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /*#### Function Layer 1.
    *  ┌───┐┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐┌───┬───┬───┐
    *  │   ││   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│VolMute││PSc│SlK│Pau│
    *  ├───┤├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤├───┼───┼───┤
    *  │   ││(2)  │   │   │   │   │   │   │   │   │   │   │   │   │     ││   │   │   │
    *  ├───┤├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤└───┴───┴───┘
    *  │VlU││FnCAPS│   │   │   │   │   │   │←  │↓  │↑  │→  │   │        │
    *  ├───┤├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤    ┌───┐
    *  │VlD││        │   │   │   │   │   │   │   │   │   │   │          │    │VlU│
    *  ├───┤├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─────┤┌───┼───┼───┐
    *  │VlM││     │   │MENU │                           │     │(1)│     ││WBk│VlD│Wfw│
    *  └───┘└─────┴───┴─────┴───────────────────────────┴─────┴───┴─────┘└───┴───┴───┘
    */
    [1] = LAYOUT(
        XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MUTE,          KC_PSCR, KC_SCRL, KC_PAUS,
        XXXXXXX, MO(2),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_INS,  XXXXXXX, XXXXXXX,
        KC_VOLU, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,          XXXXXXX,
        KC_VOLD, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_VOLU, 
        KC_MUTE, XXXXXXX, XXXXXXX, KC_MENU,                            XXXXXXX,                                     _______, XXXXXXX, XXXXXXX,          KC_WBAK, KC_VOLD, KC_WFWD
    ),
    /*#### Function Layer 2.
    *  ┌───┐┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐┌───┬───┬───┐
    *  │   ││   │   │   │   │   │   │   │   │   │   │   │   │   │       ││   │MR1│MP1│
    *  ├───┤├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤├───┼───┼───┤
    *  │   ││(2)  │   │   │   │Rst│   │   │   │   │   │   │   │   │     ││STP│MR2│MP2│
    *  ├───┤├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤└───┴───┴───┘
    *  │   ││FnCaps│   │   │   │   │   │   │   │   │   │   │   │        │
    *  ├───┤├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤    ┌───┐
    *  │   ││        │   │   │   │   │   │   │   │   │   │   │          │    │   │
    *  ├───┤├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─────┤┌───┼───┼───┐
    *  │   ││     │   │     │                           │     │(1)│     ││   │   │   │
    *  └───┘└─────┴───┴─────┴───────────────────────────┴─────┴───┴─────┘└───┴───┴───┘
    */
    [2] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, DM_REC1, DM_PLY1,
        XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          DM_RSTP, DM_REC2, DM_PLY2,
        XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                                     _______, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
    ),
    /*#### Function Layer 3.
    *  ┌───┐┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐┌───┬───┬───┐
    *  │   ││   │   │   │   │   │   │   │   │   │   │   │   │   │       ││   │   │   │
    *  ├───┤├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤├───┼───┼───┤
    *  │   ││     │   │   │   │   │   │   │   │   │   │   │   │   │     ││   │   │   │
    *  ├───┤├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤└───┴───┴───┘
    *  │   ││      │   │   │   │   │   │   │   │   │   │   │   │        │
    *  ├───┤├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤    ┌───┐
    *  │   ││        │   │   │   │   │   │   │   │   │   │   │          │    │   │
    *  ├───┤├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─────┤┌───┼───┼───┐
    *  │   ││     │   │     │                           │     │   │     ││   │   │   │
    *  └───┘└─────┴───┴─────┴───────────────────────────┴─────┴───┴─────┘└───┴───┴───┘
    */
    [3] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        break;
    }
    return true;
}
#endif
