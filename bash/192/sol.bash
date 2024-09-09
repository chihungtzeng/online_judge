#!/bin/bash
cat words.txt | tr -s " " "\n" | sort | uniq -c |  sort -nr -k 1 | awk '{print $2" "$1}'
