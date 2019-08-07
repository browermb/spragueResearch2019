import curses
import sys
import math
import serial
import time
import bitstruct
import numpy as np
speed_port = '/dev/ttyUSB0' #hardcoded depending on computer



class teleop(object):
    
    MAX_SPEED = 255
    
    def __init__(self):

        self.prev_key = 1
        self.cur_vel = 0 #  (0 - 255)
        try:
            self.speed_ser = serial.Serial(speed_port, 9600, write_timeout=0)
        except Exception as e:
            print("Motor_endpoint: " + str(e))
            exit(0)
	    curses.wrapper(self.get_input)


    def get_input(self, stdscr):
	curses.use_default_colors()
	for i in range(0, curses.COLORS):
	    curses.init_pair(i, i, -1)

	angle_max = 720
	angle_step = 15
	velstr = 'Hard stop     '
	anglestr = 'Center wheels '
    stdscr.nodelay(True)
	stdscr.addstr(0,0,'Move with WASD, X for hard stop and Y for centering the wheel')
	stdscr.addstr(1,0,'CTRL-C to exit')
	stdscr.addstr(3,0,'TURNING       WHEEL ANGLE')
	stdscr.addstr(6,0,'FORWARD MOVEMENT')
        while True:

            keyval = stdscr.getch()

            if keyval == ord('w'):
                self.cur_vel = min(self.MAX_SPEED, self.cur_vel + 10)
                #print self.cur_vel
            elif keyval == ord('s'):
                self.cur_vel = max(0, self.cur_vel - 10)
                #print self.cur_vel
	    elif keyval == ord('x'):
		    self.cur_vel = 0
        elif keyval == ord('z'):
	        self.brake(self.cur_vel / 255.0 * 3, stdscr)
            self.cur_vel = 0
                
	    self.send_cmd(self.cur_vel, 0, 0, stdscr)
	    self.prev_key = keyval
        time.sleep(1/10.)

    def brake(self, delay, stdscr):
        rate = 10.
        steps = delay * rate
        for brake in np.linspace(0, 255, steps, endpoint=True):
            self.send_cmd(0, int(brake), 0, stdscr)
            time.sleep(1./rate)
            stdscr.getch()
        
    def send_cmd(self, throttle, brake, steering, stdscr):
        angle = 0
	    data = bytearray(b'\x00' * 6)
        bitstruct.pack_into('u8u8u8u8u16', data, 0, 42, 21,
                            throttle, brake, steering)
        self.speed_ser.write(data) 
	    stdscr.addstr(7,0,str(throttle) + "       ")
        stdscr.addstr(8,0,str(brake) + "      ")
        
if __name__ == "__main__": 
    teleop()
