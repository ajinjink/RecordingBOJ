import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    a, b, f = map(int, input().split())
    print("Data set:", a, b, f)
    for _ in range(f):
        if a > b:
            a //= 2
        else:
            b //= 2
    print(max(a, b), min(a, b))
    print()