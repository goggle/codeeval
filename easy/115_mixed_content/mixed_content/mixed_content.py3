#!/usr/bin/env python

#
# MIXED CONTENT
#

from sys import argv

def main():
    if len(argv) < 2:
        return

    filename = argv[1]
    with open(filename, 'r') as f:
        for line in f:
            s = line.strip('\n').split(',')
            word_list = []
            number_list = []
            for elem in s:
                if elem.isalpha():
                    word_list.append(elem)
                elif elem.isdecimal():
                    number_list.append(elem)
            s = ''
            word_output = ','.join(word_list)
            number_output = ','.join(number_list)
            if (word_list and number_list):
                print(word_output + '|' + number_output)
            elif (word_list):
                print(word_output)
            elif (number_list):
                print(number_output)

if __name__ == '__main__':
    main()
