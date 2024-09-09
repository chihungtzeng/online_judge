#!/bin/bash
IFS=$'\n'
for line in `cat file.txt`; do
  if [[ "${line}" =~ ^\([0-9]{3}\)\ [0-9]{3}-[0-9]{4}$ ]]; then
    echo $line
  elif [[ "${line}" =~ ^[0-9]{3}-[0-9]{3}-[0-9]{4}$ ]]; then
    echo $line
  fi
done
