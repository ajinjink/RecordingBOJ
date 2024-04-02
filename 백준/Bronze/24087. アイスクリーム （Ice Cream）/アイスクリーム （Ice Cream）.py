import math
import sys
input = sys.stdin.readline

s = int(input())
a = int(input())
b = int(input())
res = 250
res += 100*(math.ceil((s - a) / b))
print(250 if s <= a else res)