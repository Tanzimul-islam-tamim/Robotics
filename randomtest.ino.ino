int in1 = 2;
int in2 = 5;
int in3 = 7;
int in4 = 10;

int on1 = 3;
int on2 = 6;
int on3 = 8;
int on4 = 11;

const int RaspiPhelps = 12;


int command;


void setup() {
    Serial.begin(9600);
    pinMode(RaspiPhelps, INPUT);

    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    pinMode(on1, OUTPUT);
    pinMode(on2, OUTPUT);
    pinMode(on3, OUTPUT);
    pinMode(on4, OUTPUT);

    pinMode(13,OUTPUT);
    digitalWrite(13,HIGH);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in3, LOW);

  digitalWrite(on1, LOW);
  digitalWrite(on2, LOW);
  digitalWrite(on4, LOW);
  digitalWrite(on3, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    stop(); 
  }
switch (command) {
      case 'F':
        Forward();
        break;
      case 'B':
        Back();
        break;
      case 'L':
        Left();
        break;
      case 'R':
        Right();
        break;

} 
}
void Forward(){

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  digitalWrite(on1, LOW);
  digitalWrite(on2, HIGH); 
  digitalWrite(on3, HIGH);
  digitalWrite(on4, LOW);
  
}

void Left(){ //Right and Left Fixed

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  
  digitalWrite(on1, LOW);
  digitalWrite(on2, HIGH);
  digitalWrite(on3, LOW);
  digitalWrite(on4, HIGH);
  

}

void Right(){ //Right and Left fixed

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  digitalWrite(on1, HIGH);
  digitalWrite(on2, LOW);
  digitalWrite(on3, HIGH);
  digitalWrite(on4, LOW);


}

void Back(){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  digitalWrite(on1, HIGH);
  digitalWrite(on2, LOW); 
  digitalWrite(on3, LOW);
  digitalWrite(on4, HIGH);
  
}

void stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in3, LOW);

  digitalWrite(on1, LOW);
  digitalWrite(on2, LOW);
  digitalWrite(on4, LOW);
  digitalWrite(on3, LOW);
}

void PhelpsVille(){
  
  Forward();
  delay(1800);
  stop();
  delay(2000);


  Right();
  delay(600);
  stop();
  delay(2000);

  Forward();
  delay(1800);
  stop();
  delay(2000);
  
  Left();
  delay(600);
  stop();
  delay(2000);


}
