import sys
input = sys.stdin.readline

m, s, x1, x2 = map(int, input().split())
for a in range(m):
    for c in range(m):
        if x1 == (a * s + c) % m and x2 == (a * x1 + c) % m:
            print(a, c)
            exit(0)