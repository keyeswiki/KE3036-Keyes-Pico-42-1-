'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 27
 * AD key
'''
import machine
import utime

ad_key = machine.ADC(26)

while True:
    value = ad_key.read_u16()
    print(value, end = '')
    if value <= 6000:
        print("  no key  is pressed")
    elif value <= 20000:
        print("  SW5 is pressed")
    elif value <= 32000:
        print("  SW4 is pressed")
    elif value <= 45000:
        print("  SW3 is pressed")
    elif value <= 59000:
        print("  SW2 is pressed")
    else:
        print("  SW1 is pressed")
    utime.sleep(0.1)

