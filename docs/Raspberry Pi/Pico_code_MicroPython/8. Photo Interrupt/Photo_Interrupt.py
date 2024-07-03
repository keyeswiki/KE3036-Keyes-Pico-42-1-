'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 8
 * Photo_Interrupt
'''
from machine import Pin
import time

sensor = Pin(3, Pin.IN, Pin.PULL_UP)
lastState = 0
PushCounter = 0

while True:
    State = sensor.value()
    if  State != lastState:
        if State == 1:
            PushCounter += 1
            print(PushCounter)   #Print count value
    lastState = State

