import sys
input = sys.stdin.readline

n, m = map(int, input().split())
cnt = n
while n:
    n = n // m
    cnt += n
print(cnt)