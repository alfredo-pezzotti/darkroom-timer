P=blinky
P_SIM=blinky_SIM
MOCKFLAG=-DMOCK
OBJECTS=src/main.o \
        src/hal/HAL_mcuSetup.o src/hal/HAL_ShiftReg.o\
        src/application/AL_TimeSet.o \
        src/util/buttons.o src/util/7seg.o
CFLAGS = -gdwarf-2 -g3 -DF_CPU=20000000UL -Os -mmcu=atmega328
LDLIBS=
CC=avr-gcc

$(P): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDLIBS) -o build/$(P) $(OBJECTS)

$(P_SIM): $(OBJECTS)
	$(CC) $(CFLAGS) $(MOCKFLAG) $(LDLIBS) -o build/$(P_SIM) $(OBJECTS)

clean: $(OBJECTS)
	rm src/*.o src/application/*o src/hal/*.o src/util/*.o \
    build/$(P) build/$(P_SIM) 2> /dev/null || true
