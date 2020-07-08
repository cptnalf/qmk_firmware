#include QMK_KEYBOARD_H

#include "rgblight.h"

const rgblight_segment_t PROGMEM numloc_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {4, 1, HSV_BLUE }
);

const rgblight_segment_t PROGMEM dota2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {3, 1, HSV_RED },
  {14, 1, HSV_RED },
  {18, 1, HSV_RED },
  {20, 1, HSV_RED }
);

const rgblight_segment_t* const PROGMEM cptnalf_rgblayers[] = RGBLIGHT_LAYERS_LIST(
  numloc_layer,
  dota2_layer
);

#define _BASE 0
#define _FX   1
#define _KBFX 2
#define _DOTA2 3
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* number pad
 * ---------------------------
 * |MO(1)|MO(2)| ctrl| tg(3) |
 * ---------------------------
 * | NUM |  /  |  *  |  -    |
 * ---------------------------
 * |  7  |  8  |  9  |  +    |
 * -------------------       |
 * |  3  |  4  |  6  |       |
 * ---------------------------
 * |  1  |  2  |  3  | enter |
 * -------------------       |
 * |  0        |  x  |       |
 * ---------------------------
 */
[_BASE] = LAYOUT_numpad_6x4( /* Base */
 MO(_FX) ,MO(_KBFX),KC_RCTL ,TG(_DOTA2) \
,KC_NLCK ,KC_PSLS ,KC_PAST ,KC_PMNS \
,KC_P7   ,KC_P8   ,KC_P9 \
,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS \
,KC_P1   ,KC_P2   ,KC_P3   \
,KC_P0            ,KC_PDOT ,KC_PENT 
),

/* 
 * ---------------------------
 * |     |     |MO(3)| Home  |
 * ---------------------------
 * | f10 | f11 | f12 |  end  |
 * ---------------------------
 * |  f7 |  f8 |  f9 | space |
 * -------------------       |
 * |  f4 |  f5 |  f6 |       |
 * ---------------------------
 * |  f1 |  f2 |  f3 | enter |
 * -------------------       |
 * |  ctrl     | paus|       |
 * ---------------------------
 */
[_FX] = LAYOUT_numpad_6x4( /* m2 */
 KC_TRNS ,KC_TRNS ,MO(_DOTA2)   ,KC_HOME \
,KC_F10  ,KC_F11  ,KC_F12  ,KC_END \
,KC_F7   ,KC_F8   ,KC_F9   \
,KC_F4   ,KC_F5   ,KC_F6   ,KC_SPC \
,KC_F1   ,KC_F2   ,KC_F3   \
,KC_RCTL          ,KC_PAUS ,KC_PENT
	      ),

/* rgb functions
 * ---------------------------
 * |     |     |rgbmx| rgb mg|
 * ---------------------------
 * | RST |rgbtg|     |  rmod |
 * ---------------------------
 * | hui | sai | vai | mod   |
 * -------------------  RGB  |
 * | hud | sad | vad |       |
 * ---------------------------
 * | m_p | m_b | m_r |  rgb  |
 * -------------------  m k  |
 * | rgb m_sw  | m_sn|       |
 * ---------------------------
 */
[_KBFX] = LAYOUT_numpad_6x4( /* 15% */
 KC_TRNS  ,KC_TRNS  ,RGB_M_X ,RGB_M_G \
,RESET    ,RGB_TOG  ,KC_TRNS ,RGB_RMOD \
,RGB_HUI  ,RGB_SAI  ,RGB_VAI \
,RGB_HUD  ,RGB_SAD  ,RGB_VAD ,RGB_MOD \
,RGB_M_P  ,RGB_M_B  ,RGB_M_R \
,RGB_M_SW           ,RGB_M_SN ,RGB_M_K 
	      ),

/* dota-2 macro-pad-ish.
 * ---------------------------
 * |  T  |  G  |  N  | tg(3) |
 * ---------------------------
 * |  R  |  F  |  B  |  1    |
 * ---------------------------
 * |  E  | D   |  V  | shift |
 * -------------------       |
 * |  W  |  S  |  C  |       |
 * ---------------------------
 * |  Q  |  A  |  X  |  Ctrl |
 * -------------------       |
 * |  Alt      |  Z  |       |
 * ---------------------------
 */
[_DOTA2] = LAYOUT_numpad_6x4( /* dota2 keys */
 KC_T    ,KC_G  ,KC_N  ,KC_TRNS \
,KC_R    ,KC_F  ,KC_B  ,KC_1 \
,KC_E    ,KC_D  ,KC_V  \
,KC_W    ,KC_S  ,KC_C  ,KC_LSFT \
,KC_Q    ,KC_A  ,KC_X  \
,KC_LALT        ,KC_Z  ,KC_LCTL 
),
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {
    // This keymap only has a single base layer, so reset the default if needed
    if(eeconfig_read_default_layer() > 1){
        eeconfig_update_default_layer(1);
        default_layer_set(1);
    }
}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(1, layer_state_cmp(state, _DOTA2));
  return state;
}

bool led_update_user(led_t led_state) {
  rgblight_set_layer_state(0, led_state.num_lock);
  return true;
}

void keyboard_post_init_user(void) {
  rgblight_layers = cptnalf_rgblayers;
}