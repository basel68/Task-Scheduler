CC=arm-none-eabi-gcc
MARCH=cortex-m4
CFLAGS=-mthumb \
	-c\
	-mcpu=$(MARCH)\
	-std=gnu11\
	-O0 \
	-Wall
LFLAGS= -mcpu=$(MARCH) -mthumb -mfloat-abi=soft --specs=nano.specs -T Linker_Script.ld -Wl,-Map=final.map
LFLAGS_SH= -mcpu=$(MARCH) -mthumb -mfloat-abi=soft --specs=rdimon.specs -T Linker_Script.ld -Wl,-Map=final.map
SOURCES= 	./src/led.c \
		./src/main.c \
		./src/STM32_Startup.c\
		./src/syscalls.c


OBJS=$(SOURCES:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) $^
	
Compile-ALL:$(OBJS)
SH_exec.elf:$(OBJS)
	$(CC) $(LFLAGS_SH) $^ -o $@
Exec.elf:$(OBJS)
	$(CC) $(LFLAGS) $^ -o $@

clean:
	rm -rf *.o *.elf 
load:
	openocd -f board/stm32f4discovery.cfg 

