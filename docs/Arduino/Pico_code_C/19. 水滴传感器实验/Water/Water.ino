/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 19
 * Steam sensor
*/
int val = 0;
int Water = 26; //水蒸气传感器的PIN为26
void setup() {
  Serial.begin(9600);//设置波特率为9600
}

void loop() {
  val = analogRead(Water);  //读取水蒸气传感器的值
  Serial.print("Water:");
  Serial.println(val);
  delay(100);

}
