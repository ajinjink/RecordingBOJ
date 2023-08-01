import sys
input = sys.stdin.readline

n = int(input())
cnt = 0
for i in range(2, n - 1, 2):
    cnt += (n - i - 2) // 2
print(cnt)