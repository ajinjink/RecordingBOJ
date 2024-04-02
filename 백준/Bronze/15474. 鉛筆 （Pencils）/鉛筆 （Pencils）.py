import math
import sys
input = sys.stdin.readline

n, a, b, c, d = map(int, input().split())
print(min(math.ceil(n / a) * b, math.ceil(n / c) * d))