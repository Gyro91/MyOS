#ifndef __SCREEN_H__
#define __SCREEN_H__

/* Video memory starts from VIDEO_ADDRESS */
#define VIDEO_ADDRESS 0xb8000

/* In text mode the VGA controller can be seen as a matrix 25x80. */
#define MAX_ROWS 25
#define MAX_COLS 80

/* Constants useful for printing on screen. */
#define WHITE_ON_BLACK 0x0f
#define RED_ON_BLACK 0x04
#define BLACK_ON_RED 0x40


/* In order to access the controller VGA, the IND reg is and index
 * for all the registers. The DATA register is used to r/w a data
 * in the register.
 * */
#define REG_SCREEN_IND 0x03D4
#define REG_SCREEN_DATA 0x03D5

/* The cursor position is stored in these two registers. In CURSOR_H
 * it is stored the most significant byte of the position and in
 * CURSOR_L the least significant byte. */
#define REG_SCREEN_CURSOR_H 0x0E
#define REG_SCREEN_CURSOR_L 0x0F

#include "../include/types.h"

extern void print_char(uint8_t c, uint8_t attribute_byte);
extern void clear_screen(uint8_t attribute_byte);
extern void set_cursor(uint16_t x, uint16_t y);
extern void screen_init();

typedef struct cursor {
	uint16_t row;
	uint16_t column;
} cursor;


#endif
