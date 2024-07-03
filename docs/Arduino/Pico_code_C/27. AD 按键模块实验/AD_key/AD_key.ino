/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 27
 * AD Key
*/
int val = 0;
int ADkey = 26; //定义五路AD按键接GPIO26
void setup() {
  Serial.begin(9600); //设置波特率为9600
}

void loop() {
  val = analogRead(ADkey);  //读取AD按键的模拟值并赋给变量val
  Serial.print(val);  //换行打印变量val
  if (val <= 500) { //没有按键按下时，val小于等于500
    Serial.println("   no key  is pressed");

  } else if (val <= 1200) { //按键5按下时，val在500到1200之间
    Serial.println("   SW5 is pressed");
  } else if (val <= 2000) { //按键4按下时，val在1200到2000之间
    Serial.println("   SW4 is pressed");
  } else if (val <= 2800) { //按键3按下时，val在2000到2800之间
    Serial.println("   SW3 is pressed");
  } else if (val <= 3500) { //按键2按下时，val在2800到3500之间
    Serial.println("   SW2 is pressed");
  } else {  //按键1按下时，val大于3500
    Serial.println("   SW1 is pressed");
  }
  delay(200);

}
