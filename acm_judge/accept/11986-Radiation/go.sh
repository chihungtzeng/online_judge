#!/bin/sh
gcc 11986.c -o v1
gcc 11986-2.c -o v2
gcc genTest.c -o gen
./gen > in2.txt
./v1 < in2.txt > out2.txt
./v2 < in2.txt > t
md5sum out2.txt
md5sum t
