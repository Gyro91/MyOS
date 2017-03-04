HOME=/home/matteo
CC=$(HOME)/opt/cross/bin/i686-elf-gcc
LD=$(HOME)/opt/cross/bin/i686-elf-ld
OBJ=$(HOME)/opt/cross/bin/i686-elf-objcopy

all: kernel.bin boot_sect.bin
	cat boot_sect.bin kernel.bin > os-image

boot_sect.bin: 
		nasm boot_sect.asm -f bin -o boot_sect.bin

kernel.bin: kernel.elf
	$(OBJ) -O binary kernel.elf kernel.bin

kernel.elf: kernel.o 
	$(LD) -Ttext 0x1000 kernel.o -m elf_i386 -o kernel.elf
	$(OBJ) --remove-section=.comment --remove-section=.eh_frame kernel.elf kernel.elf

kernel.o: kernel.c
	$(CC) -ffreestanding -c kernel.c -o kernel.o -fno-exceptions
	
clean:
	rm *.bin *.o os-image
	
	
