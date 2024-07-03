/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 17.2
 * rgb_2
*/
int redPin = 9; //定义红色接GP9
int greenPin = 10; //定义绿色接GP10
int bluePin = 11; //定义蓝色接GP11
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
void loop() {
  //红色(255, 0, 0)
  analogWrite(9, 255);
  analogWrite(10, 0);
  analogWrite(11, 0);
  delay(1000);
  //橙色(255, 97, 0)
  analogWrite(9, 255);
  analogWrite(10, 97);
  analogWrite(11, 0);
  delay(1000);
  //黄色(255, 255, 0)
  analogWrite(9, 255);
  analogWrite(10, 255);
  analogWrite(11, 0);
  delay(1000);
  //绿色(0, 255, 0)
  analogWrite(9, 0);
  analogWrite(10, 255);
  analogWrite(11, 0);
  delay(1000);
  //蓝色(0, 0, 255)
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 255);
  delay(1000);
  //青色(0, 255, 255)
  analogWrite(9, 0);
  analogWrite(10, 255);
  analogWrite(11, 255);
  delay(1000);
  //紫色(160, 32, 240)
  analogWrite(9, 160);
  analogWrite(10, 32);
  analogWrite(11, 240);
  delay(1000);

}
