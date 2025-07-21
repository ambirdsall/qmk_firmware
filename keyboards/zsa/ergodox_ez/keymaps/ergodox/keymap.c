#include QMK_KEYBOARD_H
#include "version.h"

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

#define DLT_WORD LALT(KC_DELETE)
#define FWD_WORD LALT(KC_RIGHT)
#define BK_WORD LALT(KC_LEFT)

#define PLAY_PAUSE KC_MEDIA_PLAY_PAUSE
#define PREV_TRACK KC_MEDIA_PREV_TRACK
#define NEXT_TRACK KC_MEDIA_NEXT_TRACK
#define VOL_UP KC_AUDIO_VOL_UP
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define MUTE KC_AUDIO_MUTE

enum layers {
    BASE_L, // Home base: this is where the magic (i.e. standard typing and top-level layer selection) happens
    SYM_L,  // "Symbol layer" does what it says on the tin, but also offers a numpad
    NAV_L,  // Life is too short *not* to add hardware support for using H/J/K/L as arrow keys
    EMOU_L, // Aspirationally short for "emojis + mouse". It doesn't even have emojis tho smh
    PRO_L,  // "Programming layer"; a transitional compromise between the old symbol layer being lowkey shit vs. how deep its muscle memory goes
    VOL_L,  // the assumption behind naming this "Volume layer" is that those are the media control keys I'll use most
    NUM_L,  // "Num{ber,pad} layer"
    FUN_L,  // "Function [key] layer" is like a numpad, but for F1, F2, F3, et al
    SYST_L, // "System layer" for firmware metashenanigans. Flashing, rebooting, maybe someday the rest of the iceberg.
};

#define SYM(kc) LT(SYM_L,kc)
#define NAV(kc) LT(NAV_L,kc)
#define EMOU(kc) LT(EMOU_L,kc)
#define PRO(kc) LT(PRO_L,kc)
#define VOL(kc) LT(VOL_L,kc)
#define NUM(kc) LT(NUM_L,kc)
#define FUN(kc) LT(FUN_L,kc)
#define SYST(kc) LT(SYST_L,kc)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  HSV_86_255_128,
  HSV_27_255_255,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_L] = LAYOUT_ergodox_pretty(
    KC_GRAVE,          KC_1,         KC_2,           KC_3,         KC_4,         KC_5,        ALT_T(KC_LEFT), /**/   RALT_T(KC_RIGHT), KC_6,      KC_7,         KC_8,         KC_9,         KC_0,              KC_BSPC,
    NAV(KC_TAB),       KC_Q,         KC_W,           KC_E,         KC_R,         KC_T,        KC_HOME,        /**/   KC_PGUP,          KC_Y,      KC_U,         KC_I,         KC_O,         KC_P,              KC_BSLS,
    CTL_T(KC_ESCAPE),  CTL_T(KC_A),  ALT_T(KC_S),    GUI_T(KC_D),  SFT_T(KC_F),  KC_G,                        /**/                     KC_H,      SFT_T(KC_J),  GUI_T(KC_K),  ALT_T(KC_L),  CTL_T(KC_SCLN),    KC_QUOTE,
    SC_LSPO,           EMOU(KC_Z),   FUN(KC_X),      NUM(KC_C),    VOL(KC_V),    KC_B,        KC_END,         /**/   KC_PGDN,          KC_N,      PRO(KC_M),    SYM(KC_COMMA),KC_DOT,       EMOU(KC_SLASH),    SC_RSPC,
    SYST(KC_GRAVE),    KC_QUOTE,     KC_PSCR,        KC_LEFT,      KC_RIGHT,                                  /**/                                KC_UP,        KC_DOWN,      KC_LBRC,      KC_RBRC,           MO(SYM_L),
                                                                                                              /**/
                                                                                   ALT_T(KC_LEFT), KC_RIGHT,  /**/ KC_DOWN, MO(SYM_L),
                                                                                                     KC_END,  /**/ KC_PGUP,
                                                            SYM(KC_SPACE),   NAV(KC_ENTER), ALT_T(KC_MINUS),  /**/ RALT_T(KC_EQUAL),  NAV(KC_ENTER),   PRO(KC_SPACE)
  ),
  [SYM_L] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,         KC_F1,        KC_F2,          KC_F3,        KC_F4,        KC_F5,       KC_TRNS,        /**/    KC_TRNS,        KC_F6,       KC_F7,        KC_F8,        KC_F9,        KC_F10,            KC_F11,
    KC_TRNS,           KC_EXLM,      KC_AT,          KC_LBRC,      KC_RBRC,      KC_PIPE,     KC_TRNS,        /**/    KC_TRNS,        KC_UP,       KC_7,         KC_8,         KC_9,         KC_ASTR,           KC_F12,
    KC_TRNS,           KC_HASH,      KC_DLR,         KC_LCBR,      KC_RCBR,      KC_MINUS,                    /**/                    KC_DOWN,     KC_4,         KC_5,         KC_6,         KC_PLUS,           KC_TRNS,
    KC_TRNS,           KC_PERC,      KC_SLASH,       KC_LT,        KC_GT,        KC_EQUAL,    KC_TRNS,        /**/    KC_TRNS,        KC_0,        KC_1,         KC_2,         KC_3,         KC_BSLS,           KC_TRNS,
    KC_TRNS,           KC_TILD,      KC_TRNS,        KC_TRNS,      KC_TRNS,                                   /**/                                 KC_DOT,       KC_DOT,       KC_0,         KC_EQUAL,          KC_TRNS,
                                                                                                              /**/
                                                                                            KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS,
                                                                                                     KC_TRNS, /**/ KC_TRNS,
                                                                          SFT_T(KC_MINUS), KC_EQUAL, KC_TRNS, /**/ KC_TRNS, RGB_HUD, SFT_T(KC_UNDERSCORE)
  ),
  [NAV_L] = LAYOUT_ergodox_pretty(
    KC_TRNS,           ALT_T(KC_1),  ALT_T(KC_2),    ALT_T(KC_3),  ALT_T(KC_4),  ALT_T(KC_5), KC_TRNS,        /**/    KC_TRNS,        ALT_T(KC_6), ALT_T(KC_7), ALT_T(KC_8), ALT_T(KC_9),   KC_F3,          A(KC_BSPC),
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,     KC_TRNS,        /**/    TO(3),          KC_HOME,     KC_PGDN,     KC_PGUP,     KC_END,        KC_TRNS,        KC_TRNS,
    ALT_T(KC_BSPC),    KC_TRNS,      KC_TRNS,        DLT_WORD,     FWD_WORD,     KC_TRNS,                     /**/                    KC_LEFT,     KC_DOWN,     KC_UP,       KC_RIGHT,      KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      BK_WORD,     KC_TRNS,        /**/    KC_TRNS,        BK_WORD,     KC_TRNS,     KC_TRNS,     FWD_WORD,      KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,                                   /**/                                 KC_TRNS,     KC_TRNS,     KC_TRNS,       KC_TRNS,        KC_TRNS,
                                                                                                              /**/
                                                                                     KC_TRNS,        KC_TRNS, /**/ KC_TRNS, KC_TRNS,
                                                                                                     KC_TRNS, /**/ KC_TRNS,
                                                                                  KC_TRNS,  KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [EMOU_L] = LAYOUT_ergodox_pretty(
    KC_TRNS,           ALT_T(KC_1),  ALT_T(KC_2),    ALT_T(KC_3),  ALT_T(KC_4),  ALT_T(KC_5), KC_TRNS,        /**/    KC_TRNS,        ALT_T(KC_6),   ALT_T(KC_7),    ALT_T(KC_8), ALT_T(KC_9),       KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,          /**/    KC_TRNS,        KC_MS_BTN1,    KC_MS_BTN2,     KC_TRNS,     KC_TRNS,           KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,                     /**/                    KC_MS_LEFT,    KC_MS_DOWN,     KC_MS_UP,    KC_MS_RIGHT,       NEXT_TRACK,     PLAY_PAUSE,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,          /**/    KC_TRNS,        KC_MS_WH_LEFT, KC_MS_WH_DOWN,  KC_MS_WH_UP, KC_MS_WH_RIGHT,    KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,                                   /**/                                   VOL_UP,         VOL_DOWN,    MUTE,              KC_TRNS,        KC_TRNS,
                                                                                                              /**/
                                                                                     KC_TRNS,        KC_TRNS, /**/ KC_TRNS, KC_TRNS,
                                                                                                     KC_TRNS, /**/ KC_TRNS,
                                                                     GUI_T(KC_TAB), GUI_T(KC_GRAVE), KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_WWW_BACK
  ),
  // PRO :: "programming"? An alternate symbol layer I'm trying out, with hopes it will fully supercede SYM someday.
  // Based on https://getreuer.info/posts/keyboards/symbol-layer/index.html#sunakus-symbol-layer
  [PRO_L] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,         KC_F1,        KC_F2,          KC_F3,        KC_F4,        KC_F5,    KC_TRNS,           /**/   KC_TRNS,        KC_F6,          KC_F7,        KC_F8,        KC_F9,        KC_F10,            KC_F11,
    KC_TILD,           KC_LCBR,      KC_PERC,        KC_GRAVE,     KC_RCBR,      KC_QUES,  KC_TRNS,           /**/   KC_TRNS,        KC_UP,          KC_7,         KC_8,         KC_9,         KC_ASTR,           KC_F12,
    KC_HASH,           KC_CIRC,      KC_EQUAL,       KC_UNDERSCORE,KC_DOLLAR,    KC_ASTERISK,                 /**/                   KC_DOWN,        KC_4,         KC_5,         KC_6,         KC_PLUS,           KC_TRNS,
    KC_EXLM,           KC_LT,        KC_PIPE,        KC_MINUS,     KC_GT,        KC_SLASH, KC_TRNS,           /**/   KC_TRNS,        KC_0,           KC_1,         KC_2,         KC_3,         KC_BSLS,           KC_TRNS,
    KC_TRNS,           KC_COMMA,     KC_AMPR,        KC_PLUS,      KC_SCLN,                                   /**/                                   KC_DOT,       KC_DOT,       KC_0,         KC_EQUAL,          KC_TRNS,
                                                                                                              /**/
                                                                                           KC_TRNS, KC_TRNS,  /**/ KC_TRNS, KC_TRNS,
                                                                                                    KC_TRNS,  /**/ KC_TRNS,
                                                                         SFT_T(KC_MINUS), KC_EQUAL, KC_TRNS,  /**/ KC_TRNS, RGB_HUD, SFT_T(KC_UNDERSCORE)
  ),
  [VOL_L] = LAYOUT_ergodox_pretty(
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,          /**/    KC_TRNS,        KC_TRNS,       KC_TRNS,        KC_TRNS,     KC_TRNS,           KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,          /**/    KC_TRNS,        KC_TRNS,       KC_TRNS,        KC_TRNS,     KC_TRNS,           KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,                     /**/                    KC_MPRV,       VOL_DOWN,       VOL_UP,      KC_MNXT,           KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,          /**/    KC_TRNS,        KC_TRNS,       KC_MUTE,        KC_TRNS,     KC_TRNS,           KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,                                   /**/                                   KC_TRNS,        KC_TRNS,     KC_TRNS,           KC_TRNS,        KC_TRNS,
                                                                                                              /**/
                                                                                          KC_TRNS,   KC_TRNS, /**/ KC_TRNS, KC_TRNS,
                                                                                                     KC_TRNS, /**/ KC_TRNS,
                                                                                   KC_MPLY, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_MPLY
  ),
  [NUM_L] = LAYOUT_ergodox_pretty(
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,          /**/    KC_TRNS,        KC_TRNS,       KC_0,           KC_TRNS,     KC_TRNS,           KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,          /**/    KC_TRNS,        KC_TRNS,       KC_7,           KC_8,        KC_9,              KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,                     /**/                    KC_TRNS,       KC_4,           KC_5,        KC_6,              KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,          /**/    KC_TRNS,        KC_0,          KC_1,           KC_2,        KC_3,              KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,                                   /**/                                   KC_DOT,         KC_DOT,      KC_0,              KC_TRNS,        KC_TRNS,
                                                                                                              /**/
                                                                                          KC_TRNS,   KC_TRNS, /**/ KC_TRNS, KC_TRNS,
                                                                                                     KC_TRNS, /**/ KC_TRNS,
                                                                                   KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [FUN_L] = LAYOUT_ergodox_pretty(
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,          /**/    KC_TRNS,        KC_TRNS,       KC_F10,         KC_F11,      KC_F12,            KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,          /**/    KC_TRNS,        KC_TRNS,       KC_F7,          KC_F8,       KC_F9,             KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,                     /**/                    KC_TRNS,       KC_F4,          KC_F5,       KC_F6,             KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,          /**/    KC_TRNS,        KC_TRNS,       KC_F1,          KC_F2,       KC_F3,             KC_TRNS,        KC_TRNS,
    KC_TRNS,           KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,                                   /**/                                   KC_TRNS,        KC_TRNS,     KC_TRNS,           KC_TRNS,        KC_TRNS,
                                                                                                              /**/
                                                                                          KC_TRNS,   KC_TRNS, /**/ KC_TRNS, KC_TRNS,
                                                                                                     KC_TRNS, /**/ KC_TRNS,
                                                                                   KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [SYST_L] = LAYOUT_ergodox_pretty(
    KC_NO,             KC_NO,        KC_NO,          KC_NO,        KC_NO,        KC_NO,     KC_NO,            /**/    KC_NO,          KC_NO,         KC_F10,         KC_F11,      KC_F12,            KC_NO,          QK_BOOT,
    KC_NO,             KC_NO,        KC_NO,          KC_NO,        QK_RBT,       KC_NO,     KC_NO,            /**/    KC_NO,          KC_NO,         KC_F7,          KC_F8,       KC_F9,             KC_NO,          KC_NO,
    KC_NO,             KC_NO,        KC_NO,          DB_TOGG,      KC_NO,        KC_NO,                       /**/                    KC_NO,         KC_F4,          KC_F5,       KC_F6,             KC_NO,          KC_NO,
    KC_NO,             KC_NO,        KC_NO,          KC_NO,        KC_NO,        QK_BOOT,   KC_NO,            /**/    KC_NO,          KC_NO,         KC_F1,          KC_F2,       KC_F3,             KC_NO,          KC_NO,
    KC_NO,             KC_NO,        KC_NO,          KC_NO,        KC_NO,                                     /**/                                   KC_NO,          KC_NO,       KC_NO,             KC_NO,          KC_NO,
                                                                                                              /**/
                                                                                          KC_NO,     KC_NO,   /**/ KC_NO,   KC_NO,
                                                                                                     KC_NO,   /**/ KC_NO,
                                                                                   KC_NO,   KC_NO,   KC_NO,   /**/ KC_NO,   KC_NO,   KC_TRNS
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  }
  return true;
}

void red_light(void) {
  ergodox_right_led_1_on();
}

void green_light(void) {
  ergodox_right_led_2_on();
}

void blue_light(void) {
  ergodox_right_led_3_on();
}

void yellow_light(void) {
  red_light();
  green_light();
}

void magenta_light(void) {
  red_light();
  blue_light();
}

void aqua_light(void) {
  green_light();
  blue_light();
}

void white_light(void) {
  red_light();
  green_light();
  blue_light();
}

layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // non-default input layers
    case PRO_L:
      yellow_light();
      break;
    case SYM_L:
      white_light();
      break;
    case NUM_L:
      white_light();
      break;

    // navigating by arrow or mouse
    case NAV_L:
      green_light();
      break;
    case EMOU_L:
      aqua_light();
      break;

    case VOL_L:
      blue_light();
      break;

    case FUN_L:
      magenta_light();
      break;

    // i get to pretend i am scary
    case SYST_L:
      red_light();
      break;
    default:
      break;
  }
  return state;
};

