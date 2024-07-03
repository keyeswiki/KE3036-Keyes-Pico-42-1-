/*
   Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
   lesson 57
   SK6812 RGB
*/
#include"rgb.h"
RGB rgb(15, 4); //rgb(pin, num);  num = 0-100
//用来储存RGB颜色的变量
int R = 0;
int G = 0;
int B = 0;
int num = 0;
void setup() {
  rgb.setBrightness(100); //rgb.setBrightness(0-255);
  delay(10);
  rgb.clear(); //Turn off all leds
  delay(10);
}

void loop() {
  num++;
  if (num > 3) {  //num在0~3之间
    //取0~255之间的随机整数
    R = random(0, 255);
    G = random(0, 255);
    B = random(0, 255);
    num = 0;
  }
  rgb.setPixelColor(num, R, G, B); //设置num-1灯号颜色
  rgb.show();//显示
  delay(100);//200ms刷新颜色
}
