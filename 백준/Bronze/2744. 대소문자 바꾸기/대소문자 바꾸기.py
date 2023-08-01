import sys

input = sys.stdin.readline

str = input().strip()

for i in str:
    if ord(i) >= ord('a'):
        c = ord(i) - (ord('a') - ord('A'))

        print(chr(c), end='')
    else:
        c = ord(i) + (ord('a') - ord('A'))

        print(chr(c), end='')
