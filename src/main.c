#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN (2)

#ifdef MOCK
int mock_portb;
# define LED_PORT mock_portb
#else
# define LED_PORT PORTB
#endif

int main(void)
{
    DDRB |= 1 << LED_PIN;
    while (1) {
        LED_PORT ^= 1 << LED_PIN;
        _delay_ms(1000);
    }
}
