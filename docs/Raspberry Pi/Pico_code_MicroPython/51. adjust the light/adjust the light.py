'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 51
 * adjust the light
'''
import machine
import utime

potentiometer = machine.ADC(26)

pwm = machine.PWM(machine.Pin(15))
pwm.freq(1000)

while True:
    pot_value = potentiometer.read_u16()
    pwm.duty_u16(pot_value)
    utime.sleep(0.1)
