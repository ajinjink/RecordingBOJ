import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, m = map(int, input().split())
    print(11 * m + 4 if n >= 12 and m >= 4 else -1)