 #include <dht.h>
 dht DHT;
 #define DHT11_PIN 8
 
 void setup() {
  Serial.begin(9600);
}

void loop() {
  DHT.read11(DHT11_PIN);

  //Temperatura
  Serial.print("Temperatura = ");
  Serial.print(DHT.temperature);
  Serial.println(" C");

  //Humedad
  Serial.print("Humedad = ");
  Serial.print(DHT.humidity);
  Serial.println(" %");

  delay(1000);
}
