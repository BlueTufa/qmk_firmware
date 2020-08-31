#include "badger_audio.h"
#ifdef _BADGER_AUDIO_
void playSongForLayer(int currentLayer) {
  #ifdef AUDIO_ENABLE
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
  #endif
}

void playSongForEvent(float song) {
  #ifdef AUDIO_ENABLE
  PLAY_SONG(song);
  #endif
}
#endif