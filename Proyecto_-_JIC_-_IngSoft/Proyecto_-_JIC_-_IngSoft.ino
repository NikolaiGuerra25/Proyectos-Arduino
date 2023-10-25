//Blynk Template
#define BLYNK_TEMPLATE_ID "TMPL2rpgCwG1F"
#define BLYNK_DEVICE_NAME "Detector de Gas"
#define BLYNK_AUTH_TOKEN "klZTMIatT5hhJgVc9rcldlbN40jngB5K"

#define BLYNK_PRINT Serial

//Librerias
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <LiquidCrystal.h>

//WiFi
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = ""; // Change your Wifi/ Hotspot Name
char pass[] = ""; // Change your Wifi/ Hotspot Password

BlynkTimer timer;

//Variables
//Sensor
int SensorValue = 33;
int valorD = 0;
int valorA = 0;

//Pantalla
int rs = 23;
int e = 22;
int d4 = 21;
int d5 = 19;
int d6 = 18;
int d7 = 5;

//LEDs
int ledRojo = 12;
int ledVerde = 27;

//Buzzer
int buzzPin = 14;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void mySensor()
{
  //Limpiar Pantalla
  lcd.clear();
  
  //Valor Digital
  int valorD = analogRead(SensorValue);

  //Valor Analogico
  int valorA = valorD-(valorD*0.75);
  
  Blynk.virtualWrite(V0, valorA);
  
  if (valorA <= 250)
  {
    digitalWrite(ledRojo,LOW);
    digitalWrite(ledVerde,HIGH);

    lcd.setCursor(0,0);
    lcd.print("ESTADO: NORMAL");
  
    lcd.setCursor(0,1);
    lcd.print("VALOR: ");
    lcd.print(valorA);
    lcd.print(" ppm");

    digitalWrite(buzzPin, LOW);
  }
  else
  {
    if (valorA > 250 && valorA <= 800)
    {
      digitalWrite(ledRojo,HIGH);
      digitalWrite(ledVerde,LOW);
    
      lcd.setCursor(0,0);
      lcd.print("GAS DETECTADO");

      lcd.setCursor(0,1);
      lcd.print("VALOR: ");
      lcd.print(valorA);
      lcd.print(" ppm");

      digitalWrite(buzzPin, HIGH);

      //Alerta Blynk
      Blynk.logEvent("alerta_de_fuga_de_gas", "Fuga de Gas Detectada");
    }
    else
    {
      digitalWrite(ledRojo,HIGH);
      digitalWrite(ledVerde,LOW);
    
      lcd.setCursor(0,0);
      lcd.print("   PELIGRO  ");

      lcd.setCursor(0,1);
      lcd.print("VALOR: ");
      lcd.print(valorA);
      lcd.print(" ppm");

      digitalWrite(buzzPin, HIGH);

      //Alerta Blynk
      Blynk.logEvent("alerta_de_fuga_de_gas", "Fuga de Gas Detectada");
    }
  }
  
  Serial.print("MQ2 Level: ");
  Serial.println(valorA);
}

void setup() //Setup function - only function that is run in deep sleep mode
{
  //Inicio
  Serial.begin(9600);
  lcd.begin(16,2);
  Blynk.begin(auth, ssid, pass);//Splash screen delay
  
  //Modo
  pinMode(buzzPin,OUTPUT);
  pinMode(ledRojo,OUTPUT);
  pinMode(ledVerde,OUTPUT);

  //Pantalla Inicial
  lcd.setCursor(0,0);
  lcd.print("Iniciando Sensor");
  
  delay(5000);
  timer.setInterval(1000L, mySensor);
}

void loop() //Loop function
{
  Blynk.run();
  timer.run();
}
