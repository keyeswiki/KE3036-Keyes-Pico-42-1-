/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 21
 * Photoresistance
*/
int val = 0;
int photoPin = 28;  //光敏电阻传感器接模拟口ADC2
void setup() {
  Serial.begin(9600);//设置波特率9600
}

void loop() {
  val = analogRead(photoPin);//读取传感器器的值
  Serial.println(val);//打印值
  delay(100);//延时100MS

}
