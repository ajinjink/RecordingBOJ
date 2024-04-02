import sys
input = sys.stdin.readline

while True :
    a, b, c = map(int, input().split())
    if a == b == c == 0:
        break
    if a == 0:
        print(c // b, b, c)
    elif b == 0:
        print(a, c // a, c)
    else:
        print(a, b, a * b)