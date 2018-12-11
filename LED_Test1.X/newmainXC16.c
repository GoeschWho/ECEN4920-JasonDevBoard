/*
 * File:   newmainXC16.c
 * Author: Megan Bird
 */

#include "xc.h"

//--- Procedure Declarations ---//

// LEDs
void LEDInit(void);
void GreenLEDOn(void);
void GreenLEDOff(void);
void BlueLEDOn(void);
void BlueLEDOff(void);

void delay(void);

unsigned int ctr = 0;
unsigned int delayVal = 3048;

int main(void)
{
    LEDInit();
    
    while(1)
    {
        GreenLEDOn();
        BlueLEDOff();
        delay();

        GreenLEDOff();
        BlueLEDOn();
        delay();

        ctr++;
    }
}

void LEDInit(void) {
    // Disable Analog, make digital pin
    ANSELE &= 0xFC;
    // Set port direction. 1=input(default)
    TRISE &= 0xFC;
}

void GreenLEDOn(void) {
    LATE |= 0x01;
}

void GreenLEDOff(void) {
    LATE &= 0xFE;
}

void BlueLEDOn(void) {
    LATE |= 0x02;
}

void BlueLEDOff(void) {
    LATE &= 0xFD;
}

void delay(void)
{
    unsigned int i,j;

    for (i = 0; i < delayVal; i++)
    {
        for (j = 0; j < 20; j++);
    }
}