/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#pragma once

#ifdef VIA_ENABLE
/* VIA configuration. */
#    define DYNAMIC_KEYMAP_LAYER_COUNT 4
#endif // VIA_ENABLE

#ifndef __arm__
/* Disable unused features. */
#    define NO_ACTION_ONESHOT
#endif // __arm__

// XXX: redefine gpio for this charybdis board
#undef DIODE_DIRECTION
#undef MATRIX_COL_PINS
#undef MATRIX_ROW_PINS
#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROW_PINS { GP11, GP10, GP9, GP8, GP26 }
#define MATRIX_COL_PINS { GP25, GP18, GP17, GP14, GP13, GP12 }

#define SPLIT_HAND_PIN GP15
#define SPLIT_HAND_PIN_LOW_IS_LEFT

/* Charybdis-specific features. */

#ifdef POINTING_DEVICE_ENABLE
// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif // POINTING_DEVICE_ENABLE

#define CHARYBDIS_MINIMUM_DEFAULT_DPI 600
#define CHARYBDIS_CONFIG_SYNC
#define WHEEL_EXTENDED_SUPPORT
#define MASTER_RIGHT

#define TAP_CODE_DELAY 5

#define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
// #define PERMISSIVE_HOLD_PER_KEY

#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define QUICK_TAP_TERM_PER_KEY
#define QUICK_TAP_TERM 120

#define CHORDAL_HOLD

#define DISABLE_LEADER
#ifndef NO_DEBUG
	#define NO_DEBUG
#endif

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
	#define NO_PRINT
#endif

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
// #define NO_ACTION_ONESHOT

// Use Left Ctrl + Right Ctrl to activate the Command feature.
#define IS_COMMAND() (get_mods() == MOD_MASK_CTRL)

// #define NO_ALT_REPEAT_KEY

#ifdef COMBO_ENABLE
#define COMBO_TERM 50
#endif
#define USB_SUSPEND_WAKEUP_DELAY 0
#define LAYER_STATE_8BIT

#ifdef CAPS_WORD_ENABLE
#define CAPS_WORD_INVERT_ON_SHIFT
#define CAPS_WORD_IDLE_TIMEOUT 5000
#endif

#ifdef LAYER_LOCK_ENABLE
#define LAYER_LOCK_IDLE_TIMEOUT 60000
#endif

#define SELECT_WORD_OS_DYNAMIC

// #ifdef OS_DETECTION_ENABLE
// #define OS_DETECTION_SINGLE_REPORT
// #endif

#define FLOW_TAP_TERM 150
// #define ACTION_DEBUG

#ifdef POINTING_DEVICE_ENABLE
// XXX: somehow hires scroll only works on MacOS
// #define POINTING_DEVICE_HIRES_SCROLL_ENABLE
// #define POINTING_DEVICE_HIRES_SCROLL_EXPONENT 1
// #define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE

// XXX: this will cause issue on holding left mouse key and drag on
//      when usb cable is connected at right hand side, issue is gone
#define MOUSE_EXTENDED_REPORT
#endif
