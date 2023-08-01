import sys
input = sys.stdin.readline

n = int(input())
l = [input().strip() for _ in range(n)]
m = int(input())

if m == 1:
    for i in range(n):
        print(l[i])
elif m == 2:
    res = [[l[i][n-1-j] for j in range(n)] for i in range(n)]
    for i in range(n):
        print(''.join(res[i]))
else:
    res = [l[n-1-i] for i in range(n)]
    for i in range(n):
        print(res[i])