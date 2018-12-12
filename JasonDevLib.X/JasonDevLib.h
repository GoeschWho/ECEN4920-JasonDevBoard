/* 
 * File:   JasonDevLib.h
 * Author: megan
 *
 * Created on December 10, 2018, 5:17 PM
 */

#ifndef JASONDEVLIB_H
#define	JASONDEVLIB_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    
#include "xc.h"
    
// led.c
void LEDInit(void);
void GreenLEDOn(void);
void GreenLEDOff(void);
void BlueLEDOn(void);
void BlueLEDOff(void);

// lcd.c
void LCDInit(void);
void LCDInitDemo(void);
void LCDCSWrite(int val);
void LCDRSTWrite(int val);
void LCDRSTWrite(int val);
void SPITX(short data);
short SPIRX(void);
void SPIInit(void);


#ifdef	__cplusplus
}
#endif

#endif	/* JASONDEVLIB_H */

