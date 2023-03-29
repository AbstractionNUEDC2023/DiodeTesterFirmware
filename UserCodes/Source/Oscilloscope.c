#include <tim.h>
#include <Oscilloscope.h>
#include <UserInterface.h>

uint8_t timIntStart = 0;
uint16_t msTickStart = 0;
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
    ILI9341DrawString(1, 5, "Status: RUN ", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
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
        HAL_Delay(10);
        ILI9341FillRectangle(20, 40, 200, 200, RGB565_BLACK);
        ILI9341DrawLine(20, 40, 20, 240, RGB565_ORANGE);
        ILI9341DrawLine(20, 40, 220, 40, RGB565_ORANGE);
        ILI9341DrawLine(20, 240, 220, 240, RGB565_ORANGE);
        ILI9341DrawLine(220, 240, 220, 40, RGB565_ORANGE);
        ILI9341DrawLine(60, 40, 60, 240, RGB565_ORANGE);
        ILI9341DrawLine(100, 40, 100, 240, RGB565_ORANGE);
        ILI9341DrawLine(140, 40, 140, 240, RGB565_ORANGE);
        ILI9341DrawLine(180, 40, 180, 240, RGB565_ORANGE);
        ILI9341DrawLine(20, 80, 220, 80, RGB565_ORANGE);
        ILI9341DrawLine(20, 120, 220, 120, RGB565_ORANGE);
        ILI9341DrawLine(20, 160, 220, 160, RGB565_ORANGE);
        ILI9341DrawLine(20, 200, 220, 200, RGB565_ORANGE);
        // Partly Redraw GUI
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