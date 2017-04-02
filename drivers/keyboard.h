
/* This library provides the drivers for using the keyboard */

#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__


#define REG_KEYBOARD_RBR 0x0060
#define REG_KEYBOARD_TBR 0x0060
#define REG_KEYBOARD_STR 0x0064
#define REG_KEYBOARD_CMR 0x0064

extern void keyboard_init();
extern uint8_t get_code();

#endif
