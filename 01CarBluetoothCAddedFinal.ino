int in1 = 2;
int in2 = 5;
int in3 = 7;
int in4 = 10;

int on1 = 3;
int on2 = 6;
int on3 = 8;
int on4 = 11;

const int RaspiPhelps = 13;





void setup() {

    pinMode(RaspiPhelps, INPUT);

    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    pinMode(on1, OUTPUT);
    pinMode(on2, OUTPUT);
    pinMode(on3, OUTPUT);
    pinMode(on4, OUTPUT);


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
 // bool phelps
delay(10000);
Forward();
Right();
Left();
Back();




}
void Forward(){

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  digitalWrite(on1, LOW);
  digitalWrite(on2, HIGH); 
  digitalWrite(on3, LOW);
  digitalWrite(on4, HIGH);
  
  delay(1000);  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in3, LOW);

  digitalWrite(on1, LOW);
  digitalWrite(on2, LOW);
  digitalWrite(on4, LOW);
  digitalWrite(on3, LOW);
}

void Right(){

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  
  digitalWrite(on1, LOW);
  digitalWrite(on2, HIGH);
  digitalWrite(on3, HIGH);
  digitalWrite(on4, LOW);
  

}
void Left(){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  digitalWrite(on1, HIGH);
  digitalWrite(on2, LOW);
  digitalWrite(on3, LOW);
  digitalWrite(on4, HIGH);

  delay(50000);   ////Change This according to you required destination

}

void Back(){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  digitalWrite(on1, HIGH);
  digitalWrite(on2, LOW); 
  digitalWrite(on3, HIGH);
  digitalWrite(on4, LOW);
  

}

