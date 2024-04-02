import sys
input = sys.stdin.readline

n, m = map(int, input().split())
original = [input().strip() for _ in range(n)]
input()
misha = [input().strip() for _ in range(n)]

cnt = 0
for i in range(n):
    for j in range(m):
        if original[i][j] == misha[i][j]:
            cnt += 1

print(cnt)