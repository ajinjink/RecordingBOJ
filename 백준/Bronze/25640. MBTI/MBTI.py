import sys
input = sys.stdin.readline

s = input().strip()
n = int(input())
cnt = 0
for _ in range(n):
    mbti = input().strip()
    if s == mbti:
        cnt += 1
print(cnt)