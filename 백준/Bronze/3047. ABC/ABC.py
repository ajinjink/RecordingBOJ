import sys
input = sys.stdin.readline

l = sorted(list(map(int, input().split())))
order = input().strip()
for c in order:
    if c == 'A':
        print(l[0], end=' ')
    if c == 'B':
        print(l[1], end=' ')
    if c == 'C':
        print(l[2], end=' ')