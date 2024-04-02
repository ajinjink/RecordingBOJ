import sys
input = sys.stdin.readline

h, m = map(int, input().split())

print(60 * (h - 9) + m)