
const int steerPin = A5;
const int steerStp = 6;
const int steerDir = 7;
int totalPulses = 0;
const float stepAngle = .45;
boolean right = false;


void setup() {
  Serial.begin(9600);
  pinMode(steerStp, OUTPUT);
  pinMode(steerDir, OUTPUT);
  pinMode(steerPin, INPUT);
}

void loop() {
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
