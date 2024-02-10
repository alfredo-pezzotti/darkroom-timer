

#include "main.h"
#include "application/AL_TimeSet.h"
#include "util/buttons.h"
#include "hal/HAL_mcuSetup.h"
#include <avr/io.h>
#include <util/delay.h>


#ifdef MOCK
    int     mock_portb;
    uint8_t mock_portc;
#else
    // setting up chip FUSEs:
    //TODO: please see sect. 23.15 of avr-libc manual or sect 25.2 of datasheet!
    FUSES =
    {
        .low =  (FUSE_SUT1    & FUSE_CKSEL3  & FUSE_CKSEL2 & FUSE_CKSEL1 \
                              & FUSE_CKSEL0),   // 0b00101111 = 0x2F
        .high = (FUSE_BOOTSZ1 & FUSE_BOOTSZ0 & FUSE_EESAVE & FUSE_SPIEN  \
                              & FUSE_RSTDISBL), // 0b10101110 = 0xAE
        // disables Brown-Out Detector:
        .extended = (FUSE_BODLEVEL2 & FUSE_BODLEVEL1 & FUSE_BODLEVEL0),
                                                // 0b00000111 = 0x07
    };
#endif


void main(void)
{
    HAL_mcuSetup_init();

    // turns on the display:
    SHR_PORT = (OUT_HIGH << SHR_CLR);

    // DEBUG: turns off the debug pin:
    DEBUG_PORT &= ~((OUT_LOW << DEBUG_PIN1) | (OUT_LOW << DEBUG_PIN2));

    // main microcontroller loop:
    while (EXECUTE_FOREVER)
    {
        // reads input from PORTD, if any button is pressed, enters this if
        // (please remember that a pressed button is a LOW signal):
        if ((~TIMESET_PORT) & PD_INPUT_MASK)
        {
            button_pressed((~TIMESET_PORT) & PD_INPUT_MASK, Buttons_PORTD);
        }
        else
        {
            PORTB ^= (OUT_HIGH << DEBUG_PIN1);
            _delay_ms(500);
        }
    }
}
