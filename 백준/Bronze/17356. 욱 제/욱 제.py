import sys
input = sys.stdin.readline

a, b = map(int, input().split())
m = (b - a) / 400
print(1 / (1 + pow(10, m)))