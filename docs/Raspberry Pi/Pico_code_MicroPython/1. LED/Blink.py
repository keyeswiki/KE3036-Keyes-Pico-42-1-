'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 1.2
 * Blink
'''
from machine import Pin
import time

led = Pin(0, Pin.OUT)# Build the led object, connect the external LED light to pin 0, and set pin 0 to output mode 
while True:
    led.value(1)# Led on
    time.sleep(1)# Wait for 1 second
    led.value(0)# led off 
    time.sleep(1)# Wait for 1 second