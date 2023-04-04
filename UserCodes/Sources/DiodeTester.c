#include <adc.h>
#include <dac.h>
#include <tim.h>
#include <UserCommon.h>

void DiodeTesterInitialize(void) {
    flags.deviceRunFlag = 1;
    GUIUpdateStatus();
    HAL_DAC_Start(&hdac, DAC_CHANNEL_2);
}

void DiodeTesterServiceFunction(void) {
    if(flags.deviceRunFlag) {
        HAL_TIM_Base_Start_IT(&htim6);
        for(uint8_t i = 0; i < 200; i++) {
            while(flags.dacConvCpltFlag == 0);
            HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, 20 * i);
            while(HAL_IS_BIT_SET(HAL_DAC_GetState(&hdac), HAL_DAC_STATE_BUSY));
            adcBuffer[i] = GetOverSamplingADCValue(&hadc3);
            flags.adcConvCpltFlag = 0;
            adcBuffer[i] = ((float)(200.0 / 65535) * adcBuffer[i]);
        }
        HAL_TIM_Base_Stop_IT(&htim6);
        GUIDrawCurveOnGrids(adcBuffer);
        flags.deviceRunFlag = 0;
        GUIUpdateStatus();
    }
}

void DiodeTesterDeinitialize(void) {
    HAL_DAC_Stop(&hdac, DAC_CHANNEL_2);
    HAL_ADC_Stop(&hadc3);
    HAL_TIM_Base_Stop_IT(&htim6);
}