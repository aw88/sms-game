#include <stdint.h>

#include "SMSlib.h"
#include "overworld.h"

#include "../out/assets.h"

enum PLAYER_FACING {
  NORTH=0x04,
  SOUTH=0x00,
  EAST=0x08,
  WEST=0x0C,
};

short player_x = 64;
short player_y = 64;

uint8_t facing = SOUTH;

void overworld_init(void) {
  SMS_mapROMBank(sprites_pal_bank);
  SMS_loadSpritePalette(sprites_pal);
  SMS_mapROMBank(sprites_bank);
  SMS_loadTiles(sprites, 0x100, sprites_size);
  SMS_setSpriteMode(SPRITEMODE_TALL);
}

void overworld_loop(void) {
  for (;;) {
    SMS_initSprites();

    unsigned int buttons = SMS_getKeysStatus();

    if (buttons & PORT_A_KEY_UP) {
      player_y--;
      facing = NORTH;
    }
    if (buttons & PORT_A_KEY_DOWN) {
      player_y++;
      facing = SOUTH;
    }
    if (buttons & PORT_A_KEY_LEFT) {
      player_x--;
      facing = WEST;
    }
    if (buttons & PORT_A_KEY_RIGHT) {
      player_x++;
      facing = EAST;
    }

    SMS_addTwoAdjoiningSprites(player_x, player_y, facing);

    SMS_waitForVBlank();
    SMS_copySpritestoSAT();

    if (buttons & PORT_A_KEY_1) return;
  }
}

void do_overworld(void) {
  overworld_init();
  overworld_loop();
}
