#include "../drivers/screen.h"

void main()
{
  char *video_memory = (char *) 0xb8000;

  
  *video_memory = 'X';

  print_char('Y', 0, 0, WHITE_ON_BLACK);
}