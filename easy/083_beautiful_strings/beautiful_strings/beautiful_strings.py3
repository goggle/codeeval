#!/usr/bin/env python

#
# BEAUTIFUL STRINGS
#

from sys import argv



def main():
    if len(argv) < 2:
        return

    filename = argv[1]
    with open(filename, 'r') as f:
        for line in f:
            dictionary = {
                'a': 0,
                'b': 0,
                'c': 0,
                'd': 0,
                'e': 0,
                'f': 0,
                'g': 0,
                'h': 0,
                'i': 0,
                'j': 0,
                'k': 0,
                'l': 0,
                'm': 0,
                'n': 0,
                'o': 0,
                'p': 0,
                'q': 0,
                'r': 0,
                's': 0,
                't': 0,
                'u': 0,
                'v': 0,
                'w': 0,
                'x': 0,
                'y': 0,
                'z': 0
            }
            line = line.lower()
            for c in line:
                if c.isalpha():
                    dictionary[c] += 1
            count = []
            for elem in dictionary.values():
                if elem > 0:
                    count.append(elem)
            count = sorted(count, reverse=True)

            s = 0
            i = 26
            for elem in count:
                s += elem * i
                i -= 1
            print(s)


if __name__ == '__main__':
    main()
