#include <Servo.h>
Servo myservo;
int pos = 0;
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
int track1 = 0;
int track2 = 0;
int track3 = 0;
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
   if(cm<8 ){ Moov(); }
    else if(cm<60 && cm >15){
     FirstPos();
   }
   else if(cm> 60 && cm < 112){
     SecondPos();
   }
   else if(cm > 112 && cm <172){
     ThirdPos();
   }
   
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}







void Moov(){
  
  for(int i =120; i>=0 ; i--)
{
  myservo.write(i);delay(10);
}
  for(int i =0; i<=120 ; i++)
{
  myservo.write(i);delay(10);
}

}


void FirstPos(){

  if(track1 == 0){
    Serial.print("Track One Time \n");
    track1++;
  }
  else{  Serial.print("Track Changed!!! \n");
}
}
void SecondPos(){

  if(track2 == 0){
    Serial.print("Track Two Time \n");
    track2++;
  }
  else{  Serial.print("Track Changed!!! \n");
}
}
void ThirdPos(){

  if(track3 == 0){
    Serial.print("Track Three Time \n");
    track3++;
  }
  else{  Serial.print("Track Changed!!! \n");
}
}

