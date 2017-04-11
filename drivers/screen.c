#include "screen.h"
#include "../kernel/PMIO_func.h"


/*
 * This function prints a character on screen in (row, col) coordinates
 * according with the byte attribute for the color passed.
 *
 */

void print_char(uint8_t character, uint8_t col, uint8_t row,
		uint8_t attribute_byte)
{
    uint16_t *memory_video = (uint16_t *) VIDEO_ADDRESS;
    uint16_t tmp_char = attribute_byte;

    /* In text mode the most significant byte defines the color
     * and the least significant is the character */
    tmp_char = tmp_char << 8;
    tmp_char |= character;
    memory_video[(row * MAX_COLS) + col] = tmp_char;
}

/*
 * This function clears the screen with all space characters
 * and the attribute_byte passed
 */

void clear_screen(uint8_t attribute_byte)
{
	uint16_t i, j, tmp_char = attribute_byte;;
	uint16_t *memory_video = (uint16_t *) VIDEO_ADDRESS;

	tmp_char |= ' ';
	for(i = 0; i < MAX_ROWS; i++)
		for(j = 0; j < MAX_COLS; j++) {
			memory_video[(i * MAX_COLS) + j] = tmp_char;
		}
}

/* It updates the cursor position with the passed parameters. */

void cursor(uint8_t x, uint8_t y)
{
	uint16_t position = (x * MAX_ROWS) + y;

	port_byte_out(REG_SCREEN_IND, REG_SCREEN_CURSOR_H);
	port_byte_out(REG_SCREEN_DATA, position >> 8);

	port_byte_out(REG_SCREEN_IND, REG_SCREEN_CURSOR_L);
	port_byte_out(REG_SCREEN_DATA, position);
}
