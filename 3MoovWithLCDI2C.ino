#include <LiquidCrystal_I2C.h>
#include <Servo.h>
Servo myservo;
//int pos = 0;
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
//int soundInput = A0;
//const int TouchToStartPos = 13;

int track1 = 0;
int track2 = 0;
int track3 = 0;
int ntf = 3;
int time = 0;
int cm; int cm2;  long dura;
LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   myservo.attach(10);
myservo.write(120);

    //  pinMode(soundInput, INPUT);
    //  pinMode(TouchToStartPos,INPUT);






  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  
  // Print a message on both lines of the LCD.
  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print("COUBERTIN");
  
  lcd.setCursor(2,1);   //Move cursor to character 2 on line 1
  lcd.print(" on Wheels...");
}

void loop() {

   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(20);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(80);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
 
   cm = microsecondsToCentimeters(duration);
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
//bool touch = digitalRead(TouchToStartPos);
  // int sound = analogRead(soundInput);
    
//Serial.println(cm);
//Serial.println(sound);

   if(cm<10){ Moov(); }else{
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  
  // Print a message on both lines of the LCD.
  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
    lcd.print("C O U B ER T I N");

  lcd.setCursor(2,1);   //Move cursor to character 2 on line 1
  lcd.print(" on wheels...");}
//Serial.println(touch);


}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}


void Moov(){
  
  lcd.init();
  lcd.clear();         
  lcd.backlight(); 
  lcd.setCursor(0,0);
  lcd.print("Spray Activated");



  for(int i =120; i>=0 ; i--)
{
  myservo.write(i);delay(10);
}
  for(int i =0; i<=120 ; i++)
{
  myservo.write(i);delay(10);
}

}


void PositionsOn(){
        if(cm<60 && cm >15 ){
     FirstPos();
   }
   else if(cm> 60 && cm < 112){
     SecondPos();
   }
   else if(cm > 112 && cm <172){
     ThirdPos();
   }
}

void FirstPos(){

  lcd.init();
  lcd.clear();         
  lcd.backlight(); 
  lcd.setCursor(0,0);
  lcd.print("Track One");
  lcd.setCursor(0,1);
  lcd.print("runner came");
  delay(100);
  lcd.init();
  lcd.clear();         
  lcd.backlight(); 
  lcd.setCursor(0,0);
  lcd.print("Track One");
  lcd.setCursor(0,1);
  lcd.print("Time:");
  lcd.setCursor(6,1);
  lcd.print(time);
  ntf--;
}

void SecondPos(){

  lcd.init();
  lcd.clear();         
  lcd.backlight(); 
  lcd.setCursor(0,0);
  lcd.print("Track Two");
  lcd.setCursor(0,1);
  lcd.print("runner came");
  delay(100);
  lcd.init();
  lcd.clear();         
  lcd.backlight(); 
  lcd.setCursor(0,0);
  lcd.print("Track Two");
  lcd.setCursor(0,1);
  lcd.print("Time:");
  lcd.setCursor(6,1);
  lcd.print(time);
  ntf--;
 // ntf--;
}
void ThirdPos(){

  lcd.init();
  lcd.clear();         
  lcd.backlight(); 
  lcd.setCursor(0,0);
  lcd.print("Track Three");
  lcd.setCursor(0,1);
  lcd.print("runner came");
  delay(100);
  lcd.init();
  lcd.clear();         
  lcd.backlight(); 
  lcd.setCursor(0,0);
  lcd.print("Track Three");
  lcd.setCursor(0,1);
  lcd.print("Time:");
  lcd.setCursor(6,1);
  lcd.print(time);
 // ntf--;
  ntf--;
}



   



