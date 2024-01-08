

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

// setting up chip FUSEs:
//TODO: please see sect. 23.15 of avr-libc manual or sect 25.2 of datasheet!
FUSES =
{
    .low =  (FUSE_SUT1    & FUSE_CKSEL3  & FUSE_CKSEL2 & FUSE_CKSEL1 \
                          & FUSE_CKSEL0),
    .high = (FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_EESAVE & FUSE_SPIEN  \
                          & FUSE_RSTDISBL),
    // disables Brown-Out Detector:
    .extended = (FUSE_BODLEVEL2 & FUSE_BODLEVEL1 & FUSE_BODLEVEL0),
};
#endif


void setup_MCU_init(void)
{
    // PERIPHERALS SETUP

    // Watch Dog Timer flag is cleared:
    MCUSR &= ~(1 << WDRF);

    // Keeps old prescaler setting to prevent unintentional time-out (code
    // taken from atmega328P's datasheet, sect. 8.8.2):
    WDTCSR |= (1 << WDCE) | ( 1<< WDE);

    // finally, turns off the WDT:
    WDTCSR = 0x00u;

    // disables sleep mode by setting SE bit to 0 (along with everything else)
    // (cfr. sect. 7.11.1 of the ATMEGA328P's datasheet):
    SMCR = 0x00u;


    // PINOUT SETUP

    // portB
    DDRB |= OUTPUT_PIN << LED_PIN;

    // shift register communication portC:
    DDRC  = OUTPUT_PIN << PC_SHR_CLR    | OUTPUT_PIN << PC_SHR_CLK       |
            OUTPUT_PIN << PC_SHR_STRCLK | OUTPUT_PIN << PC_SHR_OUTENABLE |
            OUTPUT_PIN << PC_SHR_DATA   | INPUT_PIN  << PC_UNASSIGNED_6;

    // initialises PORTC to low outputs while setting PC6 to Hi-Z:
    PORTC = 0 << PC_UNASSIGNED_6;
}

void main(void)
{
    setup_MCU_init();

    while (EXECUTE_FOREVER)
    {
        LED_PORT ^= 1 << LED_PIN;
        _delay_ms(1000);
    }
}
