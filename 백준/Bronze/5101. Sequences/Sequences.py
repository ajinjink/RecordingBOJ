import sys
input = sys.stdin.readline

while True:
    a, b, c = map(int, input().split())
    if a == b == c == 0:
        break
    res = c - a + b
    if res % b != 0 or (b != 0 and a > c):
        print('X')
    else:
        print(res // b)