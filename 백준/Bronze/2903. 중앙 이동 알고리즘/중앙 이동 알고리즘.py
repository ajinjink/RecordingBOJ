import sys
input = sys.stdin.readline

n = int(input())
res = 2
for _ in range(n):
    res += res - 1
print(res**2)