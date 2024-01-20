
#include "HAL_shiftReg.h"
#include "../main.h"


// internal defines for ports (a trailing underscore indicates a complemented
// signal!):
#define TX_PORT                 SHR_PORT
#define SRCLR_                  SHR_CLR
#define SRCLK                   SHR_CLK
#define RCLK                    SHR_STRCLK
#define OUT_ENABLE_             SHR_OUTENABLE
#define SER                     SHR_DATA

void HAL_SR_transmitDataToShiftRegisters(const uint8_t* txData, 
                                         int16_t        txDataLen)
{
    for (int16_t digit = 0; digit < txDataLen; digit++)
    {
        for (char i = 0; i < BYTE_BITS; i++)
        {
            // sets state and wait:
            //NOTES: - SER needs to be populated 25ns before SCLK (id est,
            //         2 instructions @ 20MHz).
            //       - If RCLK is tied together with SRCLK, then it runs one
            //         clock pulse behind the SRCLK.
        }
    }
}
