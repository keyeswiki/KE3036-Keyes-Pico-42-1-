'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 22
 * Temperature sensor
'''
import machine
import utime
import math

sensor = machine.ADC(0)
while True:
    temp = sensor.read_u16()
    print("Temperature ADC: ", end = " ")
    print(temp)
    utime.sleep(0.1)