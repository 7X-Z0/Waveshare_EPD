#ifndef EPD_H
#define EPD_H

#include <stdint.h>
#include <stdbool.h>
#include <fonts.h>

#define EPD_FB_WIDTH 250
#define EPD_FB_HEIGHT 128 //Actual is 122

#define EPD_FB_SIZE (EPD_FB_WIDTH * EPD_FB_HEIGHT) / 8

//Taken from manufacture

//data

#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

// GPIO config

#define EPD_SCK_PIN  13
#define EPD_MOSI_PIN 14
#define EPD_CS_PIN   15
#define EPD_RST_PIN  26
#define EPD_DC_PIN   27
#define EPD_BUSY_PIN 25


//Enable it or not according to the actual hardware used, and the corresponding pin

#define D_9PIN  0
#if D_9PIN
    #define EPD_PWR_PIN 33
#endif


#define GPIO_PIN_SET   1
#define GPIO_PIN_RESET 0



#endif