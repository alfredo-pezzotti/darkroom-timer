

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
    // Pinout setup:
    DDRB |= OUTPUT_PIN << LED_PIN;
    // shift register communication port:
    DDRC = OUTPUT_PIN << PC_SHR_CLR    | OUTPUT_PIN << PC_SHR_CLK       |
           OUTPUT_PIN << PC_SHR_STRCLK | OUTPUT_PIN << PC_SHR_OUTENABLE |
           OUTPUT_PIN << PC_SHR_DATA;
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
