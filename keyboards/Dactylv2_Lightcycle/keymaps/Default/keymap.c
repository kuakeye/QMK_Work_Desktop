#include "Dactyl.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;
#define _QWERTY 0
#define _COLEMAK 1

#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _FN3 5
#define _WINDOWSWITCH 6
#define _ADJUST 16
enum {
	TD_CPY_PST = 0,
	TD_CMD,
	TD_SLSH,
	TD_VRDSK
};

enum custom_keycodes {
	COLEMAK = SAFE_RANGE,
	QWERTY,
	DVORAK,
	LOWER,
	RAISE,
	FN3,
//	FN4,
	ADJUST,
	dance_cln_finished,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CAPP LGUI(LSFT(KC_4))       // Capture portion of screen
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen
#define KC_X0 MT(MOD_LCTL, KC_ESC)
#define KC_LDWN LOWER				//Numpad
#define KC_LUP RAISE
#define KC_TOGUP TG(4)
#define KC_REST RESET
#define KC_X3 LT(_LOWER,KC_EQL)		//function layer 4 ie macros when held tab when pressed
#define KC_X4 LT(_ADJUST, KC_ENT) //Shift when held enter when pressed
#define KC_X5 LT(RAISE, KC_P0)  //Raise to functions when held P0 when pressed
#define KC_X6 TD(TD_SLSH)				//slash vs backslash
#define KC_X7 TD(TD_CPY_PST)		//single tap is copy double is paste
#define KC_X8 TD(TD_CMD)			//single tap is cmd double is ipconfig

#define KC_UNDO LCTL(KC_Z) //undo
#define KC_SFTENT MT(MOD_LSFT, KC_ENT)
#define KC_LGOFF LGUI(KC_L) //log out of comp
#define KC_LGON LCTL(LALT(KC_DEL)) //log into work comp


// Windows virtual desktop switching functions. Downloaded software called SylphyHornEx
#define KC_WS0 LCTL(LGUI(KC_0))
#define KC_WS1 LCTL(LGUI(KC_1))
#define KC_WS2 LCTL(LGUI(KC_2))
#define KC_WS3 LCTL(LGUI(KC_3))
#define KC_WS4 LCTL(LGUI(KC_4))
#define KC_WS5 LCTL(LGUI(KC_5))
#define KC_WS6 LCTL(LGUI(KC_6))
#define KC_WS7 LCTL(LGUI(KC_7))
#define KC_WS8 LCTL(LGUI(KC_8))
#define KC_WS9 LCTL(LGUI(KC_9))
#define KC_WSL LCTL(LGUI(KC_LEFT))
#define KC_WSR LCTL(LGUI(KC_RIGHT))
#define KC_WSWAPL LCTL(LGUI(LSFT(KC_LEFT))) // swap desktop with left one (move this desktop to the left)
#define KC_WSWAPR LCTL(LGUI(LSFT(KC_RIGHT))) // swap desktop with right one (move this desktop to the right)
#define KC_WSMAWL LGUI(LALT(KC_LEFT)) // move active window to desktop on the left
#define KC_WSMAWR LGUI(LALT(KC_RIGHT)) // move active window to desktop on the Right
#define KC_WSPIN LCTL(LGUI(LALT(KC_P))) // pin active window to all desktops
#define KC_WSNEW LCTL(LGUI(KC_D)) // move active window to created new desktop
#define KC_WSRNAME LCTL(LGUI(KC_R)) // rename current desktop


#define KC_LAYER2 MO(_COLEMAK)
#define KC_LAYER3 LT(_DVORAK, KC_SCLN)
#define KC_LAYER4 MO(_WINDOWSWITCH)


#define KC_X9 RGUI(KC_TAB)	//gui tab to switch desktops
#define KC_X10 TD(TD_VRDSK)


#define KC_XLgn M(1)
#define KC_EMAL M(2)
#define KC_WWWX M(3)
#define KC_NTAB M(4)
#define KC_0CA M(6)
#define KC_PASS M(10)
#define KC_IPCF M(11)
#define KC_OP M(12)
#define KC_OC M(13)
#define KC_OD M(14)
#define KC_TCLK M(15)
#define KC_ESCT MT(MOD_LCTL, KC_ESC)
#define KC_GUIT M(0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.           ,----------------------------------_--------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+------|           |------+------+------+------+------|--------|
 * |Tab\FN3 |   Q  |   W  |   F  |   P  |   G  |           |   J  |   L  |   U  |   Y  |   :  |   \    |
 * |--------+------+------+------+------+----- |           |------+------+------+------+------|--------|
 * | ENT/ADJ|   A  |   R  |   S  |   T  |   D  |           |   H  |   N  |   E  |   I  |   O  | ENTER  |
 * |--------+------+------+------+------+------|           |------+------+------+------+------|--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |           |   K  |   M  |   ,  |   .  |  /   |RShift |
 * `--------+------+------+------+------+------'           `-------+------+------+------+------|--------|'
 * |CTR     |  ALT | GUI  | Left | Right|    1                1   | LEFT | RIGHT|  UP  | DOWN  | ~L1  |
 * `----------------------------------'                          `----------------------------------'
 *				6	5		4	   3		2				2		 3		4		5		6
 *                                 ,-------------.       ,-------------.
 *                                 |   6  |   5  |       | 5    |  6     |
 *                          ,------|------|------|       |------+--------+------.
 *                          |   1  |  2    |   4  |       | 4    |        |      |
 *                          |Backsp|GUI   |------|       |------|    1   |    2 |
 *                          |  acs |TAB   |   3  |       | 3    |        |      |
 *                         `--------------------'       `----------------------'
 */
 
 //FOR adjust layer push and hold X3(raise) and LUP (lower).
 //x3= lower when held and Equal ("=") when pressed
 //ESCT is control when held ans Esc when pressed
 //GUIT is window+tab.  only works on win 10


      [_QWERTY] = KC_KEYMAP(Y,Z,1,2,3,4,       5,6,7,8,9,0, //dummy values for lightcycle (Dactyl Mule)
   //,----+----+----+----+----+----.                              ,----+----+----+----+----+----.
      TAB ,  Q  , W  , E  , R  , T  ,                                Y  , U  , I  , O , P  ,BSLS,
   //,----+----+----+----+----+----.                              ,----+----+----+----+----+----.
      BSPC, A  , S  , D  , F  , G ,                                 H  , J  , K  , L  ,LAYER3,QUOT,
   //|----+----+----+----+----+----|                              |----+----+----+----+----+----|
      ESC , Z  , X  , C  , V  , B  ,                                N  , M  ,COMM,DOT,SLSH,RSFT,
   //|----+----+----+----+----+----|                              |----+----+----+----+----+----|
      LCTRL,UNDO,LALT,LGUI, LAYER2  ,                                 LAYER2, LEFT, DOWN, UP, RIGHT,
//	//							`----+----+----+'			`----+----+----'
							 PGDN,PGUP,LALT,LAYER4,		   RALT , LAYER4,HOME, END,
//	//							`----+----+----+'			`----+----+----'
									   DEL,SFTENT,			ENT,SPC
//	//							`----+----+----+'			`----+----+----'
//
//	//							`----+----+----+'			`----+----+----'

   ),

			[_COLEMAK] = KC_KEYMAP(Y,Z,1,2,3,4,       5,6,7,8,9,0, //dummy values for lightcycle (Dactyl Mule)
	//,----+----+----+----+----+----. 									   ,----+----+----+----+----+----.
		    , EXLM, AT, LCBR, RCBR, PIPE,     								 LT  , 7  , 8  , 9 , PAST   ,MINS,
	//,----+----+----+----+----+----.   									 ,----+----+----+----+----+----.
	   UNDS, HASH, DLR, LPRN, RPRN, GRV, 									 GT  , 4 , 5  ,6   ,MINS,    EQL,
	//|----+----+----+----+----+----| 									   |----+----+----+----+----+----|
		   , PERC, CIRC, LBRC, RBRC, TILDE,								 AMPR  , 1  , 2  , 3  , PPLS,    ,
	//|----+----+----+----+----+----|									    |----+----+----+----+----+----|
		    ,     ,     ,     ,      ,                                  ,  0 , DOT, PSLS,    ,
	//|----+----+----+----+----+----| 									   |----+----+----+----+----+----|
//	//							`----+----+----+'			`----+----+----'
							 PGDN,PGUP,LALT,LAYER4,		   RALT , LAYER4,END, HOME,
//	//							`----+----+----+'			`----+----+----'
									   DEL,LSFT,			ENT,SPC
//	//							`----+----+----+'			`----+----+----'
//
//	//							`----+----+----+'			`----+----+----'

	),

	[_DVORAK] = KC_KEYMAP(Y,Z,1,2,3,4,       5,6,7,8,9,0, //dummy values for lightcycle (Dactyl Mule)
	//|----+----+----+----+----+----|  								   |----+----+----+----+----+----|                                
	   ,   ,    ,MS_U,   ,     ,  								       LGOFF,LGON,WH_D,    ,    ,    ,
	//|----+----+----+----+----+----|  								   |----+----+----+----+----+----|
	   ,   ,MS_L,MS_D,MS_R,    , 	                                        ,WH_R,WH_U,WH_L,    ,MPLY,
	//|----+----+----+----+----+----|    							   |----+----+----+----+----+----|
	   ,   ,    ,    ,    ,    ,                                        MPRV,MNXT,VOLD,VOLU,    ,    ,
	//|----+----+----+----+----+----| 								   |----+----+----+----+----+----|
	   ,   ,    ,    ,    ,    ,				                            ,    ,    ,    ,
	//|----+----+----+----+----+----|    							   |----+----+----+----+----+----|
//	//							`----+----+----+'			`----+----+----'
							 PGDN,PGUP,LALT,LAYER4,		   RALT , LAYER4,END, HOME,
//	//							`----+----+----+'			`----+----+----'
									   BTN2,BTN1,			BTN2,BTN1
//	//							`----+----+----+'			`----+----+----'
//
//	//							`----+----+----+'			`----+----+----'
	),

		[_WINDOWSWITCH] = KC_KEYMAP(Y,Z,1,2,3,4,       5,6,7,8,9,0, //dummy values for lightcycle (Dactyl Mule)
	//|----+----+----+----+----+----|  								   |----+----+----+----+----+----|                                
	  WSNEW,WSPIN,WS7, WS8,WS9,WSRNAME,  								        , WS7, WS8, WS9,WSPIN,WSNEW,
	//|----+----+----+----+----+----|  								   |----+----+----+----+----+----|
	   WSL , WSR, WS4, WS5, WS6,    , 	                                        , WS4, WS5, WS6, WSL, WSR,
	//|----+----+----+----+----+----|    							   |----+----+----+----+----+----|
	WSWAPL,WSWAPR,WS1,WS2 ,WS3,     ,                                      , WS1, WS2, WS3,WSWAPL,WSWAPR,
	//|----+----+----+----+----+----| 								   |----+----+----+----+----+----|
	WSMAWL,WSMAWR,    ,WS0,    ,    ,				                              WS0,    ,WSMAWL,WSMAWR,
	//|----+----+----+----+----+----|    							   |----+----+----+----+----+----|
//	//							`----+----+----+'			`----+----+----'
							 PGDN,PGUP,LALT,LAYER4,		   RALT , LAYER4,END, HOME,
//	//							`----+----+----+'			`----+----+----'
									   DEL,LSFT,			ENT,SPC
//	//							`----+----+----+'			`----+----+----'
//
//	//							`----+----+----+'			`----+----+----'

	)

/*
	[_LOWER] = KC_KEYMAP(
	//,----+----+----+----+----+----.    ,----+----+----+----+----+----.
		ESC , 1  , 2 , 3  , 4  , 5  ,      6  , 7  , 8  , 9  , 0  , EQL ,
	//|----+----+----+----+----+----|    |----+----+----+----+----+----|
		DEL ,CAPP,LEFT,RGHT, UP ,LBRC,     RBRC, P4 , P5 , P6 ,PLUS,PIPE,
	//|----+----+----+----+----+----|    |----+----+----+----+----+----|
			,CPYP, UP ,    ,DOWN,LCBR,     RCBR, P1 , P2 , P3 ,MINS,    ,11111
	//|----+----+----+----+----+----|    |----+----+----+----+----+----|
			,LEFT,DOWN,RIGHT,    ,    ,     DEL ,   , P0 ,PDOT,    ,  NLCK, 
	//`----+----+----+----+----+----'    `----+----+----+----+----+----'
		X0 ,LALT,LGUI, X10, LDWN ,BSPC,     SPC, UP ,QUOT,LEFT, DOWN ,RGHT,
	//`----+----+----+----+----+----'    `----+----+----+----+----+----'
		X3  , 1  ,REST, 3  ,    , 5  ,      6  ,    , 8  , 9 , 0  ,MINS
	//`----+----+----+----+----+----'    `----+----+----+----+----+----'
	),

	[_RAISE] = KC_KEYMAP(
	//,----+----+----+----+----+----.    ,----+----+----+----+----+----.
		ESC ,EXLM, AT ,HASH,DLR ,PERC,     CIRC,AMPR,ASTR,LPRN,RPRN,    ,
	//|----+----+----+----+----+----|    |----+----+----+----+----+----|
		DEL ,MPRV,MNXT,VOLU,PGUP,UNDS,     EQL ,HOME,    ,    ,    ,BSLS,
	//|----+----+----+----+----+----|    |----+----+----+----+----+----|
		LSFT,MSTP,MPLY,VOLD,PGDN,MINS,     PLUS,END,COMM ,    ,UP ,    ,
	//|----+----+----+----+----+----|    |----+----+----+----+----+----|
		,    ,    , X3 ,    ,    ,         ,    ,    ,LEFT,DOWN,RIGHT,    
	//`----+----+----+----+----+----'    `----+----+----+----+----+----'
		X0 ,LALT,LGUI, X10, LDWN ,BSPC,     SPC, UP ,QUOT,LEFT, DOWN ,RGHT,
	//`----+----+----+----+----+----'    `----+----+----+----+----+----'
		X3  , 1  , 2  , 3  ,   , 5  ,      6  ,   , 8  ,REST, 0  ,MINS
	//`----+----+----+----+----+----'    `----+----+----+----+----+----'
	),*/

/*
	[_FN4] = KEYMAP( \
	_______, _______, M(3)   , M(2)     , _______,  M(4)  ,		 _______, _______, _______, _______, _______, _______, \
	_______, M(6)   , _______, _______  , _______, _______,		 _______, _______, _______, _______, _______, _______, \
	_______, _______, M(1)   ,TD(TD_CMD), _______, _______,		 _______, _______, _______, _______, KC_UP, _______, \
	M(7)   , M(8)   , M(9)   , _______  , _______, _______,		 _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, \
	_______, _______, _______, _______  , _______, _______,		 _______, _______, _______, _______, _______, _______, \
	_______, _______ , _______, _______  , _______, _______,	 _______, _______, _______, _______, _______, _______ \
	),*/

	/* Adjust (Lower + Raise)
* ,-----------------------------------------------------------------------------------.
* |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|Sat Up|Sat Dn|Val Up|Val Dn| RESET|      |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |             |      |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/



};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
	eeconfig_update_default_layer(default_layer);
	default_layer_set(default_layer);
}
// Debug functions
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}


/*
void dance_cln_finished(void){
register_code (KC_LGUI);
register_code(KC_TAB);
unregister_code(KC_TAB);
unregister_code(KC_LGUI); 
}*/

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	
	switch (id) {
	case 0:
		if (record->event.pressed) {
			return MACRO(D(LGUI), T(TAB), U(LGUI), END);
		}
	case 1:
		if (record->event.pressed) {
		//	SEND_STRING("admin"SS_TAP(X_TAB)"1111"SS_TAP(X_ENTER));
		//return false;	break;
			return MACRO(I(10), T(A), T(D), T(M), T(I), T(N), W(75), T(TAB), T(1), T(1),T(1), T(1), T(ENTER), END );
		}
	case 2:
		if (record->event.pressed) {
			SEND_STRING("email");// auto send email
			return false;	break;
		}
	case 3:
		if (record->event.pressed) {
			SEND_STRING("www.support.xerox.com"SS_TAP(X_ENTER));
						return false;	break;
		}
	case 4:
		if(record->event.pressed) {
			return MACRO(I(10), D(LCTRL), T(T), T(V), T(ENTER), U(LCTRL), END);
		}
		
	case 5:{
			return  MACRO_TAP_HOLD_LAYER(record, MACRO(TYPE(KC_X), END), _LOWER);	
		}
	case 6: {
			if(record->event.pressed) 
			return MACRO(I(10), T(0), T(C), T(TAB), T(TAB), T(A), T(TAB), END);
		}
	case 10: {
		if(record->event.pressed) {
		SEND_STRING(""); //send string
			return false; break;}
	}		
	case 11: {
		if(record->event.pressed) {
			SEND_STRING("ipconfig /all");
					return false; break;}
	}
	case 12: {
	if(record->event.pressed) 
		return MACRO( I(10),T(TAB), T(O), T(P), T(TAB),T(ENTER), T(TAB),T(TAB),T(TAB),T(Z),T(R),T(TAB),T(ENTER), END );
	}	
		case 13: {
	if(record->event.pressed) 
		return MACRO( I(10),T(TAB), T(O), T(T), T(TAB),T(ENTER), T(TAB),T(TAB),T(TAB),T(Z),T(R),T(TAB),T(ENTER), END );
	}	
		case 14: {
	if(record->event.pressed) 
		return MACRO( I(10),T(TAB), T(I), T(N), T(TAB),T(ENTER), T(TAB),T(TAB),T(TAB),T(I),T(N),T(TAB),T(ENTER), END );
	}	
		case 15: {
	if(record->event.pressed) 
		SEND_STRING("username"SS_TAP(X_TAB)"pass"SS_TAP(X_TAB)SS_TAP(X_ENTER));//allows sending password for things that do NOT need to be secure
		return false; break;
	}	
		break;
	}		
	return MACRO_NONE;
}
//return MACRO_NONE;


void cmd_commands(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
		action_macro_play(MACRO(D(LCTRL), T(C), U(LCTRL),END));
	}
	else if (state->count ==2){
		action_macro_play(MACRO(D(LCTRL), T(V), U(LCTRL),END));
	}
	else {
		action_macro_play(MACRO(D(LCTRL), T(A), T(C), U(LCTRL),END));
	}
}


void cmd(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count==1){
		action_macro_play(MACRO(D(LGUI), T(R),W(255), U(LGUI),W(255), T(C), T(M), T(D), T(ENTER),END));
	}
	else if (state->count == 2) {
		action_macro_play(MACRO(D(LGUI), T(R), U(LGUI), T(C), T(M), T(D), T(ENTER),W(255),W(255), T(I), T(P), T(C), T(O), T(N), T(F), T(I), T(G), T(SPACE), T(SLASH), T(A), T(L), T(L),T(ENTER),END));
	}
	else{
		action_macro_play(MACRO(D(LGUI), T(R),W(255), U(LGUI),W(255), T(C), T(M), T(D), T(ENTER), W(255), T(P), T(I), T(N), T(G),T(SPACE), D(LCTRL), T(V), U(LCTRL), END));
	}
}
void SLSH_BSLSH(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
		register_code (KC_SLSH);
		unregister_code (KC_SLSH);
	}
	else{
		register_code (KC_BSLS);
		unregister_code (KC_BSLS);
	}
}
void VirtualDesktop(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) 
		action_macro_play(MACRO(D(LGUI),D(LCTRL),T(LEFT),U(LCTRL),U(LGUI),END));
	else if(state->count==2)
		action_macro_play(MACRO(D(LGUI),D(LCTRL),T(RIGHT),U(LCTRL),U(LGUI),END));
}
	
qk_tap_dance_action_t tap_dance_actions[] = {
	
	//Tap once for Esc, twice for Caps Lock
	[TD_CPY_PST] = ACTION_TAP_DANCE_FN(cmd_commands),
	[TD_SLSH]= ACTION_TAP_DANCE_FN(SLSH_BSLSH),
	[TD_CMD]=ACTION_TAP_DANCE_FN(cmd),
	[TD_VRDSK]=ACTION_TAP_DANCE_FN(VirtualDesktop)
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
	
	
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    xprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
  return true;
}
/*bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	case COLEMAK:
	if (record->event.pressed) {
		#ifdef AUDIO_ENABLE
		PLAY_NOTE_ARRAY(tone_colemak, false, 0);
		#endif
		persistent_default_layer_set(1UL<<_COLEMAK);
	}
	return false;
	break;
	case QWERTY:
		if (record->event.pressed) {
			#ifdef AUDIO_ENABLE
			PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
			#endif
			persistent_default_layer_set(1UL<<_QWERTY);
		}
		return false;
		break;
	case DVORAK:
		if (record->event.pressed) {
			#ifdef AUDIO_ENABLE
			PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
			#endif
			persistent_default_layer_set(1UL<<_DVORAK);
		}
		return false;
		break;
	case LOWER:
		if (record->event.pressed) {
			layer_on(_LOWER);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		} else {
			layer_off(_LOWER);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		}
		return false;
		break;
	case RAISE:
		if (record->event.pressed) {
			layer_on(_RAISE);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		} else {
			layer_off(_RAISE);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		}
		return false;
		break;
	case ADJUST:
		if (record->event.pressed) {
			layer_on(_ADJUST);
		} else {
			layer_off(_ADJUST);
		}
		return false;
		break;
	}
	return true;
}*/
