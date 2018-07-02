/* 
 * File:   main.c
 * Author: Josh Johnson
 *
 * Created on 21 June 2018, 3:13 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pic12f1822.h>
#include <xc.h>

#pragma config MCLRE = OFF // MCLR Pin Function Select->MCLR/VPP pin function is digital input
#pragma config WDTE = OFF // Watchdog Timer Enable->WDT disabled
#pragma config LVP = OFF // Low-Voltage Programming Enable->High-voltage on MCLR/VPP must be used for programming
#pragma config FOSC = INTOSC // Internal Oscilator (Enables RA5 to be used as an input.)

#define _XTAL_FREQ 40000000  // Number is not correct, need to look into
void main() {
    OSCCON = 0xF0; // Internal oscillator 8MHz and PLL enabled
    ANSELA = 0;    // All I/O pins are configured as digital
    ADCON0 = 0;    // Disable ADC module
    TRISA = (1<<3)|(1<<4);// RA3, RA4 Input, others output
    PORTA = 0;     // Initial value of port A bits OFF
    WPUA = 0;       // Disable internal pullups
    
    static const unsigned char PIN_HIGH[11]	   = {0,1,1,2,2,5,1,5,0,2,7};
    static const unsigned char PIN_LOW[11]	   = {1,0,2,1,5,2,5,1,2,0,0};
    
    int number = 135;
    int i = 0;
    
    while(1){
        
        for(i = 0; i < 8; i++)
        {
            int bitOn = ((number >> i) & 1);
            
            if (bitOn)
            {
            TRISA &= ~(1<<PIN_LOW[i]|1<<PIN_HIGH[i]);
            PORTA = 0 | (1<<PIN_HIGH[i]);
            }
            
            __delay_ms(1);
            
        }
     
       
    }
}