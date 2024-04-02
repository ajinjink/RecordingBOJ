import sys
input = sys.stdin.readline

n = int(input())
cnt = 0
for _ in range(n):
    s = input().strip()
    if int(s[2:]) <= 90:
        cnt += 1
print(cnt)