const int steerPin = A5;

void setup() {
  Serial.begin(9600);
  pinMode(steerPin, INPUT);
}

void loop() {
  int val = analogRead(steerPin);
  Serial.println(val);
}
