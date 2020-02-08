#include QMK_KEYBOARD_H
#include "keycodes.h"

enum layers {
  _QWERTY,
  _ADJUST,
  _MOVE
};

#define ESC_MOVE LT(_MOVE,KC_ESC)
#define MC_ADJST MO(_ADJUST)

/* MacOS virtual desktop shortcuts */
#define VD_1 LCTL(KC_1)
#define VD_2 LCTL(KC_2)
#define VD_3 LCTL(KC_3)
#define VD_4 LCTL(KC_4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY]   = LAYOUT_66_ansi(\
      KC_GRV,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,  KC_PGUP, \
      KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC,  KC_BSLS,  KC_PGDN, \
      MOVE,      KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,   KC_ENT, \
      KC_LSFT,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,   KC_UP,  \
      KC_LCTL,   KC_LALT,  KC_LGUI,  KC_SPC,   ADJUST,   KC_RGUI,  KC_LALT,  KC_LEFT,  KC_DOWN,  KC_RGHT),

  [_ADJUST]   = LAYOUT_66_ansi(\
      KC_ESC,    KC_F1,    KC_F2,    KC_F3,    KC_F4,     KC_F5,   KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,   KC_DEL,   KC_VOLU, \
      _______,   NK_ON,    NK_OFF,   EEP_RST,  RESET,     KC_MSTP, KC_MPLY,  KC_PGUP,  KC_HOME,  KC_END,   KC_PGDN,  AG_SWAP,   AG_NORM,  KC_INS,   KC_VOLD, \
      _______,   GE_SWAP,  GE_NORM,  DEBUG,    AG_SWAP,   AG_NORM, KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,   _______, \
      _______,   _______,  _______,  KC_CAPS,  _______,   KC_MPRV, KC_MNXT,  KC_MUTE,  KC_WBAK,  KC_WFWD,  _______,  _______,   KC_BRIU, \
      _______,   _______,  _______,  _______,  _______,   _______, _______,  KC_HOME,  KC_BRID,  KC_END),

  [_MOVE]    = LAYOUT_66_ansi(\
     KC_GRV,     VD_1,     VD_2,     VD_3,     KC_F4,     KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,   KC_DEL,   KC_VOLU, \
     _______,    MM_ULCN,  MM_UH,    MM_URCN,  RESET,    KC_MSTP,  KC_MPLY,  KC_PGUP,  KC_HOME,  KC_END,   KC_PGDN,  AG_SWAP,   AG_NORM,  KC_INS,   KC_VOLD, \
     _______,    MM_LH,    MM_MAX,   MM_RH,    WM_LRCN,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,   _______, \
     _______,    MM_LLCN,  MM_BH,    MM_LRCN,  _______,  KC_MPRV,  KC_MNXT,  KC_MUTE,  IJ_BACK,  IJ_FWD,   _______,  _______,   KC_BRIU, \
     _______,    _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_BRID,  KC_END)
};
