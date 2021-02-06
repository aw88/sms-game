#ifndef __DIALOG_H
#define __DIALOG_H

#include "SMSlib.h"
#include "stdint.h"

#define TEXT_ASCII_OFFSET_MASK 0x80

void write_string_at(uint8_t tile_x, uint8_t tile_y, uint8_t* string);

#endif
