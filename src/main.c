

#include "main.h"
#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN (2)

#ifdef MOCK
    int     mock_portb;
    uint8_t mock_portc;
    # define LED_PORT mock_portb
    #define SHR_PORT  mock_portc
#else
    # define LED_PORT PORTB
    #define SHR_PORT PORTC
#endif

void setup_MCU(void)
{
    // setting up chip FUSEs:
    //TODO

    // Pinout setup:
    DDRB |= OUTPUT_PIN << LED_PIN;
    // shift register communication port:
    DDRC  = OUTPUT_PIN << PC_SHR_CLR    | OUTPUT_PIN << PC_SHR_CLK       |
            OUTPUT_PIN << PC_SHR_STRCLK | OUTPUT_PIN << PC_SHR_OUTENABLE |
            OUTPUT_PIN << PC_SHR_DATA   | INPUT_PIN  << PC_UNASSIGNED_6;

    // initialises PORTC to low outputs while setting PC6 to Hi-Z:
    PORTC = 0 << PC_UNASSIGNED_6;
}

void main(void)
{
    setup_MCU();

    while (EXECUTE_FOREVER)
    {
        LED_PORT ^= 1 << LED_PIN;
        _delay_ms(1000);
    }
}
