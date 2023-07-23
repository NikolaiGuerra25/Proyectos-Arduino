//Librerias
#include <LiquidCrystal.h>

//Pines - Variables
int rs = 12;
int e = 11;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() 
{
  // put your setup code here, to run once:
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("ANONYMUS-507");
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("SERENO-DAVID");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0,1);
  lcd.print("LA 25");
}
