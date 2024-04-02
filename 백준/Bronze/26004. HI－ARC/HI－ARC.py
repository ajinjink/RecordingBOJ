import sys
input = sys.stdin.readline

n = int(input())
s = input()
l = [0] * 5
for c in s:
    if c == 'H':
        l[0] += 1
    elif c == 'I':
        l[1] += 1
    elif c == 'A':
        l[2] += 1
    elif c == 'R':
        l[3] += 1
    elif c == 'C':
        l[4] += 1
print(min(l))