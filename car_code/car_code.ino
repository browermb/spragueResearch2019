#include <DigiPotX9Cxxx.h>
#include <RoboClaw.h>
#include <Stepper.h>
#include <SoftwareSerial.h>

SoftwareSerial serial(10,11);  
RoboClaw roboclaw(&serial,10000);

const int steerPin = A5;
const int steerStp = 6;
const int steerDir = 7;
int totalPulses = 0;
const float stepAngle = .45;
boolean right = false;

DigiPot pot(2,3,4); // U/D -> pin 3 VH -> 5V VSS -> GND
const int digiPotPin = 8;
int inByte = 0; 

#define address 0x80

void setup() {
  Serial.begin(9600);
  roboclaw.begin(38400);
  
  pinMode(digiPotPin, OUTPUT);

  pinMode(steerStp, OUTPUT);
  pinMode(steerDir, OUTPUT);
  pinMode(steerPin, INPUT);
  
  while (!Serial) {
    delay(15);
  }
}

void loop() {
  steer();
  accel();
}

void steer() {
  int num_pulses;
  int val = analogRead(steerPin);
  
  int angle = map(val, 0, 1023, 0, 270);

  int currentAngle = totalPulses*stepAngle;
  
  if ((angle - currentAngle) > 0) {
      //Move right
      right = true;
      num_pulses = abs(angle - currentAngle)/stepAngle;
      digitalWrite(steerDir, HIGH);
  } else {
      //Move left
      right = false;
      num_pulses = abs(angle - currentAngle)/stepAngle;
      digitalWrite(steerDir, LOW);
  }

  if (num_pulses > 3) {
     if (right) {
       totalPulses = totalPulses + num_pulses;
     } else {
       totalPulses = totalPulses - num_pulses;
     }
    for (int i = 0; i < num_pulses; i++) {
      digitalWrite( steerStp, HIGH );
      delayMicroseconds( 50);
      digitalWrite( steerStp, LOW );
      delay( 1 );
    }
  }

}

void accel() {
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
}
