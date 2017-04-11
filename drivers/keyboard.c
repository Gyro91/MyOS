#include "../kernel/PMIO_func.h"
#include "keyboard.h"

/* Var that points out if the shift key is pressed */
uint8_t shift = 0;

/* List of key codes that has a match in position with the list of character
 * in chars_lowercase and chars_uppercase. 26 letters + SPACE, ENTER and ESC
 * keys.
 */
uint8_t list_codes[NUM_CODES] = { 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16,
		0x17, 0x18, 0x19, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25,
		0x26, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x39, 0x1C, 0x01 };

int8_t chars_lowercase[NUM_CODES] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i',
		'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c',
		'v', 'b', 'n', 'm', ' ', '\n', 0x1B };

int8_t chars_uppercase[NUM_CODES] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I',
		'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C',
		'V', 'B', 'N', 'M', ' ', '\n', 0x1B };


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
	uint8_t str_fi = 0, code;

	do {
		str_fi = port_byte_in(REG_KEYBOARD_STR);
	}
	while (!(str_fi & 0x01));

	code = port_byte_in(REG_KEYBOARD_RBR);

	return code;
}

/* This function converts from the keycode passed as parameter to the ascii code */

uint8_t conv_keycode_to_ascii(uint8_t keycode)
{
	uint8_t i;

	for (i = 0; i < NUM_CODES; i++) {
		if (list_codes[i] == keycode) {
			if (shift)
				return chars_uppercase[i];
			else
				return chars_lowercase[i];
		}
	}

	return 0;
}

/* This function reads a char from the keyboard and return it */

uint8_t read_char()
{
	uint8_t val_read;

	do {
		val_read = get_code();

		if (val_read == SHIFT_MAKE_CODE)
			shift = 1;
		if (val_read == SHIFT_BREAK_CODE)
			shift = 0;
	}
	while (val_read == SHIFT_MAKE_CODE ||
			val_read == SHIFT_BREAK_CODE);

	val_read = conv_keycode_to_ascii(val_read);

	return val_read;
}

