import sys
input = sys.stdin.readline

n = int(input())
res = 0
for _ in range(n):
    a = int(input())
    res += a

print(res)