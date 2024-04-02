import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    a, b, c = map(int, input().split())
    if b >= c:
        print(0)
    else:
        if a == 1:
            print(c - b)
        elif a == 2:
            print((c - b) * 3)
        elif a == 3:
            print((c - b) * 5)