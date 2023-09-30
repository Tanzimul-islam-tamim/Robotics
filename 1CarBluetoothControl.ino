int in1 = 3;
int in2 = 4;
int in3 = 5;
int in4 = 6;

int lig = 8;

int command;


void setup() {
    Serial.begin(9600);

    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    
    pinMode(lig, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in3, LOW);

  digitalWrite(lig, LOW);




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

      case 'W':
        digitalWrite(lig,HIGH); //For resetting the arduino
        break;

      
      case 'w':
        digitalWrite(lig,LOW); //For resetting the arduino
        break;
}
}
void Forward(){

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  
}

void Left(){ //Right and Left Fixed

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  

}

void Right(){ //Right and Left fixed

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  

}

void Back(){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  
}

void stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in3, LOW);


}

