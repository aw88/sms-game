#include "dialog.h"

void write_string_at(uint8_t tile_x, uint8_t tile_y, uint8_t* string) {
    SMS_setNextTileatXY(tile_x, tile_y);

    uint8_t *c = string;

    do {
        uint16_t next_tile = (*c) | TEXT_ASCII_OFFSET_MASK;
        SMS_setTile(next_tile);
    } while (*++c);
}
