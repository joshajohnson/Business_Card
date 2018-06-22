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


void main() {
    OSCCON = 0xF0; // Internal oscillator 8MHz and PLL enabled
    ANSELA = 0;    // All I/O pins are configured as digital
    ADCON0 = 0;    // Disable ADC module
    TRISA = (1<<3)|(1<<4);// RA3, RA4 Input, others output
    PORTA = 0;     // Initial value of port A bits
    
    while(1){
        if (PORTAbits.RA3 == 0) PORTAbits.RA1 = 1;
        else PORTAbits.RA1 = 0;
        
        if (PORTAbits.RA4 == 0) PORTAbits.RA2 = 1;
        else PORTAbits.RA2 = 0;
        
    }
}