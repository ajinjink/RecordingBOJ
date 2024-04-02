import math
import sys
input = sys.stdin.readline

r, c, n = map(int, input().split())
print(math.ceil(r / n) * math.ceil(c / n))