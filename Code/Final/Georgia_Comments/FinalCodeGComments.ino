//Georgia and Basir
// Final Motor Control Code (Georgia's Comments)
/* This was the first code we tried after ordering a new dimmer and it worked. With a few changes, it became our final 
code. The one hiccup we encountered with this code was that it is impossible to run delays in it because the code
already uses the Arduino's timer functions. The comments on this version are mine, to see comments from the website go
to the "Original Comments" file. */

#include <RBDdimmer.h> //Dimmer libraries and other setup info
#include <avr/io.h>
#include <avr/interrupt.h>

#define potPin 0 //potentiometer pin
#define DETECT 2 // Zero cross detect
#define GATE 11 // Sets TRIAC gate
#define PULSE 4 // Sets puls width
int i = 483; // This variable is left in but is unnecessary when potentiometer is used (see commented out code below)
int potValue = 0; //Inital potentiometer value


void setup()
{
  // set up pins
  pinMode(DETECT, INPUT); // Zero cross detect is input
  digitalWrite(DETECT, HIGH); // Enables the pull-up resistor
  pinMode(GATE, OUTPUT); // Triac gate is output
  //Below is setup for timer 1
  OCR1A = 100; 
  TIMSK1 = 0x03; 
  TCCR1A = 0x00; 
  TCCR1B = 0x00; 

  attachInterrupt(0, zeroCrossingInterrupt, RISING);
  // Sets an attach interrupt function to check zero cross pin for rising activity

  
}


void zeroCrossingInterrupt()
{
  //Interrupt function
  TCCR1B = 0x04; // Starts timer 
  TCNT1 = 0; // Resets timer from zero
}

extern "C"
{
  ISR(TIMER1_COMPA_vect)
  {
   
    digitalWrite(GATE, HIGH); // Triac gate to high 
    TCNT1 = 65536 - PULSE; 

  }
}

extern "C"
{
  ISR(TIMER1_OVF_vect)
  {
  
    digitalWrite(GATE, LOW); // Triac gate to low (off)
    TCCR1B = 0x00; // Timer disabled
          
  }
}

void loop(){

  potValue = analogRead(potPin); //Defines potentiometer value
   /*
  i--;
  // i = i -1;
  // i-=1;
  OCR1A = ; // set the compare register brightness desired.
  if (i < 65)
  {
    i = 483;
  }
*/ /*This code is commented out as it is unnecessary when the potentiometer is incorporated. It also did not work when
  we ran it like this without a potentiometer. */
  
  OCR1A = map(potValue, 0, 1023, 0, 483); // Sets OCR1A compare function to a map that converts potValue to brightness
  
  }

