/*
*  link.ld
*/
OUTPUT_FORMAT(elf32-i386)
STARTUP(startup_kernel_c/kernel.o)
SECTIONS
{
  . = 0x1000;
 
   .text : { *(.text) }
   .data : { *(.data) }
   .bss  : { *(.bss)  }
}
