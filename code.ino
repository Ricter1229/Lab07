#include <LiquidCrystal.h> 

/*
LiquidCrystal Library - Hello World
The circuit:
* LCD RS pin to digital pin 8
* LCD Enable pin to digital pin 9
* LCD D4 pin to digital pin 11
* LCD D5 pin to digital pin 12
* LCD D6 pin to digital pin 13
* LCD D7 pin to digital pin 14
* LCD R/W pin to ground
* 10K resistor:
* ends to +5V and ground
* wiper to LCD VO pin 
*/

LiquidCrystal lcd(8, 9, 11, 12, 13, 14);
void setup() {
  lcd.begin(16, 2); 
  lcd.print("06050375"); 
  lcd.setCursor(0, 1);
  lcd.print("Rick");
  Serial.begin(9600);
}
int x=0,y=0;
void loop() {
  if(Serial.available()) {
    lcd.clear();
    while(Serial.available()>0){
      char c = Serial.read();
      Serial.print(c);
      
      lcd.print(c); 
      x++;
      if(x == 16 && y == 0) {
        x = 0;
        y = 1;
        lcd.setCursor(x, y);
      }
      else if(x == 16 && y == 1) {
        x = 0;
        y = 0;
        lcd.setCursor(x, y);
      }
     } 
  }
}
