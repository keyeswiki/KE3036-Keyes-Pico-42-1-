'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 19
 * Steam sensor
'''
import machine
import utime

sensor = machine.ADC(26)#ADC0

while True:
    value = sensor.read_u16()
    print(value)
    utime.sleep(0.1)
