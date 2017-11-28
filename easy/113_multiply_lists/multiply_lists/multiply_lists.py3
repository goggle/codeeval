#!/usr/bin/env python

#
# MULTIPLY LISTS
#

import sys

def main():
    if len(sys.argv) < 2:
        return

    filename = sys.argv[1]
    with open(filename, 'r') as f:
        for line in f:
            two_lists = line.strip('\n').split('|')
            list1 = two_lists[0]
            list2 = two_lists[1]
            list1 = list1.strip(' ').split(' ')
            list2 = list2.strip(' ').split(' ')
            result = []
            for i in range(0, len(list1)):
                r = str(int(list1[i]) * int(list2[i]))
                result.append(r)
            string = ' '.join(x for x in result)
            print(string)


if __name__ == '__main__':
    main()
