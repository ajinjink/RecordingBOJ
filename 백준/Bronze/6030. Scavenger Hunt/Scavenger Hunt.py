import sys
input = sys.stdin.readline

p, q = map(int, input().split())
for i in range(1, p + 1):
    if p % i == 0:
        for j in range(1, q + 1):
            if q % j == 0:
                print(i, j)