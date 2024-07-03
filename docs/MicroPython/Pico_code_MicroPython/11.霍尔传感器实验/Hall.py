'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 11
 * Hall magnetic
'''
from machine import Pin
import time

hall = Pin(5, Pin.IN)
while True:
    value = hall.value()
    print(value, end = " ")
    if value == 0:
        print("A magnetic field")
    else:
        print("There is no magnetic field")
    time.sleep(0.1)