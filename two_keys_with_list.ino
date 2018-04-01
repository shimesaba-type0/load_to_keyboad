#include "Keyboard.h"

const int keyNum = 4;

const int inputPin[keyNum] = { 3, 4, 5, 6 };
const byte keyMap[keyNum]  = { 0x61, 0x62, 0x63, 0x64 };
//const int ledPin = 13;
bool currentState[keyNum];
bool beforeState[keyNum];

int i;

void setup() {
  for( i = 0; i < keyNum; i++ ){
    pinMode(inputPin[i], INPUT);
    currentState[i] = LOW;
    beforeState[i] = LOW;
  }
  Serial.begin(9600);
  Keyboard.begin();
}

// the loop function runs over and over again forever
void loop() {
  for( i = 0; i < keyNum; i++ ){
    currentState[i] = digitalRead(inputPin[i]);
    
    if ( currentState[i] != beforeState[i] ){
      Serial.print("key");
      Serial.print(i);
      if ( currentState[i] == HIGH ){
        Serial.println(" push");
        Keyboard.press( keyMap[i] );
      } else {
        Serial.println(" Release");
        Keyboard.release( keyMap[i] );
      }
      beforeState[i] = currentState[i];
    }
  }
}
