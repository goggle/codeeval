#!/usr/bin/env python

#
# PENULTIMATE WORD
#

from sys import argv

def main():
    if len(argv) < 2:
        return

    filename = argv[1]
    with open(filename, 'r') as f:
        for line in f:
            words = line.strip('\n').split(' ')
            print(words[-2])

if __name__ == '__main__':
    main()
