/*
 * File:   mainXC16.c
 * Author: Megan Bird
 *
 * Created on December 10, 2018, 4:33 PM
 */
 // Fosc = 8MHz
#define FOSC (8000000ULL)
#define FCY (FOSC/2)

#include "libpic30.h"
#include "xc.h"
#include "JasonDevLib.h"

int main(void) {

    LEDInit();
    GreenLEDOff();
    BlueLEDOff();
        
    LCDInit();
    LCDInitDemo();
    LCDTouchscreenDemo();
    
    while(1) {
//        GreenLEDOn();
//        BlueLEDOff();
//        __delay_ms(800);
//        GreenLEDOff();
//        BlueLEDOn();
//        __delay_ms(800);
    };
}