#ifndef UTIL_7SEG_H
#define UTIL_7SEG_H

#include <stdint.h>

// digits:
#define UTIL_7SEG_0              0b11111100u
#define UTIL_7SEG_0_i            0b11111100u
#define UTIL_7SEG_1              0b01100000u
#define UTIL_7SEG_1_i            0b00001100u
#define UTIL_7SEG_2              0b11011010u
#define UTIL_7SEG_2_i            UTIL_7SEG_2
#define UTIL_7SEG_3              0b11110010u
#define UTIL_7SEG_3_i            0b10011110u
#define UTIL_7SEG_4              0b01100110u
#define UTIL_7SEG_4_i            0b00101110u
#define UTIL_7SEG_5              0b10110110u
#define UTIL_7SEG_5_i            UTIL_7SEG_5
#define UTIL_7SEG_6              0b10111110u
#define UTIL_7SEG_6_i            0b11110110u
#define UTIL_7SEG_7              0b11100000u
#define UTIL_7SEG_7_i            0b00011100u
#define UTIL_7SEG_8              0b11111110u
#define UTIL_7SEG_8_i            UTIL_7SEG_8
#define UTIL_7SEG_9              0b11110110u
#define UTIL_7SEG_9_i            0b10111110u

// return codes:
#define UTIL_7SEG_RC_OK          0xA5u
#define UTIL_7SEG_RC_INVALIDDATA 0xe8u
#define UTIL_7SEG_RC_FAIL        0x5Au

extern uint8_t UTIL_7SEG_displayedDigits[];

// prototypes:
void UTIL_7SEG_setDisplayDigits(const uint8_t* inputTimeDigits);

#endif
