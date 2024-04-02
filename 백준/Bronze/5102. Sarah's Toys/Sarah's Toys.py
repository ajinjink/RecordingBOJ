import sys
input = sys.stdin.readline

while True:
    a, b = map(int, input().split())
    if a == b == 0:
        break
    if a - b < 2:
        print(0, 0)
    elif (a - b) % 2 == 0:
        print((a - b) // 2, 0)
    else:
        print((a - b - 3) // 2, 1)