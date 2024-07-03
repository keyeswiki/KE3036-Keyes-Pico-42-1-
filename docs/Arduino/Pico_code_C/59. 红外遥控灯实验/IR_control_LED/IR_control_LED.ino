/*
   Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
   lesson 59
   IR control LED
*/
#include"ir.h"
IR IRreceive(16);//红外接收接GP16
int led = 14;//LED接GP14
boolean flag = true;//LED标志位
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  delay(1000);
}
////////////////////
void loop() {
  Serial.println("IR receive");
  while (1) {
    int key = IRreceive.getKey();
    if (key != -1) {
      Serial.print(key);
      if (key == 64) { //按下OK键
        if (flag == true) {//flag为真
          digitalWrite(led, HIGH);//打开LED
          Serial.println("  led on");
          flag = false;//flag变为假
        } else { //flag为假
          digitalWrite(led, LOW);//关闭LED
          Serial.println("  led off");
          flag = true;//flag变为真
        }
      }
    }
  }
}
