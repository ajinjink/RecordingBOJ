import sys
input = sys.stdin.readline

n, h, v = map(int, input().split())
print(max(h, n - h) * max(v, n - v) * 4)