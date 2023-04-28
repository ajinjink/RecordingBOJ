import sys

num1, num2 = map(int, sys.stdin.readline().split())

res1 = num1 - (num1 // 100) * 99 + (num1 % 10) * 99
res2 = num2 - (num2 // 100) * 99 + (num2 % 10) * 99

if res1 > res2:
    print(res1)
else:
    print(res2)