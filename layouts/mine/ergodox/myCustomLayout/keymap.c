#include QMK_KEYBOARD_H

#include "action_layer.h"
#include "version.h"
#include "eeconfig.h"
#include "eeprom.h"
#include "keymap_colemak.h"

extern keymap_config_t keymap_config;

enum ergodox_layers { _QWERTY, _FUNCTIONS, _NUMPAD, _GAMING, _COLEMAK };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_ergodox(
		// LEFT
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, TG(_GAMING), 
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, 
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_HOME, 
		KC_LCTL, KC_LALT, KC_LGUI, MO(_FUNCTIONS), MO(_NUMPAD), 
									BL_TOGG, BL_INC, 
													BL_DEC, 
									KC_BSPC,KC_DEL, KC_ESC, 
// RIGHT
		TG(_COLEMAK), KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, 
		KC_RBRC, KC_Y, KC_U,KC_I, KC_O,KC_P, KC_BSLS, 
		KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
		KC_END, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT, 
		KC_LEFT, KC_UP, KC_DOWN,KC_RGHT, KC_EQL, 
				KC_PSCR, KC_APP, 
		KC_PGUP, 
		KC_PGDN, KC_ENT, KC_SPC
		),
	[_FUNCTIONS] = LAYOUT_ergodox(
		// LEFT
		KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_NO, 
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS, KC_NO, 
									KC_NO, KC_NO, 
													KC_NO, 
									KC_NO, KC_DEL, KC_ESC, 

		// RIGHT								
		KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F12, 
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, 
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
				KC_NO, KC_NO, 
		KC_NO, 
		KC_NO, KC_NO, KC_NO
		),
	[_NUMPAD] = LAYOUT_ergodox(
		// LEFT
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, 
									KC_NO, KC_NO, 
													KC_NO, 
									KC_BSPC, KC_DEL, KC_ESC, 

		// RIGHT				
		KC_NO, KC_NO, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_NO, 
		KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_PPLS, KC_NO, 
		KC_NO, KC_4, KC_5, KC_6, KC_PPLS, KC_NO, 
		KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_ENT, KC_NO, 
		KC_NO, KC_NO, KC_PDOT, KC_ENT, KC_NO, 
				KC_NO, KC_NO, 
		KC_NO, 
		KC_NO, KC_ENT, KC_0
		),
	[_GAMING] = LAYOUT_ergodox(
		// LEFT
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS, 
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, 
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_HOME, 
		KC_LCTL, KC_LALT, KC_LGUI, KC_NO, KC_NO, 
									KC_F1, KC_F2, 
													KC_F3, 
									KC_BSPC, KC_SPC, KC_F4, 

		// RIGHT			
		KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
		KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_F12, 
		KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
		KC_END, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT, 
		KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_EQL, 
				KC_PSCR, KC_APP, 
		KC_PGUP, 
		KC_PGDN, KC_ENT, KC_SPC
		),
	[_COLEMAK] = LAYOUT_ergodox(
		// LEFT
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO, 
		KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_LBRC, 
		KC_CAPS, KC_A, KC_R, KC_S, KC_T, KC_D, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_HOME, 
		KC_LCTL, KC_LALT, KC_LGUI, MO(_FUNCTIONS), MO(_NUMPAD), 
									BL_TOGG, BL_INC, 
													BL_DEC, 
									KC_BSPC, KC_DEL, KC_ESC, 

		// RIGHT				
		KC_TRNS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, 
		KC_RBRC, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS, 
		KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, 
		KC_END, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT, 
		KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_EQL, 
				KC_PSCR, KC_APP, 
		KC_PGUP, 
		KC_PGDN, KC_ENT, KC_SPC)
};
