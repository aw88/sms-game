#include "SMSlib.h"
#include "overworld.h"

#include "../out/assets.h"

short player_x = 64;
short player_y = 64;

void overworld_init(void) {
  SMS_mapROMBank(sprites_pal_bank);
  SMS_loadSpritePalette(sprites_pal);
  SMS_mapROMBank(sprites_bank);
  SMS_loadTiles(sprites, 0x100, sprites_size);
}

void overworld_loop(void) {
  for (;;) {
    SMS_initSprites();

    unsigned int buttons = SMS_getKeysStatus();

    if (buttons & PORT_A_KEY_UP) player_y--;
    if (buttons & PORT_A_KEY_DOWN) player_y++;
    if (buttons & PORT_A_KEY_LEFT) player_x--;
    if (buttons & PORT_A_KEY_RIGHT) player_x++;

    SMS_addSprite(player_x, player_y, 0x00);
    SMS_addSprite(player_x, player_y + 8, 0x01);
    SMS_addSprite(player_x + 8, player_y, 0x02);
    SMS_addSprite(player_x + 8, player_y + 8, 0x03);

    SMS_waitForVBlank();
    SMS_copySpritestoSAT();

    if (buttons & PORT_A_KEY_1) return;
  }
}

void do_overworld(void) {
  overworld_init();
  overworld_loop();
}
