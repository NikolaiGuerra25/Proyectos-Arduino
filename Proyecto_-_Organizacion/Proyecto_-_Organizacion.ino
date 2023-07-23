//Librerias
#include <LiquidCrystal.h>

//Pines - Variables
//Pines - Pantalla
int rs = 22;
int e = 24;
int d4 = 32;
int d5 = 34;
int d6 = 36;
int d7 = 38;

//Pines - Sensor de Gas
int sensorValue;

//Pines - Buzzer
int buzzPin = 44;

//Pines - LED
int ledRojo = 53;
int ledVerde = 51;

//Funcion Pantalla
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

//Inicio
void setup()
{
  //Ingreso
  pinMode(buzzPin,OUTPUT);
  pinMode(ledRojo,OUTPUT);
  pinMode(ledVerde,OUTPUT);
  
  //Inicio
  Serial.begin(9600);
  lcd.begin(16,2);

  //Pantalla Inicial
  lcd.setCursor(0,0);
  lcd.print("Iniciando Sensor");

  delay(2000);
}

void loop()
{
  sensorValue = analogRead(A0);
  
  if (sensorValue <= 200)
  {
    digitalWrite(ledRojo,LOW);
    digitalWrite(ledVerde,HIGH);
    
    lcd.setCursor(0,0);
    lcd.print("ESTADO: NORMAL");
  
    lcd.setCursor(0,1);
    lcd.print("VALOR: ");
    lcd.print(sensorValue);
    lcd.print(" ppm");

    digitalWrite(buzzPin, LOW);
  }
  
  if (sensorValue > 200 && sensorValue <= 800)
  {
    digitalWrite(ledRojo,HIGH);
    digitalWrite(ledVerde,LOW);
    
    lcd.setCursor(0,0);
    lcd.print("GAS DETECTADO");

    lcd.setCursor(0,1);
    lcd.print("VALOR: ");
    lcd.print(sensorValue);
    lcd.print(" ppm");
    
    digitalWrite(buzzPin, HIGH);
  }

  if (sensorValue > 800)
  {
    digitalWrite(ledRojo,HIGH);
    digitalWrite(ledVerde,LOW);
    
    lcd.setCursor(0,0);
    lcd.print("ESTADO: PELIGRO");

    lcd.setCursor(0,1);
    lcd.print("VALOR: ");
    lcd.print(sensorValue);
    lcd.print(" ppm");
    
    digitalWrite(buzzPin, HIGH);
  }
  
  delay(1000);
  lcd.clear();
}
