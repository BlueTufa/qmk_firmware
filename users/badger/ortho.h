#ifdef _BADGER_ORTHO_

#define _BADGER_AUDIO_

#include "quantum.h"
#include "badger.h"
#include "badger_audio.h"
#include <print.h>

enum OrthoLayers {
  _RAISE = _CONFIG + 1,
  _LOWER
};

enum OrthoKeys {
  KC_MAC1 = SAFE_RANGE,
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