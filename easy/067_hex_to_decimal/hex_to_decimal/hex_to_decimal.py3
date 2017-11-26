#!/usr/bin/env/python
import sys

def main():
    if len(sys.argv) < 2:
        return

    filename = sys.argv[1]
    lines = []
    with open(filename, 'r') as f:
        for line in f:
            lines.append(line)

    hex_to_int = {
        '0': 0,
        '1': 1,
        '2': 2,
        '3': 3,
        '4': 4,
        '5': 5,
        '6': 6,
        '7': 7,
        '8': 8,
        '9': 9,
        'a': 10,
        'b': 11,
        'c': 12,
        'd': 13,
        'e': 14,
        'f': 15,
    }

    for line in lines:
        s = 0
        c = 0
        i = len(line) - 2
        while i >= 0:
            s += hex_to_int[line[i]] * 16**c
            c += 1
            i -= 1
        print(s)

if __name__ == '__main__':
    main()
