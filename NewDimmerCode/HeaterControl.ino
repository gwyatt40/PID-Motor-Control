

// AC Control V1.1
// 
// This Arduino sketch is for use with the heater
// control circuit board which includes a zero
// crossing detect function and an opto-isolated TRIAC.
// 
// AC Phase control is accomplished using the internal
// hardware timer1 in the Arduino
// 
// Timing Sequence
// * timer is set up but disabled
// * zero crossing detected on pin 2
// * timer starts counting from zero
// * comparator set to "dely to on" value
// * counter reaches comparator value
// * comparator ISR turns on TRIAC gate
// * counter set to overflow - pulse width
// * counter reaches overflow
// * overflow ISR turns off TRIAC gate
// * TRIAC stops conducting at next zero cross
// The hardware timer runs at 16MHz. Using a
// divide by 256 on the counter each count is
// 16 microseconds.  1/2 wave of a 60Hz AC signal
// is about 520 counts (8,333 microseconds).
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
