#include "JasonDevLib.h"

void LCDInit(void) {
    
    // LITE = RE6 (out)
    // SCK = SCK2
    // MISO = SDI2
    // MOSI = SDO2
    // CS = RE7 (out)
    // RST = RE5 (out)
    // !WAIT = RE3
    // !INT = RE4
    
    //  E7      E6      E5      E4      |   E3
    //  CS      LITE    RST     !INT    |   !WAIT
    //  out     out     out     in      |   in
    
    // Disable Analog, make digital pin
    ANSELE &= 0x1F;
    // Set port direction. 1=input(default)
    TRISE &= 0x1F;
    
} 

void LCDCSWrite(int val) {
    if (val) {
        LATE |= 0x80;
    } else {
        LATE &= 0x7F;
    }
}

void LCDRSTWrite(int val) {
    if (val) {
        LATE |= 0x20;
    } else {
        LATE &= 0xDF;
    }
}