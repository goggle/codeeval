#!/usr/bin/env python

#
# FIND A WRITER
#

from sys import argv

def main():
    if len(argv) < 2:
        return

    filename = argv[1]
    with open(filename, 'r') as f:
        for line in f:
            parts = line.strip('\n').split('| ')
            word_list = parts[0]
            number_list = parts[1].split(' ')
            number_list = [int(x) for x in number_list]
            s = ''
            for elem in number_list:
                s += word_list[elem-1]
            print(s)

if __name__ == '__main__':
    main()
