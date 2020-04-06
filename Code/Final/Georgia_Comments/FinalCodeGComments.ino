//Georgia and Basir
// Final Motor Control Code (Georgia's Comments)
/* This was the first code we tried after ordering a new dimmer and it worked. With a few changes, it became our final 
code. The one issue we encountered with this code was that it is impossible to run delays in it because the code
already uses the Arduinos timer functions. The comments on this version are mine, to see comments from the website go
to the original commenst file. */

#include <RBDdimmer.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define potPin 0 //potentiometer read pin 
#define DETECT 2 // zero cross detect
#define GATE 11 // TRIAC gate
#define PULSE 4 // trigger pulse width (counts)
int i = 483;
int potValue = 0;


void setup()
{
  // set up pins
  pinMode(DETECT, INPUT); // zero cross detect
  digitalWrite(DETECT, HIGH); // enable pull-up resistor
  pinMode(GATE, OUTPUT); // TRIAC gate control
  // set up Timer1
  // (see ATMEGA 328 data sheet pg 134 for more details)
  OCR1A = 100; // initialize the comparator
  TIMSK1 = 0x03; // enable comparator A and overflowinterrupts
  TCCR1A = 0x00; // timer control registers set for
  TCCR1B = 0x00; // normal operation, timer disabled
  // set up zero crossing interrupt
  attachInterrupt(0, zeroCrossingInterrupt, RISING);
  // IRQ0 is pin 2. Call zeroCrossingInterrupt
  // on rising signal
  
}

// Interrupt Service Routines
void zeroCrossingInterrupt()
{
  // zero cross detect
  TCCR1B = 0x04; // start timer with divide by 256 input
  TCNT1 = 0; // reset timer - count from zero
}

extern "C"
{
  ISR(TIMER1_COMPA_vect)
  {
    // comparator match
    digitalWrite(GATE, HIGH); // set TRIAC gate to high
    TCNT1 = 65536 - PULSE; // trigger pulse width

  }
}

extern "C"
{
  ISR(TIMER1_OVF_vect)
  {
    // timer1 overflow
    digitalWrite(GATE, LOW); // turn off TRIAC gate
    TCCR1B = 0x00; // disable timer stopd unintended triggers
          
  }
}

void loop(){

  potValue = analogRead(potPin);
   /*
  i--;
  // i = i -1;
  // i-=1;
  OCR1A = ; // set the compare register brightness desired.
  if (i < 65)
  {
    i = 483;
  }
*/
  OCR1A = map(potValue, 0, 1023, 0, 483); // set the compare register brightness desired.
  
  }

