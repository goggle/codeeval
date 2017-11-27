#!/usr/bin/env python

#
# CAPITALIZE WORDS
#

from sys import argv

def main():
    if len(argv) < 2:
        return

    filename = argv[1]
    with open(filename, 'r') as f:
        for line in f:
            l = list(line)[:-1]
            l[0] = l[0].upper()
            for i in range(0, len(l)):
                if l[i] == ' ':
                    if i+1 < len(l):
                        l[i+1] = l[i+1].upper()
            print("".join(l))

if __name__ == '__main__':
    main()
