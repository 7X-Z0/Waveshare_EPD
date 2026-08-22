#include "EPD.h"

uint8_t BD_FRAMEBUFFER[BD_FB_SIZE] = {0};

void bd_set_pixel (int x, int y, bool state){
    int pos = (BD_FB_WIDTH * y + x) >> 3; //bitshift 3 is the same as divided by 8

    if (state){
        BD_FRAMEBUFFER[pos] |= (0x80 >> (x & 0x7));
    } else {
        BD_FRAMEBUFFER[pos] &= ~(0x80 >> (x & 0x7));
    }
}