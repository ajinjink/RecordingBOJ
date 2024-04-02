import sys
input = sys.stdin.readline

n = 5000
l = list(map(int, input().split()))
for i in l:
    if i == 1:
        n -= 500
    elif i == 2:
        n -= 800
    else:
        n -= 1000
print(n)