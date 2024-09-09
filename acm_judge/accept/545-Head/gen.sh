#!/bin/sh
echo 150 >> in3.txt
for f in `seq 8001 8150`; do
	echo $f >> in3.txt
done
