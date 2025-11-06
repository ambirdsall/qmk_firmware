/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"bdAVj/6qgxq"
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// I really shouldn't need to update my firmware just to work around a silly frigging
// raylib input handling bug, but here we are
#define TAP_CODE_DELAY 20
