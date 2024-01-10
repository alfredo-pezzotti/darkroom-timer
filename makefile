P=blinky
P_SIM=blinky_SIM
MOCKFLAG=-DMOCK
OBJECTS=src/main.o src/hal/HAL_mcuSetup.o
CFLAGS = -gdwarf-2 -g3 -DF_CPU=16000000UL -Os -mmcu=atmega328
LDLIBS=
CC=avr-gcc

$(P): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDLIBS) -o build/$(P) $(OBJECTS)

$(P_SIM): $(OBJECTS)
	$(CC) $(CFLAGS) $(MOCKFLAG) $(LDLIBS) -o build/$(P_SIM) $(OBJECTS)

clean: $(OBJECTS)
	rm src/*.o src/hal/*.o build/$(P) build/$(P_SIM)
