
#ifndef __PMIO_FUNC_H__
#define __PMIO_FUNC_H__

#include "..include/types.h"

/*
 * This library provides the basic functions for performing
 * port-mapped I/O operations between the CPU and peripheral
 * devices.
 *
 */


extern uint8_t port_byte_in(uint16_t port);
extern void port_byte_out(uint16_t port, uint8_t data);


extern uint16_t port_word_in(uint16_t port);
extern void port_word_out(uint16_t port, uint16_t data);

#endif
