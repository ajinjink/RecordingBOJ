import sys
input = sys.stdin.readline

x, y = map(int, input().split())
cnt = 1
while True:
    if (y - x) * cnt >= y:
        break
    cnt += 1
print(cnt)