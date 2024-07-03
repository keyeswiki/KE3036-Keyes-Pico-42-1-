/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 17.1
 * rgb_1
*/
int redPin = 9; //定义红色接GP9
int greenPin = 10; //定义绿色接GP10
int bluePin = 11; //定义蓝色接GP11
void setup(){
  //输出口都设置为输出模式
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop(){
  //红色
  digitalWrite(redPin,HIGH);
  digitalWrite(greenPin,LOW);
  digitalWrite(bluePin,LOW);
  delay(1000);
  //绿色
  digitalWrite(redPin,LOW);
  digitalWrite(greenPin,HIGH);
  digitalWrite(bluePin,LOW);
  delay(1000);
  //蓝色
  digitalWrite(redPin,LOW);
  digitalWrite(greenPin,LOW);
  digitalWrite(bluePin,HIGH);
  delay(1000);

}
