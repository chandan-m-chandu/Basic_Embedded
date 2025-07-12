#include<Servo.h>
#define trigpin 2
#define echopin 4
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int servo1Pin = 7;      //servo in the base
int servo2Pin = 8;     //servo above the base.
int servo3Pin = 10;      //servo in arm
int servo4Pin = 11;      //servo in gripper.


void servo_arm(){
                  //pick statement for gripper.
  /*servo4.write(90);       
delay(3000);
  servo2.write(90);   
  servo3.write(90); 
delay(3000);
  servo1.write(180);
delay(3000);
  servo2.write(0);   
  servo3.write(0);
delay(3000);
  servo4.write(0);
delay(3000);
  servo2.write(90);   
  servo3.write(90);           //back to mean position of the arm*/

  servo4.write(0);
  servo3.write(90);
  delay(2000);
  servo4.write(90);
  delay(2000);
  servo3.write(0);
  delay(2000);
  
}

void setup() {
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  servo4.attach(servo4Pin);
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
Serial.begin(9600);
}

void loop() {
long duration, distance;
digitalWrite(trigpin,LOW);
delay(2);
digitalWrite(trigpin,HIGH);
delay(10);
digitalWrite(trigpin,LOW);
duration = pulseIn(echopin, HIGH);
distance = (duration/2) / 29.1;
Serial.println(distance);
servo1.write(0);              ////what if the zero and motor are fixed default to 90
servo2.write(0);   
servo3.write(0);
servo4.write(0);         
delay(3000);
if (distance<=10){servo_arm();}
  }
