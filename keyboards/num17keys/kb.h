#ifndef KB_H
#define KB_H

#include "quantum.h"
#define TAPPING_TERM 200
#define KEYMAP( \
	K00, K01, K02, K03, \
	K20, K21, K22,      \
	K30, K31, K32, K33, \
	K40, K41, K42,      \
	K50,      K52, K53  \
) { \
	{ K00,   K01,   K02,   K03 }, \
	{ K20,   K21,   K22,   KC_NO }, \
	{ K30,   K31,   K32,   K33 }, \
	{ K40,   K41,   K42,   KC_NO }, \
	{ K50,   KC_NO, K52,   K53 }  \
}

#endif