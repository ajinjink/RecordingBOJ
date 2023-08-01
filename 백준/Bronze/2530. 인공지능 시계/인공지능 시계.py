import sys
input = sys.stdin.readline

a, b, c = map(int, input().split())
d = int(input())

s = d % 60
d //= 60
m = d % 60
d //= 60
h = d % 24

a += h
b += m
c += s

if c >= 60:
    c -= 60
    b += 1
if b >= 60:
    b -= 60
    a += 1
if a >= 24:
    a -= 24

print(a, b, c)