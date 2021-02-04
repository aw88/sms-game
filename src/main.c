#include "SMSlib.h"

#include "rom_header.h"

void main(void) {
    SMS_init();

    SMS_displayOn();

    for(;;) {
        SMS_waitForVBlank();
    }
}
