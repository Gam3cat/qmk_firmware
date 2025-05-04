// Copyright 2024 Gam3cat
// SPDX-License-Identifier: GPL-2.0-or-later

#include "tmk70p.h"

bool nwaa_enter;
uint16_t nwaa_timer = false;
uint16_t nwaa_interval = 1000; // (1000ms == 1s)

void nwaa(void) {
    switch(rand() % 4) {
        case 0:
            SEND_STRING("This is custom keycode #0.");
            break;
        case 1:
            SEND_STRING("This is custom keycode #1.");
            break;
        case 2:
            SEND_STRING("This is custom keycode #2.");
            break;
        case 3:
            SEND_STRING("This is custom keycode #3.");
            break;
        case 4:
            SEND_STRING("This is custom keycode #4.");
            break;
    }
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_NWAA:
            if (record->event.pressed) {
                nwaa_enter ^= 1;
		nwaa_timer = timer_read();
                srand(nwaa_timer);
		if (nwaa_enter) {
                    SEND_STRING("START.");
                }
		else {
                    SEND_STRING("STOP.");
                }
		nwaa();
            }
            return false;
//        case CUSTOM_2:
//            if (record->event.pressed) {
//                SEND_STRING("This is custom keycode #2.");
//            }
//            return false;
//        case CUSTOM_3:
//            if (record->event.pressed) {
//                SEND_STRING("This is custom keycode #3.");
//            }
//            return false;
    }
    return process_record_user(keycode, record);
};

void matrix_scan_kb(void) {
    if (nwaa_enter && timer_elapsed(nwaa_timer) >= nwaa_interval) {
        nwaa_interval = rand() % 7100 + 900;
        nwaa_timer = timer_read();
        SEND_STRING("Looping");
        nwaa();
  }
}
