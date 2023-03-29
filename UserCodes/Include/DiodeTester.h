#ifndef __NUEDC_FIRMWARE_DIODE_TESTER_HEADER__
#define __NUEDC_FIRMWARE_DIODE_TESTER_HEADER__

#include <stdint.h>

void InitializeDiodeTester();
void DiodeTestServiceFunction(uint16_t maxOutVal);
void StopDiodeTester(void);

#endif