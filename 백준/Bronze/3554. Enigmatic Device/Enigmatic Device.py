import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
m = int(input())
for _ in range(m):
    k, l, r = map(int, input().split())
    if k == 1:
        for i in range(l - 1, r):
            a[i] = a[i]**2 % 2010
    else:
        sum = 0
        for i in range(l - 1, r):
            sum += a[i]
        print(sum)