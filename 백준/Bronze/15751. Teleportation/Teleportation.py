import sys
input = sys.stdin.readline

a, b, x, y = map(int, input().split())
if a > b:
    a, b = b, a
if x > y:
    x, y = y, x
print(min(b - a, abs(x - a) + abs(y - b)))