/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 15
 * Passive buzzer
*/
int beeppin = 21; //定义喇叭引脚为GP21
void setup() {
  pinMode(beeppin, OUTPUT);//定义功放喇叭模块数字口为输出模式
}

void loop() {
  tone(beeppin, 262);//DO播放1000ms
  delay(1000);
  tone(beeppin, 294);//Re播放750ms
  delay(750);
  tone(beeppin, 330);//Mi播放625ms
  delay(625);
  tone(beeppin, 349);//Fa播放500ms
  delay(500);
  tone(beeppin, 392);//So播放375ms
  delay(375);
  tone(beeppin, 440);//La播放250ms
  delay(250);
  tone(beeppin, 494);//Si播放125ms
  delay(125);
  noTone(beeppin);//停止播放一秒
  delay(1000);
}
