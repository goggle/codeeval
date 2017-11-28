#!/usr/bin/env python

#
# LONGEST WORD
#

import sys

def main():
    if len(sys.argv) < 2:
        return

    filename = sys.argv[1]
    with open(filename, 'r') as f:
        for line in f:
            word_list = line.strip('\n').split(' ')
            length_list = [len(x) for x in word_list]
            max_length = max(length_list)
            position = length_list.index(max_length)
            print(word_list[position])

if __name__ == '__main__':
    main()
