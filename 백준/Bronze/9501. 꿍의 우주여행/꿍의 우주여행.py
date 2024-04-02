import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, d = map(int, input().split())
    res = 0
    for _ in range(n):
        vi, fi, ci = map(int, input().split())
        if vi * fi // ci >= d:
            res += 1
    print(res)