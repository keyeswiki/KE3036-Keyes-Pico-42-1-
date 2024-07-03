/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 13
 * PIR motion
*/
int val = 0;
int pirPin = 19; //定义人体红外传感器管脚为GP19
void setup() {
  Serial.begin(9600); //设置波特率为9600
  pinMode(pirPin, INPUT);  //设置传感器为输入模式
}

void loop() {
  val = digitalRead(pirPin);  //读取传感器的值
  Serial.print(val);//打印val值
  if (val == 1) {//附近有人运动,输出高电平
    Serial.print("        ");
    Serial.println("Some body is in this area!");
    delay(100);
  }
  else {//没检测到人体运动，则输出低电平
    Serial.print("        ");
    Serial.println("No one!");
    delay(100);
  }
}
