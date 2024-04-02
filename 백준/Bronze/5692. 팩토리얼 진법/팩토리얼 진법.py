import math
import sys
input = sys.stdin.readline

while True:
    n = input().strip()
    if n == '0':
        break
    res = 0
    for i in range(len(n)):
        res += int(n[i]) * math.factorial(len(n) - i)
    print(res)