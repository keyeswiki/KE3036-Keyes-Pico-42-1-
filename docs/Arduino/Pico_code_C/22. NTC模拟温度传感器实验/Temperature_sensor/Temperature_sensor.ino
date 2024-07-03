/* 
 * Keyes42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 22
 * Temperature sensor

*/
int val;
int ntcPin = 26;  //设置NTC-MF52AT模拟温度传感器接ADC0
void setup() {
  Serial.begin(9600);//设置波特率为9600
}

void loop() {
  val = analogRead(ntcPin); //读取温度模拟值
  Serial.println(val); //读取并打印热敏电阻模拟值
  delay(100);//延时100毫秒

}
