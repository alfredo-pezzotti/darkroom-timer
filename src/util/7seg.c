
#include "7seg.h"
#include "../main.h"


uint8_t UTIL_7SEG_displayedDigits[DISPLAY_DIGITS];

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

static const uint8_t* UTIL_7SEG_mapperArray[] =
{
    UTIL_7SEG_invertedDigits,
    UTIL_7SEG_straightDigits
};

void UTIL_7SEG_setDisplayDigits(const uint8_t* inputTimeDigits)
{
    uint8_t powerOf10_digits[DISPLAY_DIGITS_PER_VAL];

    for (char i = 0; i < DISPLAY_NUMBER; i++)
    {
        // gets the first power of 10 digit:
        powerOf10_digits[0] = 
                        (inputTimeDigits[i] - (inputTimeDigits[i] % 10)) / 10;

        // gets the unit:
        powerOf10_digits[1] =  inputTimeDigits[i] % 10;

        for (char j = 0; j < DISPLAY_DIGITS_PER_VAL; j++)
        {
            UTIL_7SEG_displayedDigits[(i * DISPLAY_DIGITS_PER_VAL) + j] =
                               UTIL_7SEG_mapperArray[j][(powerOf10_digits[j])];
        }
    }
}
