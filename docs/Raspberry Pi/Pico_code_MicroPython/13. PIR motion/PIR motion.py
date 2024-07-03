'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 13
 * PIR motion
'''
from machine import Pin
import time

PIR = Pin(19, Pin.IN)
while True:
    value = PIR.value()
    print(value, end = " ")
    if value == 1:
        print("Some body is in this area!")
    else:
        print("No one!")
    time.sleep(0.1)