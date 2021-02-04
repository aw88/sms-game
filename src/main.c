#include "SMSlib.h"
#include "../out/bank2.h"

#include "rom_header.h"

#define TEXT_ASCII_OFFSET_MASK 0x80

const unsigned char palette[] = {
    0x00, 0x3f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

void write_string_at(char tile_x, char tile_y, char* string);

void main(void) {
    SMS_init();

    SMS_loadBGPalette(palette);
    SMS_loadTiles(font, 0xA0, font_size);

    write_string_at(4, 20, "Hello, world!");

    SMS_displayOn();

    for(;;) {
        SMS_waitForVBlank();
    }
}

void write_string_at(char tile_x, char tile_y, char* string) {
    SMS_setNextTileatXY(tile_x, tile_y);

    char *c = string;

    while (*c) {
        int next_tile = (*c++) | TEXT_ASCII_OFFSET_MASK;
        SMS_setTile(next_tile);
    }
}
