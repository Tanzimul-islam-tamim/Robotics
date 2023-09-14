#include <Servo.h>
Servo myservo;
int pos = 0;
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   myservo.attach(9);
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(20);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(80);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
 
   cm = microsecondsToCentimeters(duration);
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(1000);
   
if(cm<8 ){


    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15 ms for the servo to reach the position
  }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20); 
  }
}
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}







void Moov(){
  
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(20);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(80);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
 
   cm = microsecondsToCentimeters(duration);
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(1000);
   
if(cm<8 ){

  for(int i =120; i>=0 ; i--)
{
  myservo.write(i);delay(10);
}
  for(int i =0; i<=120 ; i++)
{
  myservo.write(i);delay(10);
}
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

