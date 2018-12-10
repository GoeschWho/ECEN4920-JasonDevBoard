/*
 * File:   newmainXC16.c
 * Author: megan
 *
 * Created on December 9, 2018, 1:09 AM
 */


#include "xc.h"

//#pragma config FWDTEN = OFF, JTAGEN = OFF

void delay(void);

unsigned int ctr = 0;
unsigned int delayVal = 3048;

int main(void)
{
    ANSELE = 0;
    // Set port direction. 1=input(default)
    TRISE = 0;
    delay();
    
    while(1)
    {
        LATE = 0x02;
        delay();

        LATE = 0x01;
        delay();

        ctr++;
    }
}

void delay(void)
{
    unsigned int i,j;

    for (i = 0; i < delayVal; i++)
    {
        for (j = 0; j < 20; j++);
    }
}