

#include "main.h"
#include "application/AL_TimeSet.h"
#include "hal/HAL_mcuSetup.h"
#include <avr/io.h>
#include <util/delay.h>


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
    .high = (FUSE_BOOTSZ1 & FUSE_BOOTSZ0 & FUSE_EESAVE & FUSE_SPIEN  \
                          & FUSE_RSTDISBL),
    // disables Brown-Out Detector:
    .extended = (FUSE_BODLEVEL2 & FUSE_BODLEVEL1 & FUSE_BODLEVEL0),
};
#endif


void main(void)
{
    HAL_mcuSetup_init();

    // main microcontroller loop:
    while (EXECUTE_FOREVER)
    {
        // reads input from PORTD:
        switch (TIMESET_PORT & PD_INPUT_MASK)
        {
            case (BUTTON_PRESSED << PD_BTN_INCMIN):
                AL_timeSetting(PD_BTN_INCMIN);
                break;
        }

        LED_PORT ^= 1 << LED_PIN;
        _delay_ms(1000);
    }
}
