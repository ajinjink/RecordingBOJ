import sys
input = sys.stdin.readline

a, b, c = map(int, input().split())
cnt, n = 0, 0
while n < c:
    n += a
    cnt += 1
    if cnt % 7 == 0:
        n += b
print(cnt)