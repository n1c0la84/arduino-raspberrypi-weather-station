#include <dht.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
 
#define DHT11_PIN 7
Adafruit_BMP085 bmp; dht DHT;
 
void setup() { 
  Serial.begin(9600); 
}
 
void loop() {
  short temperature, humidity, pressure; char input;
 
  if (Serial.available()){ 
    input = Serial.read();
    bmp.begin(); DHT.read11(DHT11_PIN);
 
    if (input == 'T') {
      // temperatura media tra le letture dei due sensori
      temperature = (DHT.temperature + bmp.readTemperature()) / 2;
      Serial.print(temperature);
    } 
    else if (input == 'H') {
      // umidità arrotondata all'intero più vicino
      humidity = (int)(DHT.humidity + 0.4);
      Serial.print(humidity);
    } 
    else if (input == 'P') {
      // pressione in millibar arrotondata all'intero più vicino
      pressure = (int)((bmp.readPressure() / 100.0) + 0.49);
      Serial.print(pressure);
    }
  }
}
