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

// TODO verify correctness and then use these suckers
#define SYM(kc) LT(1,kc)
#define ARR(kc) LT(2,kc)
#define MEDIA(kc) LT(3,kc)

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
    KC_GRAVE,          KC_1,         KC_2,           KC_3,         KC_4,         KC_5,      LALT_T(KC_LEFT),           /**/                 RALT_T(KC_RIGHT), KC_6,        KC_7,         KC_8,         KC_9,         KC_0,              KC_BSPACE,
    ARR(KC_TAB),       KC_Q,         KC_W,           KC_E,         KC_R,         KC_T,      TT(1),                     /**/                 TT(1),            KC_Y,        KC_U,         KC_I,         KC_O,         KC_P,              KC_BSLASH,
    LCTL_T(KC_ESCAPE), LCTL_T(KC_A), LALT_T(KC_S),   LGUI_T(KC_D), LSFT_T(KC_F), KC_G,                                 /**/                                   KC_H,        RSFT_T(KC_J), RGUI_T(KC_K), LALT_T(KC_L), RCTL_T(KC_SCOLON), LGUI_T(KC_QUOTE),
    KC_LSHIFT,         MEDIA(KC_Z),  KC_X,           ARR(KC_C),    SYM(KC_V),    KC_B,      SPACEHAMMER,               /**/                 SPACEHAMMER,      KC_N,        SYM(KC_M),    ARR(KC_COMMA),KC_DOT,       MEDIA(KC_SLASH),   KC_RSHIFT,
    MEDIA(KC_GRAVE),   KC_QUOTE,     WEBUSB_PAIR,    KC_LEFT,      KC_RIGHT,                                           /**/                                                KC_NO,        KC_DOWN,      KC_LBRACKET,  KC_RBRACKET,       MO(1),
                                                                                            LALT_T(KC_LEFT), KC_RIGHT, /**/ KC_DOWN,        MO(1),
                                                                                                             KC_END,   /**/ KC_PGUP,
                                                                 LGUI_T(KC_SPACE), LCTL_T(KC_ENTER), LALT_T(KC_MINUS), /**/ RALT_T(KC_EQUAL), RCTL_T(KC_ENTER), RGUI_T(KC_SPACE)
  ),
  // SYM :: symbol layer
  [1] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,         KC_F1,        KC_F2,          KC_F3,        KC_F4,        KC_F5,      KC_TRNS,                  /**/                 KC_TRNS,        KC_F6,         KC_F7,          KC_F8,      KC_F9,          KC_F10,         KC_F11,
    KC_TRNS,           KC_EXLM,      KC_AT,          KC_LCBR,      KC_RCBR,      KC_PIPE,    KC_TRNS,                  /**/                 KC_TRNS,        KC_UP,         KC_7,           KC_8,       KC_9,           KC_ASTR,        KC_F12,
    KC_TRNS,           KC_HASH,      KC_DLR,         KC_LPRN,      KC_RPRN,      KC_MINUS,                             /**/                                 KC_DOWN,       KC_4,           KC_5,       KC_6,           KC_PLUS,        KC_TRNS,
    KC_TRNS,           KC_PERC,      KC_CIRC,        KC_LBRACKET,  KC_RBRACKET,  KC_EQUAL,   KC_TRNS,                  /**/                 KC_TRNS,        KC_AMPR,       KC_1,           KC_2,       KC_3,           KC_BSLASH,      KC_TRNS,
    KC_TRNS,           KC_TILD,      KC_TRNS,        KC_TRNS,      KC_TRNS,                                            /**/                                                KC_TRNS,        KC_DOT,     KC_0,           KC_EQUAL,       KC_TRNS,
                                                                                             KC_TRNS,        KC_TRNS,  /**/ KC_TRNS,        KC_TRNS,
                                                                                                             KC_TRNS,  /**/ KC_TRNS,
                                                                                 KC_MINUS,   KC_EQUAL,       KC_TRNS,  /**/ KC_TRNS,        RGB_HUD,        RGB_HUI
  ),
  // ARR :: arrows and alt+ shortcuts (TODO: make arrows symmetrical & extract the alt+ shortcuts to their own layer)
  [2] = LAYOUT_ergodox_pretty(
    KC_TRNS,           LALT(KC_1),   LALT(KC_2),     LALT(KC_3),   LALT(KC_4),   LALT(KC_5), KC_TRNS,                  /**/                 KC_TRNS,        LALT(KC_6),    LALT(KC_7),     LALT(KC_8), LALT(KC_9),     KC_F3,          KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,    KC_TRNS,                  /**/                 TO(3),          LALT(KC_LEFT), KC_PGDOWN,      KC_PGUP,    LALT(KC_RIGHT), KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,                              /**/                                 KC_LEFT,       KC_DOWN,        KC_UP,      KC_RIGHT,       KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,    KC_TRNS,                  /**/                 KC_TRNS,        KC_TRNS,       KC_TRNS,        KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,                                            /**/                                                KC_TRNS,        KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                             KC_TRNS,        KC_TRNS,  /**/ KC_TRNS,        KC_TRNS,
                                                                                                             KC_TRNS,  /**/ KC_TRNS,
                                                                                 KC_TRNS,    KC_TRNS,        KC_TRNS,  /**/ KC_TRNS,        KC_TRNS,        KC_TRNS
  ),
  // MEDIA :: does what it says on the tin
  [3] = LAYOUT_ergodox_pretty(
    KC_TRNS,           LALT(KC_1),   LALT(KC_2),     LALT(KC_3),   LALT(KC_4),   LALT(KC_5), KC_TRNS,                  /**/                KC_TRNS,        LALT(KC_6),    LALT(KC_7),     LALT(KC_8),  LALT(KC_9),        KC_TRNS,        RESET,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,    KC_TRNS,                  /**/                KC_TRNS,        KC_MS_BTN1,    KC_MS_BTN2,     KC_MS_WH_UP, KC_MS_WH_RIGHT,    KC_TRNS,        KC_TRNS,
    LALT(KC_BSPACE),   KC_ESCAPE,    KC_TRNS,        DLT_WORD,     KC_TRNS,      KC_TRNS,                              /**/                                KC_MS_LEFT,    KC_MS_DOWN,     KC_MS_UP,    KC_MS_RIGHT,       KC_TRNS,        KC_MEDIA_PLAY_PAUSE,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,    KC_TRNS,                  /**/                KC_TRNS,        KC_MS_WH_LEFT, KC_MS_WH_DOWN,  KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRNS,KC_TRNS,
    KC_TRNS,           WEBUSB_PAIR,  KC_TRNS,        KC_TRNS,      KC_TRNS,                                            /**/                                               KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,KC_TRNS,        KC_TRNS,
                                                                                             KC_TRNS,        KC_TRNS,  /**/ KC_TRNS,       KC_TRNS,
                                                                                                             KC_TRNS,  /**/ KC_TRNS,
                                                                                LGUI(KC_TAB),LGUI(KC_GRAVE), KC_TRNS,  /**/ KC_TRNS,       KC_TRNS,        KC_WWW_BACK
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


