import math
import sys
input = sys.stdin.readline

n = int(input())
v = 0
l = list(map(float, input().split()))
for i in l:
    v += i**3
print(math.pow(v, 1/3))