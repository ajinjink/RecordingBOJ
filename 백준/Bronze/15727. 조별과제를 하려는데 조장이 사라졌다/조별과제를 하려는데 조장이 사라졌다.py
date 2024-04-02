import sys
input = sys.stdin.readline

a = int(input())

res = a // 5
if a % 5:
    res += 1

print(res)