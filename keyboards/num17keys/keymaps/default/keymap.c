#include "kb.h"
#define Restart M(7)
#define AddressBook M(6)
#define Driver M(5)
#define TAPPING_TERM 200
enum {
  TD_ESC_CAPS = 1,
  TD_CMD_IPCONFIG=0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 1
 * |------+------+------+------+
 * |Bckspc|   /  |   *  |   -  |   
 * |------+------+------+------+
 * |   7  |   8  |   9  |      |  
 * |------+------+------+   +  |
 * |   4  |   5  |   6  |      |  
 * |------+------+------+------+
 * |   1  |   2  |   3  |      |     
 * |------+------+------+ ENTER|
 * |      0      | .    |      |
 * `---------------------------
 */

	KEYMAP(
	KC_BSPC, KC_SLSH, KC_ASTR, KC_MINS, 
	//TD(TD_CMD_IPCONFIG), KC_SLSH, KC_ASTR, KC_MINS, 
	KC_KP_7, KC_KP_8,KC_KP_9, 
	KC_KP_4, KC_KP_5, KC_KP_6, KC_PLUS, 
	KC_KP_1, KC_KP_2, KC_KP_3, 
	KC_0, LT(3,KC_KP_DOT), KC_ENT),
	
	
/* Layer 1 CLOSING NOTES	
 * ,----------------------------
 * |L3/clc|   L1 |  L3  |Bckspc| 
 * |------+------+------+------+
 * |      |   /  |   *  |   -  |   
 * |------+------+------+------+
 * |td cmd|ipcAll|cmdIPa|      |  tdcmd-> one tap=command prompt 2=command prompt with ipconfig
 * |------+------+------+   +  |
 * |   4  |   5  |   6  |      |  
 * |------+------+------+------+
 * |Restrt|adbook|Driver|      |     
 * |------+------+------+ ENTER|
 * |      0      | .    |      |
 * `---------------------------
 */

	KEYMAP(

	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	TD(TD_CMD_IPCONFIG), M(2), M(4),
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	Restart, AddressBook, Driver, 
	KC_TRNS, KC_TRNS, KC_TRNS),
	
	
	//LAYER 2 MOUSE ACTIONS
	KEYMAP(

	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	KC_MS_ACCEL2, KC_MS_UP, KC_TRNS, 
	KC_MS_LEFT, KC_TRNS, KC_MS_RIGHT, KC_TRNS, 
	KC_TRNS, KC_MS_DOWN, KC_TRNS, 
	KC_MS_BTN1, KC_TRNS, KC_MS_BTN2),
	
	
/* Layer 3 COMMAND PROMPT
 * |------+------+------+------+
 * |NumLoc|   /  |   *  |   -  |   
 * |------+------+------+------+
 * |   7  |   8  |   9  |      |  
 * |------+------+------+   +  |
 * |   4  |   5  |   6  |      |  
 * |------+------+------+------+
 * |restrt|addrbk|Driver|      |     1-> one tap=command prompt 2=command prompt with ipconfig
 * |------+------+------+ ENTER|
 * |    call     | .    |      |
 * `---------------------------
 
	KEYMAP(
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	TD(TD_ESC_CAPS), KC_TRNS, KC_TRNS, 
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	TD(TD_CMD_IPCONFIG), M(2), M(4), 
	KC_TRNS, KC_TRNS, KC_TRNS), */
		
		
	//Layer 3: select layer
	KEYMAP(
	KC_NUMLOCK, KC_TRNS, KC_TRNS, RESET,
	TD(TD_CMD_IPCONFIG), M(2), M(4),
	KC_KP_1, KC_KP_1, KC_KP_1, KC_KP_1,
	Restart, AddressBook, Driver, 
	M(1), KC_TRNS, KC_TRNS),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	
	switch (id) {
	case 0: {//press copy release paste
			if (record->event.pressed) {
				return MACRO( D(LCTL), T(C), U(LCTL), END  );
			} else {
				return MACRO( D(LCTL), T(V), U(LCTL),  END  );
			} break; }
		
	case 1: {//calling out.  adds 9 before the number
			if (record->event.pressed) {
				return MACRO( KC_9, D(LCTL), T(V), U(LCTL),KC_ENTER, END  );
			} break;	}
		
	case 2:{
			if (record->event.pressed) { 
				SEND_STRING("ipconfig /all");
				return MACRO(T(ENTER), END);
			}
			
			break;
		}
		
	case 3:{
			if (record->event.pressed) { 
				return MACRO(D(LGUI), T(R), U(LGUI), T(C), T(M), T(D), T(ENTER),W(19), END);
			} break;}
		
	case 4: {
	
			if (record->event.pressed) { 
				return MACRO(D(LGUI), T(R), U(LGUI), T(C), T(M), T(D), T(ENTER),W(255),W(255), END);
			}
			else {
				SEND_STRING("ipconfig /all");
				return MACRO( T(ENTER), END);
			} break; }
		
	case 5: {
			if (record->event.pressed) {
				SEND_STRING("Assisted the customer with installing a print driver on their computer. Sent a test print and confirmed that it is working");
			} 
			break;
		}
		
	case 6:{
			if (record->event.pressed) { 
				SEND_STRING("Walked the user through accessing the xerox machine through the web browser to edit the address book.");}
			break;	}
		
	case 7: {
			if (record->event.pressed) {
			SEND_STRING("I walked the customer through doing a reboot of the machine. After coming back online it was back to normal.");	
			} 
			break;
		}
	case 8: {
			if (record->event.pressed) {	
		return MACRO( I(20), D(LSFT), T(W), U(LSFT), T(G), T(A), T(MINUS), T(F), T(P), T(A), T(P), T(P),W(100), T(TAB),T(TAB),
		W(10),T(1), T(0), T(DOT), T(1), T(DOT), T(2), T(0), T(0), T(DOT), T(5), T(0),T(TAB), T(4), T(4), T(5),W(10), T(TAB), 
		D(LSFT), T(S), U(LSFT), T(H), T(A), T(R), T(E), T(D), T(TAB), 
		D(LSFT), T(A), U(LSFT), T(MINUS), T(I), T(M), T(P), T(O), T(R), T(T), T(E), T(D), T(P), T(T), T(D), T(O), T(C), T(S), T(BSLASH),D(LCTRL), T(V),U(LCTRL), T(TAB),
		T(C), T(O), T(P), T(I), T(E), T(R), T(1),T(TAB),
		D(LSFT), T(B), U(LSFT), T(0), T(B), D(LSFT), T(2), U(LSFT), T(F), T(E), D(LSFT), T(T), U(LSFT), D(LSFT), T(T), U(LSFT), T(TAB),
		D(LSFT), T(B), U(LSFT), T(0), T(B), D(LSFT), T(2), U(LSFT), T(F), T(E), D(LSFT), T(T), U(LSFT), D(LSFT), T(T), U(LSFT),  END);
			}
	}
		case 9: {
			if (record->event.pressed) {	
		return MACRO( I(20),T(F2), D(LCTRL), T(A), T(C),U(LCTRL),END);}
		}
	
	
	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
	
	
	bool process_record_user(uint16_t keycode, keyrecord_t *record) {
		return true;
	}
}


void cmd_commands(qk_tap_dance_state_t *state, void *user_data) {
if (state->count == 2) {
action_macro_play(MACRO(D(LGUI), T(R), U(LGUI), T(C), T(M), T(D), T(ENTER),W(255),W(255), T(I), T(P), T(C), T(O), T(N), T(F), T(I), T(G), T(SPACE), T(SLASH), T(A), T(L), T(L),T(ENTER),END));
}
else if(state->count==1){
action_macro_play(MACRO(D(LGUI), T(R),W(255), U(LGUI),W(255), T(C), T(M), T(D), T(ENTER),END));
}
else{
action_macro_play(MACRO(D(LGUI), T(R),W(255), U(LGUI),W(255), T(C), T(M), T(D), T(ENTER), W(255), T(P), T(I), T(N), T(G),T(SPACE), D(LCTRL), T(V), U(LCTRL), END));
}
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ENTER, KC_R),
  
  [TD_CMD_IPCONFIG] = ACTION_TAP_DANCE_FN(cmd_commands)
  //[TD_CMD_IPCONFIG] = ACTION_TAP_DANCE_DOUBLE(M(1),M(2))
// Other declarations would go here, separated by commas, if you have them
};


