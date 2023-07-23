int ledRojo = 13;
int ledVerde = 8;
int buzz = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledRojo,OUTPUT);
  pinMode(ledVerde,OUTPUT);
  pinMode(buzz,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(ledRojo,HIGH);
  digitalWrite(ledVerde,HIGH);
  digitalWrite(buzz,HIGH);
  delay(1000);

  digitalWrite(ledRojo,LOW);
  digitalWrite(ledVerde,LOW);
  digitalWrite(buzz,LOW);
  delay(1000);
}
