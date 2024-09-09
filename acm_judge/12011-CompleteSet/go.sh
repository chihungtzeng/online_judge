#!/bin/sh
DFILE=in2.txt
OFILE=out2.txt
gcc gen.c -o gen
./gen > $DFILE
gcc main-2.c -o tle
./tle < $DFILE > $OFILE
