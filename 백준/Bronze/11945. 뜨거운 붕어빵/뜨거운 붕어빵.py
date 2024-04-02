import sys
input = sys.stdin.readline

n, m = map(int, input().split())
for _ in range(n):
    str = input().strip()
    for i in range(len(str)-1, -1, -1):
        print(str[i], end='')
    print()