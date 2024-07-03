'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 3
 * Laser
'''
from machine import Pin
import time

laser = Pin(2, Pin.OUT)# Build the laser object, connect the laser to pin 0, and set pin 2 to output mode 
while True:
    laser.value(1)# Laser on
    time.sleep(2)# wait 2 seconds 
    laser.value(0)# Laser off
    time.sleep(2)# wait 2 seconds 