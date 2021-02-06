#include "stdint.h"
#include "SMSlib.h"
#include "title.h"
#include "../out/bank2.h"

#include "rom_header.h"

#define TEXT_ASCII_OFFSET_MASK 0x80

const uint8_t palette[] = {
    0x01, 0x3f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

void write_string_at(uint8_t tile_x, uint8_t tile_y, uint8_t* string);

void main(void) {
    SMS_init();

    SMS_loadBGPalette(palette);
    SMS_loadTiles(font, 0xA0, font_size);

    write_string_at(4, 20, "Hello, world!");

    SMS_displayOn();

    do_title();

    for (;;) {
        SMS_waitForVBlank();
    }
}

void write_string_at(uint8_t tile_x, uint8_t tile_y, uint8_t* string) {
    SMS_setNextTileatXY(tile_x, tile_y);

    uint8_t *c = string;

    do {
        uint16_t next_tile = (*c) | TEXT_ASCII_OFFSET_MASK;
        SMS_setTile(next_tile);
    } while (*++c);
}
