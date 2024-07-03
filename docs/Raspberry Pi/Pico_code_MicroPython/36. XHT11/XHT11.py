'''
 * Keyes 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 36
 * xht11
'''
import machine
import utime
import dht

pin = machine.Pin(22, machine.Pin.OUT, machine.Pin.PULL_DOWN)
sensor = dht.DHT11(pin)

while True:
    print("temperature：{} ℃  humidity：{} %".format(sensor.temperature, sensor.humidity))
    utime.sleep(1.5)
