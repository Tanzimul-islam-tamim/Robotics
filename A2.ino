#include <Servo.h>
Servo servo_med_openclose;



// Motor A connections
int en = 3;
int in1 = 7;
int in2 = 8;

//Touch Enable
bool Med;
int medicine=0;
const int medTouch;

//survo openclose
const int pingPin = 11; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 10; // Echo Pin of Ultrasonic Sensor


void setup() {
	// Set all the motor control pins to outputs
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
      pinMode(en, OUTPUT);
      pinMode(medTouch, INPUT);

    
        servo_med_openclose.attach(5);
 Serial.begin(9600); // Starting Serial Terminal
}


void loop(){
  /*
Med = digitalRead(medTouch);
if(Med == 1){
  InOut();
}
*/


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
   if(cm<8 ){InOut();}
   

}
long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

void InOut(){

if(medicine%2 == 0 ){
  medicine++;
  for(int i =0; i<5; i++){
  analogWrite(en, 60);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(5);}
  delay(3000);  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);



}
else{
  medicine++;



  for(int i =0; i<5; i++){
  analogWrite(en, 60);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(5);}
  delay(3000);  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}


}




void MedOpen(){
  for(int j=0; j <= 100; j++){
    servo_med_openclose.write(j);
    delay(30);
    }
}
void MedClose(){
  
    for(int j=100; j >= 0; j--){
    servo_med_openclose.write(j);
    delay(30);
    }
}