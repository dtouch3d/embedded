#!/usr/bin/python3

import serial
import time
import sys

ser = serial.Serial("/dev/ttyACM0")
ser.setDTR(1)
time.sleep(0.5)
ser.setDTR(0)
ser.close
