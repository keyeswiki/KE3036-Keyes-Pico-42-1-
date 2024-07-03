'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 2
 * Traffic_Light
'''
import machine
import time

led_red = machine.Pin(14, machine.Pin.OUT)
led_amber = machine.Pin(13, machine.Pin.OUT)
led_green = machine.Pin(12, machine.Pin.OUT)

while True:
    led_green.value(1) # Green light on for 5 seconds 
    time.sleep(5)# 5 seconds later 
    led_green.value(0)# green light off 
    for i in range(3):#Yellow light flashes 3 times 
        led_amber.value(1)
        time.sleep(0.5)
        led_amber.value(0)
        time.sleep(0.5)
    led_red.value(1) # Red light on for 5 seconds 
    time.sleep(5)
    led_red.value(0)
