#include <Adafruit_MCP4725.h>
#include <Wire.h>

Adafruit_MCP4725 dac1;
Adafruit_MCP4725 dac2;

int steerRelay = 7;
int brakeRelay = 8;

void setup() {
  dac1.begin(0x62);
  dac2.begin(0x63);
  pinMode(steerRelay, OUTPUT);
  pinMode(brakeRelay, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    delay(15);
  }
   Serial.println("Generating a triangle wave");
}

void loop() {
  // put your main code here, to run repeatedly:
   int counter;
    // Run through the full 12-bit scale for a triangle wave
    Serial.println("Setting: 0");
    dac1.setVoltage(0, false);
    dac2.setVoltage(0, false);
    
    delay(5000);
    Serial.println("Setting: 2048");

    dac1.setVoltage(2048, false);
    dac2.setVoltage(2048, false);
    delay(5000);
    Serial.println("Setting: 4095");

    dac1.setVoltage(4095, false);
    dac2.setVoltage(4095, false);
    delay(5000);

}
