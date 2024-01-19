
#include "HAL_shiftReg.h"
#include "../main.h"


// internal defines for ports:
#define TX_PORT                 SHIFTREG_PORT
#define CLR                     PC_SHR_CLR
#define CLK                     PC_SHR_CLK
#define STRCLK                  PC_SHR_STRCLK
#define OUT_ENABLE              PC_SHR_OUTENABLE
#define DATA                    PC_SHR_DATA

void HAL_SR_transmitDataToShiftRegisters(const uint8_t* txData, int16_t txDataLen)
{
    for (int16_t digit = 0; digit < txDataLen; digit++)
    {
        for (char i = 0; i < BYTE_BITS; i++)
        {
            //TODO: sets state and wait:
        }
    }
}
