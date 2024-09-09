#!/bin/bash
fields=`head -n 1 file.txt|wc -w`
for i in `seq 1 ${fields}`; do
  cat file.txt | awk "{print $"$i"}" | tr "\r\n" ' ' | sed 's/ $//g'
  echo
done
