import sys
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    a = int(input())
    if a % 2 == 0:
        print(a, "is even")
    else:
        print(a, "is odd")