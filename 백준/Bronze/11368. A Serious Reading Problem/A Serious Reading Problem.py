import sys
input = sys.stdin.readline

while True:
    c, w, l, p = map(int, input().split())
    if c == w == l == p == 0:
        break
    if c == 1:
        print(1)
    else:
        res = 1
        temp = w * l * p
        while temp > 0:
            res *= c
            temp -= 1
        print(res)