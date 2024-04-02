import math
import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))
evenodd = [0] * 2
for i in l:
    evenodd[i % 2] += 1
print(1 if evenodd[0] == n // 2 and evenodd[1] == math.ceil(n / 2) else 0)