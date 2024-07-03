/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 14
 * Active buzzer
*/
int buzzer = 20; //定义蜂鸣器接管脚GP20
void setup() {
  pinMode(buzzer, OUTPUT);//设置输出模式
}

void loop() {
  digitalWrite(buzzer, HIGH); //发声
  delay(1000);
  digitalWrite(buzzer, LOW); //停止发声
  delay(1000);
}
