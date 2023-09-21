CC=arm-none-eabi-gcc
MARCH=cortex-m4
CFLAGS=-mthumb \
	-c\
	-mcpu=$(MARCH)\
	-std=gnu11\
	-O0
SOURCES= 	./led.c \
		./main.c

OBJS=$(SOURCES:.c=.o)

main.o:main.c
	$(CC) $(CFLAGS) $^ -o $@
# %.o:%.c
# 	$(CC) $(CFLAGS)
	
# ALL:$(OBJS)


