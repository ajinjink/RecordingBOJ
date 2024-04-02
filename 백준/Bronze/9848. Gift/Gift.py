import sys
input = sys.stdin.readline

n, k = map(int, input().split())
t = int(input())
res = 0
for _ in range(n - 1):
    temp = int(input())
    if t - temp >= k:
        res += 1
    t = temp
print(res)