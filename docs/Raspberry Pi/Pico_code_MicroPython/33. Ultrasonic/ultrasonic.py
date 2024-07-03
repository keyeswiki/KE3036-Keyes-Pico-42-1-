'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 33
 * Ultrasonic
'''
from machine import Pin
import utime

# Ultrasonic ranging, unit: cm 
def getDistance(trigger, echo):
    # Generate 10us square wave 
    trigger.low()   #Pre-given a short low to ensure a clean high pulse: 
    utime.sleep_us(2)
    trigger.high()
    utime.sleep_us(10)#After pulling high, wait 10 microseconds, then set to low immediately 
    trigger.low()
    
    while echo.value() == 0: #Create a while loop to detect whether the echo pin is 0, and record the current time 
        start = utime.ticks_us()
    while echo.value() == 1: #Create a while loop to detect whether the echo pin is 1 and record the time at that time 
        end = utime.ticks_us()
    d = (end - start) * 0.0343 / 2 #The travel time of the sound wave x the speed of sound (343.2 m/s, or 0.0343 centimeters per microsecond), and then divide the round-trip distance by 2 
    return d

# set pins 
trigger = Pin(14, Pin.OUT)
echo = Pin(13, Pin.IN)
# main program 
while True:
    distance = getDistance(trigger, echo)
    print("The distance is ：{:.2f} cm".format(distance))
    utime.sleep(0.1)
