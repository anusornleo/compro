#include <Servo.h>
int ldr0 = 0;
int ldr_v0 = 0;
int ldr1 = 1;
int ldr_v1 = 0;
int ldr2 = 2;
int ldr_v2 = 0;
int ldr3 = 3;
int ldr_v3 = 0;
 
Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;
 
void setup()
{
  servo0.attach(8);
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  Serial.begin(9600);
  servo0.write(65);
  servo1.write(68);
  servo2.write(100);
  servo3.write(90);
  delay(5000);
}
 
void loop()
{
  
  servo0.write(65);
  servo1.write(68);
  servo2.write(100);
  servo3.write(90);
  if (analogRead(ldr0) > 400){
    servo0.write(78);
    delay(150);
    servo0.write(65);
    delay(150);
    /*if (analogRead(ldr0) <= 400){
      servo0.write(110);
      delay(200);
    }*/
  }
  
  else if  (analogRead(ldr1) > 400){
    servo1.write(57);
    delay(150);
    servo1.write(68);
    delay(150);
    /*if (analogRead(ldr1) <= 400){
      servo1.write(68);
      delay(200);
    }*/
  }
  
  else if (analogRead(ldr2) > 440){
    servo2.write(117);
    delay(150);
    servo2.write(100);
    delay(150);
    /*if (analogRead(ldr2) <= 440){
      servo2.write(100);
      delay(200);
    }*/
  }
  else if (analogRead(ldr3) > 500){
    servo3.write(72);
    delay(150);
    servo3.write(90);
    delay(150);
    /*if (analogRead(ldr3) <= 500){
      servo3.write(90);
      delay(200);
    }*/
  }
}

void runmode(){
  
}

