#qemu-system-avr -S -s -nographic -machine uno -bios build/dtSIM
simavr --mcu atmega328p build/darkroom-timer
