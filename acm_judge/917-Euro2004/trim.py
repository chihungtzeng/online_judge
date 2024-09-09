#!/usr/bin/python

from __future__ import print_function
import sys

def main():
    for line in sys.stdin:
        line = line.strip()
        fields = line.split()
        if len(fields) != 4:
            print(line)
            continue
        print("{} {} {} {}".format(fields[0][:3], fields[1][:3], fields[2], fields[3]))

if __name__ == "__main__":
    main()
