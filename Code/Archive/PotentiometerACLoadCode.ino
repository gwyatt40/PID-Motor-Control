//Georgia and Basir
//Prototype Code 1 (Potentiometer AC Load Code)
/* This was the very first prototype code we tried. It did not work. The main issue with this code is that it does not
use any functions necessary to the dimmer, such as zero cross detection. It was derived from editing an old code that 
used a potentiometer to change the brightness of an LED. I left the old comments in to illustrate this. */

int potPin= 2;  //Sets potentiometer to analog pin A0
int AC_LOAD= 12;  // Sets LED to normal arduino pin 9
int potValue;  // Variable read from potentiometer
int motorValue; // Variable written to LED
 
void setup() {
  pinMode(potPin, INPUT);  //Potentiometer pin is INPUT
  pinMode(AC_LOAD, OUTPUT); //LED pin is output
  Serial.begin(9600);      
}
 
void loop() {
  
 potValue = analogRead(potPin);  //readValue derived from reading the potentiometer value
 motorValue= potValue/4; //Formula for calculating LED write value
 analogWrite(AC_LOAD, motorValue);      //LED set to writeValue
 Serial.print("You are writing a value of ");  
 Serial.println(motorValue); //serial print for debugging purposes
 
}
