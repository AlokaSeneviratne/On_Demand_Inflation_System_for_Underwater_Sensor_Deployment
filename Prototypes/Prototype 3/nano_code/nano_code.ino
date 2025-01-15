#include <Wire.h>
#include <Adafruit_BMP085.h>
#define seaLevelPressure_hPa 1006.00

Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    while (1) {}
  }
  Serial.println("Booted");
  }

  

void loop() {
  int x = bmp.readAltitude(seaLevelPressure_hPa * 100);
  Serial.print(bmp.readTemperature());
  Serial.print(",");
  Serial.print(bmp.readPressure());
  Serial.print(",");
  Serial.print(bmp.readAltitude());
  Serial.print(",");
  Serial.print(bmp.readSealevelPressure());
  Serial.print(",");
  Serial.print(bmp.readAltitude(seaLevelPressure_hPa * 100));
  Serial.println("");     

 if (x>=-0.25){  
      digitalWrite(6, LOW);  
    } 
  else{
    digitalWrite(6, HIGH);  
    }   
delay(1000);
}


