#!/usr/bin/env python

#
# UNIQUE ELEMENTS
#

from sys import argv

def main():
    if len(argv) < 2:
        return

    filename = argv[1]
    with open(filename, 'r') as f:
        for line in f:
            number_list = []
            start = 0
            end = line.find(',')
            while (end != -1):
                number = int(line[start:end])
                line = line[end+1:]
                if not number in number_list:
                    number_list.append(number)
                end = line.find(',')
            number = int(line[start:])
            if not number in number_list:
                number_list.append(number)
            number_list = sorted(number_list)
            print(','.join([str(x) for x in number_list]))

if __name__ == '__main__':
    main()
