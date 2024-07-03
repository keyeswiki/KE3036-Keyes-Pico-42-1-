'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 32.2
 * Servo test 2
'''
from utime import sleep
from machine import Pin
from machine import PWM

pwm = PWM(Pin(0))#Servo pin is connected to GP0 
pwm.freq(50)#20ms period, so the frequency is 50Hz
'''
角度对应的占空比
0°----2.5%----1638
45°----5%----3276
90°----7.5%----4915
135°----10%----6553
180°----12.5%----8192
Considering the error, set the duty cycle at 1000~9000, so that it can rotate 0~180 degrees smoothly 
'''
# Set the rotation angle of the servo 
def setServoCycle (position):
    pwm.duty_u16(position)
    sleep(0.01)

# Convert rotation angle to duty cycle 
def convert(x, i_m, i_M, o_m, o_M):
    return max(min(o_M, (x - i_m) * (o_M - o_m) // (i_M - i_m) + o_m), o_m)

while True:
    for degree in range(0, 180, 1):#Rotate from 0° to 180° 
        pos = convert(degree, 0, 180, 1000, 9000)
        setServoCycle(pos)

    for degree in range(180, 0, -1):#Rotate from 180° to 0° 
        pos = convert(degree, 0, 180, 1000, 9000)
        setServoCycle(pos)
