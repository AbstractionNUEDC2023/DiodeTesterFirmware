#ifndef __NUEDC_DIODE_TESTER_FIRMWARE_COMMON_HEADER__
#define __NUEDC_DIODE_TESTER_FIRMWARE_COMMON_HEADER__

#include <stdint.h>

typedef struct {
    uint8_t reservedBits:3;
    uint8_t deviceRunFlag:1;
    uint8_t deviceModeFlag:1;
    uint8_t adcConvCpltFlag:1;
    uint8_t dacConvCpltFlag:1;
    uint8_t deviceModeChangeFlag:1;
} Flags_t;

extern Flags_t flags;
extern uint32_t adcBuffer[200];

void GUIInitialize(void);
void GUIUpdateStatus(void);
void GUIClearCurve(uint8_t clearMode);
void GUIDrawCurveOnGrids(uint32_t *PointsYArray);

void OscillscopeInitialize(void);
void OscillscopeServiceFunction(void);
void OscillscopeDeinitialize(void);

void DiodeTesterInitialize(void);
void DiodeTesterServiceFunction(void);
void DiodeTesterDeinitialize(void);

#endif