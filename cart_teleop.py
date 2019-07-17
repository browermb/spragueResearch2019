import serial
import time
from bitstruct import *
speed_port = '/dev/ttyACM0' #hardcoded depending on computer


def cart_teleop():

    try:
        speed_ser = serial.Serial(speed_port, 9600, write_timeout=0)
    except Exception as e:
        print("Motor_endpoint: " + str(e))
        exit(0)

    angle = 0
    while True:
	data = bytearray(b'\x00\x00\x00\x00\x00\x00')
        vals = raw_input()
        vals = vals.split()
        throttle = int(vals[0])
        brake = int(vals[1])
        steering = int(vals[2])		
        pack_into('u16u16u16u16u16', data, 0, 42, 21, throttle, brake, steering)
        speed_ser.write(data) 
        print(vals)
        time.sleep(.05)
        
        
if __name__ == "__main__": 
    cart_teleop()
