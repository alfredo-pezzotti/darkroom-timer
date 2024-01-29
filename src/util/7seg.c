
#include "7seg.h"
#include "../main.h"


uint8_t UTIL_7SEG_displayedDigits[DISPLAY_DIGITS];

// the i-th element of this array contains the mapping that would display
// "i" on an upright 7 segment common cathode display:
static const uint8_t UTIL_7SEG_straightDigits[] =
{
    UTIL_7SEG_0,
    UTIL_7SEG_1,
    UTIL_7SEG_2,
    UTIL_7SEG_3,
    UTIL_7SEG_4,
    UTIL_7SEG_5,
    UTIL_7SEG_6,
    UTIL_7SEG_7,
    UTIL_7SEG_8,
    UTIL_7SEG_9
};

// the i-th element of this array contains the mapping that would display
// "i" on an upside down 7 segment common cathode display:
static const uint8_t UTIL_7SEG_invertedDigits[] =
{
    UTIL_7SEG_0_i,
    UTIL_7SEG_1_i,
    UTIL_7SEG_2_i,
    UTIL_7SEG_3_i,
    UTIL_7SEG_4_i,
    UTIL_7SEG_5_i,
    UTIL_7SEG_6_i,
    UTIL_7SEG_7_i,
    UTIL_7SEG_8_i,
    UTIL_7SEG_9_i
};

// this array will map the digits contituting a decimal number < 10^2 to the
// correct mapping that is stored in the UTIL_7SEG_*Digits arrays:
static const uint8_t* UTIL_7SEG_mapperArray[] =
{
    UTIL_7SEG_invertedDigits,
    UTIL_7SEG_straightDigits
};

/*!
This function sets the "framebuffer" in UTIL_7SEG_displayedDigits, in order to
enable the user to call HAL_SR_transmitDataToShiftRegisters() so as to display
the inputTimeDigits' contents on the physical display.

param[in] inputTimeDigits
A buffer of size DISPLAY_DIGITS_PER_VAL containing the MINUTES, SECONDS and
CENTS values.
*/
void UTIL_7SEG_setDisplayDigits(const uint8_t* inputTimeDigits)
{
    uint8_t powerOf10_digits[DISPLAY_DIGITS_PER_VAL];

    // i iterates over the MINUTES, SECONDS, CENTS displays:
    for (int8_t i = 0; i < DISPLAY_NUMBER; i++)
    {
        // gets the first power of 10 digit:
        powerOf10_digits[0] =
                        (inputTimeDigits[i] - (inputTimeDigits[i] % 10)) / 10;

        // gets the unit:
        powerOf10_digits[1] =  inputTimeDigits[i] % 10;

        // j iterates over the digits of each displayed value (typically, 2):
        for (int8_t j = 0; j < DISPLAY_DIGITS_PER_VAL; j++)
        {
            //TODO: dude, really, document this crap...
            // each "character" in the framebuffer is populated as per input
            // value (the digit, as taken from powerOf10_digits, that is mapped
            // to the correct UTIL_7SEG_mapperArray's element):
            UTIL_7SEG_displayedDigits[(i * DISPLAY_DIGITS_PER_VAL) + j] =
                               UTIL_7SEG_mapperArray[j][(powerOf10_digits[j])];
        }
    }
}
