import sys
input = sys.stdin.readline

n, m = map(int, input().split())
l = list(map(int, input().split()))
res = l + [0] * m
for i in range(n):
    temp = list(map(int, input().split()))
    for j in range(n + m):
        res[i] -= temp[j]
        res[j] += temp[j]
print(*res)