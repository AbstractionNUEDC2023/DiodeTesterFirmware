#include <adc.h>
#include <UserCommon.h>


uint16_t GetOverSamplingADCValue(ADC_HandleTypeDef* hadc) {
    uint32_t overSamplingResult = 0;
    for(uint16_t i = 0; i <= 255; i++) {
        HAL_ADC_Start(hadc);
        HAL_ADC_PollForConversion(hadc, 50);
        while(flags.adcConvCpltFlag == 0){
            flags.adcConvCpltFlag = HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc3), HAL_ADC_STATE_REG_EOC);
        }
        // Waiting for convert finish
        HAL_ADC_Stop(hadc);
        overSamplingResult = overSamplingResult + HAL_ADC_GetValue(hadc);
    }
    overSamplingResult = overSamplingResult >> 4;
    return overSamplingResult;
}