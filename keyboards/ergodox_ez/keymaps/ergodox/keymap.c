#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"

#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

// model of double mod layer tap: shift+alt when held or `kc` when tapped
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
// save screen space
#define KC_TRNS KC_TRANSPARENT

// return of the macOS
#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)

// I think these are non-us keyboard concerns? Pretty sure I can just go ahead and delete these
// definitions, but also whatever
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define BP_NDSH_MAC ALGR(KC_8)

#define SPACEHAMMER LCTL(LGUI(LALT(KC_SPACE)))
#define DLT_WORD LALT(KC_DELETE)
#define FWD_WORD LALT(KC_RIGHT)
#define BK_WORD LALT(KC_LEFT)

#define PLAY_PAUSE KC_MEDIA_PLAY_PAUSE
#define PREV_TRACK KC_MEDIA_PREV_TRACK
#define NEXT_TRACK KC_MEDIA_NEXT_TRACK
#define VOL_UP KC_AUDIO_VOL_UP
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define MUTE KC_AUDIO_MUTE

// TODO verify correctness and then use these suckers
#define SYM(kc) LT(1,kc)
#define NAV(kc) LT(2,kc)
#define EMOU(kc) LT(3,kc)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  HSV_86_255_128,
  HSV_27_255_255,
};


/*
 * some points of order:
 * 1) home row mods? home row mods.
 * 2) right home row "alt" sends left alt: this  is a funny side effect of my terminal emacs config,
 *    which reserves right alt for the macOS default of special character input and left alt for meta
 * 3) honestly only have two so far, just adding a third to restore default indentation lmao
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_GRAVE,          KC_1,         KC_2,           KC_3,         KC_4,         KC_5,     ALT_T(KC_LEFT),   /**/    RALT_T(KC_RIGHT), KC_6,      KC_7,         KC_8,         KC_9,         KC_0,              KC_BSPACE,
    NAV(KC_TAB),       KC_Q,         KC_W,           KC_E,         KC_R,         KC_T,     TT(1),            /**/    TT(1),            KC_Y,      KC_U,         KC_I,         KC_O,         KC_P,              KC_BSLASH,
    CTL_T(KC_ESCAPE),  CTL_T(KC_A),  ALT_T(KC_S),    GUI_T(KC_D),  SFT_T(KC_F),  KC_G,                       /**/                      KC_H,      SFT_T(KC_J),  GUI_T(KC_K),  ALT_T(KC_L),  CTL_T(KC_SCOLON),  KC_QUOTE,
    KC_LSPO,           EMOU(KC_Z),   KC_X,           SYM(KC_C),    NAV(KC_V),    KC_B,     SPACEHAMMER,      /**/    SPACEHAMMER,      KC_N,      NAV(KC_M),    SYM(KC_COMMA),KC_DOT,       EMOU(KC_SLASH),    KC_RSPC,
    EMOU(KC_GRAVE),    KC_QUOTE,     WEBUSB_PAIR,    KC_LEFT,      KC_RIGHT,                                 /**/                                 KC_UP,        KC_DOWN,      KC_LBRACKET,  KC_RBRACKET,       MO(1),
                                                                                   ALT_T(KC_LEFT), KC_RIGHT, /**/ KC_DOWN, MO(1),
                                                                                                     KC_END, /**/ KC_PGUP,
                                                            SYM(KC_SPACE),   NAV(KC_ENTER), ALT_T(KC_MINUS), /**/ RALT_T(KC_EQUAL),   NAV(KC_ENTER),   SYM(KC_SPACE)
  ),
  // SYM :: symbols to the left; numpad to the right
  [1] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,         KC_F1,        KC_F2,          KC_F3,        KC_F4,        KC_F5,    KC_TRNS,          /**/    KC_TRNS,        KC_F6,       KC_F7,        KC_F8,        KC_F9,        KC_F10,            KC_F11,
    KC_TRNS,           KC_EXLM,      KC_AT,          KC_LBRACKET,  KC_RBRACKET,  KC_PIPE,  KC_TRNS,          /**/    KC_TRNS,        KC_UP,       KC_7,         KC_8,         KC_9,         KC_ASTR,           KC_F12,
    KC_TRNS,           KC_HASH,      KC_DLR,         KC_LCBR,      KC_RCBR,      KC_MINUS,                   /**/                    KC_DOWN,     KC_4,         KC_5,         KC_6,         KC_PLUS,           KC_TRNS,
    KC_TRNS,           KC_PERC,      KC_CIRC,        KC_LPRN,      KC_RPRN,      KC_EQUAL, KC_TRNS,          /**/    KC_TRNS,        KC_AMPR,     KC_1,         KC_2,         KC_3,         KC_BSLASH,         KC_TRNS,
    KC_TRNS,           KC_TILD,      KC_TRNS,        KC_TRNS,      KC_TRNS,                                  /**/                                 KC_TRNS,      KC_DOT,       KC_0,         KC_EQUAL,          KC_TRNS,
                                                                                           KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS,
                                                                                                    KC_TRNS, /**/ KC_TRNS,
                                                                                KC_MINUS, KC_EQUAL, KC_TRNS, /**/ KC_TRNS, RGB_HUD, RGB_HUI
  ),
  // NAV :: arrows and navigation
  [2] = LAYOUT_ergodox_pretty(
    KC_TRNS,           ALT_T(KC_1),  ALT_T(KC_2),    ALT_T(KC_3),  ALT_T(KC_4),  ALT_T(KC_5),KC_TRNS,        /**/    KC_TRNS,        ALT_T(KC_6), ALT_T(KC_7), ALT_T(KC_8), ALT_T(KC_9),   KC_F3,          A(KC_BSPACE),
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS,          /**/    TO(3),          BK_WORD,     KC_PGDOWN,   KC_PGUP,     FWD_WORD,      KC_TRNS,        KC_TRNS,
    ALT_T(KC_BSPACE),  KC_TRNS,      KC_TRNS,        DLT_WORD,     FWD_WORD,     KC_TRNS,                    /**/                    KC_LEFT,     KC_DOWN,     KC_UP,       KC_RIGHT,      KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      BK_WORD,  KC_TRNS,          /**/    KC_TRNS,        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,       KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,                                  /**/                                 KC_TRNS,     KC_TRNS,     KC_TRNS,       KC_TRNS,        KC_TRNS,
                                                                                    KC_TRNS,        KC_TRNS, /**/ KC_TRNS, KC_TRNS,
                                                                                                    KC_TRNS, /**/ KC_TRNS,
                                                                                 KC_TRNS,  KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS
  ),
  // EMOU :: emojis and mouse
  [3] = LAYOUT_ergodox_pretty(
    KC_TRNS,           ALT_T(KC_1),  ALT_T(KC_2),    ALT_T(KC_3),  ALT_T(KC_4),  ALT_T(KC_5),KC_TRNS,        /**/    KC_TRNS,        ALT_T(KC_6),   ALT_T(KC_7),    ALT_T(KC_8), ALT_T(KC_9),       KC_TRNS,        RESET,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS,          /**/    KC_TRNS,        KC_MS_BTN1,    KC_MS_BTN2,     KC_MS_WH_UP, KC_MS_WH_RIGHT,    KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,                    /**/                    KC_MS_LEFT,    PREV_TRACK,     VOL_DOWN,    VOL_UP,            NEXT_TRACK,     PLAY_PAUSE,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS,          /**/    KC_TRNS,        KC_MS_WH_LEFT, KC_MS_WH_DOWN,  PREV_TRACK,  NEXT_TRACK,        KC_TRNS,        KC_TRNS,
    KC_TRNS,           WEBUSB_PAIR,  KC_TRNS,        KC_TRNS,      KC_TRNS,                                  /**/                                   VOL_UP,         VOL_DOWN,    MUTE,              KC_TRNS,        KC_TRNS,
                                                                                    KC_TRNS,        KC_TRNS, /**/ KC_TRNS, KC_TRNS,
                                                                                                    KC_TRNS, /**/ KC_TRNS,
                                                                    GUI_T(KC_TAB), GUI_T(KC_GRAVE), KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_WWW_BACK
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};

