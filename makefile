
P=blinky
OBJECTS=src/main.o
CFLAGS = -gdwarf-2 -g3 -DMOCK -DF_CPU=16000000UL -Os -mmcu=atmega328
LDLIBS=
CC=avr-gcc

$(P): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDLIBS) -o $(P) $(OBJECTS)
