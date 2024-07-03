/*
   Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
   lesson 38
   ADXL345
*/
#include "adxl345_io.h"
//接口为sda-->9,scl-->910
adxl345 adxl345(9, 10);

float out_X, out_Y, out_Z;

void setup() {
  Serial.begin(57600);//启动串口监视,设置波特率为57600
  adxl345.Init();
}

void loop() {
  adxl345.readXYZ(&out_X, &out_Y, &out_Z);
  Serial.print(out_X);
  Serial.print("g   ");
  Serial.print(out_Y);
  Serial.print("g   ");
  Serial.print(out_Z);
  Serial.println("g");
  delay(100);
}
