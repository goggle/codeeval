# Shortest Repetition

![Image](https://raw.githubusercontent.com/goggle/codeeval/master/easy/107_shortest_repetition/shortest_repetition.png)

## Challenge Description:

Write a program to determine the shortest repetition in a string.
A string is said to have period p if it can be formed by concatenating one or more repetitions of another string of length p. For example, the string "xyzxyzxyzxyz" has period 3, since it is formed by 4 repetitions of the string "xyz". It also has periods 6 (two repetitions of "xyzxyz") and 12 (one repetition of "xyzxyzxyzxyz").

## Input sample:

Your program should accept as its first argument a path to a filename. Each line will contain a string of up to 80 non-blank characters. E.g.
```
abcabcabcabc
bcbcbcbcbcbcbcbcbcbcbcbcbcbc
dddddddddddddddddddd
adcdefg
```

## Output sample:

Print out the smallest period of the input string. E.g.
```
3
2
1
7
```
