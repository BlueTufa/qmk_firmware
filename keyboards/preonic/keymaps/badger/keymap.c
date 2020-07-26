#include QMK_KEYBOARD_H
#include "keycodes.h"
#include <print.h>

enum Layers {
  _QWERTY_MAC = 0,
  _MOVE_MAC,
  _QWERTY_LINUX,
  _MOVE_LINUX,
  _RAISE,
  _LOWER,
  _ADJUST
};

enum CustomKeys {
  KC_MAC1 = SAFE_RANGE,
  KC_MAC2,
  KC_LYRC,
  CS_RIGHT,
  CS_DOWN,
};

bool _capsLockState;
int _currentLayer;
const int _layerCount = 7;

#define P_ADJ LT(_ADJUST, KC_SPC)
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

void playSongForLayer(int currentLayer);

float capsOnSong[][2]                  = SONG(CAPS_ON);
float capsOffSong[][2]                 = SONG(CAPS_OFF);
float defaultLayerSong[][2]            = SONG(QWERTY_LAYER_SONG);
float moveLayerSong[][2]               = SONG(MOVE_LAYER_SONG);
float macLayerSong[][2]                = SONG(MAC_LAYER_SONG);
float raiseLayerSong[][2]              = SONG(RAISE_LAYER_SONG);
float lowerLayerSong[][2]              = SONG(LOWER_LAYER_SONG);
float agSwapSong[][2]                  = SONG(LONG_AG_SWAP);
float agNormSong[][2]                  = SONG(LONG_AG_NORM);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY_MAC]   = LAYOUT_preonic_2x2u(
      KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC, \
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS, \
      MOVE_MAC, KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT,  \
      KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, \
      KC_LCTL,  KC_LALT,  KC_LGUI,  RAISE,    P_ADJ,              KC_SPC,             LOWER,    KC_RGUI,  KC_RALT,  MAC_POP),

  [_MOVE_MAC]    = LAYOUT_preonic_2x2u(
      KC_ESC,   IJ_IMPL,  IJ_DECL,  IJ_REN,   IJ_USAG,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL,  \
      _______,  IJ_STEP,  IJ_INTO,  IJ_OUT,   IJ_RUN,   IJ_STOP,  KC_MPLY,  KC_PGUP,  KC_HOME,  KC_END,   KC_PGDN,  KC_INS,  \
      _______,  MM_LH,    MM_MAX,   MM_RH,    KC_MAC2,  KC_PSCR,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  CM_RIGHT, CM_DOWN, \
      _______,  MM_LLCN,  MM_BH,    MAC_CPY,  MAC_PST,  KC_MPRV,  KC_MNXT,  KC_MUTE,  IJ_BACK,  IJ_FWD,   KC_WSCH,  _______, \
      _______,  KC_LCTL,  KC_LALT,  KC_LGUI,  _______,            _______,            _______,  _______,  _______,  _______),

  [_QWERTY_LINUX]   = LAYOUT_preonic_2x2u(
      KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC, \
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS, \
      MOVE,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT,  \
      KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, \
      KC_LCTL,  KC_LGUI,  KC_LALT,  RAISE,    P_ADJ,              KC_SPC,             LOWER,    KC_RALT,  KC_RGUI,  OS_POP),

  [_MOVE_LINUX]    = LAYOUT_preonic_2x2u(
      KC_ESC,   VD_1,     VD_2,     VD_3,     KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL,  \
      _______,  WM_VD1,   WM_UH,    WM_VD2,   KC_MAC1,  KC_MSTP,  KC_MPLY,  KC_PGUP,  KC_HOME,  KC_END,   KC_PGDN,  KC_INS,  \
      _______,  WM_LH,    WM_MAX,   WM_RH,    KC_MAC2,  KC_PSCR,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  CS_RIGHT, CS_DOWN, \
      _______,  WM_VD3,   WM_BH,    OS_COPY,  OS_PAST,  KC_MPRV,  KC_MNXT,  KC_MUTE,  KC_WBAK,  KC_WFWD,  KC_WSCH,  _______, \
      _______,  KC_LCTL,  KC_LALT,  KC_LGUI,  _______,            _______,            _______,  _______,  _______,  _______),

  [_RAISE]    = LAYOUT_preonic_2x2u(
      KC_TILD,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL,  \
      _______,  KC_F11,   KC_F12,   KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE, \
      _______,  KC_AGIN,  KC_STOP,  KC_MENU,  KC_FIND,  KC_MPLY,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_COLN,  KC_DQUO, \
      _______,  KC_UNDO,  KC_CUT,   OS_COPY,  OS_PAST,  KC_MPRV,  KC_MNXT,  KC_MUTE,  KC_LT,    KC_GT,    KC_QUES,  KC_TRNS, \
      _______,  _______,  _______,  _______,  _______,            _______,            _______,  _______,  _______,  _______),

  [_LOWER]    = LAYOUT_preonic_2x2u(
      KC_GRV,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_INS,  \
      _______,  KC_7,     KC_8,     KC_9,     KC_PMNS,  KC_VOLD,  KC_VOLU,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS, \
      _______,  KC_4,     KC_5,     KC_6,     KC_PPLS,  KC_PSCR,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_SCLN,  KC_QUOT, \
      _______,  KC_1,     KC_2,     KC_3,     KC_PAST,  KC_NO,    KC_NO,    KC_WHOM,  KC_WBAK,  KC_WFWD,  KC_WSCH,  _______, \
      _______,  KC_0,     KC_DOT,   KC_ENT,   _______,            _______,            _______,  _______,  _______,  _______),

  [_ADJUST]   = LAYOUT_preonic_2x2u(
      KC_ESC,   AU_ON,    AU_OFF,   CK_TOGG,  CK_UP,    CK_DOWN,  CK_RST,   MU_ON,    MU_OFF,   MU_TOG,   MU_MOD,   KC_DEL,  \
      _______,  NK_ON,    NK_OFF,   EEP_RST,  RESET,    KC_MSTP,  KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  KC_BTN2,  KC_INS,  \
      _______,  GE_SWAP,  GE_NORM,  DEBUG,    AG_SWAP,  AG_NORM,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_BTN1,  _______, \
      _______,  KC_LYRC,  KC_NO,    KC_CAPS,  KC_NO,    KC_MPRV,  KC_MNXT,  KC_MUTE,  KC_ACL0,  KC_ACL1,  KC_ACL2,  _______, \
      _______,  _______,  _______,  _______,  _______,            _______,            _______,  _______,  _______,  _______)
};

void keyboard_post_init_user(void) {
  _capsLockState = false;
  _currentLayer = _QWERTY_MAC;
  layer_on(_currentLayer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  dprintf("Key event recorded. KEYCODE: %u , event: %u\n", keycode, record->event.pressed);
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
    case KC_CAPS:
      if (record->event.pressed) {
        dprintf("CAPS_LOCK state: %u\n", _capsLockState);
        _capsLockState = !_capsLockState;
        _capsLockState ? PLAY_SONG(capsOnSong) : PLAY_SONG(capsOffSong);
        return true;
      }
      break;
    case AG_SWAP:
      PLAY_SONG(agSwapSong);
      return true;
      break;
    case AG_NORM:
      PLAY_SONG(agNormSong);
      return true;
      break;
    case KC_MAC2:
      if (record->event.pressed) {
        SEND_STRING("ll\n");
        return false;
      }
      break;
    case KC_MAC1:
      if (record->event.pressed) {
        SEND_STRING("open https://www.reddit.com/r/mechanicalkeyboards\n");
        return false;
      }
      break;
    case KC_LYRC:
    if (record->event.pressed) {
      dprintf("LYR CYCLE pressed %u, CURRENT_LAYER: %u\n", keycode, _currentLayer);
      // don't turn off the QWERTY layer
      if (_currentLayer != _QWERTY_MAC) {
        layer_off(_currentLayer);
      }
      // don't lock the ADJUST layer
      // since this is accessible via the ADJUST
      // layer, that will require tricky state management
      if (++_currentLayer == _ADJUST) {
        _currentLayer = _QWERTY_MAC;
      }
      layer_on(_currentLayer);
      playSongForLayer(_currentLayer);
      return false;
    }
    break;
  }
  return true;
}

void playSongForLayer(int currentLayer) {
  switch (currentLayer) {
    case   _QWERTY_LINUX:
      PLAY_SONG(defaultLayerSong);
      break;
    case  _MOVE_LINUX:
      PLAY_SONG(moveLayerSong);
      break;
    case  _QWERTY_MAC:
      PLAY_SONG(macLayerSong);
      break;
    case  _MOVE_MAC:
      PLAY_SONG(moveLayerSong);
      break;
    case  _RAISE:
      PLAY_SONG(raiseLayerSong);
      break;
    case  _LOWER:
      PLAY_SONG(lowerLayerSong);
      break;
    default:
      break;
  }
}
