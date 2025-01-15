#include <Wire.h>
#include <Adafruit_BMP085.h>
#define seaLevelPressure_hPa 1011.50

Adafruit_BMP085 bmp;

int t=0;

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
  int32_t pressure = bmp.readPressure()*1.3402;
  Serial.print(pressure);
  Serial.print(",");
  Serial.print(bmp.readAltitude());
  Serial.print(",");
  Serial.print(bmp.readSealevelPressure()*1.3402);
  Serial.print(",");  
  Serial.print(bmp.readAltitude(seaLevelPressure_hPa * 100));
  Serial.print(",");  
  Serial.print(t);
  Serial.println("");

  if ((t<=60000) && (x<=-0.25)){  
    if (-9.75>=x){  
      digitalWrite(6, LOW);  
    } 
    else if(x<=-10.25){
      digitalWrite(6, HIGH);  
    } 
    else{
    digitalWrite(6, HIGH);      
    }  

  }
  else if((t<=60000) && (x>-0.25)){
    digitalWrite(6, LOW);      
  }
  else{
    digitalWrite(6, HIGH);  
  }
delay(1000);
t++;  
}