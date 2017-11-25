#!/usr/bin/env python

#
# REVERSE WORDS
#

import sys

def main():
    if len(sys.argv) < 2:
        return

    filename = sys.argv[1]
    with open(filename, 'r') as f:
        for line in f:
            l = line[:-1].split(' ')
            string = ''
            for i in range(len(l)-1, -1, -1):
                string += l[i]
                if (i != 0):
                    string += ' '
            print(string)

if __name__ == '__main__':
    main()
