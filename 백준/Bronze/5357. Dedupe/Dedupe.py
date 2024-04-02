import sys
input = sys.stdin.readline

a = int(input())
for _ in range(a):
    str = input().strip()
    prev = "aaa"
    for c in str:
        if c != prev:
            print(c, end='')
            prev = c
    print()