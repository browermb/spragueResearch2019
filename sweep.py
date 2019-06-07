import serial
import time
speed_port = '/dev/ttyUSB0' #hardcoded depending on computer


def sweep():

    try:
        speed_ser = serial.Serial(speed_port, 9600, write_timeout=0)
    except Exception as e:
        print("Motor_endpoint: " + str(e))
        exit(0)

    angle = 0
    while True:
        angle = int(input())
        #angle = (angle + 1) % 180
        #speed_ser.write(bytes([angle])) # python3 version
        speed_ser.write(chr(angle))
        
        print(angle)
        time.sleep(.05)
        
        
if __name__ == "__main__": 
    sweep()
