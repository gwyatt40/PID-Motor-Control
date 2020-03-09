int potPin = 0; // Sets potentiometer to analog pin A0
int potValue; // Variable read from potentiometer
int dimValue; // Dim amount variable
void setup()
{
	pinMode(potPin, INPUT); // Potentiometer pin is InPuT
	Serial.begin(9600);
}


void loop()
{
	potValue = analogRead(potPin); // readValue derived from reading the potentiometer value
	Serial.println(potValue);
	delay(100);
}
