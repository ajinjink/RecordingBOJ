import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    a, b = map(float, input().split())
    print(f"{round(abs(a - b), 1):.1f}")