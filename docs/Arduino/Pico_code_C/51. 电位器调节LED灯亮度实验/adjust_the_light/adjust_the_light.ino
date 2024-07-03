/*
   Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
   lesson 51
   adjust the light
*/
int val1 = 0;//这个变量用来存放模拟值
int val2 = 0;//这个变量用来存放要输出的PWM值
void setup() {
  Serial.begin(9600);//设置波特率为9600
}

void loop() {
  val1 = analogRead(26);//读取电位器的模拟值
  Serial.print(val1);//打印模拟值
  Serial.print("  ");
  val2 = map(val1, 0, 4095, 0, 255);//把模拟值范围映射到输出到PWM值范围
  Serial.println(val2);//打印转换后的PWM值
  analogWrite(15, val2);//引脚15输出PWM值
  delay(100);//延时100ms
}
