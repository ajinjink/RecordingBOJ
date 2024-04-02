import sys
input = sys.stdin.readline

n, k, x, y = map(int, input().split())
res = 0
for _ in range(n):
    xi, yi = map(int, input().split())
    if ((xi - x)**2 + (yi - y)**2)**0.5 > k:
        res += 1
print(res)