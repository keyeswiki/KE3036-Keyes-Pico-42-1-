'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 14
 * Active buzzer
'''
from machine import Pin
import time

buzzer = Pin(20, Pin.OUT)
while True:
    buzzer.value(1)
    time.sleep(1)
    buzzer.value(0)
    time.sleep(1)