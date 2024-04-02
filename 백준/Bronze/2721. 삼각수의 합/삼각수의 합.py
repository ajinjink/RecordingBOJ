import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    res, temp = 0, 0
    for i in range(1, n + 1):
        for k in range(1, i + 2):
            temp += k
        res += temp * i
        temp = 0
    print(res)