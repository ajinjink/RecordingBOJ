import sys
input = sys.stdin.readline

l, r, a = map(int, input().split())
total  = l + r + a
if l > r:
    l, r = r, l
if l == r and a % 2:
    total -= 1
else:
    if a < (r - l):
        total -= abs(r - l - a)
    elif a > (r - l):
        a -= r - l
        if a % 2:
            total -= 1
print(total)