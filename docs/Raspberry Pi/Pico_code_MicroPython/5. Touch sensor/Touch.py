'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 5
 * Touch sensor
'''
from machine import Pin
import time

button = Pin(3, Pin.IN, Pin.PULL_UP)

while True:
    if button.value() == 1:
        print("You pressed the button!")   #Press to print the corresponding information 
    else:
        print("You loosen the button!")
    time.sleep(0.1) #Delay 0.1 seconds 
