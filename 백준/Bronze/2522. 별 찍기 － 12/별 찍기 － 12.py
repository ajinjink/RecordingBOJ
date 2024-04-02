import sys
input = sys.stdin.readline

n = int(input())
for i in range(n):
    print(' ' * (n - 1 - i), end='')
    print('*' * (i + 1), end='')
    print()
for i in range(n - 2, -1, -1):
    print(' ' * (n - 1 - i), end='')
    print('*' * (i + 1), end='')
    print()