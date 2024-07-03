'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 62
 * Comprehensive experiment
'''
from machine import Pin, PWM
import time
import random
import dht
from ADXL345 import adxl345

scl = Pin(21)
sda = Pin(20)
bus = 0
snsr = adxl345(bus, scl, sda)

pwm_r = PWM(Pin(2))
pwm_g = PWM(Pin(3))
pwm_b = PWM(Pin(4))

pwm_r.freq(1000)
pwm_g.freq(1000)
pwm_b.freq(1000)

pin = machine.Pin(19, machine.Pin.OUT, machine.Pin.PULL_DOWN)
xht = dht.DHT11(pin)

potentiometer = machine.ADC(28)
button = Pin(16, Pin.IN)
led = PWM(Pin(14))
led.freq(1000)
ird = Pin(11,Pin.IN)
B = machine.Pin(22, machine.Pin.IN)
X = machine.ADC(26)
Y = machine.ADC(27)
avoid = Pin(0, Pin.IN)
# 设置超声波引脚
trigger = Pin(6, Pin.OUT)
echo = Pin(7, Pin.IN)

def light(red, green, blue):
    pwm_r.duty_u16(red)
    pwm_g.duty_u16(green)
    pwm_b.duty_u16(blue)

act = {"1": "LLLLLLLLHHHHHHHHLHHLHLLLHLLHLHHH","2": "LLLLLLLLHHHHHHHHHLLHHLLLLHHLLHHH","3": "LLLLLLLLHHHHHHHHHLHHLLLLLHLLHHHH",
       "4": "LLLLLLLLHHHHHHHHLLHHLLLLHHLLHHHH","5": "LLLLLLLLHHHHHHHHLLLHHLLLHHHLLHHH","6": "LLLLLLLLHHHHHHHHLHHHHLHLHLLLLHLH",
       "7": "LLLLLLLLHHHHHHHHLLLHLLLLHHHLHHHH","8": "LLLLLLLLHHHHHHHHLLHHHLLLHHLLLHHH","9": "LLLLLLLLHHHHHHHHLHLHHLHLHLHLLHLH",
       "0": "LLLLLLLLHHHHHHHHLHLLHLHLHLHHLHLH","Up": "LLLLLLLLHHHHHHHHLHHLLLHLHLLHHHLH","Down": "LLLLLLLLHHHHHHHHHLHLHLLLLHLHLHHH",
       "Left": "LLLLLLLLHHHHHHHHLLHLLLHLHHLHHHLH","Right": "LLLLLLLLHHHHHHHHHHLLLLHLLLHHHHLH","Ok": "LLLLLLLLHHHHHHHHLLLLLLHLHHHHHHLH",
       "*": "LLLLLLLLHHHHHHHHLHLLLLHLHLHHHHLH","#": "LLLLLLLLHHHHHHHHLHLHLLHLHLHLHHLH"}

def read_ircode(ird):
    wait = 1
    complete = 0
    seq0 = []
    seq1 = []

    while wait == 1:
        if ird.value() == 0:
            wait = 0
    while wait == 0 and complete == 0:
        start = time.ticks_us()
        while ird.value() == 0:
            ms1 = time.ticks_us()
        diff = time.ticks_diff(ms1,start)
        seq0.append(diff)
        while ird.value() == 1 and complete == 0:
            ms2 = time.ticks_us()
            diff = time.ticks_diff(ms2,ms1)
            if diff > 10000:
                complete = 1
        seq1.append(diff)

    code = ""
    for val in seq1:
        if val < 2000:
            if val < 700:
                code += "L"
            else:
                code += "H"
    # print(code)
    command = ""
    for k,v in act.items():
        if code == v:
            command = k
    if command == "":
        command = code
    return command


# Ultrasonic ranging, unit: cm 
def getDistance(trigger, echo):
    #Generate 10us square wave 
    trigger.low()   #Pre-given a short low to ensure a clean high pulse: 
    time.sleep_us(2)
    trigger.high()
    time.sleep_us(10)#After pulling high, wait 10 microseconds, then set to low immediately 
    trigger.low()
    
    while echo.value() == 0: #Create a while loop to detect whether the echo pin is 0, and record the current time 
        start = time.ticks_us()
    while echo.value() == 1: #Create a while loop to detect whether the echo pin is 1 and record the time at that time 
        end = time.ticks_us()
    d = (end - start) * 0.0343 / 2 #The travel time of the sound wave x the speed of sound (343.2 m/s, or 0.0343 centimeters per microsecond), and then divide the round-trip distance by 2 
    return d


keys = 0
nums = 0
print(keys % 8)
def toggle_handle(pin):
    global keys
    keys += 1
    print(keys % 7)

button.irq(trigger = Pin.IRQ_FALLING, handler = toggle_handle)

def showRGB():
    R = random.randint(0,65535)
    G = random.randint(0,65535)
    B = random.randint(0,65535)
    light(R, G, B)
    time.sleep(0.3)

def showxht11():
    print("temperature：{} ℃  humidity：{} %".format(xht.temperature, xht.humidity))
    time.sleep(1)

def IRreceive():
    command = read_ircode(ird)
    print(command)

def showJoystick():
    B_value = B.value()
    X_value = X.read_u16()
    Y_value = Y.read_u16()
    print("button:", end = " ")
    print(B_value, end = " ")
    print("X:", end = " ")
    print(X_value, end = " ")
    print("Y:", end = " ")
    print(Y_value)
    time.sleep(0.1)

def adjustLight():
    pot_value = potentiometer.read_u16()
    print(pot_value)
    led.duty_u16(pot_value)
    time.sleep(0.1)

def showAvoid():
    if avoid.value() == 0:
        print("There are obstacles")
    else:
        print("All going well")
    time.sleep(0.1)

def showDistance():
    distance = getDistance(trigger, echo)
    print("The distance is ：{:.2f} cm".format(distance))
    time.sleep(0.1)

def showADXL345():
    x,y,z = snsr.readXYZ()
    print('x:',x,'y:',y,'z:',z,'uint:mg')
    time.sleep(0.1)

while True:
    nums = keys % 8  #Multiply the number of keys to 8 to get 0 1 2 3 4 5 6  7
    if nums == 0:  #Display RGB 
        showRGB()
    elif nums == 1:  #Displays the value of infrared reception 
        IRreceive()
    elif nums == 2:  #Display temperature and humidity 
        showxht11()
    elif nums == 3:  #Display joystick value 
        showJoystick()
    elif nums == 4:  #potentiometer to adjust led 
        adjustLight()
    elif nums == 5:  #Display obstacle information 
        showAvoid()
    elif nums == 6:  #Display ultrasonic ranging value 
        showDistance()
    elif nums == 7:  #Display ultrasonic ranging value 
        showADXL345()