#!/bin/bash
IFS=$'\n'
let lineno=0
ans=""
for line in `cat file.txt`; do
  let lineno=$lineno+1
  if [[ $lineno -eq 10 ]]; then
    ans=$line
  fi
done
if [[ ! -z "${ans}" ]]; then
  echo $ans
fi
