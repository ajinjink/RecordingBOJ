import math
import sys
input = sys.stdin.readline

n = int(input())
n = math.factorial(n)
print(n // (7 * 24 * 60 * 60))