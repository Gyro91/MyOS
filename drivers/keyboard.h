
/* This library provides the drivers for using the keyboard */

#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#define NUM_CODES 29

#define REG_KEYBOARD_RBR 0x0060
#define REG_KEYBOARD_TBR 0x0060
#define REG_KEYBOARD_STR 0x0064
#define REG_KEYBOARD_CMR 0x0064

#define SHIFT_BREAK_CODE 0x2A
#define SHIFT_MAKE_CODE 0xAA

extern void keyboard_init();;
extern uint8_t read_char();

#endif
