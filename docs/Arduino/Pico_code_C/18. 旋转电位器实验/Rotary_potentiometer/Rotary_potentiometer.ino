/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 18
 * Rotary potentiometer
*/
int analogVal = 0;
int resPin = 26; //电位器器接ADC0
void setup() {
  Serial.begin(9600);//设置波特率为9600
}

void loop() {
  analogVal = analogRead(resPin);//读取电位器的值
  Serial.println(analogVal);//打印模拟值
  delay(100);//延时100毫秒

}
