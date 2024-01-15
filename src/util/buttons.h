#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdint.h>


// defines:
#define Buttons_PORTB               0xA5
#define Buttons_PORTD               0x5A

// prototypes:
void button_pressed(uint8_t pressedBtn, uint8_t activePort);

#endif
