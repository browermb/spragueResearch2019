#include <DigiPotX9Cxxx.h>

// 2 - U/D - Arduino pin 3
// 3 - VH  - 5V
// 4 - VSS - GND

DigiPot pot(2,3,4);
int inByte = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  while (!Serial) {
    delay(15);
  }
}

void loop() {
  inByte = Serial.read();
  if (inByte != -1) {
    
    if (inByte == 0) {
      digitalWrite(8, LOW);
    } else {
      digitalWrite(8, HIGH); 
    }
      pot.set(inByte);
  }
}
