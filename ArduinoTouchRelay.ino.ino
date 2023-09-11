const int TouchPin = 2; const int Relay1 = 4; //This is for The the Water Sprinkling function PINs
int LastState1 = LOW; bool CurrentState1; int RelayState1 = LOW; //Function Variables #WaterSprinkling

void setup() {


  pinMode(TouchPin, INPUT);
  pinMode(Relay1, OUTPUT);
  digitalWrite(Relay1, HIGH);

}

void loop() {

  CurrentState1 = digitalRead(TouchPin); Serial.println(CurrentState1);
  if(LastState1==LOW && CurrentState1==HIGH ){              
    WaterSprinkle();  } 
 LastState1 = CurrentState1;

}

void WaterSprinkle(){
  if(RelayState1 == LOW){RelayState1 = HIGH;}
  else if(RelayState1 == HIGH){RelayState1 = LOW;}
  digitalWrite(Relay1, RelayState1);     
}
