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
    
    unsigned char i = 1; 
    
    static const unsigned char PIN_HIGH[11]	   = {7,0,1,1,2,2,5,1,5,0,2};
    static const unsigned char PIN_LOW[11]	   = {0,1,0,2,1,5,2,5,1,2,0};
    
    while(1){
        TRISA = 0xFF & ~(1<<PIN_LOW[i]|1<<PIN_HIGH[i]);
        PORTA = (1<<PIN_HIGH[i]);
        
        if (PORTAbits.RA4 == 0) 
        {
            i++;
            __delay_ms(200);
        }
        
        if (PORTAbits.RA3 == 0) 
        {
            i--;
            __delay_ms(200);
        }
        if (i > 10) i = 0;
        
     
       
    }
}