
#include "7seg.h"
#include "../main.h"


uint8_t 7SEG_displayedDigits[DISPLAY_DIGITS];

static const uint8_t 7SEG_straightDigits[] =
{
    7SEG_0,
    7SEG_1,
    7SEG_2,
    7SEG_3,
    7SEG_4,
    7SEG_5,
    7SEG_6,
    7SEG_7,
    7SEG_8,
    7SEG_9
};

static const uint8_t 7SEG_invertedDigits[] =
{
    7SEG_0_i,
    7SEG_1_i,
    7SEG_2_i,
    7SEG_3_i,
    7SEG_4_i,
    7SEG_5_i,
    7SEG_6_i,
    7SEG_7_i,
    7SEG_8_i,
    7SEG_9_i
};

static const uint8_t* 7SEG_mapperArray[] =
{
    7SEG_invertedDigits,
    7SEG_straightDigits
};

uint8_t 7SEG_setDisplayDigits(const uint8_t* inputTimeDigits)
{
    uint8_t rc = 7SEG_RC_FAIL;
    uint8_t powerOf10_digits[DISPLAY_DIGITS_PER_VAL];

    for (char i = 0; i < DISPLAY_NUMBER; i++)
    {
        // gets the first power of 10 digit:
        powerOf10_digits[0] = (inputTimeDigits[i] - (inputTimeDigits[i] % 10)) / 10;

        // gets the unit:
        powerOf10_digits[1] =  inputTimeDigits[i] % 10;

        for (char j = 0; j < DISPLAY_DIGITS_PER_VAL; j++)
        {
            7SEG_displayedDigits[(i * DISPLAY_DIGITS_PER_VAL) + j] =
                                                        7SEG_mapperArray[j][(powerOf10_digits[j])];
        }
    }
    return rc;
}
