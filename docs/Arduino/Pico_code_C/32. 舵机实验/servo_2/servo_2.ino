/*
   Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
   lesson 32.2
   servo_2
*/
#include <Servo.h>  //舵机库
Servo myservo;
void setup() {
  myservo.attach(0);//舵机连接GP0
}

void loop() {
  for (int pos = 0; pos < 180; pos++) {
    myservo.write(pos); //转动到pos角度
    delay(15);  //加延时转慢一点
  }
  for (int pos = 180; pos > 0; pos--) {
    myservo.write(pos);
    delay(15);
  }
  delay(2000);//等待2秒
}
