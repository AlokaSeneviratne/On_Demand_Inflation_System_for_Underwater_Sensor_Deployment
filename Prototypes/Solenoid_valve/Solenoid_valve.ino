#include<Servo.h>
Servo Myservo;
Servo test1;
Servo test2;
int pos;
void setup()
{
Myservo.attach(9);
test1.attach(6);
test2.attach(10);
}

void loop()
{
for(pos=0;pos<=160;pos++){
Myservo.write(pos);
test1.write(pos);
test2.write(pos);
delay(15);
}
delay(1000); 
for(pos=160;pos>=0;pos--){
Myservo.write(pos);
test1.write(pos);
test2.write(pos);
delay(15);
}
delay(1000);
  
}
