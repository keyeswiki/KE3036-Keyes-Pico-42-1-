/*
   Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
   lesson 39
   TM1650 Four digital tube
*/
#include "KETM1650.h" //导入TM1650的库文件
int item = 0; //要显示的值
//两线接口为GP14, GP15
#define DIO 14
#define CLK 15
KETM1650 tm_4display(CLK, DIO);

void setup() {
  tm_4display.init(); //初始化
  tm_4display.setBrightness(3); //设置 亮度为3，范围（1~8）
}

void loop() {
  tm_4display.displayString(item);//四位数码管显示item值
  item = item + 1;  //自加一
  if (item > 9999) {  //加到超过9999时，清零
    item = 0;
  }
  delay(100); //延时100毫秒
}
