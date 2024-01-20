#!/bin/bash

avr-gdb -ex 'target remote :1234' build/dtSIM
