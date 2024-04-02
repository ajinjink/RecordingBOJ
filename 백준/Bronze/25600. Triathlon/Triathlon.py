import sys
input = sys.stdin.readline


n = int(input())
score = 0
for _ in range(n):
    a, d, g = map(int, input().split())
    temp = 0
    if a == d + g:
        temp += a * (d + g) * 2
    else:
        temp += a * (d + g)
    score = max(score, temp)

print(score)