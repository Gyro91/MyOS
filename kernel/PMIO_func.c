#include "../include/types.h"

/*
 * A C wrapper function that reads a byte from the 
 * specified port.
 */

uint8_t port_byte_in(uint16_t port)
{
    uint8_t result;
    
    /*
     * "=a" (result) means: put AL register in var result
     * "d" (port) means: load EDX with port
     */
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));

    return result;
}


/*
 * A C wrapper function that writes a byte to the 
 * specified port.
 */

void port_byte_out(uint16_t port, uint8_t data)
{
    __asm__("out %%al, %%dx" : :"a" (data), "d" (port));
}


/*
 * A C wrapper function that reads a word from the 
 * specified port.
 */

uint16_t port_word_in(uint16_t port)
{
    uint16_t result;
    
    /*
     * "=a" (result) means: put AL register in var result
     * "d" (port) means: load EDX with port
     */
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));

    return result;
}


/*
 * A C wrapper function that writes a word to the 
 * specified port.
 */

void port_word_out(uint16_t port, uint16_t data)
{
    __asm__("out %%al, %%dx" : :"a" (data), "d" (port));
}
