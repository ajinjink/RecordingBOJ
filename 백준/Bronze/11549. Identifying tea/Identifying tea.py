import sys
input = sys.stdin.readline

ans = int(input())
l = list(map(int, input().split()))
cnt = 0
for i in l:
    if i == ans:
        cnt += 1

print(cnt)
