#include "JasonDevLib.h"
#include "xc.h"

void LEDInit(void) {
    // Disable Analog, make digital pin
    ANSELE &= 0xFC;
    // Set port direction. 1=input(default)
    TRISE &= 0xFC;
} // end LEDInit()

void GreenLEDOn(void) {
    PORTEbits.RE0 = 1;
} // end GreenLEDOn()

void GreenLEDOff(void) {
    PORTEbits.RE0 = 0;
} // end GreenLEDOff()

void BlueLEDOn(void) {
    PORTEbits.RE1 = 1;
} // end BlueLEDOn()

void BlueLEDOff(void) {
    PORTEbits.RE1 = 0;
} // end BlueLEDOff()