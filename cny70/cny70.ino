void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
int Sensor = analogRead(A0);

if (Sensor>= 50){ //para 1.5 cm de distancia
  Serial.print("Obstaculo");
  digitalWrite(13, HIGH);}
  else{
    digitalWrite(13, LOW);
   }
  Serial.print(Sensor);
  delay(100);
}
