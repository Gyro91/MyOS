#ifndef __SCREEN_H__
#define __SCREEN_H__

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

#define WHITE_ON_BLACK 0x0f
#define RED_ON_BLACK 0x04
#define BLACK_ON_RED 0x40

#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5
#include "../include/types.h"

extern void print_char(uint8_t c, uint8_t col, uint8_t row, uint8_t attribute_byte);
extern void clear_screen(uint8_t attribute_byte);

#endif
