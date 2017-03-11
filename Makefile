HOME=/home/matteo

CC=$(HOME)/opt/cross/bin/i686-elf-gcc
LD=$(HOME)/opt/cross/bin/i686-elf-ld
OBJ=$(HOME)/opt/cross/bin/i686-elf-objcopy

C_SOURCES = $(wildcard kernel/*.c drivers/*.c)
OBJ_FILES = ${C_SOURCES:.c=.o}

all: kernel.bin boot_sect.bin
	cat boot_sect.bin kernel.bin > os-image

boot_sect.bin: 
	nasm boot/boot_sect.asm -f bin -o boot_sect.bin

kernel.bin: kernel.elf
	$(OBJ) -O binary kernel.elf kernel.bin

kernel.elf: kernel.o 
	$(LD) -Ttext 0x1000 kernel.o -m elf_i386 -o kernel.elf
	$(OBJ) --remove-section=.comment --remove-section=.eh_frame kernel.elf kernel.elf

kernel.o: $(C_SOURCES)
	$(CC) -ffreestanding -c $< -o $@ -fno-exceptions

clean:
	rm *.bin *.o *.elf os-image

