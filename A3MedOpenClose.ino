#include <Servo.h>
Servo servo_med_openclose;
 int med = 0; const int TouchMed = 2;


void setup() {
Serial.begin(9600);

  // put your setup code here, to run once:
  pinMode(TouchMed, INPUT);
servo_med_openclose.attach(9);

servo_med_openclose.write(0);


}

void loop() {

bool n = digitalRead(TouchMed);
Serial.println(n);
if(n == 1){OCD();}else{}



}

void OCD(){
  if(med==0){
    MedOpen();
    med++;
  }
  else{
    MedClose();
    med--;
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


