/*
   Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
   lesson 53
   sound-controlled lights
*/
int ledPin = 15;//LED接GP15
int microPin = 26;//声音传感器接ADC0（GP26）
void setup() {
  Serial.begin(9600);//设置波特率为9600
  pinMode(ledPin, OUTPUT);//LED为输出模式
}

void loop() {
  int val = analogRead(microPin);//读取模拟值
  Serial.print(val);//串口打印
  if(val > 200){//超过阈值200
    digitalWrite(ledPin, HIGH);//点亮LED3s，并打印相应信息
    Serial.println("  led on");
    delay(3000);
  }else{//否则
    digitalWrite(ledPin, LOW);//关闭LED， 并打印相应信息
    Serial.println("  led off");
  }
  delay(100);
}
