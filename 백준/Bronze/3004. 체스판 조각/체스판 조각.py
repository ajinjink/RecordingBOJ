import sys
input = sys.stdin.readline

N = int(input())
res, temp = 1, 1
for i in range(N):
    if i % 2 != 0:
        temp += 1
    res += temp
print(res)