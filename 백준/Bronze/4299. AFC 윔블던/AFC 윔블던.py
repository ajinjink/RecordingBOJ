import sys
input = sys.stdin.readline

a, b = map(int, input().split())

A = (a + b) // 2
B = a - A

if a + b < 0 or a - b < 0 or (a + b) % 2 == 1:
    print(-1)
else:
    print(max(A, B), min(A, B))
