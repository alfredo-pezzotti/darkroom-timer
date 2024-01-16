#ifndef 7SEG_H
#define 7SEG_H


// digits:
#define 7SEG_0              0b11111100u
#define 7SEG_0_i            0b11111100u
#define 7SEG_1              0b01100000u
#define 7SEG_1_i            0b00001100u
#define 7SEG_2              0b11011010u
#define 7SEG_2_i            7SEG_2
#define 7SEG_3              0b11110010u
#define 7SEG_3_i            0b10011110u
#define 7SEG_4              0b01100110u
#define 7SEG_4_i            0b00101110u
#define 7SEG_5              0b10110110u
#define 7SEG_5_i            7SEG_5
#define 7SEG_6              0b10111110u
#define 7SEG_6_i            0b11110110u
#define 7SEG_7              0b11100000u
#define 7SEG_7_i            0b00011100u
#define 7SEG_8              0b11111110u
#define 7SEG_8_i            7SEG_8
#define 7SEG_9              0b11110110u
#define 7SEG_9_i            0b10111110u

// return codes:
#define 7SEG_RC_OK          0xA5u
#define 7SEG_RC_INVALIDDATA 0xe8u
#define 7SEG_RC_FAIL        0x5Au

extern uint8_t HAL_SR_displayedDigits[];
#endif
