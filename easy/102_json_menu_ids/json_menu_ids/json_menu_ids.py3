#!/usr/bin/env python

#
# JSON MENU IDS
#

from sys import argv
from json import loads

def main():
    if len(argv) < 2:
        return

    filename = argv[1]
    with open(filename, 'r') as f:
        for line in f:
            line = line.strip()
            if len(line) == 0:
                continue
            js = loads(line)
            l = js.get('menu').get('items')
            s = 0
            for el in l:
                try:
                    label = el['label']
                    s += el['id']

                except (KeyError, TypeError):
                    continue

            print(s)


if __name__ == '__main__':
    main()
