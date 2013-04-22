#!/bin/bash

FILENAME=$(echo $1 | awk -F. '{ print $1 }')

avr-gcc -std=c99 -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o $FILENAME.o $1
avr-gcc -mmcu=atmega328p $FILENAME.o -o $FILENAME
avr-objcopy -O ihex -R .eeprom $FILENAME $FILENAME.hex

python ./arduino_reset.py
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:$FILENAME.hex

rm $FILENAME.o $FILENAME $FILENAME.hex
