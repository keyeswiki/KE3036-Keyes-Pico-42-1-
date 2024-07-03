/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 28
 * Joystick
*/
int X = 0;
int Y = 0;
int Button = 0;

void setup() {
  Serial.begin(9600);
  pinMode(22, INPUT);  //定义遥感按钮的PIN为GP22
}

void loop() {
  X = analogRead(26); //遥感的X轴引脚接ADC0
  Y = analogRead(27); //遥感的Y轴引脚接ADC1
  Button = digitalRead(22);  //读取按钮的状态，并在下方打印出来
  Serial.write("X:");
  Serial.print(X);
  Serial.write("     Y:");
  Serial.print(Y);
  Serial.write("     B:");
  Serial.println(Button);
  delay(100);

}
