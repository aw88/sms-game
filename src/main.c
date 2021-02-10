#include "stdint.h"
#include "SMSlib.h"
#include "vdp.h"
#include "title.h"
#include "overworld.h"
#include "../out/bank2.h"

#include "rom_header.h"

const uint8_t palette[] = {
    0x01, 0x3f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

void write_string_at(uint8_t tile_x, uint8_t tile_y, uint8_t* string);

void main(void) {
    VDP_clear_vram();

    SMS_loadBGPalette(palette);
    SMS_loadTiles(font, 0xA0, font_size);

    do_title();

    do_overworld();

    VDP_clear_vram();
    SMS_loadBGPalette(palette);
    SMS_loadTiles(font, 0xA0, font_size);
    write_string_at(10, 16, "Hello, world!");
    SMS_displayOn();

    for (;;) {
        SMS_waitForVBlank();
    }
}
