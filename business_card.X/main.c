#include <stdio.h>
#include <stdlib.h>
#include <pic12f1822.h>
#include <xc.h>

#pragma config MCLRE = OFF // MCLR Pin Function Select->MCLR/VPP pin function is digital input
#pragma config WDTE = OFF // Watchdog Timer Enable->WDT disabled
#pragma config LVP = OFF // Low-Voltage Programming Enable->High-voltage on MCLR/VPP must be used for programming
#pragma config FOSC = INTOSC // Internal Oscilator (Enables RA5 to be used as an input.)


#define _XTAL_FREQ 40000000  // Number is not correct, need to look into

// Value Display / State / Counting Variables
volatile unsigned char period = 1;
volatile unsigned char newPeriod = 1;
volatile unsigned char count = 0;
volatile unsigned char sampleButton = 1;
volatile unsigned char number = 1;


// Button related variables
volatile static const unsigned char buttonSampleThresh = 5;
volatile unsigned char buttonCountA = 0;
volatile unsigned char buttonCountB = 0;
volatile unsigned char buttonA = 0;
volatile unsigned char buttonB = 0;




void interrupt isr(void) 
    { 
    
      if((T0IE==1) && (T0IF==1))     //If TMR0 (Overflow Interrupt Enable) bit and T0IF (TMR0 Overflow Interrupt Flag) bit equal 1, interrupt.
        { 
          T0IF = 0;     // Turn interrupt off
          
          /*////////////////////////////////////////////////////////
          Clock divider to give number incrementing frequency 
          Frequency = 244/period Hz
          ////////////////////////////////////////////////////////*/
          
          if (period == count) 
          {
              count = 0;
              number++;
          }          

          // If period == count, increment number and reset count
          if (!count) period = newPeriod;

          count++; // Increment the count regardless
          
          sampleButton ^= 1; // Divides clock by two to get 122Hz sample rate
          
          if (sampleButton)
          {
            /* Count up if button is depressed, set to zero if not
               Don't count past buttonSampleThresh+2 as we might overflow! */
            if (PORTAbits.RA3 && (buttonCountA < buttonSampleThresh + 2)) buttonCountA++;
            if (!PORTAbits.RA3) buttonCountA = 0;

            if (PORTAbits.RA4 && (buttonCountB < buttonSampleThresh + 2)) buttonCountB++;
            if (!PORTAbits.RA4) buttonCountB = 0;

            /* If the value is greater than the threshold (10's of ms) 
               We have had the button depressed long enough so set output high*/
            (buttonCountA > buttonSampleThresh) ? buttonA = 1 : buttonA = 0;
            (buttonCountB > buttonSampleThresh) ? buttonB = 1 : buttonB = 0;
          }
        }
    }

void main() {
    OSCCON = 0xF0; // Internal oscillator 8MHz and PLL enabled
    ANSELA = 0;    // All I/O pins are configured as digital
    ADCON0 = 0;    // Disable ADC module
    TRISA = (1<<3)|(1<<4);// RA3, RA4 Input, others output
    PORTA = 0;     // Initial value of port A bits OFF
    WPUA = 0;       // Disable pullup resistors

    // Setup TIMER0
    OPTION_REG=0b10000110;  // Timer0 Prescaler 1:128, results in 244Hz clock 
    INTCON=0b10100000;  //Global Interrupt Enabled and TMR0 Overflow Interrupt Enabled 
    
    static const unsigned char PIN_HIGH[11]    = {0,1,1,2,2,5,1,5,0,2,7};
    static const unsigned char PIN_LOW[11]     = {1,0,2,1,5,2,5,1,2,0,0};

    unsigned char singleStep = 0;  
    unsigned char dispNumber = 1;

    unsigned char buttonPrevA = 0;
    unsigned char buttonPrevB = 0;
    unsigned char buttonPressedA = 0;
    unsigned char buttonPressedB = 0;
    unsigned char buttonReleasedA = 0;
    unsigned char buttonReleasedB = 0;

    while(1)
    {
        
      // Detect if a button has been pressed (transition from high to low)
      (buttonPrevA == 1 && buttonA == 0) ? buttonPressedA = 1 : buttonPressedA = 0;
      (buttonPrevB == 1 && buttonB == 0) ? buttonPressedB = 1 : buttonPressedB = 0; 
      // Detect if a button has been released (transition from low to high)
      (buttonPrevA == 0 && buttonA == 1) ? buttonReleasedA = 1 : buttonReleasedA = 0;
      (buttonPrevB == 0 && buttonB == 1) ? buttonReleasedB = 1 : buttonReleasedB = 0; 
      buttonPrevA = buttonA; 
      buttonPrevB = buttonB; 

      // Toggle State if both buttons are pressed
      unsigned char buttonBoth = ((!buttonA && buttonPressedB) || (!buttonB && buttonPressedA));
      if (buttonBoth)
      {
       singleStep = !singleStep;
       number = dispNumber;
      }

      if (singleStep)
      {
        if (buttonPressedA) dispNumber--;
        if (buttonPressedB) dispNumber++;

      }


      if (!singleStep)
      {
        if (buttonPressedA && (newPeriod < 210)) newPeriod += 10;
        if (buttonPressedB && (newPeriod > 11)) newPeriod -= 10;

        dispNumber = number;
      }
      
             
      for(int i = 0; i <= 7; i++)
      {
          int bitOn = ((dispNumber >> i) & 1);
          PORTA = 0;
          if (bitOn)
          {
          TRISA = 0xFF & ~(1<<PIN_LOW[i]|1<<PIN_HIGH[i]);
          PORTA = (1<<PIN_HIGH[i]);
          }
          __delay_ms(1);            
      }

    }
}