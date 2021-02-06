#include "SMSlib.h"
#include "stdint.h"
#include "title.h"

#include "../out/bank2.h"
uint8_t test = 0;

void title_line_interrupt(void) {
  SMS_setBGPaletteColor(0, test++);
  SMS_setLineCounter(120);
}

void title_init(void) {
  SMS_displayOff();
  SMS_loadTiles(title, 0x10, title_size);

  uint16_t t = 0x0010;
  for (uint8_t j = 0; j < 5; j++) {
    SMS_setNextTileatXY(10, 8 + j);

    for (uint8_t i = 0; i < 11; i++) {
      SMS_setTile(t++);
    }
  }

  SMS_setLineInterruptHandler(title_line_interrupt);
  SMS_setLineCounter(60);
  SMS_enableLineInterrupt();

  SMS_displayOn();
}

void title_loop(void) {
  for(;;) {
    SMS_waitForVBlank();
    SMS_setLineCounter(60);
    test = 1;
    SMS_setBGPaletteColor(0, 0x00);
  }
}

void title_exit(void) {
  // ???
}

void do_title(void) {
  title_init();
  title_loop();
  title_exit();
}