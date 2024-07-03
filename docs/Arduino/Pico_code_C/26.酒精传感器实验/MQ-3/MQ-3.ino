/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 26
 * MQ3
*/
//烟雾传感器两个管脚，分别接22、26
int digitalPin =  22;
int analogPin = 26;
//以下两个变量分别存放数字信号与模拟信号
int analogVal = 0;
int digitalVal = 0;

void setup() {
  Serial.begin(9600); //设置波特率为9600
  pinMode(digitalPin, INPUT); //数字引脚22设置为输入模式
}

void loop() {
  analogVal = analogRead(analogPin);  //读取模拟信号
  digitalVal = digitalRead(digitalPin);  //读取数字信号
  Serial.print(analogVal);
  if (digitalVal == 1) {
    Serial.println("    Normal");
  }
  else {
    Serial.println("    Exceeding");
  }
  delay(100); //延时100毫秒

}
