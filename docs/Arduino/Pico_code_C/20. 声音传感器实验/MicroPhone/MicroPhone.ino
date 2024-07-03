/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 20
 * MicroPhone
*/
int val = 0;
int Microphone = 27;  //麦克风传感器接ADC1
void setup() {
  Serial.begin(9600);//设置波特率9600
}

void loop() {
  val = analogRead(Microphone); //读取传感器的值赋给变量val
  Serial.println(val);  //换行打印传感器输出的模拟值
  delay(100); //加延时100MS

}
