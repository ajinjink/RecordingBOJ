import sys
input = sys.stdin.readline

for _ in range(int(input())):
    res = 0
    x, w = map(int, input().split())
    while x < w:
        x *= 2
        res += 1
    print(res)