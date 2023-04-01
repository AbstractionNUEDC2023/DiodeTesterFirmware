#include <adc.h>
#include <UserCommon.h>

Flags_t flags = { 0 };
uint32_t adcBuffer[200] = { 0 };

void OscillscopeInitialize(void) {
    flags.deviceRunFlag = 1;
    GUIUpdateStatus();
    HAL_ADC_Start(&hadc3);
}

void OscillscopeServiceFunction(void) {
    if(flags.deviceRunFlag) {
        for(uint8_t i = 0; i < 200; i++) {
            HAL_ADC_Start(&hadc3);
            HAL_ADC_PollForConversion(&hadc3, 50);
            while(flags.adcConvCpltFlag == 0){
                flags.adcConvCpltFlag = HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc3), HAL_ADC_STATE_REG_EOC);
            }
            adcBuffer[i] = HAL_ADC_GetValue(&hadc3);
            flags.adcConvCpltFlag = 0;
            HAL_ADC_Stop(&hadc3);
            adcBuffer[i] = ((float)(200.0 / 4096) * adcBuffer[i]);
        }
        GUIDrawCurveOnGrids(adcBuffer);
    }
}

void OscillscopeDeinitialize(void) {
    HAL_ADC_Stop(&hadc3);
}