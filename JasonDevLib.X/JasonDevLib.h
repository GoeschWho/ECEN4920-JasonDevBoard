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
#include "Libpic30.h"  // Delays
    
// led.c
void LEDInit(void);
void GreenLEDOn(void);
void GreenLEDOff(void);
void BlueLEDOn(void);
void BlueLEDOff(void);

// lcd.c
void LCDInit(void);
void LCDCSWrite(int val);
void LCDRSTWrite(int val);


#ifdef	__cplusplus
}
#endif

#endif	/* JASONDEVLIB_H */

