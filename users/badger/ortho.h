#ifdef _BADGER_ORTHO_

#define _BADGER_AUDIO_

#include "quantum.h"
#include "badger.h"
#include "badger_audio.h"
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

enum OrthoKeys {
  KC_MAC1 = NEW_SAFE_RANGE,
  KC_MAC2,
  KC_LYRC,
  KC_FIRST
};

bool      _capsLockState;
int       _currentLayer;
const int _layerCount = 7;

#define P_ADJ LT(_ADJUST, KC_BSPC)
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)


#endif