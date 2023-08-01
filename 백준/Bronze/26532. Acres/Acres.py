import math
import sys
input = sys.stdin.readline

a, b = map(int, input().split())
print(math.ceil(a * b / 4840 / 5))