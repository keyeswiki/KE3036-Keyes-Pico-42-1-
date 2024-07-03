/**
 * ���֣�18b20.cpp
 * ���ܣ�18b20����Դ�ļ�
 * 
 * ���ߣ�Dengfei
 * ʱ�䣺2022.1.6
 */

#ifndef _DS18B20_H__
#define _DS18B20_H__

#include "Arduino.h"

class DS18B20
{
  private:
    int DS18B20_Pin;
  
  public:
    DS18B20(int PIN);
    bool Get18B20Ack();
    void Write18B20(unsigned char dat);
    unsigned char Read18B20();
    long GetTemp();
};

#endif
