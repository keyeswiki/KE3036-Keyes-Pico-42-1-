/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 35
 * ds18b20
*/
#include <DS18B20.h>

//ds18b20 pin to 3
DS18B20 ds18b20(3);

void setup() {
  Serial.begin(9600);
}

void loop() {
  double temp = ds18b20.GetTemp();//读取温度
  temp *= 0.0625;//转换精度为0.0625/LSB
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println("C");
  delay(1000);
}
