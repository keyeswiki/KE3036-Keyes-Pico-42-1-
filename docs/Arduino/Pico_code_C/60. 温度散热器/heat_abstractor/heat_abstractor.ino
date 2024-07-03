/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 60
 * heat abstractor
*/
#include <DS18B20.h>
#include "KETM1650.h" //导入TM1650的库文件
//两线接口为GP14, GP15
#define DIO 14
#define CLK 15
KETM1650 tm_4display(CLK, DIO);

//ds18b20 pin to 3
DS18B20 ds18b20(3);
void setup() {
  Serial.begin(9600);
  tm_4display.init(); //初始化
  tm_4display.setBrightness(3); //设置 亮度为3，范围（1~8）
  //电机接20 21
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);
}

void loop() {
  double temp = ds18b20.GetTemp();//读取温度
  temp *= 0.0625;//转换精度为0.0625/LSB
  Serial.println(temp);
  tm_4display.displayString(int(temp));//四位数码管显示温度值
  if (temp > 25) {//超过25摄氏度，开启风扇
    digitalWrite(20, LOW);
    digitalWrite(21, HIGH);
  } else {//否则 关闭风扇
    digitalWrite(20, LOW);
    digitalWrite(21, LOW);
  }
  delay(100);
}
