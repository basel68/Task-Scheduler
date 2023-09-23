CC=arm-none-eabi-gcc
MARCH=cortex-m4
CFLAGS=-mthumb \
	-c\
	-mcpu=$(MARCH)\
	-std=gnu11\
	-O0 \
	-Wall
LFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T stm32_ls.ld -Wl,-Map=final.map
LFLAGS_SH= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=rdimon.specs -T stm32_ls.ld -Wl,-Map=final.map
SOURCES= 	./led.c \
		./main.c \
		./STM32_Startup.c\
		./syscalls.c

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

