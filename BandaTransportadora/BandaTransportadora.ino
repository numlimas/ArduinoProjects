int sensor = 11; //pin de sensor
int motor = 2; //pin de motor
int solenoide = 3;
int ledRojo = 13; //pin led rojo de paro
int ledVerde = 10; //pin led verde de marcha
int value = 0;

 
void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  pinMode(sensor, INPUT);  //definir sensor como entrada
  pinMode(motor, OUTPUT); // pin de motor como salida
  pinMode(solenoide, OUTPUT); // pin de solenoide como salida
  pinMode(ledRojo, OUTPUT); // pin de led rojo como salida
  pinMode(ledVerde, OUTPUT); // pin de led verde como salida
}
 
void loop(){
  value = digitalRead(sensor);  //lectura digital de pin
 
  //mandar mensaje a puerto serie en función del valor leido
  if (value == LOW) {
      Serial.println("No hay obstaculo");
      digitalWrite(motor, HIGH);
      digitalWrite(solenoide, HIGH);
  }
  else {
      Serial.println("Obstaculo");
      digitalWrite(motor, LOW);
      digitalWrite(solenoide, LOW);
  }
 // delay(1000);
}
