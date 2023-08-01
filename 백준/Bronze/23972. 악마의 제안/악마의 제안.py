import sys
input = sys.stdin.readline

k, n = map(int, input().split())
if n == 1:
    print(-1)
    exit(0)
print((k * n) // (n - 1) + (1 if (k * n) % (n - 1) else 0))