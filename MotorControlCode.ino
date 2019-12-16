
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