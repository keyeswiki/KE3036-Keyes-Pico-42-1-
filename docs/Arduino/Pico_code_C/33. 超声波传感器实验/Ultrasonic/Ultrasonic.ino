/*
   Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
   lesson 33
   Ultrasonic
*/
int distance = 0; //定义一个用来接收距离的变量
int EchoPin = 13; //Echo引脚接GP13
int TrigPin = 14; //Trig引脚接GP14
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
  Serial.begin(9600);//设置波特率为9600
  pinMode(TrigPin, OUTPUT);//Trig引脚为输出
  pinMode(EchoPin, INPUT);  //Echo引脚为输入
}

void loop() {
  distance = checkdistance();
  if (distance < 2 || distance >= 400) {  //在范围外打印"-1"
    Serial.println("-1");
    delay(100);
  }
  else {  //打印距离，单位厘米
    Serial.print("distance:");
    Serial.print(distance);
    Serial.println("cm");
    delay(100);
  }

}
