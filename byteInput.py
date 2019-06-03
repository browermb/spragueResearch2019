# !/usr/bin/env/ python

import serial

port = serial.Serial('default')
print(port.name)

byte_str = input('Please enter a value between 0 and 180')
byte_value = byte_str.encode('utf-8')

while byte_value < 0 or byte_value > 180:
    byte_str = input('Please enter a value between 0 and 180')
    byte_value = byte_str.encode('utf-8')

port.write(byte_value)
port.close()
