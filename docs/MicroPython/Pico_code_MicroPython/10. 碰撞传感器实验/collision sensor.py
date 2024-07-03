'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 10
 * collision sensor
'''
from machine import Pin
import time

TiltSensor = Pin(17, Pin.IN)

while True:
    value = TiltSensor.value()
    print(value, end = " ")
    if  value== 0:
        print("The end of his!")
    else:
        print("All going well")
    time.sleep(0.1)