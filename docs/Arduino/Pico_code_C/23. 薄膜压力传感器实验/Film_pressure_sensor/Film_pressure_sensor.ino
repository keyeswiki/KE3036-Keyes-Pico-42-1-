/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 23
 * Film pressure sensor
*/
int val = 0;
int Film = 27; //薄膜压力传感器接ADC1
void setup() {
  Serial.begin(9600);//设置波特率为9600
}
void loop() {
  val = analogRead(Film);//读取模拟值
  Serial.println(val);//打印模拟值
  delay(100);//延时100MS

}
