/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 45
 * Avoiding alarm
*/
int item = 0;
void setup() {
  pinMode(15, INPUT);  //避障传感器接GP15并设置为输入模式
  pinMode(16, OUTPUT); //蜂鸣器接GP16并设置为输出模式
}

void loop() {
  item = digitalRead(15);//读取避障传感器输出的电平值
  if (item == 0) {//检测到障碍物
    digitalWrite(16, HIGH);//蜂鸣器响起
  } else {//没有检测到障碍物
    digitalWrite(16, LOW);//蜂鸣器关闭
  }
  delay(100);//延时100ms

}
