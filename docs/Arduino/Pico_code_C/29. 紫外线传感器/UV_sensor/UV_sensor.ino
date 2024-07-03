/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 29
 * UV sensor
*/
int val = 0;
void setup() {
  Serial.begin(9600);//设置波特率为9600
  pinMode(26, INPUT);//设置传感器的PIN为输入模式
}

void loop() {
  val = analogRead(26);//读取电平
  Serial.println(val);//打印模拟电平
  delay(100);

}
