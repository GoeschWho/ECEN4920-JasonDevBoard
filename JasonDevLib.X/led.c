#include "JasonDevLib.h"

void LEDInit(void) {
    // Disable Analog, make digital pin
    ANSELE &= 0xFC;
    // Set port direction. 1=input(default)
    TRISE &= 0xFC;
} // end LEDInit()

void GreenLEDOn(void) {
    LATE |= 0x01;
} // end GreenLEDOn()

void GreenLEDOff(void) {
    LATE &= 0xFE;
} // end GreenLEDOff()

void BlueLEDOn(void) {
    LATE |= 0x02;
} // end BlueLEDOn()

void BlueLEDOff(void) {
    LATE &= 0xFD;
} // end BlueLEDOff()