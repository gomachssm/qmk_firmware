#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define L1_PRSC LT(1, KC_PSCR)
#define L1_DEL  LT(1, KC_DEL)
#define L2_SPC  LT(2, KC_SPC)
#define L2_ENT  LT(2, KC_ENT)
#define L3_RO   LT(3, KC_RO)
#define L3_APP  LT(3, KC_APP)

#define _____   KC_TRNS
#define xxx     KC_NO

#define AT_SQT  ALT_T()

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,    KC_RBRC,    /**/KC_BSLS, KC_6,   KC_7,    KC_8,     KC_9,    KC_0,    KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,    KC_Y,       /**/KC_UNDS, KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,    KC_JYEN,
    KC_CAPS, KC_A,    KC_S,    KC_D,     KC_F,    KC_G,    KC_DEL,     /**/KC_BSPC, KC_H,   KC_J,    KC_K,     KC_L,    KC_SCLN, KC_AMPR,
    KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    S(KC_LBRC), /**/KC_RALT, KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_UP,   KC_SLSH,
    KC_INS,  KC_LGUI, KC_LALT, L3_RO,    KC_LCTL, L1_PRSC, L2_SPC,     /**/L2_ENT,  L1_DEL, KC_RCTL, L3_APP,   KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [1] = LAYOUT(
    KC_ESC,  KC_EXLM, KC_LBRC, KC_HASH,  KC_DLR,  KC_PERC, KC_RCBR,    /**/KC_PIPE, KC_EQL,  KC_CIRC, KC_DQUO, KC_ASTR, KC_LPRN, S(KC_RO),
    _____,   S(KC_Q), S(KC_W), S(KC_E),  S(KC_R), S(KC_T), S(KC_Y),    /**/KC_COLN, S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), S(KC_JYEN),
    _____,   S(KC_A), S(KC_S), S(KC_D),  S(KC_F), S(KC_G), _____,      /**/_____,   S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_QUOT, KC_AT,
    _____,   S(KC_Z), S(KC_X), S(KC_C),  S(KC_V), S(KC_B), S(KC_EQL),  /**/_____,   S(KC_N), S(KC_M), KC_LT,   KC_GT,   _____,   KC_QUES,
    _____,   _____,   _____,   S(KC_RO), _____,   _____,   KC_SPC,     /**/KC_ENT,  _____,   _____,   KC_APP,  _____,   _____,   _____
  ),
  [2] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F12,     /**/KC_F5,   KC_F6,  KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,
    _____,   _____,   _____,   KC_UP,    _____,   _____,   _____,      /**/_____,   _____,  _____,   KC_UP,    _____,   _____,   _____,
    _____,   _____,   KC_LEFT, KC_DOWN,  KC_RGHT, _____,   _____,      /**/_____,   _____,  KC_LEFT, KC_DOWN,  KC_RGHT, _____,   _____,
    _____,   _____,   _____,   _____,    _____,   _____,   _____,      /**/_____,   _____,  _____,   _____,    _____,   KC_PGUP, _____,
    _____,   _____,   _____,   KC_RO,    _____,   _____,   _____,      /**/_____,   _____,  _____,   KC_APP,   KC_HOME, KC_PGDN, KC_END
  ),
  [3] = LAYOUT(
    xxx,     xxx,     KC_WH_L, xxx,      KC_WH_R, xxx,     xxx,        /**/xxx,     xxx,    xxx,     xxx,      KC_PSLS, KC_PAST, KC_PMNS,
    xxx,     xxx,     KC_BTN1, KC_MS_U,  KC_BTN2, KC_WH_U, xxx,        /**/xxx,     xxx,    xxx,     KC_7,     KC_8,    KC_9,    KC_PPLS,
    xxx,     xxx,     KC_MS_L, KC_MS_D,  KC_MS_R, KC_WH_D, xxx,        /**/xxx,     xxx,    xxx,     KC_4,     KC_5,    KC_6,    KC_PCMM,
    xxx,     xxx,     xxx,     xxx,      xxx,     xxx,     xxx,        /**/_____,   xxx,    xxx,     KC_1,     KC_2,    KC_3,    KC_PEQL,
    xxx,     xxx,     _____,   _____,    _____,   _____,   KC_SPC,     /**/KC_ENT,  _____,  _____,   _____,    KC_0,    KC_PDOT, KC_PENT
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // switch(keycode) {
    //   case any_macroname:
    //     SEND_STRING(SS_LSFT("@"));
    //     return false;
    // }
  }
  return true;
}
