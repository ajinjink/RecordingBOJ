import sys
input = sys.stdin.readline

for _ in range(2):
    t, f, s, p, c = map(int, input().split())
    print(6*t + 3*f + 2*s + p + 2*c, end=' ')

