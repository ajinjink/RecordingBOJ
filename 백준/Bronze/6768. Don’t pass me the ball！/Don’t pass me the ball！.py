import sys
input = sys.stdin.readline

n = int(input())
print(0 if n < 4 else int((n - 1) * (n - 2) * (n - 3) / 6))