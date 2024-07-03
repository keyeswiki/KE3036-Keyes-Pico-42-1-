'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 16
 * 130-DC Motor
'''
from machine import Pin
import time

#电机的两个引脚
INA = Pin(14, Pin.OUT)
INB = Pin(15, Pin.OUT)

while True:
    #Turn counterclockwise for 2s
    INA.value(1)
    INB.value(0)
    time.sleep(2)
    #Stop 1s
    INA.value(0)
    INB.value(0)
    time.sleep(1)
    #Turn clockwise 2s
    INA.value(0)
    INB.value(1)
    time.sleep(2)
    #stop 1s 
    INA.value(0)
    INB.value(0)
    time.sleep(1)