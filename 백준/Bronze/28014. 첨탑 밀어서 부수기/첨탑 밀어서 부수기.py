import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))
res = 1
for i in range(n - 1):
    if l[i] <= l[i + 1]:
        res += 1
print(res)