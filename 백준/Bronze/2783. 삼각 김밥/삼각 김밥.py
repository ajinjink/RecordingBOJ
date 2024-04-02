import sys
input = sys.stdin.readline

x, y = map(int, input().split())
res = x * 1000 / y
n = int(input())
for _ in range(n):
    xi, yi = map(int, input().split())
    res = min(res, xi * 1000 / yi)
print(res)