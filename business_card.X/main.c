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
#pragma config FOSC = INTOSC // Internal Oscilator

#define _XTAL_FREQ 40000000  // Number is not correct, need to look into
void main() {
    OSCCON = 0xF0; // Internal oscillator 8MHz and PLL enabled
    ANSELA = 0;    // All I/O pins are configured as digital
    ADCON0 = 0;    // Disable ADC module
    TRISA = 0;     // All Output
    PORTA = 0;     // Initial value of port A bits
    
    while(1){
        // LED 0 (Binary 1)
        TRISA = (1<<2)|(1<<5); // High Z
        PORTA = 0b00000001;
        __delay_ms(500);
        // LED 1 (Binary 2)
        TRISA = (1<<2)|(1<<5); // High Z
        PORTA = 0b00000010;
        __delay_ms(500);
        // LED 2 (Binary 4)
        TRISA = (1<<0)|(1<<5); // High Z
        PORTA = 0b00000010;
        __delay_ms(500);
        // LED 3 (Binary 8)
        TRISA = (1<<0)|(1<<5); // High Z
        PORTA = 0b00000100;
        __delay_ms(500);
        // LED 4 (Binary 16)
        TRISA = (1<<0)|(1<<1); // High Z
        PORTA = 0b00000100;
        __delay_ms(500);
        // LED 5 (Binary 32)
        TRISA = (1<<0)|(1<<1); // High Z
        PORTA = 0b00100000;
        __delay_ms(500);
        // LED 6 (Binary 64)
        TRISA = (1<<0)|(1<<2); // High Z
        PORTA = 0b00000010;
        __delay_ms(500);
        // LED 7 (Binary 128)
        TRISA = (1<<0)|(1<<2); // High Z
        PORTA = 0b00100000;
        __delay_ms(500);     
       
//        // LED 8 (Single Step)
//        TRISA = (1<<1)|(1<<5); // High Z
//        PORTA = 0b00000001;
//        __delay_ms(500);
//        // LED 9 (Clocked Count)
//        TRISA = (1<<1)|(1<<5); // High Z
//        PORTA = 0b00000100;
//        __delay_ms(500);    
        
        
    }
}