#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SHFT 1 // Shift +
#define SYMB 2 // symbols
#define MDIA 3 // media

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * ,--------------------------------------------------.    ,--------------------------------------------------.
 * |  =   + |  1 ! |  2 @ |  3 # |  4 $ |  5 % | Swap |    | Swap |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |  - _   |
 * |--------+------+------+------+------+-------------|    |------+------+------+------+------+------+--------|
 * |  $   @ |   Q  |   W  |   F  |   P  |   G  |  L1  |    |  L1  |   J  |   L  |   U  |   Y  |  ; : |  \ |   |
 * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
 * |  *   # |   A  |   R  |   S  |   T  |   D  |------|    |------|   H  |   N  |   E  |   I  |   O  |  ' "   |
 * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
 * | LShift |CT_T Z|   X  |   C  |   V  |   B  |  L2  |    |  L2  |   K  |   M  |  , <  | . > |  / ? | RShift |
 * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
 *   |LCtrl |  ' " |  ` ~ | Left | Right|,-------------.  ,-------------.|  Up  | Down |  [ { |  ] } | RCtrl|
 *   `----------------------------------'|Ctl Ap| Home |  |LWin |Sft Esc|`----------------------------------'
 *                                ,------|------|------|  |-----+-------+------.       
 *                                |      |      | End  |  |PgUp |       |Alt   |       
 *                                |Space |Backsp|------|  |-----|  Tab  |      |
 *                                |      |ace   | Del  |  |PgDn |       |Enter |
 *                                `--------------------'  `--------------------'                                
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,          KC_1,         KC_2,          KC_3,    KC_4, KC_5,    SH_TT,
        KC_DLR,         KC_Q,         KC_W,          KC_F,    KC_P, KC_G,    TG(SHFT),
        KC_ASTR,          KC_A,         KC_R,          KC_S,    KC_T, KC_D,
        OSM(MOD_LSFT), CTL_T(KC_Z),  KC_X,          KC_C,    KC_V, KC_B,    TG(SYMB),
        OSM(MOD_LCTL), KC_QUOT,      KC_GRV, KC_LEFT, KC_RGHT,
                                                               CTL_T(KC_APP), KC_HOME,
                                                                              KC_END,
                                                      KC_SPC,  KC_BSPC,       KC_DELT,
        // right hand
             SH_TT,KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS,
             TG(SHFT),    KC_J,   KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
                          KC_H,   KC_N,   KC_E,    KC_I,    KC_O,    KC_QUOT,
             TG(SYMB),    KC_K,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_RSFT),
                                  KC_UP,  KC_DOWN, KC_LBRC, KC_RBRC, OSM(MOD_RCTL),
             KC_LWIN,     SFT_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,     KC_TAB, ALT_T(KC_ENT)
    ),
[SHFT] = LAYOUT_ergodox(  // layer 2 : shift + base layer
        // left hand
        KC_PLUS, KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_TRNS,
        KC_AT, LSFT(KC_Q), LSFT(KC_W), LSFT(KC_F), LSFT(KC_P), LSFT(KC_G), KC_TRNS,
        KC_HASH,   LSFT(KC_A), LSFT(KC_R), LSFT(KC_S), LSFT(KC_T), LSFT(KC_D),
        KC_TRNS, LSFT(KC_Z), LSFT(KC_X), LSFT(KC_C), LSFT(KC_V), LSFT(KC_B), KC_TRNS,
        KC_TRNS, KC_TRNS,    KC_TILD,    KC_TRNS,    KC_TRNS,
                                                                 KC_TRNS,    KC_TRNS,
                                                                             KC_TRNS,
                                                     KC_TRNS,    KC_TRNS,    KC_TRNS,
        // right hand
             KC_TRNS,  KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_UNDS,
             KC_TRNS,  LSFT(KC_J), LSFT(KC_L), LSFT(KC_U), LSFT(KC_Y), KC_COLN,    KC_PIPE,
                       LSFT(KC_H), LSFT(KC_N), LSFT(KC_E), LSFT(KC_I), LSFT(KC_O), KC_DQUO,
             KC_TRNS,  LSFT(KC_K), LSFT(KC_M), KC_LABK,    KC_RABK,    KC_QUES,    KC_TRNS,
                                   KC_TRNS,    KC_TRNS,    KC_LCBR,    KC_RCBR,    KC_TRNS,
             KC_TRNS,  KC_TRNS,
             KC_TRNS,
             KC_TRNS,  KC_TRNS,    KC_TRNS
    ),
/* Keymap 2: Symbol Layer
* ,--------------------------------------------------.    ,--------------------------------------------------.
* |    +   |  F1  |  F2  |  F3  |  F4  |  F5  |      |    |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
* |--------+------+------+------+------+-------------|    |------+------+------+------+------+------+--------|
* |    &   |   *  |   |  |   {  |   }  | MsLt |      |    |      | MsUp |   7  |   8  |   9  |   *  |   F12  |
* |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
* |    $   |   %  |   ^  |   (  |   )  | MsRt |------|    |------| MsDn |   4  |   5  |   6  |   +  |   -    |
* |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
* |    !   |   @  |   #  |   [  |   ]  | MsLc |      |    |      |   .  |   1  |   2  |   3  |   /  |   ?    |
* `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
*  |   =   |   <  |   >  |      |      |,-------------.  ,-------------.|      |      |   0  |   =  |   \   |
*  `-----------------------------------'|Ctr+X |  L3  |  |  L3  |Ctr+S |`-----------------------------------'
*                                ,------|------|------|  |------+------+------.
*                                |      |      |Ctr+C |  |Ctr+Y |      |      |
*                                |      |      |------|  |------|      |      |
*                                |      |      |Ctr+V |  |Ctr+Z |      |      |
*                                `--------------------'  `--------------------'
*/
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_PPLS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_AMPR,KC_ASTR,KC_PIPE,  KC_LCBR,KC_RCBR,KC_MS_L,KC_TRNS,
       KC_DLR,KC_PERC,KC_CIRC, KC_LPRN,KC_RPRN,KC_MS_R,
       KC_EXLM,KC_AT,KC_HASH,KC_LBRC,KC_RBRC,KC_BTN1,KC_TRNS,
       KC_PEQL,KC_LABK,KC_RABK,KC_TRNS,KC_TRNS,
                                       LCTL(KC_X),TG(MDIA),
                                               LCTL(KC_V),
                               KC_TRNS,KC_TRNS,LCTL(KC_C),
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_MS_U,   KC_7,   KC_8,    KC_9,    KC_PAST, KC_F12,
                KC_MS_D, KC_4,   KC_5,    KC_6,    KC_PPLS, KC_PMNS,
       KC_TRNS, KC_DOT,  KC_1,   KC_2,    KC_3,    KC_PSLS, KC_QUES,
                         KC_TRNS,KC_TRNS, KC_0,    KC_PEQL,  KC_BSLS,
       TG(MDIA), LCTL(KC_S),
       LCTL(KC_Y),
       LCTL(KC_Z), KC_TRNS, KC_TRNS
),
 /*  Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.    ,--------------------------------------------------.
 * | RGB_HUI|      |      |      |      |      |      |    |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|    |------+------+------+------+------+------+--------|
 * | RGB_HUD|      |      | MsUp |      |      |      |    |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
 * | RGB_SAI|      |MsLeft|MsDown|MsRght|      |------|    |------|      |      |      |      |      | RGB_VAI|
 * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
 * | RGB_SAD|      |      |      |      |      |      |    |      |      |      | Prev | Next |      | RGB_VAD|
 * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
 *  |RGB_TOG|      |      | Lclk | Rclk |,-------------.  ,-------------.|VolUp |VolDn | Mute |      |RGB_MOD|
 *  `-----------------------------------'|      |      |  |      |      |`-----------------------------------'
 *                                ,------|------|------|  |------+------+------.
 *                                |      |      |      |  |      |      |      |
 *                                |      |      |      |  |      |      |      |
 *                                `--------------------'  `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       RGB_HUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       RGB_HUD, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       RGB_SAI, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       RGB_SAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       RGB_TOG, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAI,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, RGB_VAD,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, RGB_MOD,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
)
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
	
	if(layer & SYMB)
	{
		ergodox_right_led_1_on();		
	}
	if(layer & SHFT)
	{
		ergodox_right_led_2_on();
	}	
	if(layer & MDIA)
	{
		ergodox_right_led_3_on();
	}
};
