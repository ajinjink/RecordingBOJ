import sys
input = sys.stdin.readline

k = float(input())
d1, d2 = map(float, input().split())
if d1 > d2:
    d1, d2 = d2, d1
print(k**2 - ((d2 - d1) / 2)**2)