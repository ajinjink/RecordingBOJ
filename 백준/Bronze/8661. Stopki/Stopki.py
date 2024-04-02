import sys
input = sys.stdin.readline

x, k, a = map(int, input().split())
if x % (k + a) < k:
    print(1)
else:
    print(0)