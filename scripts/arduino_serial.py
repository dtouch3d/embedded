#!/usr/bin/python

import serial

ser = serial.Serial("/dev/ttyACM0", 9600)
while True:
	print(ser.readline())
