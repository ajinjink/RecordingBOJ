import sys
input = sys.stdin.readline

m, n = map(int, input().split())
for _ in range(m):
    a, b, c = map(int, input().split())
print("satisfactory" if m >= 8 else "unsatisfactory")