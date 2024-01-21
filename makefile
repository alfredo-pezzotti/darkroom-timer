P=darkroom-timer
P_SIM=dtSIM
MOCKFLAG=-DMOCK=0xA5
OBJECTS=src/main.o \
        src/hal/HAL_mcuSetup.o src/hal/HAL_ShiftReg.o\
        src/application/AL_TimeSet.o \
        src/util/buttons.o src/util/7seg.o
DFLAGS= -gdwarf-2 -g3
CFLAGS= -DF_CPU=20000001UL -Os -mmcu=atmega328p
MAPFILE= -Xlinker -Map=build/$(P).map
LDLIBS=
CC=avr-gcc

$(P): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDLIBS) $(MAPFILE) -o build/$(P) $(OBJECTS)

$(P_SIM): $(OBJECTS)
	$(CC) $(DFLAGS) $(CFLAGS) $(MOCKFLAG) $(LDLIBS) -o build/$(P_SIM) $(OBJECTS)

clean: $(OBJECTS)
	rm src/*.o src/application/*o src/hal/*.o src/util/*.o \
    build/$(P) build/$(P_SIM) build/*.map 2> /dev/null || true
