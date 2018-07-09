#include <pic12f1822.h>
#include <xc.h>

#pragma config MCLRE = OFF    // MCLR Pin disabled and acting as GPIO (Pin 4)
#pragma config WDTE = OFF     // WDT disabled
#pragma config LVP = OFF      // High voltage programming as MCLR disabled
#pragma config FOSC = INTOSC  // Using Internal Osc (Enables Pin 2 to be used as GPIO)

#define _XTAL_FREQ 8000000  // 8MHz Clock

// Value Display / State / Counting Variables
volatile unsigned char period = 1;
volatile unsigned char newPeriod = 1;
volatile unsigned char count = 0;
volatile unsigned char countUp = 1;
volatile unsigned char number = 1;

// Button related variables
volatile const unsigned char buttonSampleThresh = 5;
volatile unsigned char sampleButton = 1;
volatile unsigned char buttonCountA = 0;
volatile unsigned char buttonCountB = 0;
volatile unsigned char buttonA = 0;
volatile unsigned char buttonB = 0;


void interrupt isr(void) 
{ 
// If TMR0 (Overflow Interrupt Enable) bit and T0IF (TMR0 Overflow Interrupt Flag) bit, interrupt is result of TIMER0
if(T0IE && T0IF)     
  { 
    T0IF = 0;                         // Turn interrupt off
    
    ///////////////////////////////////////////////////////////
    //  Clock divider to give number incrementing frequency  //
    //  Frequency = 244/period Hz                            //
    ///////////////////////////////////////////////////////////
    
    // If the correct period has passed, reset count and increment number
    if (count >= period) 
    {
      count = 0;
      number++;
    }          

    if (!count) period = newPeriod;   // Changing the period only when count equals zero prevents delayed updating when the up button is pressed rapidly 
    
    count++;                          // Increment count every time ISR triggers

    ///////////////////////////////////////////////////////////
    //                   Button Sampling                     //
    ///////////////////////////////////////////////////////////

    // Used to debounce button. Counts up when button is depressed, resets to zero when not depressed
    // Once count is high enough, button has stopped bouncing and can be treated as being pressed. 
    
    sampleButton ^= 1; // Divides clock by two to get 122Hz sample rate, could use higher rate but not required and results in extra conpute time in ISR
    
    if (sampleButton)
    {
      // Count up if button is depressed, set to zero if not
      // Don't count past 255 as we might overflow!
      if (PORTAbits.RA3 && (buttonCountA < 255)) buttonCountA++;
      if (!PORTAbits.RA3) buttonCountA = 0;

      if (PORTAbits.RA4 && (buttonCountB < 255)) buttonCountB++;
      if (!PORTAbits.RA4) buttonCountB = 0;

      // If the button has been depressed for a short time (~50ms), set the button state to true, otherwise set to zero
      (buttonCountA > buttonSampleThresh) ? buttonA = 1 : buttonA = 0;
      (buttonCountB > buttonSampleThresh) ? buttonB = 1 : buttonB = 0;
    }
  }
}

// Function to set GPIO correctly to light individual LED's on board as they are charlieplexed
// Takes in index of LED (0 through 9 + 10(zero)) according to   
void displayNumber(signed char i)
{
  // Gives the RAx number to set high/low for each of the LED's
  // In order: 1 2 4 8 16 32 64 128 Single Clocked OFF
  // See Schematic for more info
  const unsigned char pinHigh[11]    = {0,1,1,2,2,5,1,5,0,2,7};
  const unsigned char pinLow[11]     = {1,0,2,1,5,2,5,1,2,0,0};

  TRISA = 0xFF & ~(1<<pinLow[i]|1<<pinHigh[i]); // All GPIO except the two for each diode need to be tristated
  PORTA = 0 | (1<<pinHigh[i]);                  // All GPIO are low except the one on anode side of diode
  __delay_us(600);                              // Wait before toggling to next LED - could use an interrupt but not needed in this case
  
  // Below is used to decrease the time LED's are high to decrease ghosting
  TRISA = (1<<3)|(1<<4);                        // RA3, RA4 Input, others output
  PORTA = 0;                                    // All GPIO are low
  __delay_us(100);                             
  
}

void main() 
{

  // Init registers
  OSCCON = 0b11110000;    // Internal oscillator 8MHz and PLL enabled
  ANSELA = 0;             // All I/O pins are configured as digital
  ADCON0 = 0;             // Disable ADC module
  TRISA = (1<<3)|(1<<4);  // RA3, RA4 Input, others output
  PORTA = 0;              // PORTA init all low
  WPUA = 0;               // Disable pullup resistors

  // Setup TIMER0
  OPTION_REG = 0b10000110;    // Weak pull-ups disabled, Timer0 prescaler 1:128 
  INTCON = 0b10100000;        // Global Interrupt Enabled and TMR0 Overflow Interrupt Enabled 
  
  // Array to store the time periods which will be used in clocked mode
  #define TIME_ELEM 13
  const unsigned char timingPeriods[TIME_ELEM] = {240,120,90,70,55,40,30,25,15,7,3,1,0};

  // Number display and state variables
  unsigned char singleStep = 0;  
  unsigned char dispNumber = 1;
  unsigned char index = 0;

  // Button State variables
  unsigned char buttonPrevA = 0;
  unsigned char buttonPrevB = 0;
  unsigned char buttonPressedA = 0;
  unsigned char buttonPressedB = 0;
  unsigned char buttonReleasedA = 0;
  unsigned char buttonReleasedB = 0;

  while(1)
  {
    ///////////////////////////////////////////////////////////
    //                   Button States                       //
    ///////////////////////////////////////////////////////////
      
    // Detect if a button has been pressed (transition from high to low)
    (buttonPrevA == 1 && buttonA == 0) ? buttonPressedA = 1 : buttonPressedA = 0;
    (buttonPrevB == 1 && buttonB == 0) ? buttonPressedB = 1 : buttonPressedB = 0; 
    // Detect if a button has been released (transition from low to high)
    (buttonPrevA == 0 && buttonA == 1) ? buttonReleasedA = 1 : buttonReleasedA = 0;
    (buttonPrevB == 0 && buttonB == 1) ? buttonReleasedB = 1 : buttonReleasedB = 0; 
    // Redefine prev button states
    buttonPrevA = buttonA; 
    buttonPrevB = buttonB; 

    // Determine if both buttons are depressed
    unsigned char buttonBoth = (unsigned char) ((!buttonA && buttonPressedB) || (!buttonB && buttonPressedA) || (buttonPressedA && buttonPressedB));

    // Toggle state if both buttons are depressed, and hand over the current number
    if (buttonBoth)
    {
      singleStep = !singleStep;
      number = dispNumber;
    }

    ///////////////////////////////////////////////////////////
    //                  State: Single Step                   //
    ///////////////////////////////////////////////////////////
    if (singleStep)
    { // Increment / decrement displayed number when buttons are pressed
      if (buttonPressedA) dispNumber--;
      if (buttonPressedB) dispNumber++;
    }

    ///////////////////////////////////////////////////////////
    //                  State: Clock Driven                  //
    ///////////////////////////////////////////////////////////
    if (!singleStep)
    { // Increment / decrement index of time array when buttons are pressed
      if (buttonPressedA && (index > 0)) index--;
      if (buttonPressedB && (index < TIME_ELEM - 1)) index ++;

      newPeriod = timingPeriods[index]; // Set the new period from the array
      dispNumber = number;              // Set the displayed number as the clocked number
    }
    
    ///////////////////////////////////////////////////////////
    //                   Display the number                  //
    ///////////////////////////////////////////////////////////   
    // Loop over the LED's and check if they need to be lit          
    for(signed char i = 7; i >= 0; i--)
    {
        unsigned char bitOn = (unsigned char) ((dispNumber >> i) & 1); // Returns 1 if bit is required to display number
        (bitOn) ? displayNumber(i) : displayNumber(10); // Display the bit if set, otherwise display nothing (10 is all off)         
    }

    (singleStep) ? displayNumber(8) : displayNumber(9); // If single step, turn SS led on (8), otherwise turn clock driven led on (9)
  }
}