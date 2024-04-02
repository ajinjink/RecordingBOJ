import sys
input = sys.stdin.readline

n, m = map(int, input().split())
for i in range(n):
    for j in range(m):
        print('*' if (i + j) % 2 == 0 else '.', end='')
    print()