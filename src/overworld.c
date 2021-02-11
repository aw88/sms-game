#include "SMSlib.h"
#include "overworld.h"

#include "../out/assets.h"

void overworld_init(void) {
  SMS_mapROMBank(sprites_pal_bank);
  SMS_loadSpritePalette(sprites_pal);
  SMS_mapROMBank(sprites_bank);
  SMS_loadTiles(sprites, 0x100, sprites_size);
}

void overworld_loop(void) {
  for (;;) {
    SMS_initSprites();

    SMS_addSprite(64, 64, 0x00);
    SMS_addSprite(64, 72, 0x01);
    SMS_addSprite(72, 64, 0x02);
    SMS_addSprite(72, 72, 0x03);

    SMS_waitForVBlank();
    SMS_copySpritestoSAT();
  }
}

void do_overworld(void) {
  overworld_init();
  overworld_loop();
}
