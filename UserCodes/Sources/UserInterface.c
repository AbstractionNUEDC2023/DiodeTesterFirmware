#include <stdint.h>
#include <ILI9341.h>
#include <UserCommon.h>
#include "Fonts/fonts.h"
#include "stm32f4xx_hal_pwr.h"

uint8_t currentCurveArray[200] = { 0 };

void GUIInitialize(void) {
    ILI9341Initialize();
    ILI9341FillScreen(RGB565_BLACK);
    // Background color
    ILI9341FillRectangle(0, 0, 240, 20, RGB565_ORANGE);
    ILI9341DrawString(8, 5, "Status:STOP", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    ILI9341DrawString(93, 5, "VREF:3.3V", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    ILI9341DrawString(163, 5, "Mode:Wave", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    // Top Status Bar
    ILI9341FillRectangle(0, 260, 240, 60, RGB565_ORANGE);
    ILI9341DrawString(1, 265, "HorizontalGrid: 660mV/div", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    ILI9341DrawString(1, 277, "VerticalGrid: 2.5uS/div", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    ILI9341DrawString(1, 302, "@Abstraction", Font_11x18, RGB565_PINK, RGB565_ORANGE);
    // Buttom Status Bar
    ILI9341DrawLine(20, 40, 20, 240, RGB565_ORANGE);
    ILI9341DrawLine(60, 40, 60, 240, RGB565_ORANGE);
    ILI9341DrawLine(100, 40, 100, 240, RGB565_ORANGE);
    ILI9341DrawLine(140, 40, 140, 240, RGB565_ORANGE);
    ILI9341DrawLine(180, 40, 180, 240, RGB565_ORANGE);
    ILI9341DrawLine(220, 40, 220, 240, RGB565_ORANGE);
    ILI9341DrawLine(20, 40, 220, 40, RGB565_ORANGE);
    ILI9341DrawLine(20, 80, 220, 80, RGB565_ORANGE);
    ILI9341DrawLine(20, 120, 220, 120, RGB565_ORANGE);
    ILI9341DrawLine(20, 160, 220, 160, RGB565_ORANGE);
    ILI9341DrawLine(20, 200, 220, 200, RGB565_ORANGE);
    ILI9341DrawLine(20, 240, 220, 240, RGB565_ORANGE);
    // Grids
}

void GUIUpdateStatus(void) {
    if(flags.deviceRunFlag) {
        ILI9341DrawString(8, 5, "Status:RUN ", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
        // DO NOT Delete space, it may cause last P of STOP stays on the screen
    } else {
        ILI9341DrawString(8, 5, "Status:STOP", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    }
    if(flags.deviceModeFlag) {
        ILI9341DrawString(163, 5, "Mode:Test", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    } else {
        ILI9341DrawString(163, 5, "Mode:Wave", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    }
}

void GUIUpdateGrid(const char* HorizontalGridText, uint16_t HorizontalGridTextLength,
                    const char* VerticalGridText, uint16_t VerticalGridTextLength){
    ILI9341FillRectangle(0, 260, 240, 60, RGB565_ORANGE);
    ILI9341DrawString(1, 265, HorizontalGridText, Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    ILI9341DrawString(1, 277, VerticalGridText, Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    ILI9341DrawString(1, 302, "@Abstraction", Font_11x18, RGB565_PINK, RGB565_ORANGE);
}

void GUIDrawCurveOnGrids(uint32_t *PointsYArray) {
    uint16_t fillColor;
    for(uint8_t i = 0; i < 200; i++){
        fillColor = RGB565_BLACK;
        if(i == 0 || i == 40 || i == 80 || i == 120 || i == 160 || i == 200
            || currentCurveArray[i] == 0 
            || currentCurveArray[i] == 40
            || currentCurveArray[i] == 80
            || currentCurveArray[i] == 120
            || currentCurveArray[i] == 160
            || currentCurveArray[i] == 200) {
                fillColor = RGB565_ORANGE;
            }
        ILI9341DrawPixel(i + 20, 240 - currentCurveArray[i], fillColor);
        currentCurveArray[i] = PointsYArray[i];
        ILI9341DrawPixel(i + 20, 240 - currentCurveArray[i], RGB565_GREEN);
    }
    // Clear Last Curve And Draw New Curve
}