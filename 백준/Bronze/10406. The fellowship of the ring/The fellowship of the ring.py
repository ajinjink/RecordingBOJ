import sys
input = sys.stdin.readline

w, n, p = map(int, input().split())
l = list(map(int, input().split()))
cnt = 0
for i in l:
    if w <= i <= n:
        cnt += 1
print(cnt)