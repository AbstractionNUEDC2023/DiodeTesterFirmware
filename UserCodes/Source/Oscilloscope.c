#include <Oscilloscope.h>
#include <UserInterface.h>

uint8_t adcSampleFinishFlag = 0;
volatile uint32_t adcBuffer[200];

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc){
    adcSampleFinishFlag = 1;
}
/**
 * @brief Initializes the ADC And Oscilloscope GUI
 * 
 * @return None
 */
void InitializeOscilloscope(){
    ILI9341DrawString(1, 5, "Status: Run ", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    ILI9341DrawString(1, 275, "VerticalGrid: 2.5uS/div           ", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    ILI9341DrawString(1, 263, "HorizontalGrid: 660mV/div         ", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adcBuffer, 200);
    // Start DMA Sampling
}
/**
 * @brief Service Function Of Oscilloscope, Make sure this function is called on infinite loop in main function
 * 
 * @return None
 */
void OscilloscopeServiceFunction(void) {
    if(adcSampleFinishFlag ==1) {
        HAL_ADC_Stop_DMA(&hadc1);
        for(uint8_t i = 0; i < 200; i++) {
            uint16_t pointX, pointY = 0;
            pointX = 20 + i;
            pointY = 240 - ((200 / 4096) * adcBuffer[i]);
            ILI9341DrawPixel(pointX, pointY, RGB565_GREEN);
        }
        HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adcBuffer, 200);
        adcSampleFinishFlag = 0;
    }
}
/**
 * @brief Stop Oscilloscope
 * 
 * @return None
 */
void StopOscilloscope(void){
    HAL_ADC_Stop_DMA(&hadc1);
}