import sys
input = sys.stdin.readline

def rf(n):
    if n - int(n) >= 0.5:
        return int(n) + 1
    else:
        return int(n)

for _ in range(int(input())):
    r, g, b = 0, 0, 0
    for _ in range(10):
        aa, bb, cc = map(int, input().split())
        r += aa
        g += bb
        b += cc
    print(rf(r / 10), rf(g / 10), rf(b / 10))