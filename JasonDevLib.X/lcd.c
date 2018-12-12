 // Fosc = 8MHz
#define FOSC (8000000ULL)
#define FCY (FOSC/2)

#include "xc.h"
#include "JasonDevLib.h"
#include "RA8875.h"
#include "libpic30.h"

void LCDInit(void) {
    
    unsigned char x;
    
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
    //ANSELEbits.ANSE6 = 0;
    ANSELGbits.ANSG6 = 0; // SCK2
    ANSELGbits.ANSG7 = 0; // SDI2
    ANSELGbits.ANSG8 = 0; // SDO2
    
    // Set port direction. 1=input(default)
    TRISE &= 0x1F;
    TRISGbits.TRISG6 = 0;
    TRISGbits.TRISG8 = 0;
    
    SPIInit();
   
//    LCDCSWrite(1);
//    LCDRSTWrite(1);
//    
//    LCDCSWrite(0);
//    SPITX(0x0F);
//    LCDCSWrite(1);
    //x = readReg(0);
    //------ LCD Setup ------//  
    
    LCDRSTWrite(1);
    
    begin(RA8875_800x480);
    displayOn(true);
    GPIOX(true);      // Enable TFT - display enable tied to GPIOX
    
    PWM1config(true, RA8875_PWM_CLK_DIV1024); // PWM output for backlight  
    PWM1out(255);
    
    // LCD_int_Write(1u); 
    LCDINTWrite(1);
    
    touchEnable(true);

} 

void LCDInitDemo(void) {
    
    //------ Declarations ------/
    // LCD Strings
    char welcome1[] = "Megan Bird";
    char welcome2[] = "ECEN 4350";
    char welcome3[] = "Fall 2017";
    char ble[] = "BLE_Central";
    
    int myDelay = 200;
    
    //----- Color Demo -----//
    
    fillScreen(RA8875_WHITE);    
    __delay_ms(myDelay);
    fillScreen(RA8875_RED);
    __delay_ms(myDelay);
    fillScreen(RA8875_YELLOW);
    __delay_ms(myDelay);
    fillScreen(RA8875_GREEN);
    __delay_ms(myDelay);
    fillScreen(RA8875_BLUE);
    __delay_ms(myDelay);
    fillScreen(RA8875_CYAN);
    __delay_ms(myDelay);
    fillScreen(RA8875_MAGENTA);
    __delay_ms(myDelay);
    fillScreen(RA8875_BLACK);
}

void LCDCSWrite(int val) {
    PORTEbits.RE7 = val;
}

void LCDRSTWrite(int val) {
    PORTEbits.RE5 = val;
}

void LCDINTWrite(int val) {
    PORTEbits.RE6 = val;
}

void SPITX(short data) {
    int trash;
    
    //trash = SPI2BUF;    // Cleans the buffer
    SPI2BUF = data;
    while(!SPI2STATbits.SPIRBF) {
        GreenLEDOn();
    }
    BlueLEDOn();
    trash = SPI2BUF;
    //LCDCSWrite(1);
}

short SPIRX(void) {
    int rec;
    
    SPI2BUF = 0;
    while(!SPI2STATbits.SPIRBF);
    rec = SPI2BUF;
    
    return rec;
}

void SPIInit(void) {
    /* The following code sequence shows SPI register configuration for Master mode */
    //IFS2bits.SPI2IF = 0; // Clear the Interrupt flag
    //IEC2bits.SPI2IE = 0; // Disable the interrupt
    // SPI2CON1 Register Settings
    SPI2CON1bits.DISSCK = 0; // Internal serial clock is enabled
    SPI2CON1bits.DISSDO = 0; // SDOx pin is controlled by the module
    SPI2CON1bits.MODE16 = 0; // Communication is byte-wide (8 bits)
    SPI2CON1bits.MSTEN = 1; // Master mode enabled
    SPI2CON1bits.SMP = 0; // Input data is sampled at the middle of data output time
    SPI2CON1bits.CKE = 0; // Serial output data changes on transition from
    // Idle clock state to active clock state
    SPI2CON1bits.CKP = 1; // Idle state for clock is a high level;
    // active state is a low level
    SPI2STATbits.SPIEN = 1; // Enable SPI module
    // Interrupt Controller Settings
    //IFS2bits.SPI2IF = 0; // Clear the Interrupt flag
    //IEC2bits.SPI2IE = 1; // Enable the interrupt
}

