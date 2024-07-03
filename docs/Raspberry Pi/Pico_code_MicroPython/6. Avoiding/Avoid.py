'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 6
 * Infrared obstacle avoidance sensor
'''
from machine import Pin
import time

sensor = Pin(16, Pin.IN)
while True:
    if sensor.value() == 0:
        print("There are obstacles")
    else:
        print("All going well")
    time.sleep(0.1)