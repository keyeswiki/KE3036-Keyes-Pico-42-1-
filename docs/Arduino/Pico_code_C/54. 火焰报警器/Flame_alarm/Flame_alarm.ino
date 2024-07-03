/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 54
 * flame alarm
*/
int item = 0;
void setup() {
  Serial.begin(9600);
  pinMode(22, INPUT);//火焰传感器数字管脚接22
  pinMode(3, OUTPUT);//蜂鸣器管脚接3
}

void loop() {
  item = digitalRead(22);//读取火焰传感器输出的数字电平
  Serial.println(item);//换行打印电平信号
  if (item == 0) {//检测到火焰
    digitalWrite(3, HIGH);//打开蜂鸣器
  } else {//否则，关闭蜂鸣器
    digitalWrite(3, LOW);
  }
  delay(100);//延时100ms

}
