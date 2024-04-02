import sys
input = sys.stdin.readline

n = int(input())
res = 0
for i in range(1, n + 1):
    res += i * (i + 1) * 3 / 2
print(int(res))