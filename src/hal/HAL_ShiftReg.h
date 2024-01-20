#ifndef HAL_SHIFTREG_H
#define HAL_SHIFTREG_H

#include <stdint.h>


// prototypes:
void HAL_SR_transmitDataToShiftRegisters(const uint8_t* txData,
                                         int16_t        txDataLen);

#endif
