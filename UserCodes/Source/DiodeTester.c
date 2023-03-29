#include <adc.h>
#include <dac.h>
#include <tim.h>
#include <main.h>
#include <ILI9341.h>
#include <DiodeTester.h>

void InitializeDiodeTester(){
    HAL_DAC_Start(&hdac, DAC_CHANNEL_2);
    HAL_ADC_Start(&hadc1);
    HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_L, 0);
    ILI9341DrawString(1, 5, "Status: Run ", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    ILI9341DrawString(1, 275, "VerticalGrid: 2.5uS/div           ", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    ILI9341DrawString(1, 263, "HorizontalGrid: 660mV/div         ", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    ILI9341DrawString(162, 5, "Mode: Test", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
}

void DiodeTestServiceFunction(uint16_t maxOutVal) {
    uint16_t step = 200 / maxOutVal, pointX, pointY;
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
    for(uint16_t i = 0; i < 200; i++) {
        HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_L, i*step);
        HAL_Delay(10);
        uint16_t adcVal = HAL_ADC_GetValue(&hadc1);
        pointX = 20 + i;
        pointY = 240 - ((200 / 4096) * adcVal);
        ILI9341DrawPixel(pointX, pointY, RGB565_GREEN);
    }
}

void StopDiodeTester(void) {
    HAL_DAC_Stop(&hdac, DAC_CHANNEL_2);
    HAL_ADC_Stop(&hadc1);
}