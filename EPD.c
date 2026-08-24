#include "EPD.h"

uint8_t EPD_FRAMEBUFFER[EPD_FB_SIZE] = {0};

void epd_set_pixel (int x, int y, bool state){
    int pos = (EPD_FB_WIDTH * y + x) >> 3; //bitshift 3 is the same as divided by 8

    if (state){
        EPD_FRAMEBUFFER[pos] |= (0x80 >> (x & 0x7));
    } else {
        EPD_FRAMEBUFFER[pos] &= ~(0x80 >> (x & 0x7));
    }
}

bool epd_get_pixel (int x, int y){
    int pos = (EPD_FB_WIDTH * y + x) >> 3; //bitshift 3 is the same as divided by 8

    return EPD_FRAMEBUFFER[pos] & (0x80 >> (x & 0x7));
}

void epd_draw_bitmap(int x, int y, int width, int height, const uint8_t *bitmap){
    uint8_t chkMsk = 0;
    int size = width * height;

    int originalX = x;
    int originalY = y;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < 8; j++){
            chkMsk = 0x80 >> j;

            epd_set_pixel(x, y, bitmap[i] & chkMsk);
            x++;

            if ((x - originalX) == width){
                x = originalX;
                y++;
            }

            if ((y - originalY) == height){
                return;
            }

            if (y > EPD_FB_HEIGHT){
                return;
            }
        }
    }
}

void epd_draw_text(int x, int y, int size, char *text){
    const uint8_t *font;
    const uint8_t *drawChar;

    int runningX = x;
    int runningY = y;

    int target;
    
    switch (size){
        case 16:
        default:
            font = Terminus16;
    }
    for (int i = 0; i < strlen(text); i++){
        
        if (runningX >= EPD_FB_WIDTH){

            runningX = x;
            runningY += size;
        }

        if (runningY >= EPD_FB_HEIGHT){
            return;
        }
        
        target = (size*size >> 3) * (text[i] - ' ');
        drawChar = font + target;

        epd_draw_bitmap(runningX, runningY, size, size, drawChar);
        runningX += size;
    }

}