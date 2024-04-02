import math
import sys
input = sys.stdin.readline

n = int(input())

side = math.sqrt(n).__floor__()

print(f"The largest square has side length {side}.")