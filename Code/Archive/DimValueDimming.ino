//Georgia and Basir
// Prototype Code 2 (Dim Value + Dimming Code)
/* We found this code online early on in the code trial process. It compares a "dimValue" variable read and converted 
from a potentiometer with a with a "dimming" variable to determine whether the brightness should increase or decrease.
There is a seperate void function involving the zero cross detector and triacs. This code did not work, but that may 
have been due to an error with our dimmer and not due to any faults in the code itself.*/



int potPin = 2; // Sets potentiometer to analog pin A0
int AC_LOAD = 3; // Sets AC LOAD pin as 3
int potValue; // Variable read from potentiometer
int dimValue; // Dim amount variable
unsigned char dimming = 128; // Dimming level (0-128) 0 = ON, 128 = OFF

void setup()
{
	pinMode(potPin, INPUT); // Potentiometer pin is InPuT
	pinMode(AC_LOAD, OUTPUT); // AC LOAD pin is output
	Serial.begin(9600);
	attachInterrupt(6, zero_crosss_int, RISING); // Choose the zero cross interrupt # from the table above
}

void zero_crosss_int()
{
	int dimtime = (65 * (int) dimming); // For 60Hz =>65
	delayMicroseconds(dimtime); // Wait till firing the TRIAC
	digitalWrite(AC_LOAD, HIGH); // Fire the TRIAC
	delayMicroseconds(10); // triac On propogation dely
	// (for 60Hz use 8.33) Some Triacs need a longer period
	digitalWrite(AC_LOAD, LOW);
}

void loop()
{
	potValue = analogRead(potPin); // readValue derived from reading the potentiometer value
	dimValue = potValue/8; // Formula for calculating dim value
	Serial.print("You are writing a value of ");
	Serial.println(dimValue); // serial print for debugging purposes
	analogWrite(AC_LOAD, dimming);

	/* for (int i = 5; i <= 126; i++)
	{
		if (dimming < dimValue)
			diming++;
		if (dimming > dimValue)
			diming--;
		// dimming= dimValue;
		delay(10);
	}
	*/
	if (dimming < dimValue)
			diming++;
	if (dimming > dimValue)
			diming--;
	// dimming= dimValue;
	delay(10);
}
