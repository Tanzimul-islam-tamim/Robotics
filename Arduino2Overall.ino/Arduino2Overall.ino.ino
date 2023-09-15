#include <Servo.h>



//WaterSprinkle-0
const int TouchPin = 2; const int Relay1 = 4; //This is for The the Water Sprinkling function PINs
int LastState1 = LOW; bool CurrentState1; int RelayState1 = LOW; //Function Variables #WaterSprinkling
//WaterSprinkle-1

/*Gatorade-0
const int TouchPin1 = 7; const int Relay2 = 8; //Input Output function PINs
int LastState2 = LOW; bool CurrentState2; int RelayState2 = LOW; //Function Variables #Gatorade
//Gatorade-1
*/
//MedKit-0
Servo servo_med_inout;  Servo servo_med_openclose;
const int TouchPin2 = 12; bool TouchStateMed;
int medicine = 0; 
//MedKit-1

//swim-0
Servo servo_under1;
Servo servo_under2;
int swim_switch = 0;
bool SwitchState;
//swim-1




void setup() {
//WaterSprinkle-0
  pinMode(TouchPin, INPUT);
  pinMode(Relay1, OUTPUT);
  digitalWrite(Relay1, HIGH);
//WaterSprinkle-1

/*Gatorade-0
  pinMode(TouchPin1, INPUT);
  pinMode(Relay2, OUTPUT);
  digitalWrite(Relay2, HIGH);
//Gatorade-1*/

//MedKit-0
pinMode(TouchPin2, INPUT);
servo_med_inout.attach(3);
servo_med_openclose.attach(5);
//MedKit-1


//SwimMode-0

servo_under1.attach(6);
servo_under2.attach(9);
pinMode(13, INPUT);
//SwimMode-1



}

void loop() {
//WaterSprinkle-0
  CurrentState1 = digitalRead(TouchPin); Serial.println(CurrentState1);
  if(LastState1==LOW && CurrentState1==HIGH ){              
    WaterSprinkle();  } 
 LastState1 = CurrentState1;
//WaterSprinkle-1

/*Gatorade-0
  CurrentState2 = digitalRead(TouchPin1); Serial.println(CurrentState2);
  if(LastState2==LOW && CurrentState2==HIGH ){              
    Gatorade();  } 
 LastState2 = CurrentState2;
//Gatorade-1 */

//MedKit-0
TouchStateMed = digitalRead(TouchPin2);
if(TouchStateMed==1){MedKit();}
//MedKit-1

//SwimMode-0
SwitchState = digitalRead(13);
Serial.println(SwitchState);
if(SwitchState==1){SwimMode();}
//SwimMode-1


}




/*Gatorade-0
void Gatorade(){
  if(RelayState2 == LOW){RelayState2 = HIGH;}
  else if(RelayState2 == HIGH){RelayState2 = LOW;}
  digitalWrite(Relay2, RelayState2);      
}
//Gatorade-1*/

//WaterSprinkle-0
void WaterSprinkle(){
  if(RelayState1 == LOW){RelayState1 = HIGH;}
  else if(RelayState1 == HIGH){RelayState1 = LOW;}
  digitalWrite(Relay1, RelayState1);     
}
//WaterSprinkle-1


//MedKit-0
void MedKit(){
  if(medicine%2 == 0)
  {
    //survo out
  for(int i=0;i <= 180; i++){
    servo_med_inout.write(i);
    delay(10);
    }
  for(int j=0; j <= 100; j++){
    servo_med_openclose.write(j);
    delay(30);
    }
  medicine++;
  }
  else{
    //survo in
    for(int j=100; j >= 0; j--){
    servo_med_openclose.write(j);
    delay(30);
    }
    for(int i=180;i >= 0; i--){
      servo_med_inout.write(i);
      delay(10);
    }

    medicine++;
  }

}
//MedKit-1




//SwimMode-0
void SwimMode(){
if(swim_switch%2 == 0){
  servo_under1.write(120);
  servo_under2.write(0);
  swim_switch++;
  Serial.print("Opnd");
}
else{
    servo_under1.write(0);
    servo_under2.write(120);
    swim_switch++;
    Serial.print("Closd");
}
}
//SwimMode-1

