#!/bin/bash

gcc heater.c -lm -lpthread -o a.out
./a.out
rm a.out
