/*
   Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
   lesson 58
   Ultrasonic radar
*/
#include "KETM1650.h"//四位数码管的库文件
KETM1650 tm_4display(15, 14);

int beeppin = 16; //定义喇叭引脚为GP16
int EchoPin = 19; //Echo引脚接GP19
int TrigPin = 20; //Trig引脚接GP20
int distance;//超声波测的距离

int redPin = 9; //定义红色接GP9
int greenPin = 10; //定义绿色接GP10
int bluePin = 11; //定义蓝色接GP11

float checkdistance() { //获取距离
  // 预先给出一个短的低电平，以确保一个干净的高脉冲:
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  // 传感器由10微秒或更长时间的高脉冲触发
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  // 读取来自传感器的信号:一个高电平脉冲，
  //其持续时间是指从发送ping命令到接收物体回波的时间(以微秒计)。
  float distance = pulseIn(EchoPin, HIGH) / 58.00;  //换算成距离
  delay(10);
  return distance;
}

void setup() {
  tm_4display.init(); //数码管初始化
  pinMode(TrigPin, OUTPUT);//Trig引脚为输出
  pinMode(EchoPin, INPUT);  //Echo引脚为输入
  pinMode(beeppin, OUTPUT);//定义功放喇叭模块数字口为输出模式
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  distance = checkdistance(); //超声波测距
  tm_4display.displayString(distance);  //数码管显示距离
  if (distance <= 10) {
    tone(beeppin, 880);
    delay(100);
    noTone(beeppin);
    analogWrite(9, 255);//红色(255, 0, 0)
    analogWrite(10, 0);
    analogWrite(11, 0);

  } else if (distance > 10 && distance <= 20) {
    tone(beeppin, 532);
    delay(200);
    noTone(beeppin);
    analogWrite(9, 0);//蓝色(255, 0, 0)
    analogWrite(10, 0);
    analogWrite(11, 255);
  } else {
    analogWrite(9, 0);//绿色(255, 0, 0)
    analogWrite(10, 255);
    analogWrite(11, 0);
  }

}
