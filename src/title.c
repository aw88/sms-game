#include "SMSlib.h"
#include "stdint.h"

#include "dialog.h"
#include "title.h"

#include "../out/assets.h"

void title_init(void) {
  SMS_displayOff();

  SMS_mapROMBank(title_bank);
  SMS_loadTiles(title, 0x10, title_size);

  uint16_t t = 0x0010;
  for (uint8_t j = 0; j < 5; j++) {
    SMS_setNextTileatXY(10, 8 + j);

    for (uint8_t i = 0; i < 11; i++) {
      SMS_setTile(t++);
    }
  }

  write_string_at(10, 18, "PRESS START");

  SMS_displayOn();
}

void title_loop(void) {
  for(;;) {
    uint16_t pressed = SMS_getKeysPressed();
    if (pressed & PORT_A_KEY_1) {
      break;
    }

    SMS_waitForVBlank();
    SMS_setBGPaletteColor(0, 0x00);
  }
}

void title_exit(void) {
  uint8_t fade[3] = { RGB(0,0,0), RGB(1,1,1), RGB(2,2,2) };
  uint8_t index = 2;
  do {
    SMS_setBGPaletteColor(1, fade[index]);
    for (uint8_t loop = 0; loop < 8; loop++) {
      SMS_waitForVBlank();
    }
  } while (index--);
}

void do_title(void) {
  title_init();
  title_loop();
  title_exit();
}