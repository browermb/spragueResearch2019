#include <DigiPotX9Cxxx.h>

// NC - Arduino pin 2
// U/D - Arduino pin 3
// CS - Arduino pin 4
// VH  - 5V
// VSS - GND

DigiPot pot(2,3,4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    delay(15);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int inByte = Serial.read();
  if (inByte != -1){
  Serial.println(inByte);

  pot.set(inByte);
  }
  delay(10);
}
