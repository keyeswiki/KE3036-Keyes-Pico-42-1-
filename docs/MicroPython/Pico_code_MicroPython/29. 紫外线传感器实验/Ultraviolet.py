'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 29
 * UV_sensor
'''
import machine
import utime

sensor = machine.ADC(26)

while True:
    analogVal = sensor.read_u16()
    print(analogVal)
    utime.sleep(0.1)
