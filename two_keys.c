#include "Keyboard.h"

const int inputPin1 = 4;
const int inputPin2 = 6;
const int ledPin = 13;
bool currentState1 = LOW;
bool beforeState1 = LOW;
bool currentState2 = LOW;
bool beforeState2 = LOW;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(inputPin1, INPUT);
  pinMode(inputPin2, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  Keyboard.begin();
}

// the loop function runs over and over again forever
void loop() {
  currentState1 = digitalRead(inputPin1);
  currentState2 = digitalRead(inputPin2);

  if ( currentState1 != beforeState1 ){
    if ( currentState1 == HIGH ){
      digitalWrite(ledPin, HIGH);
      Serial.println("1 Push!");
      Keyboard.press( 0x61 );
    }else{
      digitalWrite(ledPin, LOW);
      Serial.println("1 Release!");
      Keyboard.release( 0x61 );
    }
    beforeState1 = currentState1;
  }

  if ( currentState2 != beforeState2 ){
    if ( currentState2 == HIGH ){
      digitalWrite(ledPin, HIGH);
      Serial.println("2 Push!");
      Keyboard.press( 0x62 );
    }else{
      digitalWrite(ledPin, LOW);
      Serial.println("2 Release!");
      Keyboard.release( 0x62 );
    }
    beforeState2 = currentState2;
  }
}
