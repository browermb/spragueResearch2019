#include <Adafruit_MCP4725.h>
#include <Wire.h>

Adafruit_MCP4725 dac1;
Adafruit_MCP4725 dac2;

int steerRelay = 7;
int brakeRelay = 8;
const int magicStart = 42;
const int magicEnd = 21;


void setup() {
  dac1.begin(0x62);
  dac2.begin(0x63);
  pinMode(steerRelay, OUTPUT);
  pinMode(brakeRelay, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    delay(15);
  }
}

void loop() {
  int firstByte = Serial.read();
  delay(10);
  int throttle = -1;
  int brakeVal = -1;
  int steering = -1;
  if (firstByte != -1) {

    while(firstByte != magicStart) {
      firstByte = Serial.read();
    }

    int secondByte = Serial.read();

    while(secondByte != magicEnd) {
      firstByte = Serial.read();
      while(firstByte != magicStart) {
        firstByte = Serial.read();
      }
      secondByte = Serial.read();
    }


    byte throttleByteVal1 = Serial.read();
    byte throttleByteVal2 = Serial.read();
    throttle = calculateVal(throttleByteVal1, throttleByteVal2);

    byte brakeByteVal1 = Serial.read();
    byte brakeByteVal2 = Serial.read();
    brakeVal = calculateVal(brakeByteVal1, brakeByteVal2);

    byte steeringByteVal1 = Serial.read();
    byte steeringByteVal2 = Serial.read();
    steering = calculateVal(steeringByteVal1, steeringByteVal2);
    
    Serial.println(throttle);
    Serial.println(brakeVal);
    Serial.println(steering);
  }

  /**if(throttle != -1 && brakeVal != -1 && steering != -1) {
    
    accel(throttle);
    brake(brakeVal);
    steer(steering);
  }**/
}

void accel(int throttleVal) {
  int val = map(throttleVal, 0, 255, 0, 4095);
  dac1.setVoltage(val, false);
  if (throttleVal == 0) {
    digitalWrite(steerRelay, LOW);
  } else {
    digitalWrite(steerRelay, HIGH); 
  }
}

void brake(int brakeVal) {
  int val = map(brakeVal, 0, 255, 0, 4095); 
  dac2.setVoltage(val, false);
  if (brakeVal == 0) {
    digitalWrite(brakeRelay, LOW);
  } else {
    digitalWrite(brakeRelay, HIGH); 
  }
}

void steer(int steerVal) {

}

int calculateVal(byte byteVal1, byte byteVal2) {
  return ((byteVal1 & 0xff) << 8 | (byteVal2 & 0xff));

}
