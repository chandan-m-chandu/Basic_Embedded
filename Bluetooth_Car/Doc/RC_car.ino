#define PIN_IN5 32
#define PIN_IN6 33
#define PIN_IN7 21
#define PIN_IN8 23
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;

void setup() {
  pinMode(PIN_IN5,OUTPUT);
  pinMode(PIN_IN6,OUTPUT);
  pinMode(PIN_IN7,OUTPUT);
  pinMode(PIN_IN8,OUTPUT);

  Serial.begin(115200);
  SerialBT.begin("CORI_fish"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()) {SerialBT.write(Serial.read());}
  if (SerialBT.available()) {Serial.write(SerialBT.read());}

  if(SerialBT.read()=='R'){
  digitalWrite(PIN_IN5,HIGH);
  digitalWrite(PIN_IN6,LOW);
  digitalWrite(PIN_IN7,LOW);
  digitalWrite(PIN_IN8,HIGH); 
 }
        
  if (SerialBT.read()=='L'){
 digitalWrite(PIN_IN5,LOW);
  digitalWrite(PIN_IN6,HIGH);
  digitalWrite(PIN_IN7,HIGH);
  digitalWrite(PIN_IN8,LOW); } 

  if(SerialBT.read()=='F'){
  digitalWrite(PIN_IN5,HIGH);
  digitalWrite(PIN_IN6,LOW);
  digitalWrite(PIN_IN7,HIGH);
  digitalWrite(PIN_IN8,LOW);  }

  if(SerialBT.read()=='B'){
  digitalWrite(PIN_IN5,LOW);
  digitalWrite(PIN_IN6,HIGH);
  digitalWrite(PIN_IN7,LOW);
  digitalWrite(PIN_IN8,HIGH); }

  if(SerialBT.read()=='O'){
  digitalWrite(PIN_IN5,LOW);
  digitalWrite(PIN_IN6,LOW);
  digitalWrite(PIN_IN7,LOW);
  digitalWrite(PIN_IN8,LOW);  }

  
}
  
  