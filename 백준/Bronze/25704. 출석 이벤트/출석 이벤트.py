import sys
input = sys.stdin.readline

n = int(input())
p = int(input())

d = 0
if n >= 5:
    d = max(d, 500)
if n >= 10:
    d = max(d, p//10)
if n >= 15:
    d = max(d, 2000)
if n >= 20:
    d = max(d, p//4)

print(0 if p <= d else p - d)