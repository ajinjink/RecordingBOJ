import sys
input = sys.stdin.readline

x = int(input())
n = int(input())
res = x * (n + 1)
for _ in range(n):
    res -= int(input())
print(res)