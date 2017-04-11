#include "../drivers/screen.h"
#include "../drivers/keyboard.h"

void main()
{
  uint8_t val;

  keyboard_init();

  clear_screen(RED_ON_BLACK);

  while (1) {
	  val = read_char();
	  print_char(val, 0, 0, RED_ON_BLACK);
  }
  while(1);
}
