CC=arm-none-eabi-gcc
MARCH=cortex-m4
CFLAGS=-mthumb \
	-c\
	-mcpu=$(MARCH)\
	-std=gnu11\
	-O0 \
	-Wall
LFLAGS= -nostdlib -T Linker_Script.ld -Wl,-Map=final.map
SOURCES= 	./led.c \
		./main.c \
		./STM32_Startup.c

OBJS=$(SOURCES:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) $^
	
Compile-ALL:$(OBJS)
Exec.elf:$(OBJS)
	$(CC) $(LFLAGS) $^ -o $@

clean:
	rm -rf *.o *.elf 


