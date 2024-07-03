/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 16
 * 130DC Fan motor
*/
//定义电机的两个管脚接口，分别为14, 15
int INA = 14;
int INB = 15;
void setup() {
  //设置电机引脚为输出
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
}

void loop() {
  //逆时针转
  digitalWrite(INA, HIGH);
  digitalWrite(INB, LOW);
  delay(2000);
  //停止
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
  delay(1000);
  //顺时针转
  digitalWrite(INA, LOW);
  digitalWrite(INB, HIGH);
  delay(2000);
  //停止
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
  delay(1000);

}
