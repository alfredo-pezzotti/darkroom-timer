
#include "AL_TimeSet.h"
#include "../main.h"


// this is the time that has been set by the user via the input buttons,
// expressed in 1/100th of a second units:
uint32_t AL_TS_setTime;

// currently displayed time:
uint8_t AL_TS_currentTime[DISPLAY_NUMBER];

void AL_timeSetting(uint8_t pressedBtn)
{
    switch (pressedBtn)
    {
        case PD_BTN_INCMIN:
            // user is incrementing minutes by one unit:
            AL_TS_currentTime[DISPLAY_MINUTES] = 
                (AL_TS_currentTime[DISPLAY_MINUTES] + 1) % 60;
            break;
    }

    // sets the new time, displacing each unit by its equivalent amount in 
    // 1/100ths of a second:
    AL_TS_setTime = (AL_TS_currentTime[DISPLAY_MINUTES] * 6000) +
                    (AL_TS_currentTime[DISPLAY_SECONDS] * 100) +
                    (AL_TS_currentTime[DISPLAY_CENTS]);
}
