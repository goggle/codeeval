#!/usr/bin/env python

#
# RIGHTMOST CHAR
#

import sys

def main():
    if len(sys.argv) < 2:
        return

    filename = sys.argv[1]
    with open(filename, 'r') as f:
        for line in f:
            char = line[-2]
            line = line[:-3]
            print(line.rfind(char))

if __name__ == '__main__':
    main()
