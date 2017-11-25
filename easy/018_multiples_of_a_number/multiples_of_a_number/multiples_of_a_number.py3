#!/usr/bin/env python

#
# MULTIPLES OF A NUMBER
#

import sys

def main():
    if len(sys.argv) < 2:
        return

    filename = sys.argv[1]
    with open(filename, 'r') as f:
        for line in f:
            l = line.strip('\n').split(',')
            x = int(l[0])
            n = int(l[1])
            if (n > x):
                print('0')
            else:
                m = n
                while (m < x):
                    m += n
                print(m)


if __name__ == '__main__':
    main()
