
#include "buttons.h"
#include "../application/AL_TimeSet.h"
#include "../main.h"
#include <avr/io.h>
#include <util/delay.h>


uint8_t button_getPortStatus(uint8_t activePort)
{
    uint8_t portStatus = 0;

    switch (activePort)
    {
        case Buttons_PORTD:
            portStatus = PIND & PD_INPUT_MASK;
            break;
    }

    return portStatus;
}

void button_pressed(uint8_t pressedBtn, uint8_t activePort)
{
    bool firstPress = true;

    // this loop goes on as long as the button is pressed:
    do
    {
        if (activePort == Buttons_PORTD)
        {
            switch (pressedBtn)
            {
                case (BUTTON_PRESSED << PD_BTN_INCMIN):
                    // this button requires times setting:
                    AL_timeSetting(PD_BTN_INCMIN);
                    break;
            }
        }

        // reads again pressedBtn's status after 250ms, to see whether user is
        // holding the button pressed:
        //TODO: consider moving this to PORTD case, as the other buttons require
        //      a different handling!
        if (firstPress)
        {
            _delay_ms(200);
            firstPress = false;
        }

        _delay_ms(50);
        pressedBtn = button_getPortStatus(activePort);
    } while (pressedBtn);
}
