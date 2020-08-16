#include QMK_KEYBOARD_H
#include "keycodes.h"

enum layers {
  _QWERTY_MAC,
  _MOVE_MAC,
  _QWERTY_LINUX,
  _MOVE_LINUX,
  _ADJUST
};

enum CustomKeys {
  CS_RIGHT = SAFE_RANGE,
  CS_DOWN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY_MAC] = LAYOUT_60_ansi(\
     KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,   KC_BSPC, \
     KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC,  KC_BSLS, \
     MOVE_MAC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,   KC_ENT,   \
     KC_LSFT,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,   \
     KC_LCTL,    KC_LALT,  KC_LGUI,  KC_SPC,   ADJUST,   KC_RGUI,  KC_LALT,  KC_RCTL),

  [_MOVE_MAC]   = LAYOUT_60_ansi(\
     MAC_FRC,    MM_LEFT,  MM_RGHT,  KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   IJ_UP,     IJ_DOWN,  KC_DEL, \
     KC_BACK,    IJ_STEP,  IJ_INTO,  IJ_OUT,   IJ_RUN,   IJ_STOP,  _______,  WD_BACK,  KC_HOME,  KC_END,   WD_FRWD,  IJ_BACK,   IJ_FWD,   KC_NEXT, \
     _______,    MM_LH,    MM_MAX,   MM_RH,    MAC_POP,  IJ_IMPS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  CM_RIGHT, CM_DOWN,   _______,  \
     _______,    MM_UH,    MM_BH,    MAC_CPY,  MAC_PST,  IJ_IMPH,  _______,  IJ_REN,   IJ_IMPL,  IJ_DECL,  IJ_USAG,  _______,   \
     _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______),
     
  [_QWERTY_LINUX] = LAYOUT_60_ansi(\
     KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,   KC_BSPC, \
     KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC,  KC_BSLS, \
     MOVE,       KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,   KC_ENT,   \
     KC_LSFT,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,   \
     KC_LCTL,    KC_LGUI,  KC_LALT,  KC_SPC,   ADJUST,   KC_LALT,  KC_RGUI,  KC_RCTL),

  [_MOVE_LINUX] = LAYOUT_60_ansi(\
     KC_GRV,     VD_1,     VD_2,     VD_3,     KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,   KC_DEL, \
     _______,    WM_VD1,   WM_UH,    WM_VD2,   RESET,    KC_MSTP,  KC_MPLY,  KC_PGUP,  KC_HOME,  KC_END,   KC_PGDN,  _______,   _______,  KC_INS, \
     _______,    WM_LH,    WM_MAX,   WM_RH,    WD_FRWD,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  CS_RIGHT, CS_DOWN,   _______, \
     _______,    WM_VD3,   WM_BH,    OS_COPY,  OS_PAST,  WD_BACK,  KC_MNXT,  KC_MUTE,  KC_WBAK,  KC_WFWD,  _______,  _______,   \
     _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______),

  [_ADJUST]     = LAYOUT_60_ansi(\
     KC_ESC,    KC_F1,    KC_F2,    KC_F3,    KC_F4,     KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,   KC_DEL, \
     _______,   NK_ON,    NK_OFF,   EEP_RST,  RESET,     KC_MSTP,  KC_MPLY,  KC_PGUP,  KC_HOME,  KC_END,   KC_PGDN,  RGB_M_B,   RGB_M_R,  KC_INS, \
     _______,   GE_SWAP,  GE_NORM,  DEBUG,    AG_SWAP,   AG_NORM,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  RGB_MOD,  RGB_TOG,   _______,  \
     _______,   DF_1,     DF_2,     KC_CAPS,  RGB_M_SW,  KC_MPRV,  KC_MNXT,  KC_MUTE,  RGB_SAI,  RGB_HUI,  RGB_VAI,  _______,   \
     _______,   _______,  _______,  _______,  _______,   _______,  _______,  _______)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CS_RIGHT:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_B)SS_TAP(X_ENTER)));
        return false;
      }
      break;
    case CS_DOWN:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_V)SS_TAP(X_ENTER)));
        return false;
      }
      break;
    default:
      return true;
  }
  return true;
}
