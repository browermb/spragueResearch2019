
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int inByte = 0;         // incoming serial byte

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  while (!Serial) {
      delay(15);      ; // wait for serial port to connect. Needed for native USB port only
   }
}

void loop() {
  while(1) {
    //pos = (pos +1) % 180;
      inByte = Serial.read();
      if (inByte != -1) {
         //Serial.write(inByte);
         pos = inByte;

          if (inByte == 0) {
               digitalWrite(8, LOW);
           } else {
              digitalWrite(8, HIGH);
           }
      }
     
      
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
  }

}
