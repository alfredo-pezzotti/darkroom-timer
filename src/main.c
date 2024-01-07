

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

void main(void)
{
    // Pinout setup:
    DDRB |= 1 << LED_PIN;
    //DDRC |=

    while (EXECUTE_FOREVER)
    {
        LED_PORT ^= 1 << LED_PIN;
        _delay_ms(1000);
    }
}
