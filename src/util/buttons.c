
#include "buttons.h"
#include "../application/AL_TimeSet.h"
#include "../main.h"
#include <util/delay.h>


void button_pressed(uint8_t pressedBtn)
{
    switch (pressedBtn)
    {
        case (BUTTON_PRESSED << PD_BTN_INCMIN):
            AL_timeSetting(PD_BTN_INCMIN);
            break;
    }
}
