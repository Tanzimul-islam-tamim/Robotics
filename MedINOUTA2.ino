// Motor A connections
int in1 = 7;
int in2 = 8;
int medicine=0;
const int medTouch = 2;
bool med;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
     // pinMode(en, OUTPUT);
      pinMode(medTouch, INPUT);

//analogWrite(en, 100);
//digitalWrite(in1, HIGH);
//digitalWrite(in2, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
med = digitalRead(medTouch);
Serial.println(med);
if(med == 1){
  InOut();
//med = 0;
}
}
void InOut(){

if(medicine == 0 ){
  medicine++;
  //analogWrite(en, 60);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  delay(1500);  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  //analogWrite(en, 0);

}
else{
  //  digitalWrite(13, 1); delay(100); digitalWrite(13,0); delay(5000);

  medicine--;

//delay(10);
  //analogWrite(en, 60);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  delay(1500);  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  //analogWrite(en, 0);
}


}
