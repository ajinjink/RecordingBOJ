import sys
input = sys.stdin.readline

for _ in range(int(input())):
    res = 0
    for _ in range(int(input())):
        l = list(map(int, input().split()))
        if max(l) >= 0:
            res+=max(l)
    print(res)