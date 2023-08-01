import sys
input = sys.stdin.readline

a = int(input())
cnt = 0
for i in range(6):
    for j in range(i, 6):
        if i + j == a:
            cnt += 1
print(cnt)