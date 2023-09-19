// Motor A connections
int en = 3;
int in1 = 7;
int in2 = 8;

//Touch Enable
bool Med;
int medicine=0;
const int medTouch = 11;


void setup() {
	// Set all the motor control pins to outputs
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
      pinMode(en, OUTPUT);
      pinMode(medTouch, INPUT);

    


}


void loop(){
Med = digitalRead(medTouch);
if(Med == 1){
  InOut();
}

}


void InOut(){

if(medicine%2 == 0 ){
  medicine++;
  for(int i =0; i<5; i++){
  analogWrite(en, 50);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(5);}
  delay(1000);  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
else{
  medicine--;
  for(int i =0; i<5; i++){
  analogWrite(en, 50);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(5);}
  delay(1000);  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}


}

