/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 47
 * PIR alarm
*/
int item = 0;
void setup() {
  pinMode(15, INPUT);  //人体红外传感器接GP15并设置为为输入模式
  pinMode(16, OUTPUT);//有缘蜂鸣器接GP16并设置为为输出模式
}

void loop() {
  item = digitalRead(15);//读取红外热释传感器输出的数字电平信号
  if (item == 1) {  //检测到有人运动
    digitalWrite(16, HIGH); //打开蜂鸣器
  } else {  //没有检测到
    digitalWrite(16, LOW); //关闭蜂鸣器
  }
}
