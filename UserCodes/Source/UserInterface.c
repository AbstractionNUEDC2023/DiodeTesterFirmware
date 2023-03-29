#include "ILI9341.h"
#include <UserInterface.h>

/**
 * @brief Initialize User Interface Of Diode Tester
 * @return None 
 */
void InitializeGUI(){
    ILI9341Initialize();
    // Initialize Screen Before Using Screen
    ILI9341FillScreen(RGB565_BLACK);
    // Background
    ILI9341FillRectangle(0, 0, 240, 20, RGB565_ORANGE);
    ILI9341DrawString(1, 5, "Status:STOP", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    ILI9341DrawString(92, 5, "VREF:3.3V", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    ILI9341DrawString(162, 5, "Mode:Wave", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    // Top Status Bar
    ILI9341FillRectangle(0, 260, 240, 60, RGB565_ORANGE);
    ILI9341DrawString(1, 275, "VerticalGrid: 100mV/div", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    ILI9341DrawString(1, 263, "HorizontalGrid: 100uA/div", Font_07x10, RGB565_CYAN, RGB565_ORANGE);
    ILI9341DrawString(1, 304, "Abstractions' work", Font_11x18, RGB565_DARKCYAN, RGB565_ORANGE); 
    // Buttom Status Bar
    ILI9341DrawLine(20, 40, 20, 240, RGB565_ORANGE);
    ILI9341DrawLine(20, 40, 220, 40, RGB565_ORANGE);
    ILI9341DrawLine(20, 240, 220, 240, RGB565_ORANGE);
    ILI9341DrawLine(220, 240, 220, 40, RGB565_ORANGE);
    // Waveform Painter Box
    ILI9341DrawLine(60, 40, 60, 240, RGB565_ORANGE);
    ILI9341DrawLine(100, 40, 100, 240, RGB565_ORANGE);
    ILI9341DrawLine(140, 40, 140, 240, RGB565_ORANGE);
    ILI9341DrawLine(180, 40, 180, 240, RGB565_ORANGE);
    // Vertical Grid Lines
    ILI9341DrawLine(20, 80, 220, 80, RGB565_ORANGE);
    ILI9341DrawLine(20, 120, 220, 120, RGB565_ORANGE);
    ILI9341DrawLine(20, 160, 220, 160, RGB565_ORANGE);
    ILI9341DrawLine(20, 200, 220, 200, RGB565_ORANGE);
    // Horizontal Grid Lines
    
}   