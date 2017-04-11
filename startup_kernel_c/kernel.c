#include "../drivers/screen.h"
#include "../drivers/keyboard.h"

void main()
{
  uint8_t val;

  keyboard_init();
  screen_init();

  while (1) {
	  val = read_char();
	  print_char(val, RED_ON_BLACK);
  }
  while(1);
}
