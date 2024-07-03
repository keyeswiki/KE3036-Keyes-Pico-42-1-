/* 
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 48
 * play music
*/
#define D0 -1
#define D1 262
#define D2 293
#define D3 329
#define D4 349
#define D5 392
#define D6 440
#define D7 494
#define M1 523
#define M2 586
#define M3 658
#define M4 697
#define M5 783
#define M6 879
#define M7 987
#define H1 1045
#define H2 1171
#define H3 1316
#define H4 1393
#define H5 1563
#define H6 1755
#define H7 1971
//列出全部D调的频率
#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625
//列出所有节拍
int tune[] =       //根据简谱列出各频率
{
  D5, D5, D6, D5, M1, D7,
  D5, D5, D6, D5, M2, M1,
  D5, D5, M5, M3, M1, D7, D6,
  M4, M4, M3, M1, M2, M1
};
float durt[] =      //根据简谱列出各节拍
{
  0.5, 0.5, 1, 1, 1, 1 + 1,
  0.5, 0.5, 1, 1, 1, 1 + 1,
  0.5, 0.5, 1, 1, 1, 1, 1,
  0.5, 0.5, 1, 1, 1, 1 + 1
};
int beeppin = 15; //功放喇叭引脚接GP15
int length;
void setup() {
  pinMode(beeppin, OUTPUT);     //设置蜂鸣器引脚输出模式
  length = sizeof(tune) / sizeof(tune[0]); //计算长度
}

void loop() {
  for (int x = 0; x < length; x++)
  {
    tone(beeppin, tune[x]);
    delay(500 * durt[x]); //这里用来根据节拍调节延时，500这个指数可以自己调整，在该音乐中，我发现用500比较合适。
    noTone(beeppin);
  }
  delay(2000);
}
