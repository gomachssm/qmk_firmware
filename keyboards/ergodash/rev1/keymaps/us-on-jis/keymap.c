#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define SDEMJ(x) if(is_pressed) {SEND_STRING("U:");SEND_STRING(x);SEND_STRING("  " SS_TAP(X_ENTER));clear_layer_flag(is_pressed);}

#define _____   KC_TRNS
#define xxx     KC_NO

#define _QWERTY 0
#define _SHIFT_ 1
#define _FNCRSR 2
#define _PNTNUM 3

enum custom_keycodes {
  LAYER_START_RSRV = SAFE_RANGE,
  SFT_PRSC,
  SFT_DEL,
  FNC_SPCE,
  FNS_ENTR,
  NUM_JPRO,
  NUM_MENU,
  LAYER_END_RSRV,
  M_KAO1,
  M_KAO2,
};

#define LYR_DF_IDX LAYER_START_RSRV + 1
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_GRV,    KC_1,    KC_2,       KC_3,     KC_4,    KC_5,    KC_RBRC,        KC_BSLS,   KC_6,    KC_7,    KC_8,     KC_9,      KC_0,       KC_MINS, \
    KC_TAB,    KC_Q,    KC_W,       KC_E,     KC_R,    KC_T,    KC_AT,          KC_UNDS,   KC_Y,    KC_U,    KC_I,     KC_O,      KC_P,       KC_JYEN, \
    KC_CAPS,   KC_A,    KC_S,       KC_D,     KC_F,    KC_G,    KC_DEL,         KC_BSPC,   KC_H,    KC_J,    KC_K,     KC_L,      KC_SCLN,    KC_AMPR, \
    KC_LSFT,   KC_Z,    KC_X,       KC_C,     KC_V,    KC_B,    S(KC_LBRC),     KC_RALT,   KC_N,    KC_M,    KC_COMM,  KC_DOT,    KC_UP,      KC_SLSH, \
    KC_INS,    KC_LGUI, KC_LALT,    NUM_JPRO, KC_LCTL, SFT_PRSC,FNC_SPCE,       FNS_ENTR,  SFT_DEL, KC_RCTL, NUM_MENU, KC_LEFT,   KC_DOWN,    KC_RGHT  \
  ),
  [_SHIFT_] = LAYOUT(
    S(KC_ESC), KC_EXLM, KC_LBRC,    KC_HASH,  KC_DLR,  KC_PERC, KC_RCBR,        KC_PIPE,   KC_EQL,  KC_CIRC, KC_DQUO, KC_ASTR,    KC_LPRN,    S(KC_RO),    \
    S(KC_TAB), S(KC_Q), S(KC_W),    S(KC_E),  S(KC_R), S(KC_T), S(KC_Y),        KC_COLN,   S(KC_Y), S(KC_U), S(KC_I), S(KC_O),    S(KC_P),    S(KC_JYEN),  \
    _____,     S(KC_A), S(KC_S),    S(KC_D),  S(KC_F), S(KC_G), _____,          _____,     S(KC_H), S(KC_J), S(KC_K), S(KC_L),    KC_QUOT,    KC_AT,       \
    _____,     S(KC_Z), S(KC_X),    S(KC_C),  S(KC_V), S(KC_B), S(KC_EQL),      _____,     S(KC_N), S(KC_M), KC_LT,   KC_GT,      S(KC_UP),   KC_QUES,     \
    _____,     _____,   S(KC_LALT), S(KC_RO), _____,   _____,   S(KC_SPC),      S(KC_ENT), _____,   _____,   KC_APP,  S(KC_LEFT), S(KC_DOWN), S(KC_RGHT)   \
  ),
  [_FNCRSR] = LAYOUT(
    KC_ESC,    KC_F1,   KC_F2,      KC_F3,    KC_F4,   KC_F5,   KC_F12,         KC_F5,     KC_F6,   KC_F7,   KC_F8,    KC_F9,      KC_F10,     KC_F11, \
    _____,     _____,   _____,      KC_UP,    _____,   _____,   _____,          _____,     _____,   _____,   KC_UP,    _____,      _____,      _____,  \
    _____,     _____,   KC_LEFT,    KC_DOWN,  KC_RGHT, _____,   _____,          _____,     _____,   KC_LEFT, KC_DOWN,  KC_RGHT,    _____,      _____,  \
    _____,     _____,   _____,      _____,    _____,   _____,   _____,          _____,     _____,   _____,   _____,    _____,      KC_PGUP,    _____,  \
    _____,     _____,   _____,      KC_RO,    _____,   _____,   KC_SPC,         KC_ENT,    _____,   _____,   KC_APP,   KC_HOME,    KC_PGDN,    KC_END  \
  ),
  [_PNTNUM] = LAYOUT(
    xxx,       xxx,     KC_WH_L,    xxx,      KC_WH_R, xxx,     RESET,          RESET,     M_KAO1,  xxx,     xxx,      KC_PSLS,    KC_PAST,    KC_PMNS,  \
    xxx,       xxx,     KC_BTN1,    KC_MS_U,  KC_BTN2, KC_WH_U, KC_MHEN,        KC_HENK,   M_KAO2,  xxx,     KC_7,     KC_8,       KC_9,       KC_PPLS,  \
    xxx,       xxx,     KC_MS_L,    KC_MS_D,  KC_MS_R, KC_WH_D, xxx,            xxx,       xxx,     xxx,     KC_4,     KC_5,       KC_6,       KC_PCMM,  \
    xxx,       xxx,     xxx,        xxx,      xxx,     xxx,     xxx,            _____,     xxx,     xxx,     KC_1,     KC_2,       KC_3,       KC_PEQL,  \
    xxx,       xxx,     _____,      _____,    _____,   KC_LSFT, KC_SPC,         KC_ENT,    KC_RSFT, _____,   _____,    KC_0,       KC_DOT,     KC_PENT   \
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void tap_key(uint8_t keycode) {
  register_code(keycode);
  unregister_code(keycode);
}

typedef struct _lt_tap_hold {
    bool    pressing;   // key status flag, default value must be false
    uint8_t tapcode;    // key to send when single tapped 
    int     layer_idx;  // layer to change when key held
} lt_tap_hold;

static lt_tap_hold lth[LAYER_END_RSRV - LYR_DF_IDX] = {
  [SFT_PRSC - LYR_DF_IDX] = { false, KC_PSCR, _SHIFT_ },
  [SFT_DEL  - LYR_DF_IDX] = { false, KC_DEL,  _SHIFT_ },
  [FNC_SPCE - LYR_DF_IDX] = { false, KC_SPC,  _FNCRSR },
  [FNS_ENTR - LYR_DF_IDX] = { false, KC_ENT,  _FNCRSR },
  [NUM_JPRO - LYR_DF_IDX] = { false, KC_RO,   _PNTNUM },
  [NUM_MENU - LYR_DF_IDX] = { false, KC_APP,  _PNTNUM }
};

void clear_layer_flag(bool is_pressed) {
  if (is_pressed) {
    uint16_t layer_idxs[] = {
      SFT_PRSC,
      SFT_DEL,
      FNC_SPCE,
      FNS_ENTR,
      NUM_JPRO,
      NUM_MENU
    };
    int size = 6;
    for (int i = 0; i < size; i++) {
      lth[ layer_idxs[i] - LYR_DF_IDX ].pressing = false;
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool is_pressed = record->event.pressed;
  uint16_t kc_idx = keycode - LYR_DF_IDX;
  bool is_continue = false;
  switch(keycode) {
    // when single tap or key to change layer is pressed
    case SFT_PRSC:
    case SFT_DEL:
    case FNC_SPCE:
    case FNS_ENTR:
    case NUM_JPRO:
    case NUM_MENU:
      if (is_pressed) {
        lth[kc_idx].pressing = true;
        layer_on(lth[kc_idx].layer_idx);
      } else {
        layer_off(lth[kc_idx].layer_idx);
        if (lth[kc_idx].pressing) {
            tap_key(lth[kc_idx].tapcode);
        }
        lth[kc_idx].pressing = false;
      }
      break;
    // when held _PNTNUM and pressed key is M_KAOn, send kaomoji by unicode
    case M_KAO1: // 🤔 1F914
      SDEMJ("1F914");
      break;
    case M_KAO2: // ⌨ 2328
      SDEMJ("2328");
      break;
    // when pressed other key, send code by kaymap
    default:
      clear_layer_flag(is_pressed);
      is_continue = true;
  }
  return is_continue;
}