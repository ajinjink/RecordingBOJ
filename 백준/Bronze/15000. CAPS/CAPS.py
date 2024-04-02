import sys
input = sys.stdin.readline


a = input().strip()

for i in a:
    c = ord(i) - (ord('a') - ord('A'))
    print(chr(c), end='')