'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 18
 * Rotary potentiometer
'''
import machine
import utime

potentiometer = machine.ADC(26)

while True:
    pot_value = potentiometer.read_u16()
    print(pot_value)
    utime.sleep(0.1)
