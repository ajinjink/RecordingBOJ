import sys
input = sys.stdin.readline

s = input().strip()
l = [1, 2, 3, 4]
for c in s:
    if c == 'A':
        l[0], l[1] = l[1], l[0]
    elif c == 'B':
        l[0], l[2] = l[2], l[0]
    elif c == 'C':
        l[0], l[3] = l[3], l[0]
    elif c == 'D':
        l[1], l[2] = l[2], l[1]
    elif c == 'E':
        l[1], l[3] = l[3], l[1]
    elif c == 'F':
        l[2], l[3] = l[3], l[2]
print(l.index(1) + 1)
print(l.index(4) + 1)