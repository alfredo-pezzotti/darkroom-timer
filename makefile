P=darkroomtimer
P_O=darkroomtimer_o
P_SIM=dtSIM
P_FLASH=BURN
P_DEBUG=timerdebug
P_DEBUG_O=timerdebug_o
P_FLASH_DEBUG=BURN_DEBUG
MOCKFLAG=-DMOCK=0xA5
#DEBUG_FLAG= -DDEBUG_FLAG
TARGET_MCU=atmega328p
TARGET_PROGRAMMER=usbasp-clone
SOURCES=src/main.c \
        src/hal/HAL_mcuSetup.c src/hal/HAL_ShiftReg.c\
        src/application/AL_TimeSet.c \
        src/util/buttons.c src/util/7seg.c
OBJECTS=src/main.o \
        src/hal/HAL_mcuSetup.o src/hal/HAL_ShiftReg.o\
        src/application/AL_TimeSet.o \
        src/util/buttons.o src/util/7seg.o
DFLAGS= -gdwarf-2 -g3 -DDEBUG_FLAG -DF_CPU=20000000UL -O0 -mmcu=$(TARGET_MCU)
CFLAGS= -DF_CPU=20000000UL -Os -mmcu=$(TARGET_MCU)
MAPFILE= -Xlinker -Map=build/$(P).map
LDLIBS=
CC=avr-gcc

$(P): $(OBJECTS) $(P_O)
	$(CC) $(LDLIBS) $(MAPFILE) -o build/$(P) $(OBJECTS)

$(P_O): $(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)

$(P_DEBUG): $(OBJECTS) $(P_DEBUG_O)
	$(CC) $(LDLIBS) -o build/$(P_DEBUG) $(OBJECTS)

$(P_DEBUG_O): $(SOURCES)
	$(CC) $(DFLAGS) -c $(DEBUG_FLAG) $(SOURCES)

$(P_SIM): $(OBJECTS)
	$(CC) $(DFLAGS) $(CFLAGS) $(MOCKFLAG) $(LDLIBS) -o build/$(P_SIM) \
    $(OBJECTS)

$(P_FLASH):
	avrdude -B 125khz -p $(TARGET_MCU) -P usb -c $(TARGET_PROGRAMMER) \
    -U flash:w:build/$(P):e -v -F
    # -U efuse:w:0x07:m -U hfuse:w:0xae:m -U lfuse:w:0x2f:m

$(P_FLASH_DEBUG):
	avrdude -B 125khz -p $(TARGET_MCU) -P usb -c $(TARGET_PROGRAMMER) \
    -U flash:w:build/$(P_DEBUG):e -v -F


clean: $(OBJECTS)
	rm src/*.o src/application/*o src/hal/*.o src/util/*.o \
    build/$(P) build/$(P_SIM) build/$(P_DEBUG) build/*.map 2> /dev/null || true
