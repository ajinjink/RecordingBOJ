import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, m, l = map(int, input().split())
    if l == 1:
        if n % m == 0:
            print(n // m)
        else:
            print(n // m + 1)
    else:
        n -= (m - l + 1)
        if n % m == 0:
            print(n // m)
        else:
            print(n // m + 1)