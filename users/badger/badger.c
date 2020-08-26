#ifndef USERSPACE
#define USERSPACE
#include "badger.h"
#endif

__attribute__ ((weak))
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