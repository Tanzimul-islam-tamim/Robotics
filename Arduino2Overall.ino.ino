



//WaterSprinkle-0
const int TouchPin = 2; const int Relay1 = 4; //This is for The the Water Sprinkling function PINs
int LastState1 = LOW; bool CurrentState1; int RelayState1 = LOW; //Function Variables #WaterSprinkling
//WaterSprinkle-1

//Gatorade-0
const int TouchPin1 = 7; const int Relay2 = 8; //Input Output function PINs
int LastState2 = LOW; bool CurrentState2; int RelayState2 = LOW; //Function Variables #Gatorade
//Gatorade-1







void setup() {
//WaterSprinkle-0
  pinMode(TouchPin, INPUT);
  pinMode(Relay1, OUTPUT);
  digitalWrite(Relay1, HIGH);
//WaterSprinkle-1

//Gatorade-0
  pinMode(TouchPin1, INPUT);
  pinMode(Relay2, OUTPUT);
  digitalWrite(Relay2, HIGH);
//Gatorade-1




}

void loop() {
//WaterSprinkle-0
  CurrentState1 = digitalRead(TouchPin); Serial.println(CurrentState1);
  if(LastState1==LOW && CurrentState1==HIGH ){              
    WaterSprinkle();  } 
 LastState1 = CurrentState1;
//WaterSprinkle-1

//Gatorade-0
  CurrentState2 = digitalRead(TouchPin1); Serial.println(CurrentState2);
  if(LastState2==LOW && CurrentState2==HIGH ){              
    Gatorade();  } 
 LastState2 = CurrentState2;
//Gatorade-1


}




//Gatorade-0
void Gatorade(){
  if(RelayState2 == LOW){RelayState2 = HIGH;}
  else if(RelayState2 == HIGH){RelayState2 = LOW;}
  digitalWrite(Relay2, RelayState2);      
}
//Gatorade-1

//WaterSprinkle-0
void WaterSprinkle(){
  if(RelayState1 == LOW){RelayState1 = HIGH;}
  else if(RelayState1 == HIGH){RelayState1 = LOW;}
  digitalWrite(Relay1, RelayState1);     
}
//WaterSprinkle-1




