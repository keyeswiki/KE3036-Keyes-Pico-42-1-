/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 43
 * Breath
*/
int LED = 15; //LED管脚接GP15

void setup() {
  pinMode(LED, OUTPUT);  //设置LED引脚为输出模式
}

void loop() {
  for (int i = 0; i <= 255; i++) {  //从0到255，每次加1
    analogWrite(LED, i);
    delay(10);//延时10ms
  }
  for (int i = 255; i >= 0; i--) {  //从255到0，每次减1
    analogWrite(LED, i);
    delay(10);//延时10ms
  }
}
