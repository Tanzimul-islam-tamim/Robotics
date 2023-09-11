

const int TouchPin1 = 7; const int Relay2 = 8; //Input Output function PINs
int LastState2 = LOW; bool CurrentState2; int RelayState2 = LOW; //Function Variables #Gatorade

void setup() {


  pinMode(TouchPin1, INPUT);
  pinMode(Relay2, OUTPUT);
  digitalWrite(Relay2, HIGH);

}

void loop() {

  CurrentState2 = digitalRead(TouchPin1); Serial.println(CurrentState2);
  if(LastState2==LOW && CurrentState2==HIGH ){              
    Gatorade();  } 
 LastState2 = CurrentState2;

}

void Gatorade(){
  
  if(RelayState2 == LOW){RelayState2 = HIGH;}
  else if(RelayState2 == HIGH){RelayState2 = LOW;}
  digitalWrite(Relay2, RelayState2);     
  
}
