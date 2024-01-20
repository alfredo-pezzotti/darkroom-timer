
#include "HAL_shiftReg.h"
#include "../main.h"


// internal defines for ports (a trailing underscore indicates a complemented
// signal!):
#define TX_PORT                 SHR_PORT        // uC port assigned to ShiftReg
#define SRCLR_                  SHR_CLR         // clears the SHR if pulled Low
#define SRCLK                   SHR_CLK         // shift register clock
#define RCLK                    SHR_STRCLK      // storage clock
#define OUT_ENABLE_             SHR_OUTENABLE   // H: disable outputs, L: enable
#define SER                     SHR_DATA        // input serial data

void HAL_SR_transmitDataToShiftRegisters(const uint8_t* txData, 
                                         int16_t        txDataLen)
{
    for (int16_t digit = 0; digit < txDataLen; digit++)
    {
        for (int8_t i = MSb; i >= 0; i--)
        {
            // sets state and wait:
            //NOTES: - SER needs to be populated 25ns before SCLK (id est,
            //         2 instructions @ 20MHz).
            //       - If RCLK is tied together with SRCLK, then it runs one
            //         clock pulse behind the SRCLK.

            TX_PORT = (txData[digit] & (1 << i)) << SER;
        }
    }
}
