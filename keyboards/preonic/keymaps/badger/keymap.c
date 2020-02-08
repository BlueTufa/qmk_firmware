#include QMK_KEYBOARD_H
#include "keycodes.h"

enum layers {
  _QWERTY,
  _MOVE,
  _QWERTY_MAC,
  _MOVE_MAC,
  _RAISE,
  _LOWER,
  _ADJUST
};

enum custom_keys {
  KC_MAC1 = SAFE_RANGE,
  KC_MAC2,
  KC_LYRT,
};

int _currentLayer = _QWERTY;
const int _layerCount = 7;

#define P_ADJ LT(_ADJUST, KC_SPC)
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define MAC_LAYER_SOUND Q__NOTE(_E5), Q__NOTE(_A5), Q__NOTE(_D6), Q__NOTE(_G6), ED_NOTE(_E7), E__NOTE(_CS7), E__NOTE(_E6), E__NOTE(_A6), M__NOTE(_CS7, 20),
#define LONG_AG_SWAP Q__NOTE(_G5), Q__NOTE(_D6), Q__NOTE(_A6), Q__NOTE(_E7), SD_NOTE(_B5), SD_NOTE(_A5), SD_NOTE(_B5), SD_NOTE(_A5),

void playSongForLayer(int currentLayer);

float capsToggleSong[][2]              = SONG(CAPS_LOCK_ON_SOUND);
float defaultLayerSong[][2]            = SONG(QWERTY_SOUND);
float macLayerSong[][2]                = SONG(MAC_LAYER_SOUND);
float moveLayerSong[][2]               = SONG(WORKMAN_SOUND);
float raiseLayerSong[][2]              = SONG(FANTASIE_IMPROMPTU);
float lowerLayerSong[][2]              = SONG(NOCTURNE_OP_9_NO_1);
float adjustLayerSong[][2]             = SONG(CAMPANELLA);
float agSwapSong[][2]                  = SONG(LONG_AG_SWAP);
float agNormSong[][2]                  = SONG(AG_NORM_SOUND);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY]   = LAYOUT_preonic_2x2u(
      KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC, \
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS, \
      MOVE,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT,  \
      KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, \
      KC_LCTL,  KC_LGUI,  KC_LALT,  RAISE,    P_ADJ,              KC_SPC,             LOWER,    KC_RALT,  KC_RGUI,  KC_LYRT),

  [_MOVE]    = LAYOUT_preonic_2x2u(
      KC_GRV,   VD_1,     VD_2,     VD_3,     KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL,  \
      _______,  WM_VD1,   WM_UH,    WM_VD2,   KC_MAC1,  KC_MSTP,  KC_MPLY,  KC_PGUP,  KC_HOME,  KC_END,   KC_PGDN,  KC_INS,  \
      _______,  WM_LH,    WM_MAX,   WM_RH,    KC_MAC2,  KC_PSCR,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_SCLN,  KC_QUOT, \
      _______,  WM_VD3,   WM_BH,    OS_COPY,  OS_PAST,  KC_MPRV,  KC_MNXT,  KC_MUTE,  KC_WBAK,  KC_WFWD,  KC_WSCH,  _______, \
      _______,  KC_LCTL,  KC_LALT,  KC_LGUI,  _______,            _______,            _______,  _______,  _______,  KC_LYRT),

  [_QWERTY_MAC]   = LAYOUT_preonic_2x2u(
      KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC, \
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS, \
      MOVE_MAC, KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT,  \
      KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, \
      KC_LCTL,  KC_LALT,  KC_LGUI,  RAISE,    ADJUST,             KC_SPC,             LOWER,    KC_RGUI,  KC_RALT,  KC_LYRT),

  [_MOVE_MAC]    = LAYOUT_preonic_2x2u(
      KC_GRV,   M_VD1,    M_VD2,    M_VD3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL,  \
      _______,  MM_ULCN,  MM_UH,    MM_URCN,  KC_MAC1,  KC_MSTP,  KC_MPLY,  KC_PGUP,  KC_HOME,  KC_END,   KC_PGDN,  KC_INS,  \
      _______,  MM_LH,    MM_MAX,   MM_RH,    KC_MAC2,  KC_PSCR,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_SCLN,  KC_QUOT, \
      _______,  MM_LLCN,  MM_BH,    MM_LRCN,  KC_PAST,  KC_MPRV,  KC_MNXT,  KC_MUTE,  IJ_BACK,  IJ_FWD,   KC_WSCH,  _______, \
      _______,  KC_LCTL,  KC_LALT,  KC_LGUI,  _______,            _______,            _______,  _______,  _______,  KC_LYRT),

  [_RAISE]    = LAYOUT_preonic_2x2u(
      KC_TILD,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL,  \
      _______,  KC_F11,   KC_F12,   KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE, \
      _______,  KC_AGIN,  KC_STOP,  KC_MENU,  KC_FIND,  KC_MPLY,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_COLN,  KC_DQUO, \
      _______,  KC_UNDO,  KC_CUT,   OS_COPY,  OS_PAST,  KC_MPRV,  KC_MNXT,  KC_MUTE,  KC_LT,    KC_GT,    KC_QUES,  KC_TRNS, \
      _______,  _______,  _______,  _______,  _______,            _______,            _______,  _______,  _______,  KC_LYRT),

  [_LOWER]    = LAYOUT_preonic_2x2u(
      KC_GRV,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_INS,  \
      _______,  KC_7,     KC_8,     KC_9,     KC_PMNS,  KC_VOLD,  KC_VOLU,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS, \
      _______,  KC_4,     KC_5,     KC_6,     KC_PPLS,  KC_PSCR,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_SCLN,  KC_QUOT, \
      _______,  KC_1,     KC_2,     KC_3,     KC_PAST,  KC_NO,    KC_NO,    KC_WHOM,  KC_WBAK,  KC_WFWD,  KC_WSCH,  _______, \
      _______,  KC_0,     KC_DOT,   KC_EQL,   _______,            _______,            _______,  _______,  _______,  KC_LYRT),

  [_ADJUST]   = LAYOUT_preonic_2x2u(
      KC_ESC,   AU_ON,    AU_OFF,   CK_TOGG,  CK_UP,    CK_DOWN,  CK_RST,   MU_ON,    MU_OFF,   MU_TOG,   MU_MOD,   KC_DEL,  \
      _______,  NK_ON,    NK_OFF,   EEP_RST,  RESET,    KC_MSTP,  KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  KC_BTN2,  KC_INS,  \
      _______,  GE_SWAP,  GE_NORM,  DEBUG,    AG_SWAP,  AG_NORM,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_BTN1,  _______, \
      _______,  DF_1,     DF_2,     KC_CAPS,  KC_NO,    KC_MPRV,  KC_MNXT,  KC_MUTE,  KC_ACL0,  KC_ACL1,  KC_ACL2,  _______, \
      _______,  _______,  _______,  _______,  _______,            _______,            _______,  _______,  _______,  KC_LYRT)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_CAPS:
      PLAY_SONG(capsToggleSong);
      return true;
      break;
    case DF(_QWERTY):
      playSongForLayer(_QWERTY);
      return true;
      break;
    case DF(_QWERTY_MAC):
    playSongForLayer(_QWERTY_MAC);
      return true;
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
        SEND_STRING("open https://www.reddit.com/\n");
        return false;
      }
      break;
    case KC_LYRT:
    if (record->event.pressed) {
      if (_currentLayer != _QWERTY) {
        layer_off(_currentLayer);
      }

      if (++_currentLayer >= _layerCount) {
        _currentLayer = _QWERTY;
      }
      playSongForLayer(_currentLayer);
      layer_on(_currentLayer);
      return true;
    }
    break;
  }
  return true;
}

void playSongForLayer(int currentLayer) {
  switch (currentLayer) {
    case   _QWERTY:
      PLAY_SONG(defaultLayerSong);
      break;
    case  _MOVE:
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
    case  _ADJUST:
      PLAY_SONG(adjustLayerSong);
      break;
  }
}
