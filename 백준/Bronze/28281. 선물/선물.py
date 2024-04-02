import sys
input = sys.stdin.readline

n, x = map(int, input().split())
l = list(map(int, input().split()))
l2 = [l[i] + l[i + 1] for i in range(n - 1)]
print(min(l2) * x)