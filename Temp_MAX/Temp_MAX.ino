#include <Adafruit_MAX31865.h>
#include "SPI.h"
 
int CS1 = 53;
int CS2 = 51;

 
// Use software SPI: CS, DI, DO, CLK
//Adafruit_MAX31865 max = Adafruit_MAX31865(10, 11, 12, 13);
// use hardware SPI, just pass in the CS pin
Adafruit_MAX31865 max_1 = Adafruit_MAX31865(CS1);
Adafruit_MAX31865 max_2 = Adafruit_MAX31865(CS2);
//Adafruit_MAX31865 max_3 = Adafruit_MAX31865(8);
// The value of the Rref resistor. Use 430.0!
#define RREF 430.0
 
 
void setup() {
Serial.begin(115200);
max_1.begin(MAX31865_2WIRE);
max_2.begin(MAX31865_2WIRE);
//max_3.begin(MAX31865_3WIRE);
pinMode(CS1, OUTPUT);
pinMode(CS2, OUTPUT);
SPI.begin();
}
 
void loop() {
 
  digitalWrite(CS1, LOW);
  uint16_t rtd1 = max_1.readRTD();
  Serial.print("RTD value1: "); Serial.println(rtd1);
  float ratio1 = rtd1;
  ratio1 /= 32768;
  Serial.print("Resistance1 = "); Serial.println(RREF*ratio1,8);
  Serial.print("Temperature1 = "); Serial.println(max_1.temperature(100, RREF));
  digitalWrite(CS1, HIGH);
 

  delay(1000);
 
  digitalWrite(CS2, LOW);
  uint16_t rtd2 = max_2.readRTD();
  Serial.print("RTD value2: "); Serial.println(rtd2);
  float ratio2 = rtd2;
  ratio2 /= 32768;
  Serial.print("Resistance2 = "); Serial.println(RREF*ratio2,8);
  Serial.print("Temperature2 = "); Serial.println(max_2.temperature(100, RREF));
  digitalWrite(CS2, HIGH);
 
 
 delay(10000);
 
 
}
