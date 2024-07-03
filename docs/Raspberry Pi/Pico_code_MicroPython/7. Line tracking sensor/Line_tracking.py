'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 7
 * Line Tracking sensor
'''
from machine import Pin
import time

sensor = Pin(3, Pin.IN, Pin.PULL_UP)

while True:
    if sensor.value() == 0:
        print("0   White")   #Press to print the corresponding information.
    else:
        print("1   Black")
    time.sleep(0.1) #wait for 0.1 second
