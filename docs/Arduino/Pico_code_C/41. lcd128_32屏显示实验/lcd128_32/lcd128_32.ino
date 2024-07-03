/*
   Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
   lesson 41
   lcd128*32
*/
#include "lcd128_32_io.h"

//创建lcd12832实例,sda--->20， scl--->21
lcd lcd(20, 21);

void setup() {
  lcd.Init(); //初始化
  lcd.Clear();  //清屏
}

void loop() {
  lcd.Cursor(0, 7); //设置显示位置
  lcd.Display("KEYES"); //设置显示内容
  lcd.Cursor(1, 0);
  lcd.Display("ABCDEFGHIJKLMNOPQR");
  lcd.Cursor(2, 0);
  lcd.Display("123456789+-*/<>=$@");
  lcd.Cursor(3, 0);
  lcd.Display("%^&(){}:;'|?,.~\\[]");
}
