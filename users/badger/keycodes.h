#ifndef _COMMON_KEYCODES_H_

#define _COMMON_KEYCODES_H_

/* these are KDE and/or linux specific */
#define MOVE       LT(_MOVE, KC_ESC)
#define MOVE_MAC   LT(_MOVE_MAC, KC_ESC)
#define ADJUST     MO(_ADJUST)

#define OS_POP     LCTL(KC_F10)
#define MAC_POP    LCTL(KC_UP)
#define OS_COPY    LSFT(LCTL(KC_C))
#define OS_PAST    LSFT(LCTL(KC_V))

#define VD_1       LCTL(KC_F1)
#define VD_2       LCTL(KC_F2)
#define VD_3       LCTL(KC_F3)

#define WM_UH      LGUI(KC_UP)
#define WM_BH      LGUI(KC_DOWN)
#define WM_LH      LGUI(KC_LEFT)
#define WM_RH      LGUI(KC_RIGHT)
#define WM_MAX     LGUI(KC_PGUP)

/* THESE are not defaults in KDE and must be set manually */
#define WM_VD1     HYPR(KC_1)
#define WM_VD2     HYPR(KC_2)
#define WM_VD3     HYPR(KC_3)

/* IntelliJ / JetBrains shortcuts */
#define IJ_BACK    LGUI(LALT(KC_LEFT))
#define IJ_FWD     LGUI(LALT(KC_RIGHT))

/* MacOS virtual desktop shortcuts */
#define M_VD1      LCTL(KC_1)
#define M_VD2      LCTL(KC_2)
#define M_VD3      LCTL(KC_3)

/* rectangle shortcuts */
#define MM_ULCN    LCTL(LGUI(KC_LEFT))
#define MM_URCN    LCTL(LGUI(KC_RIGHT))
#define MM_LLCN    LCTL(LSFT(LGUI(KC_LEFT)))
#define MM_LRCN    LCTL(LSFT(LGUI(KC_RIGHT)))
#define MM_MAX     LALT(LGUI(KC_F))
#define MM_LH      HYPR(KC_LBRC)
#define MM_RH      HYPR(KC_RBRC)
#define MM_UH      LALT(LGUI(KC_UP))
#define MM_BH      LALT(LGUI(KC_DOWN))

#define DF_1       DF(_QWERTY)
#define DF_2       DF(_QWERTY_MAC)

#endif