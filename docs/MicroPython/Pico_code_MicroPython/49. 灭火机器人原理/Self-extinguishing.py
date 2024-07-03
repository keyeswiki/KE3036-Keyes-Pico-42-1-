'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 49
 * Self-extinguishing
'''
from machine import Pin
import time

#电机的两个引脚
INA = Pin(20, Pin.OUT)
INB = Pin(21, Pin.OUT)

flame_A = machine.ADC(26)

while True:
    value = flame_A.read_u16()
    print(value)
    if value < 30000:
        #开启
        INA.value(0)
        INB.value(1)
    else:
        #停止
        INA.value(0)
        INB.value(0)
    time.sleep(0.1)

