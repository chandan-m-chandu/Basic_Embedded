#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int servo1Pin = 12;      //servo above the base
int servo2Pin = 13;      //servo above the base
int servo3Pin = 7;      //servo in arm
int servo4Pin = 8;      //servo in gripper
int angle;
void setup(){
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  servo4.attach(servo4Pin);
  
}

void loop(){
    servo2.write(70);
    servo1.write(90);
    delay(1000);
  servo1.write(0);
  delay(2000);
/*servo1.write(90);
delay(2000);
servo1.write(0);
delay(5000);*/  

/*servo1.write(55);
delay(2000);
servo1.write(0);
delay(2000);*/ 
   }
