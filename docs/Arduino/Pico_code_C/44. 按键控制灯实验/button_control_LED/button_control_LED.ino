/* 
 * Keyes42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 44
 * button control LED
*/
int button = 16;//按键的管脚接数字口16
int led = 15;//LED的管脚接GP15
bool led_flag;
void setup() {
  pinMode(button, INPUT);  //按键的管脚设置为输入模式
  pinMode(led, OUTPUT);  //LED的管脚设置为输出模式
  attachInterrupt(digitalPinToInterrupt(button), toggle_handle, FALLING);  //外部中断0，下降沿触发
}

void loop() {
  digitalWrite(led, led_flag);//按下按键点亮LED或者熄灭LED
  delay(100);
}

void toggle_handle(){//切换LED状态
  led_flag = !led_flag;
}
