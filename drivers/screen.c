#include "screen.h"
#include "../include/types.h"


void print_char(uint8_t character, uint8_t col, uint8_t row,
		uint8_t attribute_byte)
{
    uint8_t *memory_video = (uint8_t *) VIDEO_ADDRESS;
   
    memory_video[(row * MAX_COLS) + col] = character; 

}
