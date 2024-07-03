'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 1.1
 * turn on led
'''
from machine import Pin

led = Pin(0, Pin.OUT)# Build the led object, connect the external LED light to pin 0, and set pin 0 to output mode 

led.value(1)# high level lighting 
    