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
const int ledPin = 12;       // the pin that the LED is attached to

// Variables will change:
int stateCounter = 0;   // counter for the number of button presses
boolean sensorState = 0;         // current state of the button
boolean lastState = 0;     // previous state of the button

int threshold=300;  // threshold to change the sensorState

int sensorValue=0;

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
  
  if(sensorValue<threshold){
    sensorState=HIGH;
  }
  else {
    sensorState=LOW;
  }

  // compare the buttonState to its previous state
  if (sensorState != lastState) {
    // if the state has changed, increment the counter
    if (sensorState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      stateCounter++;
    } 
    else {
    }
  }
  // save the current state as the last state, 
  //for next time through the loop
  lastState = sensorState;

  
  // turns on the LED every four button pushes by 
  // checking the modulo of the button push counter.
  // the modulo function gives you the remainder of 
  // the division of two numbers:
  if (stateCounter % 2 == 1) {
    digitalWrite(ledPin, HIGH);
  } else {
   digitalWrite(ledPin, LOW);
  }
  
  delay(10);
  
}









