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
    ILI9341FillRectangle(0, 300, 240, 20, RGB565_ORANGE);
    // Top Status Bar
    ILI9341FillRectangle(0, 0, 240, 80, RGB565_ORANGE);
    // Buttom Status Bar
    ILI9341DrawLine(20, 90, 220, 90, RGB565_ORANGE);
    ILI9341DrawLine(20, 90, 20, 290, RGB565_ORANGE);
    ILI9341DrawLine(20, 290, 220, 290, RGB565_ORANGE);
    ILI9341DrawLine(220, 90, 220, 290, RGB565_ORANGE);
    // Waveform Graphics Paint Box
    ILI9341DrawLine(20, 130, 220, 130, RGB565_ORANGE);
    ILI9341DrawLine(20, 170, 220, 170, RGB565_ORANGE);
    ILI9341DrawLine(20, 210, 220, 210, RGB565_ORANGE);
    ILI9341DrawLine(20, 250, 220, 250, RGB565_ORANGE);
    ILI9341DrawLine(20, 290, 220, 290, RGB565_ORANGE);
    ILI9341DrawLine(60, 90, 60, 290, RGB565_ORANGE);
    ILI9341DrawLine(100, 90, 100, 290, RGB565_ORANGE);
    ILI9341DrawLine(140, 90, 140, 290, RGB565_ORANGE);
    ILI9341DrawLine(180, 90, 180, 290, RGB565_ORANGE);
    ILI9341DrawLine(220, 90, 220, 290, RGB565_ORANGE);
    // Grids
}   