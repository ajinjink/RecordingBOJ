import sys
input = sys.stdin.readline

n = int(input())
r, c = 1, 1
while r * c < n:
    if r > c:
        c += 1
    else:
        r += 1
print(r, c)