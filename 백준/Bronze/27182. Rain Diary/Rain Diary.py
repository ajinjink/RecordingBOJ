import sys
input = sys.stdin.readline

a, b = map(int, input().split())
print([a - 7, b + 7][a <= 7])