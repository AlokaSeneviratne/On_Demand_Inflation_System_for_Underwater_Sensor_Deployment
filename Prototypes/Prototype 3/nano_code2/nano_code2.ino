#include <Wire.h>
#include <Adafruit_BMP085.h>
#define seaLevelPressure_hPa 1011.50

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

  /*
  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  Serial.print("Altitude = ");
  Serial.print(bmp.readAltitude());
  Serial.println(" meters");

  Serial.print("Pressure at sealevel (calculated) = ");
  Serial.print(bmp.readSealevelPressure());
  Serial.println(" Pa");

  Serial.print("Real altitude = ");
  Serial.print(bmp.readAltitude(seaLevelPressure_hPa * 100));
  Serial.println(" meters");

  Serial.println();
*/
  int x = bmp.readAltitude(seaLevelPressure_hPa * 100);
  Serial.print(bmp.readTemperature());
  Serial.print(",");
  int32_t pressure = bmp.readPressure()*1.3402;
  Serial.print(pressure);
  Serial.print(",");
  Serial.print(bmp.readAltitude());
  Serial.print(",");
  Serial.print(bmp.readSealevelPressure()*1.3402);
  Serial.print(",");  
  Serial.print(bmp.readAltitude(seaLevelPressure_hPa * 100));
  Serial.println("");

  if (-9.75>=x){  
      digitalWrite(6, LOW);  
    } 
    else if(x<=-10.25){
      digitalWrite(6, HIGH);  
    } 
    else{
    digitalWrite(6, HIGH);      
    }  

  delay(1000);
}