const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor 
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor 

void setup() {
Serial.begin(9600); // Starting Serial Terminal 
}

void loop() { 
long duration, inches, cm; 
pinMode(pingPin, OUTPUT); 
digitalWrite(pingPin, LOW); 
delayMicroseconds(2); 
digitalWrite(pingPin, HIGH); 
delayMicroseconds(10); 
digitalWrite(pingPin, LOW); 
pinMode(echoPin, INPUT); 
duration= pulseIn(echoPin, HIGH); 
inches microsecondsToInches (duration); 
cm = microsecondsToCentimeters (duration); 
Serial.print(inches); 
Serial.print("in, "); 
Serial.print(cm); 
Serial.print("cm"); 
Serial.println(); 
if (cm <= 5 && cm >= 0) { 
// Buzz 
digitalWrite(buzzPin, HIGH); 
Serial.print("Container full \n"); 
}
else if(cm >= 20) {
// Don't buzz 
digitalWrite(buzzPin, LOW); 
Serial.print("Container empty \n"); 
}
else { 
Serial.print("Container Partially Filled \n"); 
}
delay(1000); 

long microseconds To Inches (long microseconds) {
return microseconds / 74 / 2; 
} 

long microsecondsToCentimeters (long microseconds) {
return microseconds / 29 / 2; 
}

#define sensorPin A0 

void setup() {
// Begin serial communication at 9600 baud rate 
Serial.begin(9600); 
}
void loop() { 
// Get the voltage reading from the LM35 
int reading = analogRead (sensorPin); 

// Convert that reading into voltage 
float voltage = reading (5.0/ 1024.0); 

// Convert the voltage into the temperature in Celsius f
loat temperatureC = voltage * 100; 

// Print the temperature in Celsius 
Serial.print ("Temperature: "); 
Serial.print (temperatureC); 
Serial.print ("\xC2\xB0"); // shows degree symbol 
Serial.print ("C | "); 

// Print the temperature in Fahrenheit 
float temperatureF= (temperatureC * 9.0/5.0) + 32.0; 
Serial.print (temperatureF); 
Serial.print ("\xC2\xB0"); // shows degree symbol 
Serial.println("F"); 

delay(1000); // wait a second between readings

}
