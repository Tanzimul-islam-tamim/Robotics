#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display



void setup() {


}

void loop() {
  // put your main code here, to run repeatedly:
  // Print a message on both lines of the LCD.
    //  your setup code here, to run once:
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  
  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print("!! Welcome !!");
  lcd.setCursor(0, 1);
  lcd.print(" Dear Audience");
  delay(5000);

  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  
  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
  lcd.print("I am");
  lcd.setCursor(0, 1);
  lcd.print("____M.E.T.I.X____");
  delay(5000);

/*
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  
  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
  lcd.print("I am here");
  lcd.setCursor(0, 1);
  lcd.print("to guide you");
  delay(5000);
*/
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  
  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
  lcd.print("Please follow me");
  lcd.setCursor(0, 1);
  delay(5000);



   lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  
  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
  lcd.print("I will guide");
  lcd.setCursor(0, 1); 
  lcd.print("you to your seats");
  delay(5000);

}
