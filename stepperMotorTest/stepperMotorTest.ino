const int steerStp = 6;
const int steerDir = 7;
const int steerEna = 5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode( steerStp, OUTPUT );
  pinMode( steerDir, OUTPUT );
  pinMode(steerEna, OUTPUT);
  digitalWrite(steerEna, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite( steerDir, HIGH );
    digitalWrite( steerStp, HIGH );
    delayMicroseconds( 100 );
    digitalWrite( steerStp, LOW );
}
