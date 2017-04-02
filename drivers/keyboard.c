#include "../kernel/PMIO_func.h"
#include "keyboard.h"

/* This function initializes the keyboard writing 0x60 in CMR and then 0x60
 * in TBR. When it is written 0x60 in CMR the data in TBR has the following
 * meaning:
 *
 * bit7: must be 0 (needed to control the mouse)
 * bit6: Keyboard Translate Mode, it converts (1) or not (0) the scan code
 * 		 in DOS code
 * bit5: must be 1 (needed to control the mouse)
 * bit4: It disables (1) or not (0) the keyboard
 * bit1-3: They must be zero.
 * bit0: It enables (1) or not (1) the interface to generate an interrupt
 *
 * */


void keyboard_init()
{
	port_byte_out(REG_KEYBOARD_CMR, 0x60);
	port_byte_out(REG_KEYBOARD_TBR, 0x60);
}


/* This function loops reading STR until FI = 1, then it reads RBR
 * for the code and returns it. */

uint8_t get_code()
{
	uint8_t str_fi = 0;
	uint8_t code;

	do {
		str_fi = port_byte_in(REG_KEYBOARD_STR);
	}
	while (!(str_fi & 0x01));

	code = port_byte_in(REG_KEYBOARD_RBR);

	return code;
}


