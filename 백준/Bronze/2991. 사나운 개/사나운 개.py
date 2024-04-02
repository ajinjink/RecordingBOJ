import sys
input = sys.stdin.readline

a, b, c, d = map(int, input().split())
l = list(map(int, input().split()))
for i in l:
    res = 0
    if 0 < i % (a + b) <= a:
        res += 1
    if 0 < i % (c + d) <= c:
        res += 1
    print(res)