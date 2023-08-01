import sys
input = sys.stdin.readline

a, b = map(int, input().split())
res = abs((b - 1) // 4 - (a - 1) // 4) + abs(((b - 1) % 4) - ((a - 1) % 4))

print(res)