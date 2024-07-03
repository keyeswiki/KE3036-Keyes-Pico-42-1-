/*
   Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
   lesson 49
   Self-extinguishing
*/
int item = 0;
void setup() {
  Serial.begin(9600);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);
}

void loop() {
  item = analogRead(26);//火焰传感器接26，读取火焰传感器的模拟值赋给item
  Serial.println(item);//串口显示模拟值
  if (item < 200) {//低于200
    digitalWrite(20, LOW);//打开风扇
    digitalWrite(21, HIGH);
  } else {//否则关闭风扇
    digitalWrite(20, LOW);
    digitalWrite(21, LOW);
  }
  delay(100);
}
