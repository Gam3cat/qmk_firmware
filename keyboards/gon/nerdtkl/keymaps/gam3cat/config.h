#pragma once

//Force NKRO to be enabled.
#define FORCE_NKRO

//Force polling rate.
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 12

//GRAVE_ESC override for CTRL+SHIFT+ESC Windows task manager shortcut.
//#define GRAVE_ESC_CTRL_OVERRIDE

//Delay matrix scan for tap dance, reduce to activate modifier keys faster.
//#define TAPPING_TERM 200
