
const int steerPin = A5;
const int steerStp = A;
const int steerDir = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600)
  pinMode(steerStp, OUTPUT);
  pinMode(steerDir, OUTPUT);
  pinMode(steerPin, INPUT);
}

void loop() {
  resistance = analogRead(steerPin);
  angle = 37.172*resistance - 1.2565;
  pulse = 615.2*pow(angle, -.849); //this is pulse per revolution

  //analogWrite is written in pwm
  pwm = map(pulse, 0, 300, 0, 255)
  analogWrite(steerStp, pwm)

  //TODO: figure out how to do the direction
  //      need a way to know which way we are turning

  //TODO make the stepper motor for that pulse
  delayMicroseconds(500);
}
