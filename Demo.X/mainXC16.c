/*
 * File:   mainXC16.c
 * Author: Megan Bird
 *
 * Created on December 10, 2018, 4:33 PM
 */

#include "xc.h"
#include "JasonDevLib.h"

int main(void) {

    LEDInit();
    
    GreenLEDOn();
    BlueLEDOn();
    
    LCDInit();
    LCDCSWrite(1);
    LCDRSTWrite(1);
    
    while(1);
}