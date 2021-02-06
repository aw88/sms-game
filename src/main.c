#include "stdint.h"
#include "SMSlib.h"
#include "title.h"
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
    SMS_init();

    SMS_loadBGPalette(palette);
    SMS_loadTiles(font, 0xA0, font_size);

    do_title();

    SMS_VRAMmemset(0, 0, 0x4000);
    SMS_loadBGPalette(palette);
    SMS_loadTiles(font, 0xA0, font_size);
    write_string_at(10, 16, "Hello, world!");
    SMS_displayOn();

    for (;;) {
        SMS_waitForVBlank();
    }
}
