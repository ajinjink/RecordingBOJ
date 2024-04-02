import sys
input = sys.stdin.readline

res = 0
for _ in range(int(input())):
    res += sum(list(map(int, input().split())))
print(res)