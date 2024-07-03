'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 52
 * Smart_window
'''
import utime
from machine import Pin
from machine import PWM

pwm = PWM(Pin(9))#Servo pin is connected to GP9 
pwm.freq(50)#20ms period, so the frequency is 50Hz
sensor = machine.ADC(26)#ADC0
'''
The duty cycle corresponding to the angle 
0°----2.5%----1638
45°----5%----3276
90°----7.5%----4915
135°----10%----6553
180°----12.5%----8192
Considering the error, set the duty cycle at 1000~9000, so that it can rotate 0~180 degrees smoothly 
'''
angle_0 = 1638
angle_90 = 4915
angle_180 = 8192
    
while True:
    value = sensor.read_u16()
    print(value)
    if value > 2000:
        pwm.duty_u16(angle_0)
        utime.sleep(0.5)
    else:
        pwm.duty_u16(angle_180)
        utime.sleep(0.5)

    