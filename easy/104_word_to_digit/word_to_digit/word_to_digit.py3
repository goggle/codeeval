#!/usr/bin/env python

#
# WORD TO DIGIT
#

import sys

def main():
    if len(sys.argv) < 2:
        return

    filename = sys.argv[1]
    word_to_digit = {
        'zero': 0,
        'one': 1,
        'two': 2,
        'three': 3,
        'four': 4,
        'five': 5,
        'six': 6,
        'seven': 7,
        'eight': 8,
        'nine': 9
    }
    with open(filename, 'r') as f:
        for line in f:
            word_list = line.strip('\n').split(';')
            number_list = [word_to_digit[x] for x in word_list]
            string = ''
            for elem in number_list:
                string += str(elem)
            print(string)

if __name__ == '__main__':
    main()
