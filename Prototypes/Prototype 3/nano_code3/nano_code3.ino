#include <Wire.h>
#include <Adafruit_BMP085.h>
#define seaLevelPressure_hPa 1008.00

Adafruit_BMP085 bmp;
int timer=0;
int period = 1000;
unsigned long time_now = 0;

void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    while (1) {}
  }
  Serial.println("Booted");
  TCCR0A=(1<<WGM01);    //Set the CTC mode   
  OCR0A=0xF9; //Value for ORC0A for 1ms 
  
  TIMSK0|=(1<<OCIE0A);   //Set  the interrupt request
  sei(); //Enable interrupt
  
  TCCR0B|=(1<<CS01);    //Set the prescale 1/64 clock
  TCCR0B|=(1<<CS00);  
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
  Serial.println("");
/*
  //in this way you can count 1 second because the nterrupt request  is each 1ms
    if (-9.75>=x){  
      digitalWrite(6, LOW);  
    } 
    else if(x<=-10.25){
      digitalWrite(6, HIGH);  
    } 
    else{
    digitalWrite(6, HIGH);      
    }

  delay(1000);*/
}


/*ISR(TIMER0_COMPA_vect){    //This  is the interrupt request
  timer++;
}*/

