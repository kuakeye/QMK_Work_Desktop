#ifndef REV2_H
#define REV2_H

#include "../Dactyl.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"


#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

//void promicro_bootloader_jmp(bool program);

#ifndef FLIP_HALF
// Standard Keymap
// (TRRS jack on the left half is to the right, TRRS jack on the right half is to the left)

#define KEYMAP( \
	L00, L01, L02, L03, L04, 			  R01, R02, R03, R04, R05, \
	L10, L11, L12, L13, L14, 			  R11, R12, R13, R14, R15, \
	L20, L21, L22, L23, L24,			  R21, R22, R23, R24, R25, \
							L33, L32, 	R33, R32,   \
								L31,	R34,									\
						L41, L40,L30,	R35, R45, R44 \
	) \
	{ \
		{ L00, L01, L02, L03, L04, KC_NO }, \
		{ L10, L11, L12, L13, L14, KC_NO }, \
		{ L20, L21, L22, L23, L24, KC_NO }, \
		{ L30, L31, L32, L33, KC_NO, KC_NO }, \
		{ L40, L41,  KC_NO,  KC_NO,  KC_NO,  KC_NO }, \
		{ R05, R04, R03, R02, R01, KC_NO }, \
		{ R15, R14, R13, R12, R11, KC_NO }, \
		{ R25, R24, R23, R22, R21, KC_NO }, \
		{ R35, R34, R33, R32, KC_NO, KC_NO }, \
		{ R45, R44, KC_NO, KC_NO, KC_NO, KC_NO } \
	}
#else
// Keymap with right side flipped
// (TRRS jack on both halves are to the right)
#define KEYMAP( \
	L00, L01, L02, L03, L04, 			  R01, R02, R03, R04, R05, \
	L10, L11, L12, L13, L14, 			  R11, R12, R13, R14, R15, \
	L20, L21, L22, L23, L24,			  R21, R22, R23, R24, R25, \
							L33, L32, 	R33, R32,   \
								L31,	R34,									\
						L41, L40,L30,	R35, R45, R44 \
	) \
	{ \
		{ L00, L01, L02, L03, L04, KC_NO }, \
		{ L10, L11, L12, L13, L14, KC_NO }, \
		{ L20, L21, L22, L23, L24, KC_NO }, \
		{ L30, L31, L32, L33, KC_NO, KC_NO }, \
		{ L40, L41,  KC_NO,  KC_NO,  KC_NO,  KC_NO }, \
		{ R05, R04, R03, R02, R01, KC_NO }, \
		{ R15, R14, R13, R12, R11, KC_NO }, \
		{ R25, R24, R23, R22, R21, KC_NO }, \
		{ R35, R34, R33, R32, KC_NO, KC_NO }, \
		{ R45, R44, KC_NO, KC_NO, KC_NO, KC_NO } \
	}
#endif

#endif
