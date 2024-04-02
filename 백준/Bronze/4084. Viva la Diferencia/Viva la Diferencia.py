import sys
input = sys.stdin.readline

while True:
    a, b, c, d = map(int, input().split())
    cnt = 0
    if a == b == c == d == 0:
        break
    while not (a == b == c == d):
        a, b, c, d = abs(a - b), abs(b - c), abs(c - d), abs(d - a)
        cnt += 1
    print(cnt)