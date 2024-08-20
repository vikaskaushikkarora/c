#!/bin/bash
gcc heater.c -o a.out -lpthread
(time ./a.out) 2> output
rm a.out
