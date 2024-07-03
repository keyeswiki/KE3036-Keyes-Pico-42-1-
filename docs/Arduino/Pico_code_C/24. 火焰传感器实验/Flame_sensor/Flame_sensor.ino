/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 24
 * Flame sensor

*/
//火焰传感器两个管脚，分别接22、26
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
  Serial.print(analogVal);  //打印模拟值
  Serial.print("    "); //空格隔开，方便观察
  Serial.println(digitalVal); //打印数字值
  delay(100); //延时100毫秒

}
