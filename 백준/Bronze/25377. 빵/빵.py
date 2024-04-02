import sys
input = sys.stdin.readline

n = int(input())

time = 2000
for _ in range(n):
    a, b = map(int, input().split())
    if a <= b:
        time = min(time, max(a, b))
print(-1 if time==2000 else time)