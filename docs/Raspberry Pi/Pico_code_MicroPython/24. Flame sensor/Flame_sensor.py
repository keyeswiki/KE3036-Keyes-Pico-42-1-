'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 24
 * Flame sensor
'''
import machine
import utime

flame_D = machine.Pin(22, machine.Pin.IN)
flame_A = machine.ADC(26)

while True:
    digitalVal = flame_D.value()
    analogVal = flame_A.read_u16()
    print(digitalVal, end = "  ")
    print(analogVal)
    utime.sleep(0.1)
