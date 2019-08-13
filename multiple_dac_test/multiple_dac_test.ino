#include <Adafruit_MCP4725.h>
#include <Wire.h>

Adafruit_MCP4725 dac1;
Adafruit_MCP4725 dac2;

int steerRelay = 9;
int brakeRelay = 8;

void setup() {
  Wire.begin();
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
    Serial.println("Setting: 0");
    dac1.setVoltage(0, false);
    dac2.setVoltage(0, false);
    digitalWrite(brakeRelay, LOW);
    digitalWrite(steerRelay, LOW);
    delay(5000);
    
    Serial.println("Setting: 2048");
    digitalWrite(brakeRelay, HIGH);
    digitalWrite(steerRelay, HIGH);
    dac1.setVoltage(2048, false);
    dac2.setVoltage(2048, false);
    delay(5000);
    
    Serial.println("Setting: 4095");
    dac1.setVoltage(4095, false);
    dac2.setVoltage(4095, false);
    delay(5000);

}
