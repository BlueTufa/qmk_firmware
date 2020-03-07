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
#define MAC_PST    LGUI(KC_V)
#define MAC_CPY    LGUI(KC_C)

#define WD_BACK    LALT(KC_LEFT)
#define WD_FRWD    LALT(KC_RIGHT)

#define VD_1       LCTL(KC_F1)
#define VD_2       LCTL(KC_F2)
#define VD_3       LCTL(KC_F3)

#define WM_UH      LGUI(KC_UP)
#define WM_BH      LGUI(KC_DOWN)
#define WM_LH      LGUI(KC_LEFT)
#define WM_RH      LGUI(KC_RIGHT)
#define WM_MAX     LGUI(KC_PGUP)

#define CS_RIGHT   LCTL(LSFT(KC_9))
#define CS_DOWN    LCTL(LSFT(KC_0))

#define CM_RIGHT   LGUI(KC_D)
#define CM_DOWN    LGUI(LSFT(KC_D))

/* THESE are not defaults in KDE and must be set manually */
#define WM_VD1     HYPR(KC_1)
#define WM_VD2     HYPR(KC_2)
#define WM_VD3     HYPR(KC_3)

/* IntelliJ / JetBrains shortcuts */
#define IJ_BACK    LGUI(LALT(KC_LEFT))
#define IJ_FWD     LGUI(LALT(KC_RIGHT))
#define IJ_UP      LGUI(LALT(KC_UP))
#define IJ_DOWN    LGUI(LALT(KC_DOWN))
#define IJ_IMPL    LGUI(LALT(KC_B))
#define IJ_DECL    LGUI(KC_B)
#define IJ_REN     LSFT(KC_F6)
#define IJ_USAG    LALT(KC_F7)
#define IJ_RUN     KC_F9
#define IJ_STEP    KC_F8
#define IJ_INTO    LSFT(KC_F7)
#define IJ_OUT     LSFT(KC_F8) 
#define IJ_STOP    LGUI(KC_F2) 

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

/* audio support */
#define MAC_LAYER_SONG    H__NOTE(_E5),  H__NOTE(_A5),  Q__NOTE(_D6),   Q__NOTE(_G6), \
        ED_NOTE(_E7),     E__NOTE(_CS7), E__NOTE(_E6),  E__NOTE(_A6),   M__NOTE(_CS7, 20),
#define LONG_AG_SWAP      Q__NOTE(_G5),  Q__NOTE(_D6),  Q__NOTE(_A6),   Q__NOTE(_E7), \
        SD_NOTE(_B5),     SD_NOTE(_A5),  SD_NOTE(_B5),  SD_NOTE(_A5),
#define LONG_AG_NORM      Q__NOTE(_DS4), Q__NOTE(_DS4), B__NOTE(_C5),
#define MOVE_LAYER_SONG   E__NOTE(_GS6), E__NOTE(_A6),  S__NOTE(_REST), ED_NOTE(_E7), \
        S__NOTE(_REST),   ED_NOTE(_GS7),
#define RAISE_LAYER_SONG  W__NOTE(_BF5), Q__NOTE(_A5),  W__NOTE(_BF5),  Q__NOTE(_A5),  W__NOTE(_E6), Q__NOTE(_B5),
#define LOWER_LAYER_SONG  Q__NOTE(_DS4), E__NOTE(_DS4), E__NOTE(_DS6),  Q__NOTE(_DS5), \
        E__NOTE(_DS5),    E__NOTE(_DS6), Q__NOTE(_E5),  E__NOTE(_E5),   E__NOTE(_DS6), Q__NOTE(_DS5),
#define CAPS_ON           W__NOTE(_E5),  Q__NOTE(_BF5), W__NOTE(_E5),   Q__NOTE(_BF5), W__NOTE(_E5), Q__NOTE(_BF5),
#define CAPS_OFF          W__NOTE(_E5),  Q__NOTE(_BF5),

#endif
