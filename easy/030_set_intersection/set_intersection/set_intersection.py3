#!/usr/bin/env python

import sys

def main():
    if len(sys.argv) < 2:
        return
    filename = sys.argv[1]
    lines = []
    with open(filename, 'r') as f:
        for line in f:
            lines.append(line)

    for line in lines:
        set1 = []
        set2 = []
        separators = []
        semicolon = 0;
        passed = False
        c = ''
        for ind, elem in enumerate(line):
            if elem == ',' or elem == ';' or ind == len(line) - 1:
                if not passed:
                    set1.append(int(c))
                else:
                    set2.append(int(c))
                if elem == ';':
                    passed = True
                c = ''
            else:
                c += elem

        intersection = []
        for elem1 in set1:
            found = False
            for elem2 in set2:
                if elem1 == elem2:
                    found = True
                    break
            if found:
                intersection.append(elem1)

        if not intersection:
            print()
        else:
            print( str(intersection).strip('[]').replace(' ', '') )

if __name__ == "__main__":
    main()

