P=darkroom-timer
P_SIM=dtSIM
P_FLASH=BURN
P_DEBUG=timer-debug
P_FLASH_DEBUG=BURN_DEBUG
MOCKFLAG=-DMOCK=0xA5
DEBUG_FLAG=-DDEBUG
TARGET_MCU=atmega328p
TARGET_PROGRAMMER=usbasp-clone
OBJECTS=src/main.o \
        src/hal/HAL_mcuSetup.o src/hal/HAL_ShiftReg.o\
        src/application/AL_TimeSet.o \
        src/util/buttons.o src/util/7seg.o
DFLAGS= -gdwarf-2 -g3
CFLAGS= -DF_CPU=20000001UL -Os -mmcu=$(TARGET_MCU)
MAPFILE= -Xlinker -Map=build/$(P).map
LDLIBS=
CC=avr-gcc

$(P): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDLIBS) $(MAPFILE) -o build/$(P) $(OBJECTS)

$(P_SIM): $(OBJECTS)
	$(CC) $(DFLAGS) $(CFLAGS) $(MOCKFLAG) $(LDLIBS) -o build/$(P_SIM) \
    $(OBJECTS)

$(P_DEBUG): $(OBJECTS)
	$(CC) $(DFLAGS) $(CFLAGS) $(DEBUG_FLAG) $(LDLIBS) -o build/$(P_DEBUG) \
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
