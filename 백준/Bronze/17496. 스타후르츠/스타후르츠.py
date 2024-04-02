import sys
input = sys.stdin.readline

n, c, t, p = map(int, input().split())
print((n-1) // c * t * p)