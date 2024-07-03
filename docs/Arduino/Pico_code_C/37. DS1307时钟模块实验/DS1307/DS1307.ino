/*
   Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
   lesson 37
   DS1307 Real Time Clock
*/
#include <Wire.h>
#include "RtcDS1307.h"  //DS1307时钟模块的库

RtcDS1307<TwoWire> Rtc(Wire);//i2c接口

void setup(){
  Serial.begin(57600);//设置波特率为57600
  Rtc.Begin();
  Rtc.SetIsRunning(true);

  Rtc.SetDateTime(RtcDateTime(__DATE__, __TIME__));

  
}

void loop(){
  //打印年/月/日/时/分/秒/星期
  Serial.print(Rtc.GetDateTime().Year());
  Serial.print("/");
  Serial.print(Rtc.GetDateTime().Month());
  Serial.print("/");
  Serial.print(Rtc.GetDateTime().Day());
  Serial.print("    ");
  Serial.print(Rtc.GetDateTime().Hour());
  Serial.print(":");
  Serial.print(Rtc.GetDateTime().Minute());
  Serial.print(":");
  Serial.print(Rtc.GetDateTime().Second());
  Serial.print("    ");
  Serial.println(Rtc.GetDateTime().DayOfWeek());
  delay(1000);//延时1秒

}
