import sys
input = sys.stdin.readline

res = 0
for _ in range(4):
    a, b = input().split()
    res += int(b) * [21, 17][a == 'Stair']
print(res)