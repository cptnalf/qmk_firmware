#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_numpad_6x4( /* Base */
 MO(1)   ,MO(2)   ,KC_RCTL ,TG(3) \
,KC_NLCK ,KC_PSLS ,KC_PAST ,KC_PMNS \
,KC_P7   ,KC_P8   ,KC_P9   ,KC_PPLS \
,KC_P4   ,KC_P5   ,KC_P6 \
,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT \
,KC_P0   ,KC_PDOT
	      ),

[1] = LAYOUT_numpad_6x4( /* m2 */
 KC_TRNS ,KC_TRNS ,MO(3)   ,KC_HOME \
,KC_F10  ,KC_F11  ,KC_F12  ,KC_END \
,KC_F7   ,KC_F8   ,KC_F9   ,KC_SPC \
,KC_F4   ,KC_F5   ,KC_F6 \
,KC_F1   ,KC_F2   ,KC_F3   ,KC_PENT \
,KC_RCTL          ,KC_PAUS
	      ),

[2] = LAYOUT_numpad_6x4( /* 15% */
 KC_TRNS  ,KC_TRNS  ,RGB_M_X ,RGB_M_G \
,RESET    ,RGB_TOG  ,KC_TRNS ,RGB_RMOD \
,RGB_HUI  ,RGB_SAI  ,RGB_VAI ,RGB_MOD \
,RGB_HUD  ,RGB_SAD  ,RGB_VAD \
,RGB_M_P  ,RGB_M_B  ,RGB_M_R ,RGB_M_K \
,RGB_M_SW ,RGB_M_SN
	      ),

[3] = LAYOUT_numpad_6x4( /* dota2 keys */
 KC_T    ,KC_G  ,KC_N  ,KC_TRNS \
,KC_R    ,KC_F  ,KC_B  ,KC_1 \
,KC_E    ,KC_D  ,KC_V  ,KC_LSFT \
,KC_W    ,KC_S  ,KC_C \
,KC_Q    ,KC_A  ,KC_X  ,KC_LCTL \
,KC_LALT        ,KC_Z

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

void led_set_user(uint8_t usb_led) {

}
