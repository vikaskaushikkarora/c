#!/bin/bash

gcc heater.c -lm -lpthread -o a.out
./a.out $1 $2
rm a.out
