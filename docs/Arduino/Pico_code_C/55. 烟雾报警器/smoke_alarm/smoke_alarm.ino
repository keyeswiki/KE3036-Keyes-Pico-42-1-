/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 55
 * smoke alarm
*/
#include "KETM1650.h" //导入TM1650的库文件
int val = 0; //要显示的值
//两线接口为GP14, GP15
#define DIO 14
#define CLK 15
KETM1650 tm_4display(CLK, DIO);

void setup() {
  tm_4display.init(); //初始化
  tm_4display.setBrightness(3); //设置 亮度为3，范围（1~8）
  pinMode(3, OUTPUT);//有缘蜂鸣器接3
}

void loop() {
  val = analogRead(26);//读取烟雾模拟值
  tm_4display.displayString(val);//四位数码管显示val值
  if (val > 1000) {//模拟值大于1000
    digitalWrite(3, HIGH); //蜂鸣器报警
  } else {//否则
    digitalWrite(3, LOW); //关闭蜂鸣器
  }
  delay(100);//延时100ms
}
