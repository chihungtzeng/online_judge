#!/bin/sh
gcc gen.c -o gen
gcc 10110.c -lm -o v1
gcc 10110-2.c -lm -o v2
./gen > in2.txt
time ./v1 < in2.txt > ok
time ./v2 < in2.txt > u
