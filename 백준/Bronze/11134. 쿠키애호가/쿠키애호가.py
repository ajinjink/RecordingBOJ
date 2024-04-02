import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, c = map(int, input().split())
    res = n // c
    if n % c:
        res += 1
    print(res)