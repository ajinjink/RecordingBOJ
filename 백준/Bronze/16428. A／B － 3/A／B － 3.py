import sys
input = sys.stdin.readline

a, b = map(int, input().split())
print(a // b + (1 if a % b < 0 else 0))
print(a % b +(- b if a % b < 0 else 0))