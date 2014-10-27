/*
  State change detection (edge detection)
 	
 Often, you don't need to know the state of a digital input all the time,
 but you just need to know when the input changes from one state to another.
 For example, you want to know when a button goes from OFF to ON.  This is called
 state change detection, or edge detection.
 
 This example shows how to detect when a button or button changes from off to on
 and on to off.
 	
 The circuit:
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 * LED attached from pin 13 to ground (or use the built-in LED on
 most Arduino boards)
 
 created  27 Sep 2005
 modified 30 Aug 2011
 by Tom Igoe
 
 This example code is in the public domain.
 	
 http://arduino.cc/en/Tutorial/ButtonStateChange
 
 */

// this constant won't change:
const int  sensorPin = A0;    // the pin that the pushbutton is attached to
const int ledPin = 9;       // the pin that the LED is attached to

int sensorValue=0;
int brightness=0;

void setup() {
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  brightness=map(sensorValue,0,1023,0,255);
  brightness=constrain(brightness,0,255);
  analogWrite(ledPin,brightness);

  delay(10);

}










