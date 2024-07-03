 /*
   Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
   lesson 62
   Comprehensive experiment
*/
#include"ir.h"//红外接收的库
#include "xht11.h"
#include "adxl345_io.h"

//ADXL345 sda-->20,scl-->21
adxl345 adxl345(20, 21);

//红外接收接GP11
IR IRreceive(11);

//xht11 to gpio19
xht11 xht(19);

//rgb接2,3,4
int r_pin = 2;
int g_pin = 3;
int b_pin = 4;

//摇杆模块接口
int X = 26;
int Y = 27;
int KEY = 22;

//电位器管脚接模拟口28
int resPin = 28;

//LED接GP14
int LED = 14;

//避障传感器接GP0
int Avoid = 0;

//超声波传感器接口
int Trig = 6;
int Echo = 7;

//按键模块接口
int button = 16;

int PushCounter = 0;//存放按键按下的次数
int yushu = 0;
unsigned char dht[4] = {0, 0, 0, 0};//这里只接收前32位数据,未接收校验位
bool ir_flag = 1;
float out_X, out_Y, out_Z;

void counter() {
  delay(10);
  ir_flag = 0;
  if (!digitalRead(button)) {
    PushCounter++;
  }
}

void setup() {
  Serial.begin(9600);//设置波特率为9600
  pinMode(KEY, INPUT);//遥感模块的按钮
  pinMode(button, INPUT);//按键模块
  attachInterrupt(digitalPinToInterrupt(button), counter, FALLING);  //外部中断0，下降沿触发
  pinMode(Avoid, INPUT);//避障传感器
  pinMode(Trig, OUTPUT);//超声波模块
  pinMode(Echo, INPUT);
  adxl345.Init();
  delay(1000);
}

void loop() {
  yushu = PushCounter % 8;
  if (yushu == 0) {  //余数为0
    yushu_0();  //rgb显示
  } else if (yushu == 1) {  //余数为1
    yushu_1();  //显示红外遥控信号
  } else if (yushu == 2) {  //余数为2
    yushu_2();  //显示温湿度值
  } else if (yushu == 3) {  //余数为3
    yushu_3();  //显示摇杆值
  }else if (yushu == 4) {  //余数为4
    yushu_4();  //显示电位器控制LED
  } else if (yushu == 5) {  //余数为5
    yushu_5();  //避障传感器检测障碍物
  } else if (yushu == 6) {  //余数为6
    yushu_6();  //显示超声波测的距离
  } else if (yushu == 7) {  //余数为7
    yushu_7();  //ADXL345三轴加速度值
  }
}

//RGB
void yushu_0() {
  int R = random(0, 255);
  int G = random(0, 255);
  int B = random(0, 255);
  analogWrite(r_pin, R);
  analogWrite(g_pin, G);
  analogWrite(b_pin, B);
  delay(300);
}

//红外接收
void yushu_1() {
  ir_flag = 1;
  while (ir_flag) {
    int key = IRreceive.getKey();
    if (key != -1) {
      Serial.println(key);
    }
  }
}

void yushu_2() {
  if (xht.receive(dht)) { //检验正确返回true
    Serial.print("RH:");
    Serial.print(dht[0]); //湿度的整数部分,dht[1]为小数部分
    Serial.print("%  ");
    Serial.print("Temp:");
    Serial.print(dht[2]); //温度的整数部分,dht[3]为小数部分
    Serial.println("C");
  } else {    //读取错误
    Serial.println("sensor error");
  }
  delay(1200);
}

void yushu_3() {
  int x = analogRead(X);
  int y = analogRead(Y);
  int key = digitalRead(KEY);
  Serial.print("X:");
  Serial.print(x);
  Serial.print("    Y:");
  Serial.print(y);
  Serial.print("    KEY:");
  Serial.println(key);
  delay(100);
}

void yushu_4() {
  int RES = analogRead(resPin);
  int res = map(RES, 0, 4095, 0, 255);
  Serial.println(res);
  analogWrite(LED, res);
  delay(100);
}

void yushu_5() {
  int val = digitalRead(Avoid);
  if (val == 0) {//检测到障碍物
    Serial.println("There are obstacles");
  }
  else {//没检测到障碍物
    Serial.println("All going well");
  }
  delay(100);
}

void yushu_6() {
  float distance = checkdistance();
  Serial.print("distance:");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
}

void yushu_7() {
  adxl345.readXYZ(&out_X, &out_Y, &out_Z);
  Serial.print(out_X);
  Serial.print("g   ");
  Serial.print(out_Y);
  Serial.print("g   ");
  Serial.print(out_Z);
  Serial.println("g");
  delay(100);
}

float checkdistance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  float distance = pulseIn(Echo, HIGH) / 58.00;
  delay(10);
  return distance;
}
