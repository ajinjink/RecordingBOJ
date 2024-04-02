import sys
input = sys.stdin.readline

res = 0
for _ in range(int(input())):
    l = list(map(int, input().split()))
    res += max(l) if max(l) > 0 else 0
print(res)