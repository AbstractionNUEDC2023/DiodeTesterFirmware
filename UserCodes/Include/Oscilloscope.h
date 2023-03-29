#ifndef __NUEDC_FIRMWARE_DIODE_TESTER_OSCILLOSCOPE_HEADER__
#define __NUEDC_FIRMWARE_DIODE_TESTER_OSCILLOSCOPE_HEADER__

#include <adc.h>
#include <main.h>
#include <stm32f4xx_hal.h>

void InitializeOscilloscope(void);
void OscilloscopeServiceFunction(void);
void StopOscilloscope(void);

#endif