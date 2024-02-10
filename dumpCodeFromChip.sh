#!/bin/bash

#TODO: add code to correctly call avrdude!
avrdude -B 125khz -p atmega328p -P usb -c usbasp-clone -U flash:r:flashDump:i -v -F
